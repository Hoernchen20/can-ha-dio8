/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "can-ha-protocol.h"
#include "dio8_in_out.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan2;
CanTxMsgTypeDef CAN_TxMsg;
CanRxMsgTypeDef CAN_RxMsg;
uint_fast8_t NewSecond;


/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_CAN2_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  DIO8_GPIO_Config();
  MX_CAN2_Init();

  /* USER CODE BEGIN 2 */
  CAN_TxMsg.StdId = 0;
  CAN_TxMsg.ExtId = (222 << 18) | 333;
  CAN_TxMsg.IDE = CAN_ID_EXT;
  CAN_TxMsg.RTR = CAN_RTR_DATA;
  CAN_TxMsg.DLC = 8;
  CAN_TxMsg.Data[0] = 0xab;
  CAN_TxMsg.Data[1] = 0x12;
  CAN_TxMsg.Data[2] = 0xf1;
  CAN_TxMsg.Data[3] = 0x33;
  CAN_TxMsg.Data[4] = 0x22;
  CAN_TxMsg.Data[5] = 0x11;
  CAN_TxMsg.Data[6] = 0xff;
  CAN_TxMsg.Data[7] = 0xba;

    /*
     * Main program */
    while (1) {

        if (DIO8_GetInputState(INPUT0)) {
            Single_Indication_Write(0, FALSE);
        } else {
            Single_Indication_Write(0, TRUE);
        }

        if (DIO8_GetInputState(INPUT1)) {
            Single_Indication_Write(1, TRUE);
        } else {
            Single_Indication_Write(1, FALSE);
        }
        
        if (DIO8_GetInputState(INPUT2)) {
            Single_Indication_Write(2, TRUE);
        } else {
            Single_Indication_Write(2, FALSE);
        }
        
        if (DIO8_GetInputState(INPUT3)) {
            Single_Indication_Write(3, TRUE);
        } else {
            Single_Indication_Write(3, FALSE);
        }
        
        if (DIO8_GetInputState(INPUT4)) {
            Single_Indication_Write(4, TRUE);
        } else {
            Single_Indication_Write(4, FALSE);
        }
        
        if (DIO8_GetInputState(INPUT5)) {
            Single_Indication_Write(5, TRUE);
        } else {
            Single_Indication_Write(5, FALSE);
        }
        
        if (DIO8_GetInputState(INPUT6)) {
            Single_Indication_Write(6, TRUE);
        } else {
            Single_Indication_Write(6, FALSE);
        }
        
        if (DIO8_GetInputState(INPUT7)) {
            Single_Indication_Write(7, TRUE);
        } else {
            Single_Indication_Write(7, FALSE);
        }
        
        /*
         * Functions that only starts one time per second */
        if (NewSecond) {
            NewSecond = 0;
          
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
            
            /* Can */
            CAN_HA_Refresh();
        }

        /*
         * Test buffer, if there are new message to be send */
        static CanHA_MsgTypeDef Msg;    
        if (CANHA_GetMsgFromBuf(&Msg) == TRUE
                && hcan2.State != HAL_CAN_STATE_BUSY_TX
                && hcan2.State != HAL_CAN_STATE_BUSY_TX_RX) {
            CAN_TxMsg.ExtId = ((uint32_t)Msg.MessageType << 18) | Msg.Identifier;
            CAN_TxMsg.RTR = CAN_RTR_DATA;
            CAN_TxMsg.IDE = CAN_ID_EXT;
            CAN_TxMsg.DLC = Msg.DataLength;
            
            for (uint_fast8_t i = 0; i < 8; i++) {
                CAN_TxMsg.Data[i] = Msg.Data[i];
            }
            
            HAL_CAN_Transmit_IT(&hcan2);
        }
        
        /*
         * Sleep */
        HAL_PWR_EnterSLEEPMode(0, PWR_SLEEPENTRY_WFI);
    }
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  __HAL_RCC_PLLI2S_ENABLE();

}

/* CAN2 init function */
void MX_CAN2_Init(void) {
    hcan2.Instance = CAN2;
    hcan2.pTxMsg = &CAN_TxMsg;
    hcan2.pRxMsg = &CAN_RxMsg;

    hcan2.Init.Prescaler = 240;
    hcan2.Init.Mode = CAN_MODE_NORMAL;
    hcan2.Init.SJW = CAN_SJW_1TQ;
    hcan2.Init.BS1 = CAN_BS1_6TQ;
    hcan2.Init.BS2 = CAN_BS2_8TQ;
    hcan2.Init.TTCM = DISABLE;
    hcan2.Init.ABOM = DISABLE;
    hcan2.Init.AWUM = DISABLE;
    hcan2.Init.NART = DISABLE;
    hcan2.Init.RFLM = DISABLE;
    hcan2.Init.TXFP = DISABLE;
    HAL_CAN_Init(&hcan2);
}

/* USER CODE BEGIN 4 */

void HAL_CAN_TxCpltCallback(CAN_HandleTypeDef* hcan) {
    CANHA_MsgSent();
    
    CanHA_MsgTypeDef Msg;    
    if (CANHA_GetMsgFromBuf(&Msg) == TRUE) {
        hcan->pTxMsg->ExtId = ((uint32_t)Msg.MessageType << 18) | Msg.Identifier;
        hcan->pTxMsg->RTR = CAN_RTR_DATA;
        hcan->pTxMsg->IDE = CAN_ID_EXT;
        hcan->pTxMsg->DLC = Msg.DataLength;
        
        for (uint_fast8_t i = 0; i < 8; i++) {
            hcan->pTxMsg->Data[i] = Msg.Data[i];
        }
        
        HAL_CAN_Transmit_IT(hcan);
    }
}

void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan) {
    if (hcan->pRxMsg->IDE == CAN_ID_EXT) {
        CanHA_MsgTypeDef Msg;
        Msg.MessageType = (uint_least16_t)(hcan->pRxMsg->ExtId >>18);
        Msg.Identifier = hcan->pRxMsg->ExtId & 0x3FFFE;
        Msg.DataLength = (uint_least8_t)hcan->pRxMsg->DLC;
        
        for (uint_fast8_t i = 0; i < Msg.DataLength; i++) {
            Msg.Data[i] = hcan->pRxMsg->Data[i];
        }
        
        CAN_HA_GetMessage(&Msg);
    }

    HAL_CAN_Receive_IT(hcan, CAN_FIFO0);
}

/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
