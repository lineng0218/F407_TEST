//
// Created by uoc11 on 2023/10/20.
//
#include "bsp_DRV8303.h"

uint16_t WtiteWord1=DRV8303_Write_Mode|DRV8303_Control_Reg1|DRV8303_GATE_CURRENT_0_25|DRV8303_GATE_RESET_Normal
                    |DRV8303_PWM_MODE_6|DRV8303_OCP_MODE_OC_Latch_Shut_Down|DRV8303_OC_ADJ_SET_0_060;

uint16_t WtiteWord2=DRV8303_Write_Mode|DRV8303_Control_Reg2|DRV8303_OCTW_MODE_Report_OT_OC|DRV8303_GAIN_40
                    |DRV8303_DC_CAL_CH1_A1_INPUT|DRV8303_DC_CAL_CH2_A2_INPUT|DRV8303_OC_TOFF_Cycle_by_Cycle;

uint16_t ReadReg=DRV8303_Read_Mode|DRV8303_Control_Reg1;

uint16_t Re_vaule1=0;
uint16_t Re_vaule2=0;
uint16_t Re_vaule3=0;
uint16_t Re_vaule4=0;

/** DRv8303的SPI初始化以及使能*/
static void DRV8303_SPI_Init(void)
{

    MX_GPIO_Init();

    MX_SPI1_Init();
    MX_SPI3_Init();

    __HAL_SPI_ENABLE(&hspi1);
    __HAL_SPI_ENABLE(&hspi3);
}
/** DRv8303的设置参数*/
void DRV8303_Init(void)
{

    DRV8303_SPI_Init();

    DRV8303_EN_GATE1_High();
    DRV8303_EN_GATE2_High();
    HAL_Delay(500);
    /** 写入DRv8303_1的控制寄存器1和控制寄存器2*/
    DRV8303_ReadWrite(DRV8303_1,WtiteWord1);
    DRV8303_ReadWrite(DRV8303_1,WtiteWord2);
    /** 写入DRv8303_2的控制寄存器1和控制寄存器2*/
    DRV8303_ReadWrite(DRV8303_2,WtiteWord1);
    DRV8303_ReadWrite(DRV8303_2,WtiteWord2);
    /** 读取DRv8303_1和DRv8303_2的控制寄存器1*/
    ReadReg=DRV8303_Read_Mode|DRV8303_Control_Reg1;
    Re_vaule1=DRV8303_ReadWrite(DRV8303_1,ReadReg);
    Re_vaule2=DRV8303_ReadWrite(DRV8303_2,ReadReg);
    /** 读取DRv8303_1和DRv8303_2的控制寄存器2*/
    ReadReg=DRV8303_Read_Mode|DRV8303_Control_Reg2;
    Re_vaule3=DRV8303_ReadWrite(DRV8303_1,ReadReg);
    Re_vaule4=DRV8303_ReadWrite(DRV8303_2,ReadReg);

}