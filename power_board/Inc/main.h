/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWM_T8_Pin GPIO_PIN_0
#define PWM_T8_GPIO_Port GPIOB
#define PWM_T7_Pin GPIO_PIN_1
#define PWM_T7_GPIO_Port GPIOB
#define PWM_T5_Pin GPIO_PIN_10
#define PWM_T5_GPIO_Port GPIOB
#define PWM_T6_Pin GPIO_PIN_11
#define PWM_T6_GPIO_Port GPIOB
#define PWM_T4_Pin GPIO_PIN_15
#define PWM_T4_GPIO_Port GPIOA
#define PWM_T3_Pin GPIO_PIN_3
#define PWM_T3_GPIO_Port GPIOB
#define PWM_T2_Pin GPIO_PIN_4
#define PWM_T2_GPIO_Port GPIOB
#define PWM_T1_Pin GPIO_PIN_5
#define PWM_T1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
