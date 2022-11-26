#ifdef STM32

#include "Can.h"
#include "CanDefs.inl"
#include "../Utils/BitUtils.h"

#include <assert.h>

#define warn(m) \
    __asm__ __volatile__("BKPT"); \
    return Status::Error

#define error(m) \
    __asm__ __volatile__("BKPT"); \
    return Status::Error

#define error_m(m) \
    __asm__ __volatile__("BKPT");
    
#define okay() return Status::Okay

static CAN_Registers* hcan = (CAN_Registers*)0x40006400UL;
static GPIO_Registers* gpioa = (GPIO_Registers*)0x48000000UL;
static GPIO_Registers* gpiob = (GPIO_Registers*)0x48000400UL;
static RCC_Registers* rcc = (RCC_Registers*)0x40021000UL;

CANBus::State CANBus::state = CANBus::State::None;

// ************* CAN callback function pointers  ***********************
static CANBus::MessageReceivedCallbackType message_received_callback = nullptr;

Status CANBus::init(GPIOMode gpio_mode, bool use_default_filter)
{
    if (state != CANBus::State::None)
    {
        state = CANBus::State::Error;
        error("CANBus::begin called multiple times");
    }

    // ***************** Initialize the clock for CAN and GPIO *****************
    //
    // Enable GPIOA in the RCC (clock) peripheral control registers
    if (gpio_mode == GPIOMode::A11A12)
    {
        SET_BIT(rcc->AHB2ENR, 0);
    }
    else if (gpio_mode == GPIOMode::B8B9)
    {
        SET_BIT(rcc->AHB2ENR, 1);
    }

    // Enable CAN1 in the RCC (clock) peripheral control registers
    SET_BIT(rcc->APB1ENR1, 25);

    // ***************** Initialize the GPIO for CAN bus *****************

    GPIO_Registers* gpio = nullptr;
    uint32_t tx_pin = -1;
    uint32_t rx_pin = -1;
    if (gpio_mode == GPIOMode::A11A12)
    {
        gpio = gpioa;
        rx_pin = GPIO_PIN_11;
        tx_pin = GPIO_PIN_12;
    }
    else if (gpio_mode == GPIOMode::B8B9)
    {
        gpio = gpiob;
        rx_pin = GPIO_PIN_8;
        tx_pin = GPIO_PIN_9;
    }

    if (gpio == nullptr)
    {
        error("selected gpio mode is invalid");
    }

    uint32_t temp = 0;
    temp = gpio->OSPEEDR;
    // clear the bits before setting them
    temp &= ~((3ul << rx_pin * 2) | (3ul << tx_pin * 2));
    temp |= (GPIO_SPEED_FREQ_VERY_HIGH << rx_pin * 2) | (GPIO_SPEED_FREQ_VERY_HIGH << tx_pin * 2);
    gpio->OSPEEDR = temp;

    temp = gpio->OTYPER;
    temp &= ~((1ul << rx_pin) | (1ul << tx_pin));
    temp |= (OUTPUT_PP << rx_pin) | (OUTPUT_PP << tx_pin);
    gpio->OTYPER = temp; 

    temp = gpio->PUPDR;
    temp &= ~((3ul << rx_pin * 2) | (3ul << tx_pin * 2));
    temp |= (GPIO_NOPULL << rx_pin * 2) | (GPIO_NOPULL << tx_pin * 2);
    gpio->PUPDR = temp;

    temp = gpio->AFR[1];
    temp &= ~((0b1111ul << ((rx_pin & 0x07u) * 4u)) | (0b1111ul << ((tx_pin & 0x07u) * 4u)));
    temp |= (GPIO_AF9_CAN1 << ((rx_pin & 0x07u) * 4u)) | (GPIO_AF9_CAN1 << ((tx_pin & 0x07u) * 4u));
    gpio->AFR[1] = temp;

    temp = gpio->MODER;
    temp &= ~((3ul << rx_pin * 2) | (3ul << tx_pin * 2));
    temp |= (MODE_AF << rx_pin * 2) | (MODE_AF << tx_pin * 2);
    gpio->MODER = temp;

    // ***************** Initialize the CAN peripheral *****************

    SET_BIT(hcan->MCR, CAN_MCR_INRQ);
    // Wait until hardware is ready
    while (READ_BIT(hcan->MSR, CAN_MSR_INAK) == 0)
    {
    } 

    // Wake the CAN peripheral from sleep
    CLEAR_BIT(hcan->MCR, CAN_MCR_SLEEP);

    // Wait until hardware is ready
    while (READ_BIT(hcan->MSR, CAN_MSR_SLAK) != 0)
    {
    } 

    // Disable time-triggered communication mode
    CLEAR_BIT(hcan->MCR, CAN_MCR_TTCM);

    // Set the bit timing register
    const uint32_t prescaler = 16;
    hcan->BTR = (uint32_t)((1ul << 20) | (1ul << 16) | (prescaler - 1));

    state = CANBus::State::Initialized;

    if (use_default_filter)
    {
        if (init_filter(0, 0, FilterInitConfig{ FilterType::IDMask, { 0, 0, 0, 0 } }) != Status::Okay)
        {
            error("Failed to init default filter");
        }
    }

    okay();
}

Status CANBus::init_filter(uint16_t bank_number, uint16_t fifo_number, const FilterInitConfig& config)
{
    if (state != CANBus::State::Initialized)
    {
        state = CANBus::State::Error;
        error("CANBus::init_filter() must be called after begin() and before start().");
    }

    if (bank_number > 13)
    {
        error("Invalid filter bank number. Valid values are [0, 13]");
    }

    if (fifo_number > 1)
    {
        error("Invalid filter fifo number. Valid valeus are [0, 1]");
    }

    // enter init mode on the filter
    SET_BIT(hcan->FMR, 0);

    const uint32_t bank_number_pos = 1 << (bank_number &0x1FU);
    
    // deactivate the filter bank
    CLEAR_BIT(hcan->FA1R, bank_number_pos);

    // set bit scale. We only support 11 bit (standard) ids so only support 16 bit filters.
    CLEAR_BIT(hcan->FS1R, bank_number_pos);

    hcan->sFilterRegister[bank_number].FR1 = ((uint32_t)config.filters[1] << 16) | ((uint32_t)config.filters[0]);
    hcan->sFilterRegister[bank_number].FR2 = ((uint32_t)config.filters[3] << 16) | ((uint32_t)config.filters[2]);

    // 0 -> id mode mask
    // 1 -> id mode list
    if (config.type == FilterType::IDMask)
    {
        CLEAR_BIT(hcan->FM1R, bank_number_pos);
    }
    else if (config.type == FilterType::IDList)
    {
        SET_BIT(hcan->FM1R, bank_number_pos);
    }

    // assign everything to fifo 0
    CLEAR_BIT(hcan->FFA1R, bank_number_pos);

    // activate the filter
    SET_BIT(hcan->FA1R, bank_number_pos);

    CLEAR_BIT(hcan->FMR, 0);

    okay();
}

Status CANBus::start()
{
    if (state != CANBus::State::Initialized)
    {
        state = CANBus::State::Error;
        error("CANBus has not been initialized.");
    }

    // Request initialization after all configuration is finished
    CLEAR_BIT(hcan->MCR, CAN_MCR_INRQ);
    // Wait until hardware is ready
    while (READ_BIT(hcan->MSR, CAN_MSR_INAK) == 0)
    {
    }

    state = CANBus::State::Ready; 

    okay();
}

uint32_t CANBus::getAvailableForWrite()
{
    if (state != CANBus::State::Ready)
    {
        state = CANBus::State::Error;
        error_m("CANBus has not been started.");
        return 0;
    }

    uint32_t free_mailboxes = 0;

    if (READ_BIT(hcan->TSR, CAN_TSR_TME0) != 0)
    {
        ++free_mailboxes;
    }

    if (READ_BIT(hcan->TSR, CAN_TSR_TME1) != 0)
    {
        ++free_mailboxes;
    }

    if (READ_BIT(hcan->TSR, CAN_TSR_TME2) != 0)
    {
        ++free_mailboxes;
    }
    
    return free_mailboxes;
}

Status CANBus::write(const Message& message)
{
    if (state != CANBus::State::Ready)
    {
        state = CANBus::State::Error;
        error("CANBus has not been started.");
    }

    if (getAvailableForWrite() > 0)
    {
        // mask for the first open transmission mailbox
        const uint32_t transmit_mailbox = (hcan->TSR & (0b11ul << CAN_TSR_CODE)) >> 24;

        hcan->sTxMailBox[transmit_mailbox].TIR = (message.id << CAN_TI0R_STID) | CAN_RTR_DATA;
        hcan->sTxMailBox[transmit_mailbox].TDTR = message.size;
        // #todo: set TDTR time bit?

        hcan->sTxMailBox[transmit_mailbox].TDHR =
            (uint32_t)((uint32_t)message.data_8[7] << CAN_TDH0R_DATA7_Pos) |
            (uint32_t)((uint32_t)message.data_8[6] << CAN_TDH0R_DATA6_Pos) |
            (uint32_t)((uint32_t)message.data_8[5] << CAN_TDH0R_DATA5_Pos) |
            (uint32_t)((uint32_t)message.data_8[4] << CAN_TDH0R_DATA4_Pos);
        hcan->sTxMailBox[transmit_mailbox].TDLR =
            (uint32_t)((uint32_t)message.data_8[3] << CAN_TDL0R_DATA3_Pos) |
            (uint32_t)((uint32_t)message.data_8[2] << CAN_TDL0R_DATA2_Pos) |
            (uint32_t)((uint32_t)message.data_8[1] << CAN_TDL0R_DATA1_Pos) |
            (uint32_t)((uint32_t)message.data_8[0] << CAN_TDL0R_DATA0_Pos);

        SET_BIT(hcan->sTxMailBox[transmit_mailbox].TIR, CAN_TI0R_TXRQ);
        return Status::Error;
    }
    else
    {
        // Fail transmission, we have no free mailboxes
        warn("No free mailboxes");
    }

    okay();
}

uint32_t CANBus::getAvailableForRead(uint32_t rx_fifo)
{
    if (state != CANBus::State::Ready)
    {
        state = CANBus::State::Error;
        error_m("CANBus has not been started.");
        return 0;
    }

    if (rx_fifo > 1)
    {
        error_m("Invalid rx_fifo number. Valid values are [0, 1]");
        return 0;
    }

    uint32_t fill_level = 0;
    if (rx_fifo == 0)
    {
        fill_level = hcan->RF0R & 0xb11;
    }
    else
    {
        fill_level = hcan->RF1R & 0xb11;
    }
    return fill_level;
}

Status CANBus::read(Message& message_out, uint32_t rx_fifo)
{
    if (state != CANBus::State::Ready)
    {
        state = CANBus::State::Error;
        error("CANBus has not been started.");
    }

    if (rx_fifo > 1)
    {
        error("Invalid rx_fifo number. Valid values are [0, 1]");
    }

    if (getAvailableForRead(rx_fifo) == 0)
    {
        warn("No mailboxes with available messages");
    }
    
    message_out.data_8[0] = (uint8_t)((CAN_RDL0R_DATA0 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA0_Pos);
    message_out.data_8[1] = (uint8_t)((CAN_RDL0R_DATA1 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA1_Pos);
    message_out.data_8[2] = (uint8_t)((CAN_RDL0R_DATA2 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA2_Pos);
    message_out.data_8[3] = (uint8_t)((CAN_RDL0R_DATA3 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA3_Pos);
    message_out.data_8[4] = (uint8_t)((CAN_RDH0R_DATA4 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA4_Pos);
    message_out.data_8[5] = (uint8_t)((CAN_RDH0R_DATA5 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA5_Pos);
    message_out.data_8[6] = (uint8_t)((CAN_RDH0R_DATA6 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA6_Pos);
    message_out.data_8[7] = (uint8_t)((CAN_RDH0R_DATA7 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA7_Pos);

    message_out.id = CAN_RI0R_STID & hcan->sFIFOMailBox[rx_fifo].RIR >> CAN_RI0R_STID_Pos;

    if (rx_fifo == 0)
    {
        SET_BIT(hcan->RF0R, CAN_RF0R_RFOM0_Pos);
    }
    else
    {
        SET_BIT(hcan->RF0R, CAN_RF0R_RFOM0_Pos);
    }

    okay();
}

void CANBus::register_msg_received_callback(MessageReceivedCallbackType callback)
{
    message_received_callback = callback;
}

#endif // STM32
