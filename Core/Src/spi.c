#include "spi.h"

SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi3;

/* SPI1 init function */
void MX_SPI1_Init(void)
{

    SPI1_SPI_CLK_ENABLE();

    hspi1.Instance = SPI1_SPI;
    hspi1.Init.Mode = SPI_MODE_MASTER;
    hspi1.Init.Direction = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
    hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi1.Init.NSS = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi1.Init.CRCPolynomial = 7;

    HAL_SPI_Init(&hspi1);
    __HAL_SPI_ENABLE(&hspi1);

}
/* SPI3 init function */
void MX_SPI3_Init(void)
{


    SPI3_SPI_CLK_ENABLE();

    hspi3.Instance = SPI3_SPI;
    hspi3.Init.Mode = SPI_MODE_MASTER;
    hspi3.Init.Direction = SPI_DIRECTION_2LINES;
    hspi3.Init.DataSize = SPI_DATASIZE_16BIT;
    hspi3.Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi3.Init.NSS = SPI_NSS_SOFT;
    hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
    hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
    hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi3.Init.CRCPolynomial = 7;

    HAL_SPI_Init(&hspi3);
    __HAL_SPI_ENABLE(&hspi3);

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(spiHandle->Instance==SPI1)
    {
        SPI1_SPI_CLK_ENABLE();
        SPI1_SCK_GPIO_CLK_ENABLE();
        SPI1_MISO_GPIO_CLK_ENABLE();
        SPI1_MOSI_GPIO_CLK_ENABLE();


        GPIO_InitStruct.Pin = SPI1_SCK_GPIO_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(SPI1_SCK_GPIO_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI1_MISO_GPIO_PIN;
        HAL_GPIO_Init(SPI1_MISO_GPIO_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = SPI1_MOSI_GPIO_PIN;
        HAL_GPIO_Init(SPI1_MOSI_GPIO_PORT, &GPIO_InitStruct);

    }
    else if(spiHandle->Instance==SPI3)
    {

        SPI3_SPI_CLK_ENABLE();
        SPI3_SCK_GPIO_CLK_ENABLE();
        SPI3_MISO_GPIO_CLK_ENABLE();
        SPI3_MOSI_GPIO_CLK_ENABLE();

        GPIO_InitStruct.Pin =SPI3_SCK_GPIO_PIN;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
        HAL_GPIO_Init(SPI3_SCK_GPIO_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin =SPI3_MISO_GPIO_PIN;
        HAL_GPIO_Init(SPI3_MISO_GPIO_PORT, &GPIO_InitStruct);

        GPIO_InitStruct.Pin =SPI3_MOSI_GPIO_PIN;
        HAL_GPIO_Init(SPI3_MOSI_GPIO_PORT, &GPIO_InitStruct);
    }
}

void SPI_NSS_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    SPI1_NSS_GPIO_CLK_ENABLE();
    SPI3_NSS_GPIO_CLK_ENABLE();

    HAL_GPIO_WritePin(SPI1_NSS_GPIO_PORT, SPI1_NSS_GPIO_PIN , GPIO_PIN_SET);
    HAL_GPIO_WritePin(SPI3_NSS_GPIO_PORT, SPI3_NSS_GPIO_PIN , GPIO_PIN_SET);

    GPIO_InitStruct.Pin = SPI1_NSS_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(SPI1_NSS_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = SPI3_NSS_GPIO_PIN;
    HAL_GPIO_Init(SPI3_NSS_GPIO_PORT, &GPIO_InitStruct);
}

FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
    FlagStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH_EXT(SPIx));
    assert_param(IS_SPI_I2S_GET_FLAG(SPI_I2S_FLAG));

    /* Check the status of the specified SPI flag */
    if ((SPIx->SR & SPI_I2S_FLAG) != (uint16_t)RESET)
    {
        /* SPI_I2S_FLAG is set */
        bitstatus = SET;
    }
    else
    {
        /* SPI_I2S_FLAG is reset */
        bitstatus = RESET;
    }
    /* Return the SPI_I2S_FLAG status */
    return  bitstatus;
}

static void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
{
    assert_param(IS_SPI_ALL_PERIPH_EXT(SPIx));
    SPIx->DR = Data;
}

static uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
{
    assert_param(IS_SPI_ALL_PERIPH_EXT(SPIx));
    return SPIx->DR;
}

static uint16_t SPI_ReadWriteByte(SPI_TypeDef* SPIx,uint16_t TxData)
{
    uint16_t re_Data;
    /** 等待TXE标志，TXE=1，发送数据到发送缓冲区*/
    while( SPI_I2S_GetFlagStatus(SPIx,SPI_FLAG_TXE) == RESET){}
    SPI_I2S_SendData(SPIx,TxData);
    /** 等待RXNE标志，RXNE=1，发送数据到接收缓冲区*/
    while( SPI_I2S_GetFlagStatus(SPIx,SPI_FLAG_RXNE) == RESET){}
    re_Data=SPI_I2S_ReceiveData(SPIx);
    return re_Data;
}

uint16_t DRV8303_ReadWrite(SPI_TypeDef* SPIx,uint16_t TxData)
{

    uint16_t Data;
    DRV8303_SPI_NSS_LOW()
    SPI_ReadWriteByte(SPIx,TxData);
    DRV8303_SPI_NSS_High()
    HAL_Delay(10);
    DRV8303_SPI_NSS_LOW()
    Data = SPI_ReadWriteByte(SPIx,TxData);
    DRV8303_SPI_NSS_High()
    return Data;
}