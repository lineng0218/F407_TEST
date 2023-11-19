//
// Created by uoc11 on 2023/10/24.
//

#ifndef F407_TEST_BSP_KEY_H
#define F407_TEST_BSP_KEY_H
#include "main.h"
#include "stm32f4xx_hal.h"

#define KEY_ON	1
#define KEY_OFF	0

/**KEY2引脚定义*/
#define KEY2_GPIO_PORT                  GPIOB
#define KEY2_GPIO_PIN                   GPIO_PIN_1
#define KEY2_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOB_CLK_ENABLE()
/**KEY3引脚定义*/
#define KEY3_GPIO_PORT                  GPIOF
#define KEY3_GPIO_PIN                   GPIO_PIN_11
#define KEY3_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOF_CLK_ENABLE()
/**KEY4引脚定义*/
#define KEY4_GPIO_PORT                  GPIOF
#define KEY4_GPIO_PIN                   GPIO_PIN_13
#define KEY4_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOF_CLK_ENABLE()
/**KEY5引脚定义*/
#define KEY5_GPIO_PORT                  GPIOF
#define KEY5_GPIO_PIN                   GPIO_PIN_14
#define KEY5_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOF_CLK_ENABLE()
/**KEY6引脚定义*/
#define KEY6_GPIO_PORT                  GPIOF
#define KEY6_GPIO_PIN                   GPIO_PIN_15
#define KEY6_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOF_CLK_ENABLE()


void KEY_Init(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif //F407_TEST_BSP_KEY_H
