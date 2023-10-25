//
// Created by uoc11 on 2023/10/24.
//
#include "bsp_BLDC_control.h"
#include "bsp_timer.h"

static bldcm_data_t bldcm_data;

void bldcm_init(void)
{
    TIMx_Configuration();
    hall_tim_config();

}

motor_dir_t get_bldcm_direction(void)
{
    return bldcm_data.direction;
}

void set_bldcm_enable(void)
{
    hall_enable();
}

void set_bldcm_disable(void)
{

    hall_disable();
    stop_pwm_output();
}

void set_bldcm_speed(uint16_t v)
{
    bldcm_data.dutyfactor = v;

    set_pwm_pulse(v);
}

void set_bldcm_direction(motor_dir_t dir)
{
    bldcm_data.direction = dir;
}
