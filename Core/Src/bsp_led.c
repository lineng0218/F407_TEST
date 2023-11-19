//
// Created by uoc11 on 2023/11/18.
//
#include "bsp_led.h"

void led_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;

    LED1_GPIO_CLK_ENABLE();
    LED2_GPIO_CLK_ENABLE();
    LED3_GPIO_CLK_ENABLE();
    LED4_GPIO_CLK_ENABLE();

    gpio_init_struct.Pin = LED1_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED1_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = LED2_GPIO_PIN;
    HAL_GPIO_Init(LED2_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = LED3_GPIO_PIN;
    HAL_GPIO_Init(LED3_GPIO_PORT, &gpio_init_struct);

    gpio_init_struct.Pin = LED4_GPIO_PIN;
    HAL_GPIO_Init(LED4_GPIO_PORT, &gpio_init_struct);

    LED1_OFF;
    LED2_OFF;
    LED3_OFF;
    LED4_OFF;
}