//
// Created by uoc11 on 2023/10/24.
//

#ifndef F407_TEST_BSP_BLDC_CONTROL_H
#define F407_TEST_BSP_BLDC_CONTROL_H
#include "main.h"


typedef enum
{
    MOTOR_FWD = 0,
    MOTOR_REV,
}motor_dir_t;

typedef struct
{
    motor_dir_t direction;
    uint16_t dutyfactor;
    uint8_t is_enable;
    uint32_t lock_timeout;
}bldcm_data_t;

void bldcm_init(void);
void set_bldcm_speed(uint16_t v);
void set_bldcm_direction(motor_dir_t dir);
motor_dir_t get_bldcm_direction(void);
void set_bldcm_enable(void);
void set_bldcm_disable(void);

#endif //F407_TEST_BSP_BLDC_CONTROL_H
