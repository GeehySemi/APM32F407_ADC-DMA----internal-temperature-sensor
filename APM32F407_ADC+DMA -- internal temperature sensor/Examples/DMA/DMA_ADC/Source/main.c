/*!
 * @file       main.c
 *
 * @brief      Main program body
 *
 * @version     V1.0.1
 *
 * @date        2022-02-25
 *
 * @attention
 *
 *  Copyright (C) 2021-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be usefull and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

#include "main.h"
#include "stdio.h"
#include "Board.h"
#include "apm32f4xx_dma.h"
#include "apm32f4xx_adc.h"

/** printf function configs to USART1*/
#define DEBUG_USART  USART1

/** define Tramismit Buf Size*/
#define BufSize 0x100

/** Delay */
void Delay(uint32_t count);
/** ADC Init */
void ADC_Init(void);
/** DMA Init */
void DMA_Init(uint32_t* Buf);

/*!
 * @brief       Main program
 *
 * @param       None
 *
 * @retval      None
 */
int main(void)
{
    USART_Config_T usartConfigStruct;

    /** USART configuration */
    USART_ConfigStructInit(&usartConfigStruct);
    usartConfigStruct.baudRate = 115200;
    usartConfigStruct.mode = USART_MODE_TX_RX;
    usartConfigStruct.parity = USART_PARITY_NONE;
    usartConfigStruct.stopBits = USART_STOP_BIT_1;
    usartConfigStruct.wordLength = USART_WORD_LEN_8B;
    usartConfigStruct.hardwareFlow = USART_HARDWARE_FLOW_NONE;

    /** COM1 init*/
    APM_MINI_COMInit(COM1, &usartConfigStruct);

    /** DMA value from ADC*/
    uint32_t DMA_ConvertedValue = 0;
    /** ADC convert to volatage*/
    float ADC_ConvertedValue = 0;
    float Temperature = 0;

    ADC_Init();
    DMA_Init(&DMA_ConvertedValue);

    while (1)
    {
        if (DMA_ReadStatusFlag(DMA2_Stream0, DMA_FLAG_TCIFLG0))
        {
            ADC_ConvertedValue = (float)DMA_ConvertedValue/4096*3.3;
						Temperature = (ADC_ConvertedValue-0.76)/0.0025+25;
						printf("Temperature:%.2f¡æ\r\n",Temperature);	
            Delay(0xFFFFFF);
            DMA_ClearStatusFlag(DMA2_Stream0, DMA_FLAG_TCIFLG0);

        }
    }
}

/*!
 * @brief       ADC Init
 *
 * @param       None
 *
 * @retval      None
 */
void ADC_Init(void)
{
    ADC_Config_T  adcConfig;

    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_ADC1);

    /** ADC Configuration */
    ADC_Reset();
    ADC_ConfigStructInit(&adcConfig);
    /** Set resolution*/
    adcConfig.resolution = ADC_RESOLUTION_12BIT;
    /** Set dataAlign*/
    adcConfig.dataAlign = ADC_DATA_ALIGN_RIGHT;
    /** Set scanDir*/
    adcConfig.scanConvMode = DISABLE;
    /** Set convMode continous*/
    adcConfig.continuousConvMode = ENABLE;
    /** Set extTrigEdge*/
    adcConfig.extTrigEdge = ADC_EXT_TRIG_EDGE_NONE;
    /** Set nbrOfConversion*/

    ADC_Config(ADC1, &adcConfig);

		/** Enables the temperature sensor and Vrefint channels*/
		ADC_EnableTempSensorVrefint(); 
    ADC_ConfigRegularChannel(ADC1, ADC_CHANNEL_16, 1, ADC_SAMPLETIME_480CYCLES);

    ADC_EnableDMA(ADC1);
    ADC_EnableDMARequest(ADC1);

    /** Enable ADC*/
    ADC_Enable(ADC1);
    ADC_SoftwareStartConv(ADC1);
}

/*!
 * @brief       DMA Init
 *
 * @param       None
 *
 * @retval      None
 */
void DMA_Init(uint32_t* Buf)
{
    /** DMA Configure */
    DMA_Config_T dmaConfig;

    /** Enable DMA clock */
    RCM_EnableAHB1PeriphClock(RCM_AHB1_PERIPH_DMA2);

    /** size of buffer*/
    dmaConfig.bufferSize = 1;
    /** set memory Data Size*/
    dmaConfig.memoryDataSize = DMA_MEMORY_DATA_SIZE_HALFWORD;
    /** Set peripheral Data Size*/
    dmaConfig.peripheralDataSize = DMA_PERIPHERAL_DATA_SIZE_HALFWORD;
    /** Enable Memory Address increase*/
    dmaConfig.memoryInc = DMA_MEMORY_INC_DISABLE;
    /** Disable Peripheral Address increase*/
    dmaConfig.peripheralInc = DMA_PERIPHERAL_INC_DISABLE;
    /** Reset Circular Mode*/
    dmaConfig.loopMode = DMA_MODE_CIRCULAR;
    /** set priority*/
    dmaConfig.priority = DMA_PRIORITY_HIGH;
    /** read from peripheral*/
    dmaConfig.dir = DMA_DIR_PERIPHERALTOMEMORY;
    /** Set memory Address*/
    dmaConfig.memoryBaseAddr = (uint32_t)Buf;
    /** Set Peripheral Address*/
    dmaConfig.peripheralBaseAddr = (uint32_t)&ADC1->REGDATA;

    dmaConfig.channel = DMA_CHANNEL_0;
    dmaConfig.fifoMode = DMA_FIFOMODE_DISABLE;
    dmaConfig.fifoThreshold = DMA_FIFOTHRESHOLD_FULL;
    dmaConfig.peripheralBurst = DMA_PERIPHERALBURST_SINGLE;
    dmaConfig.memoryBurst = DMA_MEMORYBURST_SINGLE; 

    DMA_Config(DMA2_Stream0, &dmaConfig);
    /** Clear DMA TF flag*/
    DMA_ClearIntFlag(DMA2_Stream0, DMA_INT_TCIFLG0);
    /** Enable DMA Interrupt*/
    DMA_EnableInterrupt(DMA2_Stream0, DMA_INT_TCIFLG);
    DMA_Enable(DMA2_Stream0);
}

/*!
 * @brief       Delay
 *
 * @param       count:  delay count
 *
 * @retval      None
 */
void Delay(uint32_t count)
{
    volatile uint32_t delay = count;

    while (delay--);
}

/*!
 * @brief       Redirect C Library function printf to serial port.
 *              After Redirection, you can use printf function.
 *
 * @param       ch:  The characters that need to be send.
 *
 * @param       *f:  pointer to a FILE that can recording all information
 *              needed to control a stream
 *
 * @retval      The characters that need to be send.
 */
int fputc(int ch, FILE* f)
{
    /** send a byte of data to the serial port */
    USART_TxData(DEBUG_USART, (uint8_t)ch);

    /** wait for the data to be send  */
    while (USART_ReadStatusFlag(DEBUG_USART, USART_FLAG_TXBE) == RESET);

    return (ch);
}
