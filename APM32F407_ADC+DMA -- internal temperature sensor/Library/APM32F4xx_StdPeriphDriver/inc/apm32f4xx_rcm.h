/*!
 * @file        apm32f4xx_rcm.h
 *
 * @brief       This file contains all the functions prototypes for the RCM firmware library
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

#ifndef __APM32F4XX_RCM_H
#define __APM32F4XX_RCM_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup RCM_Driver RCM Driver
  @{
*/

/** @addtogroup RCM_Enumerations Enumerations
  @{
*/

/**
 * @brief HSE state
 */
typedef enum
{
    RCM_HSE_CLOSE,    //!< CLOSE HSE
    RCM_HSE_OPEN,     //!< OPEN HSE
    RCM_HSE_BYPASS    //!< HSE BYPASS
} RCM_HSE_T;

/**
 * @brief LSE State
 */
typedef enum
{
    RCM_LSE_CLOSE,
    RCM_LSE_OPEN,
    RCM_LSE_BYPASS
} RCM_LSE_T;

/**
 * @brief RCM PLL source select
 */
typedef enum
{
    RCM_PLLSEL_HSI,
    RCM_PLLSEL_HSE
} RCM_PLLSEL_T;

/**
 * @brief RCM PLL System Division
 */
typedef enum
{
    RCM_PLL_SYS_DIV_2,
    RCM_PLL_SYS_DIV_4,
    RCM_PLL_SYS_DIV_6,
    RCM_PLL_SYS_DIV_8
} RCM_PLL_SYS_DIV_T;

/**
 * @brief RCM MCO1 Source Selece
 */
typedef enum
{
    RCM_MCO1_SEL_HSICLK,
    RCM_MCO1_SEL_LSECLK,
    RCM_MCO1_SEL_HSECLK,
    RCM_MCO1_SEL_PLLCLK
} RCM_MCO1_SEL_T;

/**
 * @brief RCM MCO1 Div
 */
typedef enum
{
    RCM_MCO1_DIV_1,
    RCM_MCO1_DIV_2 = 4,
    RCM_MCO1_DIV_3,
    RCM_MCO1_DIV_4,
    RCM_MCO1_DIV_5
} RCM_MCO1_DIV_T;

/**
 * @brief RCM MCO2 Source Selece
 */
typedef enum
{
    RCM_MCO2_SEL_SYSCLK,
    RCM_MCO2_SEL_PLL2CLK,
    RCM_MCO2_SEL_HSECLK,
    RCM_MCO2_SEL_PLLCLK
} RCM_MCO2_SEL_T;

/**
 * @brief RCM MCO2 Division
 */
typedef enum
{
    RCM_MCO2_DIV_1,
    RCM_MCO2_DIV_2 = 4,
    RCM_MCO2_DIV_3,
    RCM_MCO2_DIV_4,
    RCM_MCO2_DIV_5
} RCM_MCO2_DIV_T;

/**
 * @brief System clock select
 */
typedef enum
{
    RCM_SYSCLK_SEL_HSI,
    RCM_SYSCLK_SEL_HSE,
    RCM_SYSCLK_SEL_PLL
} RCM_SYSCLK_SEL_T;

/**
 * @brief AHB divider Number
 */
typedef enum
{
    RCM_AHB_DIV_1 = 7,
    RCM_AHB_DIV_2,
    RCM_AHB_DIV_4,
    RCM_AHB_DIV_8,
    RCM_AHB_DIV_16,
    RCM_AHB_DIV_64,
    RCM_AHB_DIV_128,
    RCM_AHB_DIV_256,
    RCM_AHB_DIV_512
} RCM_AHB_DIV_T;

/**
 * @brief APB divider Number
 */
typedef enum
{
    RCM_APB_DIV_1 = 3,
    RCM_APB_DIV_2,
    RCM_APB_DIV_4,
    RCM_APB_DIV_8,
    RCM_APB_DIV_16
} RCM_APB_DIV_T;

/**
 * @brief SDRAM divider Number
 */
typedef enum
{
    RCM_SDRAM_DIV_1 = 0,
    RCM_SDRAM_DIV_2 = 1,
    RCM_SDRAM_DIV_4 = 2,
} RCM_SDRAM_DIV_T;

/**
 * @brief RTC clock select
 */
typedef enum
{
    RCM_RTCCLK_LSE,
    RCM_RTCCLK_LSI,
    RCM_RTCCLK_HSE_DIV2,
    RCM_RTCCLK_HSE_DIV3,
    RCM_RTCCLK_HSE_DIV4,
    RCM_RTCCLK_HSE_DIV5,
    RCM_RTCCLK_HSE_DIV6,
    RCM_RTCCLK_HSE_DIV7,
    RCM_RTCCLK_HSE_DIV8,
    RCM_RTCCLK_HSE_DIV9,
    RCM_RTCCLK_HSE_DIV10,
    RCM_RTCCLK_HSE_DIV11,
    RCM_RTCCLK_HSE_DIV12,
    RCM_RTCCLK_HSE_DIV13,
    RCM_RTCCLK_HSE_DIV14,
    RCM_RTCCLK_HSE_DIV15,
    RCM_RTCCLK_HSE_DIV16,
    RCM_RTCCLK_HSE_DIV17,
    RCM_RTCCLK_HSE_DIV18,
    RCM_RTCCLK_HSE_DIV19,
    RCM_RTCCLK_HSE_DIV20,
    RCM_RTCCLK_HSE_DIV21,
    RCM_RTCCLK_HSE_DIV22,
    RCM_RTCCLK_HSE_DIV23,
    RCM_RTCCLK_HSE_DIV24,
    RCM_RTCCLK_HSE_DIV25,
    RCM_RTCCLK_HSE_DIV26,
    RCM_RTCCLK_HSE_DIV27,
    RCM_RTCCLK_HSE_DIV28,
    RCM_RTCCLK_HSE_DIV29,
    RCM_RTCCLK_HSE_DIV30,
    RCM_RTCCLK_HSE_DIV31
} RCM_RTCCLK_T;

/**
 * @brief I2S Clock Source
 */
typedef enum
{
    RCM_I2S_CLK_PLLI2S,
    RCM_I2S_CLK_EXT
} RCM_I2S_CLK_T;

/**
 * @brief RCM Interrupt Source
 */
typedef enum
{
    RCM_INT_LSIRDY   = BIT0, //!< LSI ready interrupt
    RCM_INT_LSERDY   = BIT1, //!< LSE ready interrupt
    RCM_INT_HSIRDY   = BIT2, //!< HSI ready interrupt
    RCM_INT_HSERDY   = BIT3, //!< HSE ready interrupt
    RCM_INT_PLL1RDY  = BIT4, //!< PLL1 ready interrupt
    RCM_INT_PLL2RDY  = BIT5, //!< PLL2 ready interrupt
    RCM_INT_CSS      = BIT7  //!< Clock security system interrupt
} RCM_INT_T;

/**
 * @brief AHB1 peripheral
 */
typedef enum
{
    RCM_AHB1_PERIPH_GPIOA        = BIT0,
    RCM_AHB1_PERIPH_GPIOB        = BIT1,
    RCM_AHB1_PERIPH_GPIOC        = BIT2,
    RCM_AHB1_PERIPH_GPIOD        = BIT3,
    RCM_AHB1_PERIPH_GPIOE        = BIT4,
    RCM_AHB1_PERIPH_GPIOF        = BIT5,
    RCM_AHB1_PERIPH_GPIOG        = BIT6,
    RCM_AHB1_PERIPH_GPIOH        = BIT7,
    RCM_AHB1_PERIPH_GPIOI        = BIT8,
    RCM_AHB1_PERIPH_GPIOJ        = BIT9,
    RCM_AHB1_PERIPH_GPIOK        = BIT10,
    RCM_AHB1_PERIPH_CRC          = BIT12,
    RCM_AHB1_PERIPH_FLITF        = BIT15,
    RCM_AHB1_PERIPH_SRAM1        = BIT16,
    RCM_AHB1_PERIPH_SRAM2        = BIT17,
    RCM_AHB1_PERIPH_BKPSRAM      = BIT18,
    RCM_AHB1_PERIPH_SRAM3        = BIT19,
    RCM_AHB1_PERIPH_CCMDATARAMEN = BIT20,
    RCM_AHB1_PERIPH_DMA1         = BIT21,
    RCM_AHB1_PERIPH_DMA2         = BIT22,
    RCM_AHB1_PERIPH_ETH_MAC      = BIT25,
    RCM_AHB1_PERIPH_ETH_MAC_Tx   = BIT26,
    RCM_AHB1_PERIPH_ETH_MAC_Rx   = BIT27,
    RCM_AHB1_PERIPH_ETH_MAC_PTP  = BIT28,
    RCM_AHB1_PERIPH_OTG_HS       = BIT29,
    RCM_AHB1_PERIPH_OTG_HS_ULPI  = BIT30
} RCM_AHB1_PERIPH_T;

/**
 * @brief AHB2 peripheral
 */
typedef enum
{
    RCM_AHB2_PERIPH_DCI    = BIT0,
    RCM_AHB2_PERIPH_FPU    = BIT1,
    RCM_AHB2_PERIPH_BN     = BIT2,
    RCM_AHB2_PERIPH_SM     = BIT3,
    RCM_AHB2_PERIPH_CRYP   = BIT4,
    RCM_AHB2_PERIPH_HASH   = BIT5,
    RCM_AHB2_PERIPH_RNG    = BIT6,
    RCM_AHB2_PERIPH_OTG_FS = BIT7
} RCM_AHB2_PERIPH_T;

/**
 * @brief APB1 peripheral
 */
typedef enum
{
    RCM_APB1_PERIPH_TMR2   = BIT0,
    RCM_APB1_PERIPH_TMR3   = BIT1,
    RCM_APB1_PERIPH_TMR4   = BIT2,
    RCM_APB1_PERIPH_TMR5   = BIT3,
    RCM_APB1_PERIPH_TMR6   = BIT4,
    RCM_APB1_PERIPH_TMR7   = BIT5,
    RCM_APB1_PERIPH_TMR12  = BIT6,
    RCM_APB1_PERIPH_TMR13  = BIT7,
    RCM_APB1_PERIPH_TMR14  = BIT8,
    RCM_APB1_PERIPH_WWDT   = BIT11,
    RCM_APB1_PERIPH_SPI2   = BIT14,
    RCM_APB1_PERIPH_SPI3   = BIT15,
    RCM_APB1_PERIPH_USART2 = BIT17,
    RCM_APB1_PERIPH_USART3 = BIT18,
    RCM_APB1_PERIPH_UART4  = BIT19,
    RCM_APB1_PERIPH_UART5  = BIT20,
    RCM_APB1_PERIPH_I2C1   = BIT21,
    RCM_APB1_PERIPH_I2C2   = BIT22,
    RCM_APB1_PERIPH_I2C3   = BIT23,
    RCM_APB1_PERIPH_CAN1   = BIT25,
    RCM_APB1_PERIPH_CAN2   = BIT26,
    RCM_APB1_PERIPH_PMU    = BIT28,
    RCM_APB1_PERIPH_DAC    = BIT29,
    RCM_APB1_PERIPH_UART7  = BIT30,
    RCM_APB1_PERIPH_UART8  = (int32_t)BIT31
} RCM_APB1_PERIPH_T;

/**
 * @brief APB2 peripheral
 */
typedef enum
{
    RCM_APB2_PERIPH_TMR1   = BIT0,
    RCM_APB2_PERIPH_TMR8   = BIT1,
    RCM_APB2_PERIPH_USART1 = BIT4,
    RCM_APB2_PERIPH_USART6 = BIT5,
    RCM_APB2_PERIPH_ADC    = BIT8,
    RCM_APB2_PERIPH_ADC1   = BIT8,
    RCM_APB2_PERIPH_ADC2   = BIT9,
    RCM_APB2_PERIPH_ADC3   = BIT10,
    RCM_APB2_PERIPH_SDIO   = BIT11,
    RCM_APB2_PERIPH_SPI1   = BIT12,
    RCM_APB2_PERIPH_SPI4   = BIT13,
    RCM_APB2_PERIPH_SYSCFG = BIT14,
    RCM_APB2_PERIPH_EXTIT  = BIT15,
    RCM_APB2_PERIPH_TMR9   = BIT16,
    RCM_APB2_PERIPH_TMR10  = BIT17,
    RCM_APB2_PERIPH_TMR11  = BIT18,
    RCM_APB2_PERIPH_SPI5   = BIT20,
    RCM_APB2_PERIPH_SPI6   = BIT21,
    RCM_APB2_PERIPH_SAI1   = BIT22,
    RCM_APB2_PERIPH_LTDC   = BIT26
} RCM_APB2_PERIPH_T;

/**
 * @brief RCM FLAG define
 */
typedef enum
{
    RCM_FLAG_HSIRDY  = 0x001,   //!< HSI Ready Flag
    RCM_FLAG_HSERDY  = 0x011,   //!< HSE Ready Flag
    RCM_FLAG_PLL1RDY = 0x019,   //!< PLL1 Ready Flag
    RCM_FLAG_PLL2RDY = 0x01B,   //!< PLL2 Ready Flag

    RCM_FLAG_LSERDY  = 0x101,   //!< LSE Ready Flag

    RCM_FLAG_LSIRDY  = 0x201,   //!< LSI Ready Flag
    RCM_FLAG_BORRST  = 0x219,   //!< POR/PDR or BOR reset Flag
    RCM_FLAG_PINRST  = 0x21A,   //!< PIN reset flag
    RCM_FLAG_PORRST  = 0x21B,   //!< POR/PDR reset flag
    RCM_FLAG_SWRST   = 0x21C,   //!< Software reset flag
    RCM_FLAG_IWDTRST = 0x21D,   //!< Independent watchdog reset flag
    RCM_FLAG_WWDTRST = 0x21E,   //!< Window watchdog reset flag
    RCM_FLAG_LPRRST  = 0x21F,   //!< Low-power reset flag
} RCM_FLAG_T;

/**@} end of group RCM_Enumerations*/

/** @addtogroup RCM_Fuctions Fuctions
  @{
*/

/** Function description */

/** RCM Reset */
void RCM_Reset(void);

/** HSE clock */
void RCM_ConfigHSE(RCM_HSE_T state);
uint8_t RCM_WaitHSEReady(void);

/** HSI clock */
void RCM_ConfigHSITrim(uint8_t HSITrim);
void RCM_EnableHSI(void);
void RCM_DisableHSI(void);

/** LSE and LSI clock */
void RCM_ConfigLSE(RCM_LSE_T state);
void RCM_EnableLSI(void);
void RCM_DisableLSI(void);

/** PLL clock */
void RCM_ConfigPLL1(uint32_t pllSelect, uint32_t inputDiv, uint32_t vcoMul,
                   RCM_PLL_SYS_DIV_T sysDiv, uint32_t appDiv);
void RCM_EnablePLL1(void);
void RCM_DisablePLL1(void);
void RCM_ConfigPLL2(uint32_t i2sVcoMul, uint32_t i2sDiv);
void RCM_EnablePLL2(void);
void RCM_DisablePLL2(void);

/** Clock Security System */
void RCM_EnableCSS(void);
void RCM_DisableCSS(void);

void RCM_ConfigMCO1(RCM_MCO1_SEL_T mco1Select, RCM_MCO1_DIV_T mco1Div);
void RCM_ConfigMCO2(RCM_MCO2_SEL_T mco2Select, RCM_MCO2_DIV_T mco2Div);
void RCM_ConfigSYSCLK(RCM_SYSCLK_SEL_T sysClkSelect);
RCM_SYSCLK_SEL_T RCM_ReadSYSCLKSource(void);

/** Config clock prescaler of AHB, APB1, APB2, SDRAM, USB and ADC */
void RCM_ConfigAHB(RCM_AHB_DIV_T AHBDiv);
void RCM_ConfigAPB1(RCM_APB_DIV_T APB1Div);
void RCM_ConfigAPB2(RCM_APB_DIV_T APB2Div);
void RCM_ConfigSDRAM(RCM_SDRAM_DIV_T SDRAMDiv);

/** Reads the clock frequency */
uint32_t RCM_ReadSYSCLKFreq(void);
uint32_t RCM_ReadHCLKFreq(void);
void RCM_ReadPCLKFreq(uint32_t* PCLK1, uint32_t* PCLK2);

/** RTC clock */
void RCM_ConfigRTCCLK(RCM_RTCCLK_T rtcClkSelect);
void RCM_EnableRTCCLK(void);
void RCM_DisableRTCCLK(void);

/** Backup domain reset */
void RCM_EnableBackupReset(void);
void RCM_DisableBackupReset(void);

void RCM_ConfigI2SCLK(RCM_I2S_CLK_T i2sClkSource);

/** Enable or disable Periph Clock */
void RCM_EnableAHB1PeriphClock(uint32_t AHB1Periph);
void RCM_DisableAHB1PeriphClock(uint32_t AHB1Periph);
void RCM_EnableAHB2PeriphClock(uint32_t AHB2Periph);
void RCM_DisableAHB2PeriphClock(uint32_t AHB2Periph);
void RCM_EnableAPB1PeriphClock(uint32_t APB1Periph);
void RCM_DisableAPB1PeriphClock(uint32_t APB1Periph);
void RCM_EnableAPB2PeriphClock(uint32_t APB2Periph);
void RCM_DisableAPB2PeriphClock(uint32_t APB2Periph);

/** Enable or disable Periph Reset */
void RCM_EnableAHB1PeriphReset(uint32_t AHB1Periph);
void RCM_DisableAHB1PeriphReset(uint32_t AHB1Periph);
void RCM_EnableAHB2PeriphReset(uint32_t AHB2Periph);
void RCM_DisableAHB2PeriphReset(uint32_t AHB2Periph);
void RCM_EnableAPB1PeriphReset(uint32_t APB1Periph);
void RCM_DisableAPB1PeriphReset(uint32_t APB1Periph);
void RCM_EnableAPB2PeriphReset(uint32_t APB2Periph);
void RCM_DisableAPB2PeriphReset(uint32_t APB2Periph);

/** Enable or disable Periph clock during Low Power (Sleep) mode */
void RCM_EnableAHB1PeriphClockLPMode(uint32_t AHB1Periph);
void RCM_DisableAHB1PeriphClockLPMode(uint32_t AHB1Periph);
void RCM_EnableAHB2PeriphClockLPMode(uint32_t AHB2Periph);
void RCM_DisableAHB2PeriphClockLPMode(uint32_t AHB2Periph);
void RCM_EnableAPB1PeriphClockLPMode(uint32_t APB1Periph);
void RCM_DisableAPB1PeriphClockLPMode(uint32_t APB1Periph);
void RCM_EnableAPB2PeriphClockLPMode(uint32_t APB2Periph);
void RCM_DisableAPB2PeriphClockLPMode(uint32_t APB2Periph);

/** Interrupts and flags */
void RCM_EnableInterrupt(uint32_t interrupt);
void RCM_DisableInterrupt(uint32_t interrupt);
uint8_t RCM_ReadStatusFlag(RCM_FLAG_T flag);
void RCM_ClearStatusFlag(void);
uint8_t RCM_ReadIntFlag(RCM_INT_T flag);
void RCM_ClearIntFlag(uint32_t flag);

/**@} end of group RCM_Fuctions*/
/**@} end of group RCM_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_RCM_H */
