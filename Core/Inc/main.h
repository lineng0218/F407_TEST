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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN_GATE2_Pin GPIO_PIN_2
#define EN_GATE2_GPIO_Port GPIOE
#define SPI1_NSS_Pin GPIO_PIN_4
#define SPI1_NSS_GPIO_Port GPIOA
#define KEY1_Pin GPIO_PIN_1
#define KEY1_GPIO_Port GPIOB
#define KEY2_Pin GPIO_PIN_11
#define KEY2_GPIO_Port GPIOF
#define KEY3_Pin GPIO_PIN_13
#define KEY3_GPIO_Port GPIOF
#define KEY4_Pin GPIO_PIN_14
#define KEY4_GPIO_Port GPIOF
#define KEY5_Pin GPIO_PIN_15
#define KEY5_GPIO_Port GPIOF
#define MOTOR_PWM_AL_Pin GPIO_PIN_13
#define MOTOR_PWM_AL_GPIO_Port GPIOB
#define MOTOR_PWM_BL_Pin GPIO_PIN_14
#define MOTOR_PWM_BL_GPIO_Port GPIOB
#define MOTOR_PWM_CL_Pin GPIO_PIN_15
#define MOTOR_PWM_CL_GPIO_Port GPIOB
#define EN_GATE1_Pin GPIO_PIN_8
#define EN_GATE1_GPIO_Port GPIOD
#define HALL_A_Pin GPIO_PIN_6
#define HALL_A_GPIO_Port GPIOC
#define HALL_B_Pin GPIO_PIN_7
#define HALL_B_GPIO_Port GPIOC
#define HALL_C_Pin GPIO_PIN_8
#define HALL_C_GPIO_Port GPIOC
#define MOTOR_PWM_AH_Pin GPIO_PIN_8
#define MOTOR_PWM_AH_GPIO_Port GPIOA
#define MOTOR_PWM_BH_Pin GPIO_PIN_9
#define MOTOR_PWM_BH_GPIO_Port GPIOA
#define MOTOR_PWM_CH_Pin GPIO_PIN_10
#define MOTOR_PWM_CH_GPIO_Port GPIOA
#define SPI3_NSS_Pin GPIO_PIN_15
#define SPI3_NSS_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
