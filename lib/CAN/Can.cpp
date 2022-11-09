#include "Can.h"
#include "CanDefs.inl"
#include "../Utils/BitUtils.h"

static CAN_Registers* hcan = (CAN_Registers*)0x40006400;

static GPIO_Registers* gpioa = (GPIO_Registers*)0x48000000UL;

static RCC_Registers* rcc = (RCC_Registers*)0x40021000UL;

void CANBus::begin(CANBus::IDType id_type, CANBus::BitRate bit_rate, CANBus::GPIOMode gpio_mode)
{
    // ***************** Initialize the clock for CAN and GPIO *****************
    //
    // Enable GPIOA in the RCC (clock) peripheral control registers
    SET_BIT(rcc->AHB2ENR, 0);

    // Enable CAN1 in the RCC (clock) peripheral control registers
    SET_BIT(rcc->AHB1ENR, 25);

    // ***************** Initialize the GPIO for CAN bus *****************

    uint32_t temp = 0;
    temp = gpioa->OSPEEDR;
    // clear the bits before setting them
    temp &= ~((0ul << GPIO_PIN_11 * 2) | (0ul << GPIO_PIN_12 * 2));
    temp |= (GPIO_SPEED_FREQ_VERY_HIGH << GPIO_PIN_11 * 2) | (GPIO_SPEED_FREQ_VERY_HIGH << GPIO_PIN_12 * 2);
    gpioa->OSPEEDR = temp;

    temp = gpioa->OTYPER;
    temp &= ~((0ul << GPIO_PIN_11) | (0ul << GPIO_PIN_11));
    temp |= (OUTPUT_PP << GPIO_PIN_11) | (OUTPUT_PP << GPIO_PIN_12);
    gpioa->OTYPER = temp; 

    temp = gpioa->PUPDR;
    temp &= ~((0ul << GPIO_PIN_11 * 2) | (0ul << GPIO_PIN_12 * 2));
    temp |= (GPIO_NOPULL << GPIO_PIN_11 * 2) | (GPIO_NOPULL << GPIO_PIN_12 * 2);
    gpioa->PUPDR = temp;

    temp = gpioa->AFR[1];
    temp &= ~((0ul << ((GPIO_PIN_11 & 0x07u) * 4u)) | (0ul << ((GPIO_PIN_12 & 0x07u) * 4u)));
    temp |= (GPIO_AF9_CAN1 << ((GPIO_PIN_11 & 0x07u) * 4u)) | (GPIO_AF9_CAN1 << ((GPIO_PIN_12 & 0x07u) * 4u));
    gpioa->AFR[1] = temp;

    temp = gpioa->MODER;
    temp &= ~((0ul << GPIO_PIN_11 * 2) | (0ul << GPIO_PIN_12 * 2));
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
    hcan->BTR = (uint32_t)(3ul << 20) | (12ul << 16) | ((uint32_t)bit_rate << 0);

    // #todo: initialize the filters

    // Request initialization after all configuration is finished
    CLEAR_BIT(hcan->MCR, CAN_MCR_INRQ);
}