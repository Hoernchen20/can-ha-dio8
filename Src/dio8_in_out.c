
/*
 * dio8_in_out.c
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


/* Includes ------------------------------------------------------------------*/
#include "dio8_in_out.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
volatile uint32_t key_state;  /* debounced and inverted key state
                                 bit = 1: key pressed */
volatile uint32_t key_press;  /* key press detect */
//volatile uint16_t InputRepeat; /* key long press and repeat */

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Configures the GPIO of DIO8.
  * @param  None
  * @retval None
  */
void DIO8_GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStruct;

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* Configure unused GPIO pins */
    GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_7 
                          |GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Configure input GPIO pins */
    GPIO_InitStruct.Pin = INPUT0|INPUT1|INPUT2|INPUT3|INPUT4|INPUT5|INPUT6|INPUT7;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(INPUT_PORT, &GPIO_InitStruct);

    /*Configure output GPIO pins */
    GPIO_InitStruct.Pin = OUTPUT0|OUTPUT1|OUTPUT2|OUTPUT3;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(OUTPUT_PORT_PIN0_3, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = OUTPUT4|OUTPUT5|OUTPUT6|OUTPUT7;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(OUTPUT_PORT_PIN4_7, &GPIO_InitStruct);
}

/**
  * @brief  Debounce input port of DIO8. Have to run in a 10ms interrupt.
  * @param  None
  * @retval None
  */
void DIO8_InputDebounce(void) {
    static uint32_t counter0, counter1;
    uint32_t i;

    i = key_state ^ ~INPUT_PORT->IDR;
    counter0 = ~(counter0 & i);
    counter1 = counter0 ^ (counter1 & i);
    i &= counter0 & counter1;
    key_state ^= i;
    key_press |= key_state & i;
}

/**
  * @brief  Get debounced input press.
  * @param  Input_Pin:
  * @retval 
  */
uint32_t DIO8_GetInputPress(uint32_t Input_Pin) {
    Input_Pin &= ~key_state; //anders als im original
    Input_Pin &= key_press;
    key_press ^= Input_Pin;
    return Input_Pin;
}

/**
  * @brief  Get debounced input state.
  * @param  Input_Pin:
  * @retval 
  */
uint32_t DIO8_GetInputState(uint32_t Input_Pin) {
    Input_Pin &= ~key_state;
    return Input_Pin;
}
