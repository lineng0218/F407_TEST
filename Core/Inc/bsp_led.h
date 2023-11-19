//
// Created by uoc11 on 2023/11/18.
//

#ifndef F407_TEST_BSP_LED_H
#define F407_TEST_BSP_LED_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32f4xx_hal.h"

/**LED1引脚定义*/
#define LED1_GPIO_PORT                  GPIOE
#define LED1_GPIO_PIN                   GPIO_PIN_8
#define LED1_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOE_CLK_ENABLE()

/**LED2引脚定义*/
#define LED2_GPIO_PORT                  GPIOE
#define LED2_GPIO_PIN                   GPIO_PIN_7
#define LED2_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOE_CLK_ENABLE()

/**LED3引脚定义*/
#define LED3_GPIO_PORT                  GPIOG
#define LED3_GPIO_PIN                   GPIO_PIN_1
#define LED3_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOG_CLK_ENABLE()

/**LED4引脚定义*/
#define LED4_GPIO_PORT                  GPIOG
#define LED4_GPIO_PIN                   GPIO_PIN_0
#define LED4_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOG_CLK_ENABLE()

#define LED1_ON                        HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET)
#define LED1_OFF                       HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET)

#define LED2_ON                        HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_GPIO_PIN, GPIO_PIN_RESET)
#define LED2_OFF                       HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_GPIO_PIN, GPIO_PIN_SET)

#define LED3_ON                        HAL_GPIO_WritePin(LED3_GPIO_PORT, LED3_GPIO_PIN, GPIO_PIN_RESET)
#define LED3_OFF                       HAL_GPIO_WritePin(LED3_GPIO_PORT, LED3_GPIO_PIN, GPIO_PIN_SET)

#define LED4_ON                        HAL_GPIO_WritePin(LED4_GPIO_PORT, LED4_GPIO_PIN, GPIO_PIN_RESET)
#define LED4_OFF                       HAL_GPIO_WritePin(LED4_GPIO_PORT, LED4_GPIO_PIN, GPIO_PIN_SET)

void led_init(void);
#endif //F407_TEST_BSP_LED_H
