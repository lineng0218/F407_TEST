//
// Created by uoc11 on 2023/10/24.
//
#include "bsp_timer.h"
#include "bsp_BLDC_control.h"

TIM_HandleTypeDef  htim1;
TIM_OC_InitTypeDef TIM_OCInitStructure;

TIM_HandleTypeDef htim3;
static uint16_t bldcm_pulse = 0;

static void TIMx_GPIO_Config(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;

    MOTOR_OCPWM1_GPIO_CLK_ENABLE();
    MOTOR_OCNPWM1_GPIO_CLK_ENABLE();
    MOTOR_OCPWM2_GPIO_CLK_ENABLE();
    MOTOR_OCNPWM2_GPIO_CLK_ENABLE();
    MOTOR_OCPWM3_GPIO_CLK_ENABLE();
    MOTOR_OCNPWM3_GPIO_CLK_ENABLE();

    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;

    GPIO_InitStructure.Pin = MOTOR_OCNPWM1_PIN;
    HAL_GPIO_Init(MOTOR_OCNPWM1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = MOTOR_OCNPWM2_PIN;
    HAL_GPIO_Init(MOTOR_OCNPWM2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = MOTOR_OCNPWM3_PIN;
    HAL_GPIO_Init(MOTOR_OCNPWM3_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;

    GPIO_InitStructure.Pin = MOTOR_OCPWM1_PIN;
    GPIO_InitStructure.Alternate = MOTOR_OCPWM1_AF;
    HAL_GPIO_Init(MOTOR_OCPWM1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = MOTOR_OCPWM2_PIN;
    GPIO_InitStructure.Alternate = MOTOR_OCPWM2_AF;
    HAL_GPIO_Init(MOTOR_OCPWM2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = MOTOR_OCPWM3_PIN;
    GPIO_InitStructure.Alternate = MOTOR_OCPWM3_AF;
    HAL_GPIO_Init(MOTOR_OCPWM3_GPIO_PORT, &GPIO_InitStructure);
}

static void TIM_Mode_Config(void)
{

    MOTOR_TIM_CLK_ENABLE();

    htim1.Instance = MOTOR_TIM;
    htim1.Init.Period = PWM_PERIOD_COUNT - 1;
    htim1.Init.Prescaler = PWM_PRESCALER_COUNT - 1;
    htim1.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
    htim1.Init.CounterMode=TIM_COUNTERMODE_UP;
    htim1.Init.RepetitionCounter=0;

    HAL_TIM_PWM_Init(&htim1);

    TIM_OCInitStructure.OCMode = TIM_OCMODE_PWM1;
    TIM_OCInitStructure.Pulse = 0;
    TIM_OCInitStructure.OCPolarity = TIM_OCPOLARITY_HIGH;
    TIM_OCInitStructure.OCNPolarity = TIM_OCNPOLARITY_HIGH;
    TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_SET;
    TIM_OCInitStructure.OCNIdleState = TIM_OCNIDLESTATE_RESET;

    HAL_TIM_PWM_ConfigChannel(&htim1,&TIM_OCInitStructure,TIM_CHANNEL_1);    // ³õÊ¼»¯Í¨µÀ 1 Êä³ö PWM
    HAL_TIM_PWM_ConfigChannel(&htim1,&TIM_OCInitStructure,TIM_CHANNEL_2);    // ³õÊ¼»¯Í¨µÀ 2 Êä³ö PWM
    HAL_TIM_PWM_ConfigChannel(&htim1,&TIM_OCInitStructure,TIM_CHANNEL_3);    // ³õÊ¼»¯Í¨µÀ 3 Êä³ö PWM

    HAL_TIMEx_ConfigCommutationEvent(&htim1, TIM_COM_TS_ITRx, TIM_COMMUTATION_SOFTWARE);

    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
}

void stop_pwm_output(void)
{

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);

    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);

    HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);
}

void set_pwm_pulse(uint16_t pulse)
{
    bldcm_pulse = pulse;
}

void TIMx_Configuration(void)
{
    TIMx_GPIO_Config();
    TIM_Mode_Config();
}

static void hall_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    HALL_INPUTU_GPIO_CLK_ENABLE();
    HALL_INPUTV_GPIO_CLK_ENABLE();
    HALL_INPUTW_GPIO_CLK_ENABLE();

    GPIO_InitStruct.Pin = HALL_INPUTU_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Alternate = HALL_INPUTU_AF;
    HAL_GPIO_Init(HALL_INPUTU_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = HALL_INPUTV_PIN;
    HAL_GPIO_Init(HALL_INPUTV_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = HALL_INPUTW_PIN;
    HAL_GPIO_Init(HALL_INPUTW_GPIO_PORT, &GPIO_InitStruct);
}

static void hall_tim_init(void)
{
    TIM_HallSensor_InitTypeDef  hall_sensor_cfg;

    HALL_TIM_CLK_ENABLE();

    htim3.Instance = HALL_TIM;
    htim3.Init.Prescaler = HALL_PRESCALER_COUNT - 1;
    htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim3.Init.Period = HALL_PERIOD_COUNT - 1;
    htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

    hall_sensor_cfg.IC1Prescaler = TIM_ICPSC_DIV1;
    hall_sensor_cfg.IC1Polarity = TIM_ICPOLARITY_BOTHEDGE;
    hall_sensor_cfg.IC1Filter = 10;
    hall_sensor_cfg.Commutation_Delay = 0U;
    HAL_TIMEx_HallSensor_Init(&htim3, &hall_sensor_cfg);

    HAL_NVIC_SetPriority(HALL_TIM_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(HALL_TIM_IRQn);
}

void hall_enable(void)
{

    __HAL_TIM_ENABLE_IT(&htim3, TIM_IT_TRIGGER);
    __HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);

    HAL_TIMEx_HallSensor_Start(&htim3);

    HAL_TIM_TriggerCallback(&htim3);
}

void hall_disable(void)
{

    __HAL_TIM_DISABLE_IT(&htim3, TIM_IT_TRIGGER);
    __HAL_TIM_DISABLE_IT(&htim3, TIM_IT_UPDATE);
    HAL_TIMEx_HallSensor_Stop(&htim3);
}

uint8_t get_hall_state(void)
{
    uint8_t state = 0;

#if 1
    if(HAL_GPIO_ReadPin(HALL_INPUTU_GPIO_PORT, HALL_INPUTU_PIN) != GPIO_PIN_RESET)
    {
        state |= 0x01U << 0;
    }

    if(HAL_GPIO_ReadPin(HALL_INPUTV_GPIO_PORT, HALL_INPUTV_PIN) != GPIO_PIN_RESET)
    {
        state |= 0x01U << 1;
    }

    if(HAL_GPIO_ReadPin(HALL_INPUTW_GPIO_PORT, HALL_INPUTW_PIN) != GPIO_PIN_RESET)
    {
        state |= 0x01U << 2;
    }
#else
    state = (GPIOH->IDR >> 10) & 7;
#endif

    return state;
}

void hall_tim_config(void)
{
    hall_gpio_init();
    hall_tim_init();
}

int update = 0;

void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim)
{

    uint8_t step = 0;
    step = get_hall_state();

#if 0
    if(get_bldcm_direction() == MOTOR_FWD)
  {
    step = 7 - step;
  }
#endif
    if(get_bldcm_direction() == MOTOR_FWD)
    {
        switch(step)
        {
            case 1:    /* U+ W- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);
                break;

            case 2:     /* V+ U- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);

                break;

            case 3:    /* V+ W- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);
                break;

            case 4:     /* W+ V- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);
                break;

            case 5:     /* U+  V -*/
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);
                break;

            case 6:     /* W+ U- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);
                break;
        }
    }
    else
    {
        switch(step)
        {
            case 1:   /* W+ U- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);
                break;

            case 2:    /* U+  V -*/
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);
                break;

            case 3:   /* W+ V- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_SET);

                break;

            case 4:    /* V+ W- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);
                break;

            case 5:    /* V+ U- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_SET);
                break;

            case 6:    /* U+ W- */
                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM2_GPIO_PORT, MOTOR_OCNPWM2_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
                HAL_GPIO_WritePin(MOTOR_OCNPWM1_GPIO_PORT, MOTOR_OCNPWM1_PIN, GPIO_PIN_RESET);

                __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, bldcm_pulse);
                HAL_GPIO_WritePin(MOTOR_OCNPWM3_GPIO_PORT, MOTOR_OCNPWM3_PIN, GPIO_PIN_SET);
                break;
        }
    }
    HAL_TIM_GenerateEvent(&htim1, TIM_EVENTSOURCE_COM);
    update = 0;
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (update++ > 1)
    {
        update = 0;
        hall_disable();
        stop_pwm_output();
    }
}
