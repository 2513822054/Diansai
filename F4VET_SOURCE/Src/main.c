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
float sin400[400]={
0.00000,0.01571,0.03141,0.04711,0.06279,0.07846,0.09411,0.10973,0.12533,0.14090,0.15643,0.17193,0.18738,0.20279,0.21814,0.23345,0.24869,0.26387,0.27899,0.29404,0.30902,0.32392,0.33874,0.35347,0.36812,0.38268,0.39715,0.41151,0.42578,0.43994,0.45399,0.46793,0.48175,0.49546,0.50904,0.52250,0.53583,0.54902,0.56208,0.57501,0.58779,0.60042,0.61291,0.62524,0.63742,0.64945,0.66131,0.67301,0.68455,0.69591,0.70711,0.71813,0.72897,0.73963,0.75011,0.76041,0.77051,0.78043,0.79016,0.79968,0.80902,0.81815,0.82708,0.83581,0.84433,0.85264,0.86074,0.86863,0.87631,0.88377,0.89101,0.89803,0.90483,0.91140,0.91775,0.92388,0.92978,0.93544,0.94088,0.94609,0.95106,0.95579,0.96029,0.96456,0.96858,0.97237,0.97592,0.97922,0.98229,0.98511,0.98769,0.99002,0.99211,0.99396,0.99556,0.99692,0.99803,0.99889,0.99951,0.99988,1.00000,0.99988,0.99951,0.99889,0.99803,0.99692,0.99556,0.99396,0.99211,0.99002,0.98769,0.98511,0.98229,0.97922,0.97592,0.97237,0.96858,0.96456,0.96029,0.95579,0.95106,0.94609,0.94088,0.93544,0.92978,0.92388,0.91775,0.91140,0.90483,0.89803,0.89101,0.88377,0.87631,0.86863,0.86074,0.85264,0.84433,0.83581,0.82708,0.81815,0.80902,0.79968,0.79016,0.78043,0.77051,0.76041,0.75011,0.73963,0.72897,0.71813,0.70711,0.69591,0.68455,0.67301,0.66131,0.64945,0.63742,0.62524,0.61291,0.60042,0.58779,0.57501,0.56208,0.54902,0.53583,0.52250,0.50904,0.49546,0.48175,0.46793,0.45399,0.43994,0.42578,0.41151,0.39715,0.38268,0.36812,0.35347,0.33874,0.32392,0.30902,0.29404,0.27899,0.26387,0.24869,0.23345,0.21814,0.20279,0.18738,0.17193,0.15643,0.14090,0.12533,0.10973,0.09411,0.07846,0.06279,0.04711,0.03141,0.01571,0.00000,-0.01571,-0.03141,-0.04711,-0.06279,-0.07846,-0.09411,-0.10973,-0.12533,-0.14090,-0.15643,-0.17193,-0.18738,-0.20279,-0.21814,-0.23345,-0.24869,-0.26387,-0.27899,-0.29404,-0.30902,-0.32392,-0.33874,-0.35347,-0.36812,-0.38268,-0.39715,-0.41151,-0.42578,-0.43994,-0.45399,-0.46793,-0.48175,-0.49546,-0.50904,-0.52250,-0.53583,-0.54902,-0.56208,-0.57501,-0.58779,-0.60042,-0.61291,-0.62524,-0.63742,-0.64945,-0.66131,-0.67301,-0.68455,-0.69591,-0.70711,-0.71813,-0.72897,-0.73963,-0.75011,-0.76041,-0.77051,-0.78043,-0.79016,-0.79968,-0.80902,-0.81815,-0.82708,-0.83581,-0.84433,-0.85264,-0.86074,-0.86863,-0.87631,-0.88377,-0.89101,-0.89803,-0.90483,-0.91140,-0.91775,-0.92388,-0.92978,-0.93544,-0.94088,-0.94609,-0.95106,-0.95579,-0.96029,-0.96456,-0.96858,-0.97237,-0.97592,-0.97922,-0.98229,-0.98511,-0.98769,-0.99002,-0.99211,-0.99396,-0.99556,-0.99692,-0.99803,-0.99889,-0.99951,-0.99988,-1.00000,-0.99988,-0.99951,-0.99889,-0.99803,-0.99692,-0.99556,-0.99396,-0.99211,-0.99002,-0.98769,-0.98511,-0.98229,-0.97922,-0.97592,-0.97237,-0.96858,-0.96456,-0.96029,-0.95579,-0.95106,-0.94609,-0.94088,-0.93544,-0.92978,-0.92388,-0.91775,-0.91140,-0.90483,-0.89803,-0.89101,-0.88377,-0.87631,-0.86863,-0.86074,-0.85264,-0.84433,-0.83581,-0.82708,-0.81815,-0.80902,-0.79968,-0.79016,-0.78043,-0.77051,-0.76041,-0.75011,-0.73963,-0.72897,-0.71813,-0.70711,-0.69591,-0.68455,-0.67301,-0.66131,-0.64945,-0.63742,-0.62524,-0.61291,-0.60042,-0.58779,-0.57501,-0.56208,-0.54902,-0.53583,-0.52250,-0.50904,-0.49546,-0.48175,-0.46793,-0.45399,-0.43994,-0.42578,-0.41151,-0.39715,-0.38268,-0.36812,-0.35347,-0.33874,-0.32392,-0.30902,-0.29404,-0.27899,-0.26387,-0.24869,-0.23345,-0.21814,-0.20279,-0.18738,-0.17193,-0.15643,-0.14090,-0.12533,-0.10973,-0.09411,-0.07846,-0.06279,-0.04711,-0.03141,-0.01571
};
uint16_t mode=1,freq=1;
float volt=0.1;
uint16_t DAC_Buf[400];
int i=0,j=0;
uint16_t count;

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
  MX_TIM3_Init();
	HAL_DAC_SetValue(&hdac,DAC_CHANNEL_2,DAC_ALIGN_12B_R,4000*freq/40);
  /* USER CODE BEGIN 2 */

for (i=0;i<400;i++){
		DAC_Buf[i]=(int)(sin400[i]*volt/2/3.3*4096+2048);
}
i=0;

HAL_DAC_Start(&hdac,DAC_CHANNEL_1); //??DAC??
HAL_DAC_Start(&hdac,DAC_CHANNEL_2); //??DAC??
HAL_TIM_Base_Start_IT(&htim3); //?????2????
TIM3->ARR=9;
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
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
if(htim == &htim3){
//		if(mode==1){
//				HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,DAC_Buf[i]);
//				i+=freq;
//				if(i>=400){
//						i-=400;
//				}
//			}
//		if(mode==2){
//			if(freq<=40){
//				HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,DAC_Buf[i]);
//				//HAL_DAC_SetValue(&hdac,DAC_CHANNEL_2,DAC_ALIGN_12B_R,DAC_Buf[i]);
//				i+=freq;
//				if(i>=400){
//						i-=400;
//					}
//				}
//			else{
//				HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,DAC_Buf[i]);
//				//HAL_DAC_SetValue(&hdac,DAC_CHANNEL_2,DAC_ALIGN_12B_R,DAC_Buf[i]);
//				i+=(81-freq);
//				if(i>=400){
//						i-=400;
//					}
//			}
//				count++;
//		if(count>4000){
//						freq++;
//					  if(freq>80)freq=1;
//						if(freq<=40)HAL_DAC_SetValue(&hdac,DAC_CHANNEL_2,DAC_ALIGN_12B_R,4000*freq/40);
//						else HAL_DAC_SetValue(&hdac,DAC_CHANNEL_2,DAC_ALIGN_12B_R,4000*(81-freq)/40);
//						count=1;
//				}

//			}
				
		}
	
}
//按键中断函数
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//wakeup键被按下
  if(GPIO_Pin==GPIO_PIN_0){
			if(mode==1){mode=2;freq=1;count=0;}
			else mode=1;
	}
	
	//KEY0被按下
	if(GPIO_Pin==GPIO_PIN_3){
			volt+=0.1;
			if(volt>=3.21
				){
					volt=0.1;
			}
			for(j=0;j<400;j++){
					DAC_Buf[j]=(int)(sin400[j]*volt/2/3.3*4096+2048);
			}
	}
	
	//KEY1被按下
		if(GPIO_Pin==GPIO_PIN_4){
			freq+=1;
			if(freq>40){
					freq=1;
			}
			HAL_DAC_SetValue(&hdac,DAC_CHANNEL_2,DAC_ALIGN_12B_R,100*freq);
		}
	for(j=0;j<=2000;j++){;}
}

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
