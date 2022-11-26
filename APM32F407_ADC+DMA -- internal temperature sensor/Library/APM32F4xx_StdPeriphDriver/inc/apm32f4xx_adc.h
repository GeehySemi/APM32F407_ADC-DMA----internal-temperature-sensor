/*!
 * @file        apm32f4xx_adc.h
 *
 * @brief       This file contains all the functions prototypes for the ADC firmware library
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

#ifndef __APM32F4XX_ADC_H
#define __APM32F4XX_ADC_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup ADC_Driver ADC Driver
  @{
*/

/** @addtogroup ADC_Enumerations Enumerations
  @{
*/

/**
 * @brief ADC Common mode
 */
typedef enum
{
    /** All the ADCs independent */
    ADC_MODE_INDEPENDENT                  = (uint8_t)0x00, //!< Independent mode

    /** ADC1 and ADC2 working together but ADC3 is independent */
    ADC_MODE_DUAL_REGSIMULT_INJECSIMULT = (uint8_t)0x01, //!< regular simultaneous + injected simultaneous
    ADC_MODE_DUAL_REGSIMULT_ALTERTRIG   = (uint8_t)0x02, //!< regular simultaneous + alternate trigger
    ADC_MODE_DUAL_INJECSIMULT           = (uint8_t)0x05, //!< Injected simultaneous mode only
    ADC_MODE_DUAL_REGSIMULT             = (uint8_t)0x06, //!< Regular simultaneous mode only
    ADC_MODE_DUAL_INTERL                = (uint8_t)0x07, //!< Interleaved mode only
    ADC_MODE_DUAL_ALTERTRIG             = (uint8_t)0x09, //!< Alternate trigger mode only

    /** ADC1, ADC2 and ADC3 working together */
    ADC_MODE_TRIPLE_REGSIMULT_INJECSIMULT = (uint8_t)0x11, //!< regular simultaneous + injected simultaneous
    ADC_MODE_TRIPLE_REGSIMULT_ALTERTRIG   = (uint8_t)0x12, //!< regular simultaneous + alternate trigger
    ADC_MODE_TRIPLE_INJECSIMULT           = (uint8_t)0x15, //!< Injected simultaneous mode only
    ADC_MODE_TRIPLE_REGSIMULT             = (uint8_t)0x16, //!< Regular simultaneous mode only
    ADC_MODE_TRIPLE_INTERL                = (uint8_t)0x17, //!< Interleaved mode only
    ADC_MODE_TRIPLE_ALTERTRIG             = (uint8_t)0x19  //!< Alternate trigger mode only
} ADC_MODE_T;

/**
 * @brief ADC Prescaler
 */
typedef enum
{
    ADC_PRESCALER_DIV2,
    ADC_PRESCALER_DIV4,
    ADC_PRESCALER_DIV6,
    ADC_PRESCALER_DIV8
} ADC_PRESCALER_T;

/**
 * @brief ADC Direct memory access mode for multi mode
 */
typedef enum
{
    ADC_ACCESS_MODE_DISABLED, //!< DMA mode disabled
    ADC_ACCESS_MODE_1,        //!< DMA mode 1 enabled (2/3 half-words one by one - 1 then 2 then 3)
    ADC_ACCESS_MODE_2,        //!< DMA mode 2 enabled (2/3 half-words by pairs - 2&1 then 1&3 then 3&2)
    ADC_ACCESS_MODE_3         //!< DMA mode 3 enabled (2/3 bytes by pairs - 2&1 then 1&3 then 3&2)
} ADC_ACCESS_MODE_T;

/**
 * @brief ADC Delay between 2 sampling phases
 */
typedef enum
{
    ADC_TWO_SAMPLING_5CYCLES,
    ADC_TWO_SAMPLING_6CYCLES,
    ADC_TWO_SAMPLING_7CYCLES,
    ADC_TWO_SAMPLING_8CYCLES,
    ADC_TWO_SAMPLING_9CYCLES,
    ADC_TWO_SAMPLING_10CYCLES,
    ADC_TWO_SAMPLING_11CYCLES,
    ADC_TWO_SAMPLING_12CYCLES,
    ADC_TWO_SAMPLING_13CYCLES,
    ADC_TWO_SAMPLING_14CYCLES,
    ADC_TWO_SAMPLING_15CYCLES,
    ADC_TWO_SAMPLING_16CYCLES,
    ADC_TWO_SAMPLING_17CYCLES,
    ADC_TWO_SAMPLING_18CYCLES,
    ADC_TWO_SAMPLING_19CYCLES,
    ADC_TWO_SAMPLING_20CYCLES
} ADC_TWO_SAMPLING_T;

/**
 * @brief ADC_resolution
 */
typedef enum
{
    ADC_RESOLUTION_12BIT, //!< ADC Resolution is 12 bits
    ADC_RESOLUTION_10BIT, //!< ADC Resolution is 10 bits
    ADC_RESOLUTION_8BIT,  //!< ADC Resolution is 8 bits
    ADC_RESOLUTION_6BIT   //!< ADC Resolution is 6 bits
} ADC_RESOLUTION_T;

/**
 * @brief ADC External trigger edge for regular channels conversion
 */
typedef enum
{
    ADC_EXT_TRIG_EDGE_NONE,
    ADC_EXT_TRIG_EDGE_RISING,
    ADC_EXT_TRIG_EDGE_FALLING,
    ADC_EXT_TRIG_EDGE_RISING_FALLING,
} ADC_EXT_TRIG_EDGE_T;

/**
 * @brief ADC External event trigger select for regular group
 */
typedef enum
{
    ADC_EXT_TRIG_CONV_TMR1_CC1,
    ADC_EXT_TRIG_CONV_TMR1_CC2,
    ADC_EXT_TRIG_CONV_TMR1_CC3,
    ADC_EXT_TRIG_CONV_TMR2_CC2,
    ADC_EXT_TRIG_CONV_TMR2_CC3,
    ADC_EXT_TRIG_CONV_TMR2_CC4,
    ADC_EXT_TRIG_CONV_TMR2_TRGO,
    ADC_EXT_TRIG_CONV_TMR3_CC1,
    ADC_EXT_TRIG_CONV_TMR3_TRGO,
    ADC_EXT_TRIG_CONV_TMR4_CC4,
    ADC_EXT_TRIG_CONV_TMR5_CC1,
    ADC_EXT_TRIG_CONV_TMR5_CC2,
    ADC_EXT_TRIG_CONV_TMR5_CC3,
    ADC_EXT_TRIG_CONV_TMR8_CC1,
    ADC_EXT_TRIG_CONV_TMR8_TRGO,
    ADC_EXT_TRIG_CONV_EINT_11
} ADC_EXT_TRIG_CONV_T;

/**
 * @brief ADC Data align
 */
typedef enum
{
    ADC_DATA_ALIGN_RIGHT,
    ADC_DATA_ALIGN_LEFT
} ADC_DATA_ALIGN_T;

/**
 * @brief ADC Channel number
 */
typedef enum
{
    ADC_CHANNEL_0,  //!< ADC Channel 0
    ADC_CHANNEL_1,  //!< ADC Channel 1
    ADC_CHANNEL_2,  //!< ADC Channel 2
    ADC_CHANNEL_3,  //!< ADC Channel 3
    ADC_CHANNEL_4,  //!< ADC Channel 4
    ADC_CHANNEL_5,  //!< ADC Channel 5
    ADC_CHANNEL_6,  //!< ADC Channel 6
    ADC_CHANNEL_7,  //!< ADC Channel 7
    ADC_CHANNEL_8,  //!< ADC Channel 8
    ADC_CHANNEL_9,  //!< ADC Channel 9
    ADC_CHANNEL_10, //!< ADC Channel 10
    ADC_CHANNEL_11, //!< ADC Channel 11
    ADC_CHANNEL_12, //!< ADC Channel 12
    ADC_CHANNEL_13, //!< ADC Channel 13
    ADC_CHANNEL_14, //!< ADC Channel 14
    ADC_CHANNEL_15, //!< ADC Channel 15
    ADC_CHANNEL_16, //!< ADC Channel 16
    ADC_CHANNEL_17, //!< ADC Channel 17
    ADC_CHANNEL_18, //!< ADC Channel 18
} ADC_CHANNEL_T;

/**
 * @brief ADC_sampling_times
 */
typedef enum
{
    ADC_SAMPLETIME_3CYCLES,
    ADC_SAMPLETIME_15CYCLES,
    ADC_SAMPLETIME_28CYCLES,
    ADC_SAMPLETIME_56CYCLES,
    ADC_SAMPLETIME_84CYCLES,
    ADC_SAMPLETIME_112CYCLES,
    ADC_SAMPLETIME_144CYCLES,
    ADC_SAMPLETIME_480CYCLES
} ADC_SAMPLETIME_T;

/**
 * @brief ADC external trigger edge for injected channels conversion
 */
typedef enum
{
    ADC_EXT_TRIG_INJEC_EDGE_NONE,
    ADC_EXT_TRIG_INJEC_EDGE_RISING,
    ADC_EXT_TRIG_INJEC_EDGE_FALLING,
    ADC_EXT_TRIG_INJEC_EDGE_RISING_FALLING
} ADC_EXT_TRIG_INJEC_EDGE_T;

/**
 * @brief ADC extrenal trigger sources for injected channels conversion
 */
typedef enum
{
    ADC_EXT_TRIG_INJEC_CONV_TMR1_CC4,
    ADC_EXT_TRIG_INJEC_CONV_TMR1_TRGO,
    ADC_EXT_TRIG_INJEC_CONV_TMR2_CC1,
    ADC_EXT_TRIG_INJEC_CONV_TMR2_TRGO,
    ADC_EXT_TRIG_INJEC_CONV_TMR3_CC2,
    ADC_EXT_TRIG_INJEC_CONV_TMR3_CC4,
    ADC_EXT_TRIG_INJEC_CONV_TMR4_CC1,
    ADC_EXT_TRIG_INJEC_CONV_TMR4_CC2,
    ADC_EXT_TRIG_INJEC_CONV_TMR4_CC3,
    ADC_EXT_TRIG_INJEC_CONV_TMR4_TRGO,
    ADC_EXT_TRIG_INJEC_CONV_TMR5_CC4,
    ADC_EXT_TRIG_INJEC_CONV_TMR5_TRGO,
    ADC_EXT_TRIG_INJEC_CONV_TMR8_CC2,
    ADC_EXT_TRIG_INJEC_CONV_TMR8_CC3,
    ADC_EXT_TRIG_INJEC_CONV_TMR8_CC4,
    ADC_EXT_TRIG_INJEC_CONV_EINT15
} ADC_EXT_TRIG_INJEC_CONV_T;

/**
 * @brief ADC injected channel selection
 */
typedef enum
{
    ADC_INJEC_CHANNEL_1 = (uint8_t)0x01,
    ADC_INJEC_CHANNEL_2 = (uint8_t)0x02,
    ADC_INJEC_CHANNEL_3 = (uint8_t)0x03,
    ADC_INJEC_CHANNEL_4 = (uint8_t)0x04
} ADC_INJEC_CHANNEL_T;

/**
 * @brief ADC analog watchdog selection
 */
typedef enum
{
    ADC_ANALOG_WATCHDOG_SINGLE_INJEC      = (uint8_t)0x11,
    ADC_ANALOG_WATCHDOG_SINGLE_REG        = (uint8_t)0x12,
    ADC_ANALOG_WATCHDOG_SINGLE_REG_INJEC  = (uint8_t)0x13,
    ADC_ANALOG_WATCHDOG_ALL_INJEC         = (uint8_t)0x01,
    ADC_ANALOG_WATCHDOG_ALL_REG           = (uint8_t)0x02,
    ADC_ANALOG_WATCHDOG_ALL_REG_ALL_INJEC = (uint8_t)0x03,
    ADC_ANALOG_WATCHDOG_NONE              = (uint8_t)0x00
} ADC_ANALOG_WATCHDOG_T;

/**
 * @brief ADC interrupts
 */
typedef enum
{
    ADC_INT_EOC         = BIT5,
    ADC_INT_AWD         = BIT6,
    ADC_INT_INJEOC      = BIT7,
    ADC_INT_OVR         = BIT26
} ADC_INT_T;

/**
 * @brief ADC interrupt flags
 */
typedef enum
{
    ADC_INT_FLAG_AWD    = 0x0501,
    ADC_INT_FLAG_EOC    = 0x0602,
    ADC_INT_FLAG_INJEOC = 0x0704,
    ADC_INT_FLAG_OVR    = 0x1A20
} ADC_INT_FLAG_T;

/**
 * @brief ADC status flags
 */
typedef enum
{
    ADC_FLAG_AWD        = BIT0,
    ADC_FLAG_EOC        = BIT1,
    ADC_FLAG_INJEOC     = BIT2,
    ADC_FLAG_INJCS      = BIT3,
    ADC_FLAG_REGCS      = BIT4,
    ADC_FLAG_OVR        = BIT5
} ADC_FLAG_T;

/**@} end of group ADC_Enumerations*/

/** @addtogroup ADC_Structure Data Structure
  @{
*/

/**
 * @brief ADC configuration Mode
 */
typedef struct
{
    ADC_RESOLUTION_T    resolution;
    uint8_t             scanConvMode;       //!< This value can be ENABLE or DISABLE
    uint8_t             continuousConvMode; //!< This value can be ENABLE or DISABLE
    ADC_EXT_TRIG_EDGE_T extTrigEdge;
    ADC_EXT_TRIG_CONV_T extTrigConv;
    ADC_DATA_ALIGN_T    dataAlign;
    uint8_t             nbrOfChannel; //!< regular channel sequence length can be from 1 to 16
} ADC_Config_T;

/**
 * @brief ADC Common Init structure definition
 */
typedef struct
{
    ADC_MODE_T         mode;
    ADC_PRESCALER_T    prescaler;
    ADC_ACCESS_MODE_T  accessMode;
    ADC_TWO_SAMPLING_T twoSampling;
} ADC_CommonConfig_T;

/**@} end of group ADC_Structure*/

/** @addtogroup ADC_Fuctions Fuctions
  @{
*/

/** ADC Reset */
void ADC_Reset(void);

/** Configuration */
void ADC_Config(ADC_T* adc, ADC_Config_T* adcConfig);
void ADC_ConfigStructInit(ADC_Config_T* adcConfig);
void ADC_CommonConfig(ADC_CommonConfig_T* adcCommonConfig);
void ADC_CommonConfigStructInit(ADC_CommonConfig_T* adcCommonConfig);
void ADC_Enable(ADC_T* adc);
void ADC_Disable(ADC_T* adc);

/** Analog Watchdog */
void ADC_EnableAnalogWatchdog(ADC_T* adc, ADC_ANALOG_WATCHDOG_T analogWatchdog);
void ADC_DisableAnalogWatchdog(ADC_T* adc);
void ADC_ConfigAnalogWatchdogThresholds(ADC_T* adc, uint16_t highThreshold, uint16_t lowThreshold);
void ADC_ConfigAnalogWatchdogSingleChannel(ADC_T* adc, uint8_t channel);

/** Temperature Sensor, Vrefint and VBAT management **/
void ADC_EnableTempSensorVrefint(void);
void ADC_DisableTempSensorVrefint(void);
void ADC_EnableVbat(void);
void ADC_DisableVbat(void);

/** Regular Channels Configuration */
void ADC_ConfigRegularChannel(ADC_T* adc, uint8_t channel,
                              uint8_t rank, uint8_t sampleTime);
void ADC_SoftwareStartConv(ADC_T* adc);
uint8_t ADC_ReadSoftwareStartConvStatus(ADC_T* adc);

void ADC_EnableEOCOnEachChannel(ADC_T* adc);
void ADC_DisableEOCOnEachChannel(ADC_T* adc);

/** Continuous Mode */
void ADC_EnableContinuousMode(ADC_T* adc);
void ADC_DisableContinuousMode(ADC_T* adc);

/** Discontinuous Mode */
void ADC_ConfigDiscMode(ADC_T* adc, uint8_t number);
void ADC_EnableDiscMode(ADC_T* adc);
void ADC_DisableDiscMode(ADC_T* adc);

uint16_t ADC_ReadConversionValue(ADC_T* adc);
uint32_t ADC_ReadMultiValue(void);

/** Regular Channels DMA */
void ADC_EnableDMA(ADC_T* adc);
void ADC_DisableDMA(ADC_T* adc);

void ADC_EnableDMARequest(ADC_T* adc);
void ADC_DisableDMARequest(ADC_T* adc);

void ADC_EnableMultiModeDMARequest(void);
void ADC_DisableMultiModeDMARequest(void);

/** Injected channels Configuration functions */
void ADC_ConfigInjectedChannel(ADC_T* adc, uint8_t channel, uint8_t rank,
                               uint8_t sampleTime);
void ADC_ConfigInjectedSequencerLength(ADC_T* adc, uint8_t length);
void ADC_ConfigInjectedOffset(ADC_T* adc, ADC_INJEC_CHANNEL_T channel, uint16_t offset);
void ADC_ConfigExternalTrigInjectedConv(ADC_T* adc, ADC_EXT_TRIG_INJEC_CONV_T extTrigInjecConv);
void ADC_ConfigExternalTrigInjectedConvEdge(ADC_T* adc, ADC_EXT_TRIG_INJEC_EDGE_T extTrigInjecConvEdge);
void ADC_EnableSoftwareStartInjectedConv(ADC_T* adc);
uint8_t ADC_ReadSoftwareStartInjectedConvStatus(ADC_T* adc);
void ADC_EnableAutoInjectedConv(ADC_T* adc);
void ADC_DisableAutoInjectedConv(ADC_T* adc);
void ADC_EnableInjectedDiscMode(ADC_T* adc);
void ADC_DisableInjectedDiscMode(ADC_T* adc);
uint16_t ADC_ReadInjectedConversionValue(ADC_T* adc, ADC_INJEC_CHANNEL_T channel);

/** Interrupts and flags */
void ADC_EnableInterrupt(ADC_T* adc, uint32_t interrupt);
void ADC_DisableInterrupt(ADC_T* adc, uint32_t interrupt);
uint8_t ADC_ReadStatusFlag(ADC_T* adc,  ADC_FLAG_T flag);
void ADC_ClearStatusFlag(ADC_T* adc, uint32_t flag);
uint16_t ADC_ReadIntFlag(ADC_T* adc, ADC_INT_FLAG_T flag);
void ADC_ClearIntFlag(ADC_T* adc, uint32_t flag);

/**@} end of group ADC_Fuctions*/
/**@} end of group ADC_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /** __APM32F4XX_ADC_H */
