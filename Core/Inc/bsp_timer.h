//
// Created by uoc11 on 2023/10/24.
//

#ifndef F407_TEST_BSP_TIMER_H
#define F407_TEST_BSP_TIMER_H
#include "main.h"

#define MOTOR_TIM           				      TIM1
#define MOTOR_TIM_CLK_ENABLE()  			       __TIM1_CLK_ENABLE()

extern TIM_HandleTypeDef  htim1;
extern TIM_HandleTypeDef  htim3;

#define PWM_PERIOD_COUNT                          (5600)

#define PWM_MAX_PERIOD_COUNT                      (PWM_PERIOD_COUNT - 100)

#define PWM_PRESCALER_COUNT                       (2)

#define MOTOR_OCPWM1_PIN           		          GPIO_PIN_8
#define MOTOR_OCPWM1_GPIO_PORT     		          GPIOA
#define MOTOR_OCPWM1_GPIO_CLK_ENABLE() 	          __GPIOA_CLK_ENABLE()
#define MOTOR_OCPWM1_AF					          GPIO_AF1_TIM1

#define MOTOR_OCPWM2_PIN           		          GPIO_PIN_9
#define MOTOR_OCPWM2_GPIO_PORT     		          GPIOA
#define MOTOR_OCPWM2_GPIO_CLK_ENABLE() 	          __GPIOA_CLK_ENABLE()
#define MOTOR_OCPWM2_AF					          GPIO_AF1_TIM1

#define MOTOR_OCPWM3_PIN           		         GPIO_PIN_10
#define MOTOR_OCPWM3_GPIO_PORT     		         GPIOA
#define MOTOR_OCPWM3_GPIO_CLK_ENABLE() 	         __GPIOA_CLK_ENABLE()
#define MOTOR_OCPWM3_AF					         GPIO_AF1_TIM1


#define MOTOR_OCNPWM1_PIN            		     GPIO_PIN_13
#define MOTOR_OCNPWM1_GPIO_PORT      		     GPIOB
#define MOTOR_OCNPWM1_GPIO_CLK_ENABLE()	         __GPIOB_CLK_ENABLE()
#define MOTOR_OCNPWM1_AF					     GPIO_AF1_TIM1


#define MOTOR_OCNPWM2_PIN            		     GPIO_PIN_14
#define MOTOR_OCNPWM2_GPIO_PORT      		     GPIOB
#define MOTOR_OCNPWM2_GPIO_CLK_ENABLE()	         __GPIOB_CLK_ENABLE()
#define MOTOR_OCNPWM2_AF					     GPIO_AF1_TIM1


#define MOTOR_OCNPWM3_PIN            		     GPIO_PIN_15
#define MOTOR_OCNPWM3_GPIO_PORT      		     GPIOB
#define MOTOR_OCNPWM3_GPIO_CLK_ENABLE()	         __GPIOB_CLK_ENABLE()
#define MOTOR_OCNPWM3_AF					     GPIO_AF1_TIM1

#define TIM_COM_TS_ITRx                          TIM_TS_ITR2

#define HALL_TIM           				         TIM3
#define HALL_TIM_CLK_ENABLE()  			         __TIM3_CLK_ENABLE()

#define HALL_PERIOD_COUNT                        (0xFFFF)

#define HALL_PRESCALER_COUNT                     (128)

#define HALL_INPUTU_PIN           		         GPIO_PIN_6
#define HALL_INPUTU_GPIO_PORT     		         GPIOC
#define HALL_INPUTU_GPIO_CLK_ENABLE() 	         __GPIOC_CLK_ENABLE()
#define HALL_INPUTU_AF					         GPIO_AF2_TIM3


#define HALL_INPUTV_PIN           		         GPIO_PIN_7
#define HALL_INPUTV_GPIO_PORT     		         GPIOC
#define HALL_INPUTV_GPIO_CLK_ENABLE() 	         __GPIOC_CLK_ENABLE()
#define HALL_INPUTV_AF					         GPIO_AF2_TIM3


#define HALL_INPUTW_PIN           		         GPIO_PIN_8
#define HALL_INPUTW_GPIO_PORT     		         GPIOC
#define HALL_INPUTW_GPIO_CLK_ENABLE()            __GPIOC_CLK_ENABLE()
#define HALL_INPUTW_AF					         GPIO_AF2_TIM3

#define HALL_TIM_IRQn                            TIM3_IRQn
#define HALL_TIM_IRQHandler                      TIM3_IRQHandler

extern TIM_HandleTypeDef TIM_TimeBaseStructure;

void TIMx_Configuration(void);
void stop_pwm_output(void);
void set_pwm_pulse(uint16_t pulse);

void hall_enable(void);
void hall_disable(void);
void hall_tim_config(void);

#endif //F407_TEST_BSP_TIMER_H