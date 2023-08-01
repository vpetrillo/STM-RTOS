/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

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
I2C_HandleTypeDef hi2c1;

I2S_HandleTypeDef hi2s3;

SPI_HandleTypeDef hspi1;

HCD_HandleTypeDef hhcd_USB_OTG_FS;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask03 */
osThreadId_t myTask03Handle;
const osThreadAttr_t myTask03_attributes = {
  .name = "myTask03",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask04 */
osThreadId_t myTask04Handle;
const osThreadAttr_t myTask04_attributes = {
  .name = "myTask04",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask05 */
osThreadId_t myTask05Handle;
const osThreadAttr_t myTask05_attributes = {
  .name = "myTask05",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask06 */
osThreadId_t myTask06Handle;
const osThreadAttr_t myTask06_attributes = {
  .name = "myTask06",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask07 */
osThreadId_t myTask07Handle;
const osThreadAttr_t myTask07_attributes = {
  .name = "myTask07",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask08 */
osThreadId_t myTask08Handle;
const osThreadAttr_t myTask08_attributes = {
  .name = "myTask08",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask09 */
osThreadId_t myTask09Handle;
const osThreadAttr_t myTask09_attributes = {
  .name = "myTask09",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask10 */
osThreadId_t myTask10Handle;
const osThreadAttr_t myTask10_attributes = {
  .name = "myTask10",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask11 */
osThreadId_t myTask11Handle;
const osThreadAttr_t myTask11_attributes = {
  .name = "myTask11",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask12 */
osThreadId_t myTask12Handle;
const osThreadAttr_t myTask12_attributes = {
  .name = "myTask12",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask13 */
osThreadId_t myTask13Handle;
const osThreadAttr_t myTask13_attributes = {
  .name = "myTask13",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask14 */
osThreadId_t myTask14Handle;
const osThreadAttr_t myTask14_attributes = {
  .name = "myTask14",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask15 */
osThreadId_t myTask15Handle;
const osThreadAttr_t myTask15_attributes = {
  .name = "myTask15",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask16 */
osThreadId_t myTask16Handle;
const osThreadAttr_t myTask16_attributes = {
  .name = "myTask16",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask17 */
osThreadId_t myTask17Handle;
const osThreadAttr_t myTask17_attributes = {
  .name = "myTask17",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask18 */
osThreadId_t myTask18Handle;
const osThreadAttr_t myTask18_attributes = {
  .name = "myTask18",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask19 */
osThreadId_t myTask19Handle;
const osThreadAttr_t myTask19_attributes = {
  .name = "myTask19",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for myTask20 */
osThreadId_t myTask20Handle;
const osThreadAttr_t myTask20_attributes = {
  .name = "myTask20",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime,
};
/* USER CODE BEGIN PV */

int count = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2S3_Init(void);
static void MX_SPI1_Init(void);
static void MX_USB_OTG_FS_HCD_Init(void);
void StartDefaultTask(void *argument);
void StartTask02(void *argument);
void StartTask03(void *argument);
void StartTask04(void *argument);
void StartTask05(void *argument);
void StartTask06(void *argument);
void StartTask07(void *argument);
void StartTask08(void *argument);
void StartTask09(void *argument);
void StartTask10(void *argument);
void StartTask11(void *argument);
void StartTask12(void *argument);
void StartTask13(void *argument);
void StartTask14(void *argument);
void StartTask15(void *argument);
void StartTask16(void *argument);
void StartTask17(void *argument);
void StartTask18(void *argument);
void StartTask19(void *argument);
void StartTask20(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_I2C1_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_OTG_FS_HCD_Init();
  /* USER CODE BEGIN 2 */
  vTraceEnable(TRC_START);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of myTask02 */
  myTask02Handle = osThreadNew(StartTask02, NULL, &myTask02_attributes);

  /* creation of myTask03 */
  myTask03Handle = osThreadNew(StartTask03, NULL, &myTask03_attributes);

  /* creation of myTask04 */
  myTask04Handle = osThreadNew(StartTask04, NULL, &myTask04_attributes);

  /* creation of myTask05 */
  myTask05Handle = osThreadNew(StartTask05, NULL, &myTask05_attributes);

  /* creation of myTask06 */
  myTask06Handle = osThreadNew(StartTask06, NULL, &myTask06_attributes);

  /* creation of myTask07 */
  myTask07Handle = osThreadNew(StartTask07, NULL, &myTask07_attributes);

  /* creation of myTask08 */
  myTask08Handle = osThreadNew(StartTask08, NULL, &myTask08_attributes);

  /* creation of myTask09 */
  myTask09Handle = osThreadNew(StartTask09, NULL, &myTask09_attributes);

  /* creation of myTask10 */
  myTask10Handle = osThreadNew(StartTask10, NULL, &myTask10_attributes);

  /* creation of myTask11 */
  myTask11Handle = osThreadNew(StartTask11, NULL, &myTask11_attributes);

  /* creation of myTask12 */
  myTask12Handle = osThreadNew(StartTask12, NULL, &myTask12_attributes);

  /* creation of myTask13 */
  myTask13Handle = osThreadNew(StartTask13, NULL, &myTask13_attributes);

  /* creation of myTask14 */
  myTask14Handle = osThreadNew(StartTask14, NULL, &myTask14_attributes);

  /* creation of myTask15 */
  myTask15Handle = osThreadNew(StartTask15, NULL, &myTask15_attributes);

  /* creation of myTask16 */
  myTask16Handle = osThreadNew(StartTask16, NULL, &myTask16_attributes);

  /* creation of myTask17 */
  myTask17Handle = osThreadNew(StartTask17, NULL, &myTask17_attributes);

  /* creation of myTask18 */
  myTask18Handle = osThreadNew(StartTask18, NULL, &myTask18_attributes);

  /* creation of myTask19 */
  myTask19Handle = osThreadNew(StartTask19, NULL, &myTask19_attributes);

  /* creation of myTask20 */
  myTask20Handle = osThreadNew(StartTask20, NULL, &myTask20_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();
  /* We should never get here as control is now taken by the scheduler */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
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

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2S3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S3_Init(void)
{

  /* USER CODE BEGIN I2S3_Init 0 */

  /* USER CODE END I2S3_Init 0 */

  /* USER CODE BEGIN I2S3_Init 1 */

  /* USER CODE END I2S3_Init 1 */
  hi2s3.Instance = SPI3;
  hi2s3.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s3.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s3.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s3.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
  hi2s3.Init.AudioFreq = I2S_AUDIOFREQ_96K;
  hi2s3.Init.CPOL = I2S_CPOL_LOW;
  hi2s3.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s3.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S3_Init 2 */

  /* USER CODE END I2S3_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_HCD_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  hhcd_USB_OTG_FS.Instance = USB_OTG_FS;
  hhcd_USB_OTG_FS.Init.Host_channels = 8;
  hhcd_USB_OTG_FS.Init.speed = HCD_SPEED_FULL;
  hhcd_USB_OTG_FS.Init.dma_enable = DISABLE;
  hhcd_USB_OTG_FS.Init.phy_itface = HCD_PHY_EMBEDDED;
  hhcd_USB_OTG_FS.Init.Sof_enable = DISABLE;
  if (HAL_HCD_Init(&hhcd_USB_OTG_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CS_I2C_SPI_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BOOT1_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin LD5_Pin LD6_Pin
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	traceString counter_string = xTraceRegisterString("Task 1");
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
    vTracePrintF(counter_string, "Counter: %d", count);
    count++;
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
	traceString counter_string = xTraceRegisterString("Task 2");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void *argument)
{
  /* USER CODE BEGIN StartTask03 */
	traceString counter_string = xTraceRegisterString("Task 3");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void *argument)
{
  /* USER CODE BEGIN StartTask04 */
	traceString counter_string = xTraceRegisterString("Task 4");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the myTask05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void StartTask05(void *argument)
{
  /* USER CODE BEGIN StartTask05 */
	traceString counter_string = xTraceRegisterString("Task 5");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask05 */
}

/* USER CODE BEGIN Header_StartTask06 */
/**
* @brief Function implementing the myTask06 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask06 */
void StartTask06(void *argument)
{
  /* USER CODE BEGIN StartTask06 */
	traceString counter_string = xTraceRegisterString("Task 6");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask06 */
}

/* USER CODE BEGIN Header_StartTask07 */
/**
* @brief Function implementing the myTask07 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask07 */
void StartTask07(void *argument)
{
  /* USER CODE BEGIN StartTask07 */
	traceString counter_string = xTraceRegisterString("Task 7");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask07 */
}

/* USER CODE BEGIN Header_StartTask08 */
/**
* @brief Function implementing the myTask08 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask08 */
void StartTask08(void *argument)
{
  /* USER CODE BEGIN StartTask08 */
	traceString counter_string = xTraceRegisterString("Task 8");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask08 */
}

/* USER CODE BEGIN Header_StartTask09 */
/**
* @brief Function implementing the myTask09 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask09 */
void StartTask09(void *argument)
{
  /* USER CODE BEGIN StartTask09 */
	traceString counter_string = xTraceRegisterString("Task 9");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask09 */
}

/* USER CODE BEGIN Header_StartTask10 */
/**
* @brief Function implementing the myTask10 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask10 */
void StartTask10(void *argument)
{
  /* USER CODE BEGIN StartTask10 */
	traceString counter_string = xTraceRegisterString("Task 10");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask10 */
}

/* USER CODE BEGIN Header_StartTask11 */
/**
* @brief Function implementing the myTask11 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask11 */
void StartTask11(void *argument)
{
  /* USER CODE BEGIN StartTask11 */
	traceString counter_string = xTraceRegisterString("Task 11");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask11 */
}

/* USER CODE BEGIN Header_StartTask12 */
/**
* @brief Function implementing the myTask12 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask12 */
void StartTask12(void *argument)
{
  /* USER CODE BEGIN StartTask12 */
	traceString counter_string = xTraceRegisterString("Task 12");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask12 */
}

/* USER CODE BEGIN Header_StartTask13 */
/**
* @brief Function implementing the myTask13 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask13 */
void StartTask13(void *argument)
{
  /* USER CODE BEGIN StartTask13 */
	traceString counter_string = xTraceRegisterString("Task 13");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask13 */
}

/* USER CODE BEGIN Header_StartTask14 */
/**
* @brief Function implementing the myTask14 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask14 */
void StartTask14(void *argument)
{
  /* USER CODE BEGIN StartTask14 */
	traceString counter_string = xTraceRegisterString("Task 14");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask14 */
}

/* USER CODE BEGIN Header_StartTask15 */
/**
* @brief Function implementing the myTask15 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask15 */
void StartTask15(void *argument)
{
  /* USER CODE BEGIN StartTask15 */
	traceString counter_string = xTraceRegisterString("Task 15");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask15 */
}

/* USER CODE BEGIN Header_StartTask16 */
/**
* @brief Function implementing the myTask16 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask16 */
void StartTask16(void *argument)
{
  /* USER CODE BEGIN StartTask16 */
	traceString counter_string = xTraceRegisterString("Task 16");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask16 */
}

/* USER CODE BEGIN Header_StartTask17 */
/**
* @brief Function implementing the myTask17 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask17 */
void StartTask17(void *argument)
{
  /* USER CODE BEGIN StartTask17 */
	traceString counter_string = xTraceRegisterString("Task 17");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask17 */
}

/* USER CODE BEGIN Header_StartTask18 */
/**
* @brief Function implementing the myTask18 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask18 */
void StartTask18(void *argument)
{
  /* USER CODE BEGIN StartTask18 */
	traceString counter_string = xTraceRegisterString("Task 18");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask18 */
}

/* USER CODE BEGIN Header_StartTask19 */
/**
* @brief Function implementing the myTask19 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask19 */
void StartTask19(void *argument)
{
  /* USER CODE BEGIN StartTask19 */
	traceString counter_string = xTraceRegisterString("Task 19");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask19 */
}

/* USER CODE BEGIN Header_StartTask20 */
/**
* @brief Function implementing the myTask20 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask20 */
void StartTask20(void *argument)
{
  /* USER CODE BEGIN StartTask20 */
	traceString counter_string = xTraceRegisterString("Task 20");
  /* Infinite loop */
  for(;;)
  {
	  vTracePrintF(counter_string, "Counter: %d", count);
	  count++;
    osDelay(1);
  }
  /* USER CODE END StartTask20 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
