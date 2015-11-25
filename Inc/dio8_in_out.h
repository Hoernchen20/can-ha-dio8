/*
 * dio8_in_out.h
 *
 * Copyright 2015  Felix Horn
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#ifndef DIO8_IN_OUT_H_
#define DIO8_IN_OUT_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32f1xx_hal.h"

/* Exported constants --------------------------------------------------------*/
/* Input pins */
#define INPUT_PORT          GPIOA
#define INPUT0              GPIO_PIN_0
#define INPUT1              GPIO_PIN_1
#define INPUT2              GPIO_PIN_2
#define INPUT3              GPIO_PIN_3
#define INPUT4              GPIO_PIN_4
#define INPUT5              GPIO_PIN_5
#define INPUT6              GPIO_PIN_6
#define INPUT7              GPIO_PIN_7

/* Output pins */
#define OUTPUT_PORT_PIN0_3  GPIOA
#define OUTPUT_PORT_PIN4_7  GPIOC
#define OUTPUT0             GPIO_PIN_11
#define OUTPUT1             GPIO_PIN_10
#define OUTPUT2             GPIO_PIN_9
#define OUTPUT3             GPIO_PIN_8
#define OUTPUT4             GPIO_PIN_9
#define OUTPUT5             GPIO_PIN_8
#define OUTPUT6             GPIO_PIN_7
#define OUTPUT7             GPIO_PIN_6

/* Exported variables --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#ifndef BOOL
#define BOOL
typedef enum { FALSE, TRUE }bool;
#endif

/* Exported macro ------------------------------------------------------------*/
#define READ_INPUT0()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT0)
#define READ_INPUT1()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT1)
#define READ_INPUT2()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT2)
#define READ_INPUT3()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT3)
#define READ_INPUT4()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT4)
#define READ_INPUT5()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT5)
#define READ_INPUT6()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT6)
#define READ_INPUT7()   HAL_GPIO_ReadPin(INPUT_PORT, INPUT7)

#define SET_OUTPUT0()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT0, GPIO_PIN_SET)
#define RESET_OUTPUT0() HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT0, GPIO_PIN_RESET)

#define SET_OUTPUT1()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT1, GPIO_PIN_SET)
#define RESET_OUTPUT1() HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT1, GPIO_PIN_RESET)

#define SET_OUTPUT2()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT2, GPIO_PIN_SET)
#define RESET_OUTPUT2() HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT2, GPIO_PIN_RESET)

#define SET_OUTPUT3()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT3, GPIO_PIN_SET)
#define RESET_OUTPUT3() HAL_GPIO_WritePin(OUTPUT_PORT_PIN0_3, OUTPUT3, GPIO_PIN_RESET)

#define SET_OUTPUT4()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT4, GPIO_PIN_SET)
#define RESET_OUTPUT4() HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT4, GPIO_PIN_RESET)

#define SET_OUTPUT5()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT5, GPIO_PIN_SET)
#define RESET_OUTPUT5() HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT5, GPIO_PIN_RESET)

#define SET_OUTPUT6()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT6, GPIO_PIN_SET)
#define RESET_OUTPUT6() HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT6, GPIO_PIN_RESET)

#define SET_OUTPUT7()   HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT7, GPIO_PIN_SET)
#define RESET_OUTPUT7() HAL_GPIO_WritePin(OUTPUT_PORT_PIN4_7, OUTPUT7, GPIO_PIN_RESET)

/* Exported functions ------------------------------------------------------- */
void DIO8_GPIO_Config(void);
void DIO8_InputDebounce(void);
uint32_t DIO8_GetInputPress(uint32_t Input_Pin);
uint32_t DIO8_GetInputState(uint32_t Input_Pin);

#endif /* DIO8_IN_OUT_H_ */
