#ifdef STM32

#include "Can.h"
#include "CanDefs.inl"
#include "../Utils/BitUtils.h"

static CAN_Registers* hcan = (CAN_Registers*)0x40006400UL;
static GPIO_Registers* gpioa = (GPIO_Registers*)0x48000000UL;
static RCC_Registers* rcc = (RCC_Registers*)0x40021000UL;

void CANBus::begin()
{
    // ***************** Initialize the clock for CAN and GPIO *****************
    //
    // Enable GPIOA in the RCC (clock) peripheral control registers
    SET_BIT(rcc->AHB2ENR, 0);

    // Enable CAN1 in the RCC (clock) peripheral control registers
    SET_BIT(rcc->APB1ENR1, 25);

    // ***************** Initialize the GPIO for CAN bus *****************

    uint32_t temp = 0;
    temp = gpioa->OSPEEDR;
    // clear the bits before setting them
    temp &= ~((3ul << GPIO_PIN_11 * 2) | (3ul << GPIO_PIN_12 * 2));
    temp |= (GPIO_SPEED_FREQ_VERY_HIGH << GPIO_PIN_11 * 2) | (GPIO_SPEED_FREQ_VERY_HIGH << GPIO_PIN_12 * 2);
    gpioa->OSPEEDR = temp;

    temp = gpioa->OTYPER;
    temp &= ~((1ul << GPIO_PIN_11) | (1ul << GPIO_PIN_11));
    temp |= (OUTPUT_PP << GPIO_PIN_11) | (OUTPUT_PP << GPIO_PIN_12);
    gpioa->OTYPER = temp; 

    temp = gpioa->PUPDR;
    temp &= ~((3ul << GPIO_PIN_11 * 2) | (3ul << GPIO_PIN_12 * 2));
    temp |= (GPIO_NOPULL << GPIO_PIN_11 * 2) | (GPIO_NOPULL << GPIO_PIN_12 * 2);
    gpioa->PUPDR = temp;

    temp = gpioa->AFR[1];
    temp &= ~((0b1111ul << ((GPIO_PIN_11 & 0x07u) * 4u)) | (0b1111ul << ((GPIO_PIN_12 & 0x07u) * 4u)));
    temp |= (GPIO_AF9_CAN1 << ((GPIO_PIN_11 & 0x07u) * 4u)) | (GPIO_AF9_CAN1 << ((GPIO_PIN_12 & 0x07u) * 4u));
    gpioa->AFR[1] = temp;

    temp = gpioa->MODER;
    temp &= ~((3ul << GPIO_PIN_11 * 2) | (3ul << GPIO_PIN_12 * 2));
    temp |= (MODE_AF << GPIO_PIN_11 * 2) | (MODE_AF << GPIO_PIN_12 * 2);
    gpioa->MODER = temp;

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
    //hcan->BTR = (uint32_t)(3ul << 20) | (12ul << 16) | ((uint32_t)bit_rate << 0);
    const uint32_t prescaler = 16;
    hcan->BTR = (uint32_t)((1ul << 20) | (1ul << 16) | (prescaler - 1));

    // #todo: initialize the filters

    init_filter();

    // Request initialization after all configuration is finished
    CLEAR_BIT(hcan->MCR, CAN_MCR_INRQ);
    // Wait until hardware is ready
    while (READ_BIT(hcan->MSR, CAN_MSR_INAK) == 0)
    {
    } 
}

void CANBus::init_filter()
{
    // enter init mode on the filter
    SET_BIT(hcan->FMR, 0);

    uint32_t filter_bank = 0;
    uint32_t filter_bank_pos = 0;
    
    // deactivate the first filter bank
    CLEAR_BIT(hcan->FA1R, filter_bank_pos);

    // set 32 bit scale
    SET_BIT(hcan->FS1R, filter_bank_pos);
    
    hcan->sFilterRegister[filter_bank].FR1 = 0x00000000;
    hcan->sFilterRegister[filter_bank].FR2 = 0x00000000;

    // 0 -> id mode mask
    // 1 -> id mode list
    CLEAR_BIT(hcan->FM1R, filter_bank_pos);

    // assign everything to fifo 0
    CLEAR_BIT(hcan->FFA1R, filter_bank_pos);

    // activate the filter
    SET_BIT(hcan->FA1R, filter_bank_pos);

    CLEAR_BIT(hcan->FMR, 0);
}

uint32_t CANBus::getAvailableForWrite()
{
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

void CANBus::write(uint16_t message_id, const uint8_t data[], uint32_t size)
{
    if (getAvailableForWrite() > 0)
    {
        // mask for the first open transmission mailbox
        uint32_t transmit_mailbox = (hcan->TSR & (0b11ul << CAN_TSR_CODE)) >> 24;

        // #todo: std id, frame type
        hcan->sTxMailBox[transmit_mailbox].TIR = (message_id << CAN_TI0R_STID) | CAN_RTR_DATA;
        hcan->sTxMailBox[transmit_mailbox].TDTR = 8; // always only transmit 8 bytes for simplicity
        // #todo: set TDTR time bit?

        hcan->sTxMailBox[transmit_mailbox].TDHR =
            (uint32_t)((uint32_t)data[7] << CAN_TDH0R_DATA7_Pos) |
            (uint32_t)((uint32_t)data[6] << CAN_TDH0R_DATA6_Pos) |
            (uint32_t)((uint32_t)data[5] << CAN_TDH0R_DATA5_Pos) |
            (uint32_t)((uint32_t)data[4] << CAN_TDH0R_DATA4_Pos);
        hcan->sTxMailBox[transmit_mailbox].TDLR =
            (uint32_t)((uint32_t)data[3] << CAN_TDL0R_DATA3_Pos) |
            (uint32_t)((uint32_t)data[2] << CAN_TDL0R_DATA2_Pos) |
            (uint32_t)((uint32_t)data[1] << CAN_TDL0R_DATA1_Pos) |
            (uint32_t)((uint32_t)data[0] << CAN_TDL0R_DATA0_Pos);

        SET_BIT(hcan->sTxMailBox[transmit_mailbox].TIR, CAN_TI0R_TXRQ);
    }
    else
    {
        // Fail tramission, we have no free mailboxes
    }
}

uint32_t CANBus::getAvailableForRead(uint32_t rx_fifo)
{
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

uint32_t CANBus::read(uint8_t data_out[], uint32_t size, uint32_t rx_fifo)
{
    if (getAvailableForRead(rx_fifo) == 0)
    {
        return -1;
    }
    
    data_out[0] = (uint8_t)((CAN_RDL0R_DATA0 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA0_Pos);
    data_out[1] = (uint8_t)((CAN_RDL0R_DATA1 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA1_Pos);
    data_out[2] = (uint8_t)((CAN_RDL0R_DATA2 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA2_Pos);
    data_out[3] = (uint8_t)((CAN_RDL0R_DATA3 & hcan->sFIFOMailBox[rx_fifo].RDLR) >> CAN_RDL0R_DATA3_Pos);
    data_out[4] = (uint8_t)((CAN_RDH0R_DATA4 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA4_Pos);
    data_out[5] = (uint8_t)((CAN_RDH0R_DATA5 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA5_Pos);
    data_out[6] = (uint8_t)((CAN_RDH0R_DATA6 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA6_Pos);
    data_out[7] = (uint8_t)((CAN_RDH0R_DATA7 & hcan->sFIFOMailBox[rx_fifo].RDHR) >> CAN_RDH0R_DATA7_Pos);

    uint32_t std_id = CAN_RI0R_STID & hcan->sFIFOMailBox[rx_fifo].RIR >> CAN_RI0R_STID_Pos;

    if (rx_fifo == 0)
    {
        SET_BIT(hcan->RF0R, CAN_RF0R_RFOM0_Pos);
    }
    else
    {
        SET_BIT(hcan->RF0R, CAN_RF0R_RFOM0_Pos);
    }

    return std_id;
}

#endif // STM32