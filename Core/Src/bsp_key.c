//
// Created by uoc11 on 2023/10/24.
#include "bsp_key.h"
void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    KEY2_GPIO_CLK_ENABLE();
    KEY3_GPIO_CLK_ENABLE();
    KEY4_GPIO_CLK_ENABLE();
    KEY5_GPIO_CLK_ENABLE();
    KEY6_GPIO_CLK_ENABLE();

    GPIO_InitStruct.Pin =KEY2_GPIO_PIN ;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStruct);

    /*Configure GPIO pins : PFPin PFPin PFPin PFPin */
    GPIO_InitStruct.Pin = KEY3_GPIO_PIN ;
    HAL_GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = KEY4_GPIO_PIN ;
    HAL_GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = KEY5_GPIO_PIN ;
    HAL_GPIO_Init(KEY5_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = KEY6_GPIO_PIN ;
    HAL_GPIO_Init(KEY6_GPIO_PORT, &GPIO_InitStruct);

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