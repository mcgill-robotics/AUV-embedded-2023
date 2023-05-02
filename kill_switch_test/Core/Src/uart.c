/*
 * uart.c
 *
 *  Created on: Nov. 13, 2022
 *      Author: felix
 */

#include "main.h"

void put_char(char character)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&character, 1, HAL_MAX_DELAY);
}
