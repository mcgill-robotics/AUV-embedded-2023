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

    // Request initialization after all configuration is finished
    CLEAR_BIT(hcan->MCR, CAN_MCR_INRQ);
    // Wait until hardware is ready
    while (READ_BIT(hcan->MSR, CAN_MSR_INAK) == 0)
    {
    } 
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

#endif // STM32