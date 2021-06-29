/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dac.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
float sin400[400]={0.0000,0.0157,0.0314,0.0471,0.0628,0.0785,0.0941,0.1097,0.1253,0.1409,0.1564,0.1719,0.1874,0.2028,0.2181,0.2334,0.2487,0.2639,0.2790,0.2940,0.3090,0.3239,0.3387,0.3535,0.3681,0.3827,0.3971,0.4115,0.4258,0.4399,0.4540,0.4679,0.4818,0.4955,0.5090,0.5225,0.5358,0.5490,0.5621,0.5750,0.5878,0.6004,0.6129,0.6252,0.6374,0.6494,0.6613,0.6730,0.6845,0.6959,0.7071,0.7181,0.7290,0.7396,0.7501,0.7604,0.7705,0.7804,0.7902,0.7997,0.8090,0.8181,0.8271,0.8358,0.8443,0.8526,0.8607,0.8686,0.8763,0.8838,0.8910,0.8980,0.9048,0.9114,0.9178,0.9239,0.9298,0.9354,0.9409,0.9461,0.9511,0.9558,0.9603,0.9646,0.9686,0.9724,0.9759,0.9792,0.9823,0.9851,0.9877,0.9900,0.9921,0.9940,0.9956,0.9969,0.9980,0.9989,0.9995,0.9999,1.0000,0.9999,0.9995,0.9989,0.9980,0.9969,0.9956,0.9940,0.9921,0.9900,0.9877,0.9851,0.9823,0.9792,0.9759,0.9724,0.9686,0.9646,0.9603,0.9558,0.9511,0.9461,0.9409,0.9354,0.9298,0.9239,0.9178,0.9114,0.9048,0.8980,0.8910,0.8838,0.8763,0.8686,0.8607,0.8526,0.8443,0.8358,0.8271,0.8181,0.8090,0.7997,0.7902,0.7804,0.7705,0.7604,0.7501,0.7396,0.7290,0.7181,0.7071,0.6959,0.6845,0.6730,0.6613,0.6494,0.6374,0.6252,0.6129,0.6004,0.5878,0.5750,0.5621,0.5490,0.5358,0.5225,0.5090,0.4955,0.4818,0.4679,0.4540,0.4399,0.4258,0.4115,0.3971,0.3827,0.3681,0.3535,0.3387,0.3239,0.3090,0.2940,0.2790,0.2639,0.2487,0.2334,0.2181,0.2028,0.1874,0.1719,0.1564,0.1409,0.1253,0.1097,0.0941,0.0785,0.0628,0.0471,0.0314,0.0157,0.0000,-0.0157,-0.0314,-0.0471,-0.0628,-0.0785,-0.0941,-0.1097,-0.1253,-0.1409,-0.1564,-0.1719,-0.1874,-0.2028,-0.2181,-0.2334,-0.2487,-0.2639,-0.2790,-0.2940,-0.3090,-0.3239,-0.3387,-0.3535,-0.3681,-0.3827,-0.3971,-0.4115,-0.4258,-0.4399,-0.4540,-0.4679,-0.4818,-0.4955,-0.5090,-0.5225,-0.5358,-0.5490,-0.5621,-0.5750,-0.5878,-0.6004,-0.6129,-0.6252,-0.6374,-0.6494,-0.6613,-0.6730,-0.6845,-0.6959,-0.7071,-0.7181,-0.7290,-0.7396,-0.7501,-0.7604,-0.7705,-0.7804,-0.7902,-0.7997,-0.8090,-0.8181,-0.8271,-0.8358,-0.8443,-0.8526,-0.8607,-0.8686,-0.8763,-0.8838,-0.8910,-0.8980,-0.9048,-0.9114,-0.9178,-0.9239,-0.9298,-0.9354,-0.9409,-0.9461,-0.9511,-0.9558,-0.9603,-0.9646,-0.9686,-0.9724,-0.9759,-0.9792,-0.9823,-0.9851,-0.9877,-0.9900,-0.9921,-0.9940,-0.9956,-0.9969,-0.9980,-0.9989,-0.9995,-0.9999,-1.0000,-0.9999,-0.9995,-0.9989,-0.9980,-0.9969,-0.9956,-0.9940,-0.9921,-0.9900,-0.9877,-0.9851,-0.9823,-0.9792,-0.9759,-0.9724,-0.9686,-0.9646,-0.9603,-0.9558,-0.9511,-0.9461,-0.9409,-0.9354,-0.9298,-0.9239,-0.9178,-0.9114,-0.9048,-0.8980,-0.8910,-0.8838,-0.8763,-0.8686,-0.8607,-0.8526,-0.8443,-0.8358,-0.8271,-0.8181,-0.8090,-0.7997,-0.7902,-0.7804,-0.7705,-0.7604,-0.7501,-0.7396,-0.7290,-0.7181,-0.7071,-0.6959,-0.6845,-0.6730,-0.6613,-0.6494,-0.6374,-0.6252,-0.6129,-0.6004,-0.5878,-0.5750,-0.5621,-0.5490,-0.5358,-0.5225,-0.5090,-0.4955,-0.4818,-0.4679,-0.4540,-0.4399,-0.4258,-0.4115,-0.3971,-0.3827,-0.3681,-0.3535,-0.3387,-0.3239,-0.3090,-0.2940,-0.2790,-0.2639,-0.2487,-0.2334,-0.2181,-0.2028,-0.1874,-0.1719,-0.1564,-0.1409,-0.1253,-0.1097,-0.0941,-0.0785,-0.0628,-0.0471,-0.0314,-0.0157};
float big400[400];
	/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DAC_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
HAL_DAC_Start(&hdac,DAC_CHANNEL_1); 

HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
