//
// Created by uoc11 on 2023/10/24.
//

#ifndef F407_TEST_BSP_KEY_H
#define F407_TEST_BSP_KEY_H
#include "main.h"

#define KEY_ON	1
#define KEY_OFF	0

void KEY_Init(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#endif //F407_TEST_BSP_KEY_H
