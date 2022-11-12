#pragma once

/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ (0U)
#define CAN_MCR_SLEEP (1U)
#define CAN_MCR_TXFP (2U)
#define CAN_MCR_RFLM (3U)
#define CAN_MCR_NART (4U)
#define CAN_MCR_AWUM (5U)
#define CAN_MCR_ABOM (6U)
#define CAN_MCR_TTCM (7U)
#define CAN_MCR_RESET (15U)

/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK (0U)
#define CAN_MSR_SLAK (1U)
#define CAN_MSR_ERRI (2U)
#define CAN_MSR_WKUI (3U)
#define CAN_MSR_SLAKI (4U)
#define CAN_MSR_TXM (8U)
#define CAN_MSR_RXM (9U)
#define CAN_MSR_SAMP (10U)
#define CAN_MSR_RX (11U)

/*******************  Bit definition for CAN_TSR register  ********************/

#define CAN_TSR_CODE           (24)                                /* TSR Code. Stores id of next free mailbox. */
#define CAN_TSR_TME0           (26)                                /*!<Transmit Mailbox 0 Empty */
#define CAN_TSR_TME1           (27)                                /*!<Transmit Mailbox 1 Empty */
#define CAN_TSR_TME2           (28)                                /*!<Transmit Mailbox 2 Empty */

/*******************  Bit definition for CAN transmissions  ********************/

#define CAN_RTR_DATA                (0x00000000U)  /*!< Data frame   */
#define CAN_RTR_REMOTE              (0x00000002U)  /*!< Remote frame *

/******************  Bit definition for CAN_TDL0R register  *******************/

#define CAN_TDL0R_DATA0_Pos    (0U)
#define CAN_TDL0R_DATA0_Msk    (0xFFUL << CAN_TDL0R_DATA0_Pos)                 /*!< 0x000000FF */
#define CAN_TDL0R_DATA0        CAN_TDL0R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_TDL0R_DATA1_Pos    (8U)
#define CAN_TDL0R_DATA1_Msk    (0xFFUL << CAN_TDL0R_DATA1_Pos)                 /*!< 0x0000FF00 */
#define CAN_TDL0R_DATA1        CAN_TDL0R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_TDL0R_DATA2_Pos    (16U)
#define CAN_TDL0R_DATA2_Msk    (0xFFUL << CAN_TDL0R_DATA2_Pos)                 /*!< 0x00FF0000 */
#define CAN_TDL0R_DATA2        CAN_TDL0R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_TDL0R_DATA3_Pos    (24U)
#define CAN_TDL0R_DATA3_Msk    (0xFFUL << CAN_TDL0R_DATA3_Pos)                 /*!< 0xFF000000 */
#define CAN_TDL0R_DATA3        CAN_TDL0R_DATA3_Msk                             /*!<Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4_Pos    (0U)
#define CAN_TDH0R_DATA4_Msk    (0xFFUL << CAN_TDH0R_DATA4_Pos)                 /*!< 0x000000FF */
#define CAN_TDH0R_DATA4        CAN_TDH0R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_TDH0R_DATA5_Pos    (8U)
#define CAN_TDH0R_DATA5_Msk    (0xFFUL << CAN_TDH0R_DATA5_Pos)                 /*!< 0x0000FF00 */
#define CAN_TDH0R_DATA5        CAN_TDH0R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_TDH0R_DATA6_Pos    (16U)
#define CAN_TDH0R_DATA6_Msk    (0xFFUL << CAN_TDH0R_DATA6_Pos)                 /*!< 0x00FF0000 */
#define CAN_TDH0R_DATA6        CAN_TDH0R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_TDH0R_DATA7_Pos    (24U)
#define CAN_TDH0R_DATA7_Msk    (0xFFUL << CAN_TDH0R_DATA7_Pos)                 /*!< 0xFF000000 */
#define CAN_TDH0R_DATA7        CAN_TDH0R_DATA7_Msk                             /*!<Data byte 7 *

/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos       (1U)
#define CAN_RI0R_RTR_Msk       (0x1UL << CAN_RI0R_RTR_Pos)                     /*!< 0x00000002 */
#define CAN_RI0R_RTR           CAN_RI0R_RTR_Msk                                /*!<Remote Transmission Request */
#define CAN_RI0R_IDE_Pos       (2U)
#define CAN_RI0R_IDE_Msk       (0x1UL << CAN_RI0R_IDE_Pos)                     /*!< 0x00000004 */
#define CAN_RI0R_IDE           CAN_RI0R_IDE_Msk                                /*!<Identifier Extension */
#define CAN_RI0R_EXID_Pos      (3U)
#define CAN_RI0R_EXID_Msk      (0x3FFFFUL << CAN_RI0R_EXID_Pos)                /*!< 0x001FFFF8 */
#define CAN_RI0R_EXID          CAN_RI0R_EXID_Msk                               /*!<Extended Identifier */
#define CAN_RI0R_STID_Pos      (21U)
#define CAN_RI0R_STID_Msk      (0x7FFUL << CAN_RI0R_STID_Pos)                  /*!< 0xFFE00000 */
#define CAN_RI0R_STID          CAN_RI0R_STID_Msk                               /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos    (0U)
#define CAN_RDL0R_DATA0_Msk    (0xFFUL << CAN_RDL0R_DATA0_Pos)                 /*!< 0x000000FF */
#define CAN_RDL0R_DATA0        CAN_RDL0R_DATA0_Msk                             /*!<Data byte 0 */
#define CAN_RDL0R_DATA1_Pos    (8U)
#define CAN_RDL0R_DATA1_Msk    (0xFFUL << CAN_RDL0R_DATA1_Pos)                 /*!< 0x0000FF00 */
#define CAN_RDL0R_DATA1        CAN_RDL0R_DATA1_Msk                             /*!<Data byte 1 */
#define CAN_RDL0R_DATA2_Pos    (16U)
#define CAN_RDL0R_DATA2_Msk    (0xFFUL << CAN_RDL0R_DATA2_Pos)                 /*!< 0x00FF0000 */
#define CAN_RDL0R_DATA2        CAN_RDL0R_DATA2_Msk                             /*!<Data byte 2 */
#define CAN_RDL0R_DATA3_Pos    (24U)
#define CAN_RDL0R_DATA3_Msk    (0xFFUL << CAN_RDL0R_DATA3_Pos)                 /*!< 0xFF000000 */
#define CAN_RDL0R_DATA3        CAN_RDL0R_DATA3_Msk                             /*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos    (0U)
#define CAN_RDH0R_DATA4_Msk    (0xFFUL << CAN_RDH0R_DATA4_Pos)                 /*!< 0x000000FF */
#define CAN_RDH0R_DATA4        CAN_RDH0R_DATA4_Msk                             /*!<Data byte 4 */
#define CAN_RDH0R_DATA5_Pos    (8U)
#define CAN_RDH0R_DATA5_Msk    (0xFFUL << CAN_RDH0R_DATA5_Pos)                 /*!< 0x0000FF00 */
#define CAN_RDH0R_DATA5        CAN_RDH0R_DATA5_Msk                             /*!<Data byte 5 */
#define CAN_RDH0R_DATA6_Pos    (16U)
#define CAN_RDH0R_DATA6_Msk    (0xFFUL << CAN_RDH0R_DATA6_Pos)                 /*!< 0x00FF0000 */
#define CAN_RDH0R_DATA6        CAN_RDH0R_DATA6_Msk                             /*!<Data byte 6 */
#define CAN_RDH0R_DATA7_Pos    (24U)
#define CAN_RDH0R_DATA7_Msk    (0xFFUL << CAN_RDH0R_DATA7_Pos)                 /*!< 0xFF000000 */
#define CAN_RDH0R_DATA7        CAN_RDH0R_DATA7_Msk                             /*!<Data byte 7 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos      (0U)
#define CAN_RF0R_FMP0_Msk      (0x3UL << CAN_RF0R_FMP0_Pos)                    /*!< 0x00000003 */
#define CAN_RF0R_FMP0          CAN_RF0R_FMP0_Msk                               /*!<FIFO 0 Message Pending */
#define CAN_RF0R_FULL0_Pos     (3U)
#define CAN_RF0R_FULL0_Msk     (0x1UL << CAN_RF0R_FULL0_Pos)                   /*!< 0x00000008 */
#define CAN_RF0R_FULL0         CAN_RF0R_FULL0_Msk                              /*!<FIFO 0 Full */
#define CAN_RF0R_FOVR0_Pos     (4U)
#define CAN_RF0R_FOVR0_Msk     (0x1UL << CAN_RF0R_FOVR0_Pos)                   /*!< 0x00000010 */
#define CAN_RF0R_FOVR0         CAN_RF0R_FOVR0_Msk                              /*!<FIFO 0 Overrun */
#define CAN_RF0R_RFOM0_Pos     (5U)
#define CAN_RF0R_RFOM0_Msk     (0x1UL << CAN_RF0R_RFOM0_Pos)                   /*!< 0x00000020 */
#define CAN_RF0R_RFOM0         CAN_RF0R_RFOM0_Msk                              /*!<Release FIFO 0 Output Mailbox *

/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ          (0u)                               /*!<Transmit Mailbox Request */
#define CAN_TI0R_RTR           (1u)                                /*!<Remote Transmission Request */
#define CAN_TI0R_IDE           (2u)                                /*!<Identifier Extension */
#define CAN_TI0R_EXID          (3u)                               /*!<Extended Identifier */
#define CAN_TI0R_STID          (21u)                               /*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for GPIO registers  ********************/

/** @defgroup GPIO_pins GPIO pins
  * @{
  */
#define GPIO_PIN_0                 ((uint32_t)0u)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint32_t)1u)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint32_t)2u)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint32_t)3u)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint32_t)4u)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint32_t)5u)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint32_t)6u)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint32_t)7u)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint32_t)8u)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint32_t)9u)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint32_t)10u)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint32_t)11u)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint32_t)12u)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint32_t)13u)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint32_t)14u)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint32_t)15u)  /* Pin 15 selected   */

/** @defgroup GPIO_speed GPIO speed
  * @brief GPIO Output Maximum frequency
  * @{
  */
#define GPIO_SPEED_FREQ_LOW             0x00000000ul  /*!< Low speed       */
#define GPIO_SPEED_FREQ_MEDIUM          0x00000001ul  /*!< Medium speed    */
#define GPIO_SPEED_FREQ_HIGH            0x00000002ul  /*!< High speed      */
#define GPIO_SPEED_FREQ_VERY_HIGH       0x00000003ul  /*!< Very high speed */

/** @defgroup GPIO_pull GPIO pull
  * @brief GPIO Pull-Up or Pull-Down Activation
  * @{
  */
#define GPIO_NOPULL                     0x00000000ul   /*!< No Pull-up or Pull-down activation  */
#define GPIO_PULLUP                     0x00000001ul   /*!< Pull-up activation                  */
#define GPIO_PULLDOWN                   0x00000002ul   /*!< Pull-down activation                */

#define GPIO_AF9_CAN1          (0x09ul)  /* CAN1 Alternate Function mapping    */

#define OUTPUT_PP                               (0x0uL)
#define OUTPUT_OD                               (0x1uL)

#define MODE_AF (0x2ul)

#define __IO volatile

/**
 * @brief Controller Area Network TxMailBox
 */

typedef struct
{
    __IO uint32_t TIR;  /*!< CAN TX mailbox identifier register */
    __IO uint32_t TDTR; /*!< CAN mailbox data length control and time stamp register */
    __IO uint32_t TDLR; /*!< CAN mailbox data low register */
    __IO uint32_t TDHR; /*!< CAN mailbox data high register */
} CAN_TxMailBox;

/**
 * @brief Controller Area Network FIFOMailBox
 */

typedef struct
{
    __IO uint32_t RIR;  /*!< CAN receive FIFO mailbox identifier register */
    __IO uint32_t RDTR; /*!< CAN receive FIFO mailbox data length control and time stamp register */
    __IO uint32_t RDLR; /*!< CAN receive FIFO mailbox data low register */
    __IO uint32_t RDHR; /*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox;

/**
 * @brief Controller Area Network FilterRegister
 */

typedef struct
{
    __IO uint32_t FR1; /*!< CAN Filter bank register 1 */
    __IO uint32_t FR2; /*!< CAN Filter bank register 1 */
} CAN_FilterRegister;

typedef struct
{
    __IO uint32_t MCR;                      /*!< CAN master control register,         Address offset: 0x00          */
    __IO uint32_t MSR;                      /*!< CAN master status register,          Address offset: 0x04          */
    __IO uint32_t TSR;                      /*!< CAN transmit status register,        Address offset: 0x08          */
    __IO uint32_t RF0R;                     /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
    __IO uint32_t RF1R;                     /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
    __IO uint32_t IER;                      /*!< CAN interrupt enable register,       Address offset: 0x14          */
    __IO uint32_t ESR;                      /*!< CAN error status register,           Address offset: 0x18          */
    __IO uint32_t BTR;                      /*!< CAN bit timing register,             Address offset: 0x1C          */
    uint32_t RESERVED0[88];                 /*!< Reserved, 0x020 - 0x17F                                            */
    CAN_TxMailBox sTxMailBox[3];            /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
    CAN_FIFOMailBox sFIFOMailBox[2];        /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
    uint32_t RESERVED1[12];                 /*!< Reserved, 0x1D0 - 0x1FF                                            */
    __IO uint32_t FMR;                      /*!< CAN filter master register,          Address offset: 0x200         */
    __IO uint32_t FM1R;                     /*!< CAN filter mode register,            Address offset: 0x204         */
    uint32_t RESERVED2;                     /*!< Reserved, 0x208                                                    */
    __IO uint32_t FS1R;                     /*!< CAN filter scale register,           Address offset: 0x20C         */
    uint32_t RESERVED3;                     /*!< Reserved, 0x210                                                    */
    __IO uint32_t FFA1R;                    /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
    uint32_t RESERVED4;                     /*!< Reserved, 0x218                                                    */
    __IO uint32_t FA1R;                     /*!< CAN filter activation register,      Address offset: 0x21C         */
    uint32_t RESERVED5[8];                  /*!< Reserved, 0x220-0x23F                                              */
    CAN_FilterRegister sFilterRegister[28]; /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_Registers;

typedef struct
{
    __IO uint32_t MODER;   /*!< GPIO port mode register,               Address offset: 0x00      */
    __IO uint32_t OTYPER;  /*!< GPIO port output type register,        Address offset: 0x04      */
    __IO uint32_t OSPEEDR; /*!< GPIO port output speed register,       Address offset: 0x08      */
    __IO uint32_t PUPDR;   /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    __IO uint32_t IDR;     /*!< GPIO port input data register,         Address offset: 0x10      */
    __IO uint32_t ODR;     /*!< GPIO port output data register,        Address offset: 0x14      */
    __IO uint32_t BSRR;    /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
    __IO uint32_t LCKR;    /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    __IO uint32_t AFR[2];  /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
    __IO uint32_t BRR;     /*!< GPIO Bit Reset register,               Address offset: 0x28      */

} GPIO_Registers;

typedef struct
{
  __IO uint32_t CR;          /*!< RCC clock control register,                                              Address offset: 0x00 */
  __IO uint32_t ICSCR;       /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
  __IO uint32_t CFGR;        /*!< RCC clock configuration register,                                        Address offset: 0x08 */
  __IO uint32_t PLLCFGR;     /*!< RCC system PLL configuration register,                                   Address offset: 0x0C */
  __IO uint32_t PLLSAI1CFGR; /*!< RCC PLL SAI1 configuration register,                                     Address offset: 0x10 */
  uint32_t      RESERVED;    /*!< Reserved,                                                                Address offset: 0x14 */
  __IO uint32_t CIER;        /*!< RCC clock interrupt enable register,                                     Address offset: 0x18 */
  __IO uint32_t CIFR;        /*!< RCC clock interrupt flag register,                                       Address offset: 0x1C */
  __IO uint32_t CICR;        /*!< RCC clock interrupt clear register,                                      Address offset: 0x20 */
  uint32_t      RESERVED0;   /*!< Reserved,                                                                Address offset: 0x24 */
  __IO uint32_t AHB1RSTR;    /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
  __IO uint32_t AHB2RSTR;    /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
  __IO uint32_t AHB3RSTR;    /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
  uint32_t      RESERVED1;   /*!< Reserved,                                                                Address offset: 0x34 */
  __IO uint32_t APB1RSTR1;   /*!< RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
  __IO uint32_t APB1RSTR2;   /*!< RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
  __IO uint32_t APB2RSTR;    /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
  uint32_t      RESERVED2;   /*!< Reserved,                                                                Address offset: 0x44 */
  __IO uint32_t AHB1ENR;     /*!< RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
  __IO uint32_t AHB2ENR;     /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
  __IO uint32_t AHB3ENR;     /*!< RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
  uint32_t      RESERVED3;   /*!< Reserved,                                                                Address offset: 0x54 */
  __IO uint32_t APB1ENR1;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
  __IO uint32_t APB1ENR2;    /*!< RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
  __IO uint32_t APB2ENR;     /*!< RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
  uint32_t      RESERVED4;   /*!< Reserved,                                                                Address offset: 0x64 */
  __IO uint32_t AHB1SMENR;   /*!< RCC AHB1 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x68 */
  __IO uint32_t AHB2SMENR;   /*!< RCC AHB2 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x6C */
  __IO uint32_t AHB3SMENR;   /*!< RCC AHB3 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
  uint32_t      RESERVED5;   /*!< Reserved,                                                                Address offset: 0x74 */
  __IO uint32_t APB1SMENR1;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1, Address offset: 0x78 */
  __IO uint32_t APB1SMENR2;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2, Address offset: 0x7C */
  __IO uint32_t APB2SMENR;   /*!< RCC APB2 peripheral clocks enable in sleep mode and stop modes register, Address offset: 0x80 */
  uint32_t      RESERVED6;   /*!< Reserved,                                                                Address offset: 0x84 */
  __IO uint32_t CCIPR;       /*!< RCC peripherals independent clock configuration register,                Address offset: 0x88 */
  uint32_t      RESERVED7;   /*!< Reserved,                                                                Address offset: 0x8C */
  __IO uint32_t BDCR;        /*!< RCC backup domain control register,                                      Address offset: 0x90 */
  __IO uint32_t CSR;         /*!< RCC clock control & status register,                                     Address offset: 0x94 */
  __IO uint32_t CRRCR;       /*!< RCC clock recovery RC register,                                          Address offset: 0x98 */
} RCC_Registers;
