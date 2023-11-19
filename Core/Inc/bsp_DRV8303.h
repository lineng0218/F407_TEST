#ifndef F407_TEST_8303_H
#define F407_TEST_8303_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal.h"
#include "spi.h"

#define DRV8303_1                                           SPI1
#define DRV8303_2                                           SPI3

/** 寄存器读写模式 */
#define DRV8303_Write_Mode                                  ((uint16_t)0x0000<<15)
#define DRV8303_Read_Mode                                   ((uint16_t)0x0001<<15)
/** 寄存器地址设置 */
#define DRV8303_Status_Reg1                                 ((uint16_t)0x0000<<11)
#define DRV8303_Status_Reg2                                 ((uint16_t)0x0001<<11)
#define DRV8303_Control_Reg1                                ((uint16_t)0x0002<<11)
#define DRV8303_Control_Reg2                                ((uint16_t)0x0003<<11)

/** 控制寄存器1参数 */
#define DRV8303_GATE_CURRENT_1_7                            ((uint16_t)0x0000)
#define DRV8303_GATE_CURRENT_0_7                            ((uint16_t)0x0001)
#define DRV8303_GATE_CURRENT_0_25                           ((uint16_t)0x0002)
#define DRV8303_GATE_CURRENT_Res                            ((uint16_t)0x0003)

#define DRV8303_GATE_RESET_Normal                           ((uint16_t)0x0000<<2)
#define DRV8303_GATE_RESET_R                            ((uint16_t)0x0001<<2)

#define DRV8303_PWM_MODE_6                                  ((uint16_t)0x0000<<3)
#define DRV8303_PWM_MODE_3                                  ((uint16_t)0x0001<<3)

#define DRV8303_OCP_MODE_Current_limit                      ((uint16_t)0x0000<<4)
#define DRV8303_OCP_MODE_OC_Latch_Shut_Down                 ((uint16_t)0x0001<<4)
#define DRV8303_OCP_MODE_Report_Only                        ((uint16_t)0x0002<<4)
#define DRV8303_OCP_MODE_OC_Disabled                        ((uint16_t)0x0003<<4)

#define DRV8303_OC_ADJ_SET_0_060                            ((uint16_t)0x0000<<6)
#define DRV8303_OC_ADJ_SET_0_068                            ((uint16_t)0x0001<<6)
#define DRV8303_OC_ADJ_SET_0_076                            ((uint16_t)0x0002<<6)
#define DRV8303_OC_ADJ_SET_0_086                            ((uint16_t)0x0003<<6)
#define DRV8303_OC_ADJ_SET_0_097                            ((uint16_t)0x0004<<6)
#define DRV8303_OC_ADJ_SET_0_109                            ((uint16_t)0x0005<<6)
#define DRV8303_OC_ADJ_SET_0_123                            ((uint16_t)0x0006<<6)
#define DRV8303_OC_ADJ_SET_0_138                            ((uint16_t)0x0007<<6)
#define DRV8303_OC_ADJ_SET_0_155                            ((uint16_t)0x0010<<6)
#define DRV8303_OC_ADJ_SET_0_175                            ((uint16_t)0x0011<<6)
#define DRV8303_OC_ADJ_SET_0_197                            ((uint16_t)0x0012<<6)
#define DRV8303_OC_ADJ_SET_0_222                            ((uint16_t)0x0013<<6)
#define DRV8303_OC_ADJ_SET_0_250                            ((uint16_t)0x0014<<6)
#define DRV8303_OC_ADJ_SET_0_282                            ((uint16_t)0x0015<<6)
#define DRV8303_OC_ADJ_SET_0_317                            ((uint16_t)0x0016<<6)
#define DRV8303_OC_ADJ_SET_0_358                            ((uint16_t)0x0017<<6)
#define DRV8303_OC_ADJ_SET_0_403                            ((uint16_t)0x0020<<6)
#define DRV8303_OC_ADJ_SET_0_454                            ((uint16_t)0x0021<<6)
#define DRV8303_OC_ADJ_SET_0_511                            ((uint16_t)0x0022<<6)
#define DRV8303_OC_ADJ_SET_0_576                            ((uint16_t)0x0023<<6)
#define DRV8303_OC_ADJ_SET_0_648                            ((uint16_t)0x0024<<6)
#define DRV8303_OC_ADJ_SET_0_730                            ((uint16_t)0x0025<<6)
#define DRV8303_OC_ADJ_SET_0_822                            ((uint16_t)0x0026<<6)
#define DRV8303_OC_ADJ_SET_0_926                            ((uint16_t)0x0027<<6)

/** 控制寄存器2参数设置 */
#define DRV8303_OCTW_MODE_Report_OT_OC                      ((uint16_t)0x0000)
#define DRV8303_OCTW_MODE_Report_OT                         ((uint16_t)0x0001)
#define DRV8303_OCTW_MODE_Report_OC                         ((uint16_t)0x0002)
#define DRV8303_OCTW_MODE_Report_OC_r                    ((uint16_t)0x0003)

#define DRV8303_GAIN_10                                     ((uint16_t)0x0000<<2)
#define DRV8303_GAIN_20                                     ((uint16_t)0x0001<<2)
#define DRV8303_GAIN_40                                     ((uint16_t)0x0002<<2)
#define DRV8303_GAIN_80                                     ((uint16_t)0x0003<<2)

#define DRV8303_DC_CAL_CH1_A1_INPUT                         ((uint16_t)0x0000<<4)
#define DRV8303_DC_CAL_CH1_A1_Short_INPUT                   ((uint16_t)0x0001<<4)

#define DRV8303_DC_CAL_CH2_A2_INPUT                         ((uint16_t)0x0000<<5)
#define DRV8303_DC_CAL_CH2_A2_Short_INPUT                   ((uint16_t)0x0001<<5)

#define DRV8303_OC_TOFF_Cycle_by_Cycle                      ((uint16_t)0x0000<<6)
#define DRV8303_OC_TOFF_Off_Time_C                           ((uint16_t)0x0001<<6)
/** DRV8303使能引脚*/
#define DRV8303_EN_GATE1_GPIO_PIN                            GPIO_PIN_8
#define DRV8303_EN_GATE1_GPIO_PORT                           GPIOD
#define DRV8303_EN_GATE1_GPIO_ENABLE()                       __HAL_RCC_GPIOD_CLK_ENABLE()

#define DRV8303_EN_GATE2_GPIO_PIN                            GPIO_PIN_2
#define DRV8303_EN_GATE2_GPIO_PORT                           GPIOE
#define DRV8303_EN_GATE2_GPIO_ENABLE()                       __HAL_RCC_GPIOE_CLK_ENABLE()
/** DRV8303的SPI片选*/
#define DRV8303_SPI1_NSS_LOW()    HAL_GPIO_WritePin(GPIOA, SPI1_NSS_Pin, GPIO_PIN_RESET);
#define DRV8303_SPI1_NSS_High()   HAL_GPIO_WritePin(GPIOA, SPI1_NSS_Pin, GPIO_PIN_SET);

#define DRV8303_SPI3_NSS_LOW()    HAL_GPIO_WritePin(GPIOA, SPI3_NSS_Pin, GPIO_PIN_RESET);
#define DRV8303_SPI3_NSS_High()   HAL_GPIO_WritePin(GPIOA, SPI3_NSS_Pin, GPIO_PIN_SET);

#define  DRV8303_SPI_NSS_High()    HAL_GPIO_WritePin(GPIOA, SPI3_NSS_GPIO_PIN|SPI1_NSS_GPIO_PIN, GPIO_PIN_SET);
#define  DRV8303_SPI_NSS_LOW()     HAL_GPIO_WritePin(GPIOA, SPI3_NSS_GPIO_PIN|SPI1_NSS_GPIO_PIN, GPIO_PIN_RESET);

/** DRV8303使能*/
#define DRV8303_EN_GATE2_LOW()    HAL_GPIO_WritePin(DRV8303_EN_GATE2_GPIO_PORT ,DRV8303_EN_GATE2_GPIO_PIN , GPIO_PIN_RESET);
#define DRV8303_EN_GATE2_High()    HAL_GPIO_WritePin(DRV8303_EN_GATE2_GPIO_PORT ,DRV8303_EN_GATE2_GPIO_PIN , GPIO_PIN_SET);

#define DRV8303_EN_GATE1_LOW()    HAL_GPIO_WritePin(DRV8303_EN_GATE1_GPIO_PORT,DRV8303_EN_GATE1_GPIO_PIN , GPIO_PIN_RESET);
#define DRV8303_EN_GATE1_High()    HAL_GPIO_WritePin(DRV8303_EN_GATE1_GPIO_PORT,DRV8303_EN_GATE1_GPIO_PIN , GPIO_PIN_SET);

#define SPIT_FLAG_TIMEOUT              0x1000

void DRV8303_Init(void);

#endif //F407_TEST_8303_H
