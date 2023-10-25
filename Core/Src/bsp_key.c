//
// Created by uoc11 on 2023/10/24.
//
#include "gpio.h"
#include "bsp_key.h"
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();

    GPIO_InitStruct.Pin = KEY1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : PFPin PFPin PFPin PFPin */
    GPIO_InitStruct.Pin = KEY2_Pin|KEY3_Pin|KEY4_Pin|KEY5_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
}

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{
    if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON )
    {
        while(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin) == KEY_ON);
        return 	KEY_ON;
    }
    else
        return KEY_OFF;
}