/*!
 * @file        apm32f4xx_usart.h
 *
 * @brief       This file contains all the functions prototypes for the USART firmware library
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

#ifndef __APM32F4XX_USART_H
#define __APM32F4XX_USART_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup USART_Driver USART Driver
  @{
*/

/** @addtogroup USART_Enumerations Enumerations
  @{
*/

/**
 * @brief USART Word Length
 */
typedef enum
{
    USART_WORD_LEN_8B,
    USART_WORD_LEN_9B
} USART_WORD_LEN_T;

/**
 * @brief USART Stop bits
 */
typedef enum
{
    USART_STOP_BIT_1,
    USART_STOP_BIT_0_5,
    USART_STOP_BIT_2,
    USART_STOP_BIT_1_5
} USART_STOP_BIT_T;

/**
 * @brief USART Parity
 */
typedef enum
{
    USART_PARITY_NONE  = (uint8_t)0x00,
    USART_PARITY_EVEN  = (uint8_t)0x01,
    USART_PARITY_ODD   = (uint8_t)0x03
} USART_PARITY_T;

/**
 * @brief USART mode
 */
typedef enum
{
    USART_MODE_RX    = (uint8_t)0x01,
    USART_MODE_TX    = (uint8_t)0x02,
    USART_MODE_TX_RX = (uint8_t)0x03
} USART_MODE_T;

/**
 * @brief USART hardware flow control
 */
typedef enum
{
    USART_HARDWARE_FLOW_NONE,
    USART_HARDWARE_FLOW_RTS,
    USART_HARDWARE_FLOW_CTS,
    USART_HARDWARE_FLOW_RTS_CTS
} USART_HARDWARE_FLOW_T;

/**
 * @brief USART Clock enable
 */
typedef enum
{
    USART_CLKEN_DISABLE,
    USART_CLKEN_ENABLE
} USART_CLKEN_T;

/**
 * @brief USART Clock polarity
 */
typedef enum
{
    USART_CLKPOL_LOW,
    USART_CLKPOL_HIGH
} USART_CLKPOL_T;

/**
 * @brief USART Clock phase
 */
typedef enum
{
    USART_CLKPHA_1EDGE,
    USART_CLKPHA_2EDGE
} USART_CLKPHA_T;

/**
 * @brief USART Last bit clock pulse
 */
typedef enum
{
    USART_LBCP_DISABLE,
    USART_LBCP_ENABLE,
} USART_LBCP_T;

/**
 * @brief USART Interrupt Source
 */
typedef enum
{
    USART_INT_PE       = 0x0010100,
    USART_INT_TXBE     = 0x7010080,
    USART_INT_TXC      = 0x6010040,
    USART_INT_RXBNE    = 0x5010020,
    USART_INT_IDLE     = 0x4010010,
    USART_INT_OVRE_RX  = 0x3010008,
    USART_INT_LBD      = 0x8020040,
    USART_INT_CTS      = 0x9040400,
    USART_INT_ERR      = 0x0040001,
    USART_INT_OVRE_ER  = 0x3040001,
    USART_INT_NE       = 0x2040001,
    USART_INT_FE       = 0x1040001
} USART_INT_T;

/**
 * @brief USART DMA enable
 */
typedef enum
{
    USART_DMA_RX    = (uint8_t)0x01,
    USART_DMA_TX    = (uint8_t)0x02,
    USART_DMA_TX_RX = (uint8_t)0x03
} USART_DMA_T;

/**
 * @brief USART Wakeup method
 */
typedef enum
{
    USART_WAKEUP_IDLE_LINE,
    USART_WAKEUP_ADDRESS_MARK
} USART_WAKEUP_T;

/**
 * @brief USART LIN break detection length
 */
typedef enum
{
    USART_LBDL_10B,
    USART_LBDL_11B
} USART_LBDL_T;

/**
 * @brief USART IrDA low-power
 */
typedef enum
{
    USART_IRDALP_NORMAL,
    USART_IRDALP_LOWPOWER
} USART_IRDALP_T;

/**
 * @brief USART flag
 */
typedef enum
{
    USART_FLAG_CTS       = 0x0200,
    USART_FLAG_LBD       = 0x0100,
    USART_FLAG_TXBE      = 0x0080,
    USART_FLAG_TXC       = 0x0040,
    USART_FLAG_RXBNE     = 0x0020,
    USART_FLAG_IDLE      = 0x0010,
    USART_FLAG_OVRE      = 0x0008,
    USART_FLAG_NE        = 0x0004,
    USART_FLAG_FE        = 0x0002,
    USART_FLAG_PE        = 0x0001
} USART_FLAG_T;

/**@} end of group USART_Enumerations*/

/** @addtogroup USART_Structure Data Structure
  @{
*/

/**
 * @brief USART Config struct definition
 */
typedef struct
{
    uint32_t                  baudRate;          //!< Specifies the baud rate
    USART_WORD_LEN_T          wordLength;        //!< Specifies the word length
    USART_STOP_BIT_T          stopBits;          //!< Specifies the stop bits
    USART_PARITY_T            parity;            //!< Specifies the parity
    USART_MODE_T              mode;              //!< Specifies the mode
    USART_HARDWARE_FLOW_T     hardwareFlow;      //!< Specifies the hardware flow control
} USART_Config_T;

/**
 * @brief USART synchronous communication clock config struct definition
 */
typedef struct
{
    USART_CLKEN_T             clock;             //!< Enable or Disable Clock
    USART_CLKPOL_T            polarity;          //!< Specifies the clock polarity
    USART_CLKPHA_T            phase;             //!< Specifies the clock phase
    USART_LBCP_T              lastBit;           //!< Enable or Disable last bit clock
} USART_ClockConfig_T;

/**@} end of group USART_Structure*/

/** @addtogroup USART_Fuctions Fuctions
  @{
*/

/** USART Reset */
void USART_Reset(USART_T* usart);

/** USART Configuration */
void USART_Config(USART_T* uart, USART_Config_T* usartConfig);
void USART_ConfigStructInit(USART_Config_T* usartConfig);
void USART_ConfigClock(USART_T* usart, USART_ClockConfig_T* clockConfig);
void USART_ConfigClockStructInit(USART_ClockConfig_T* clockConfig);
void USART_Enable(USART_T* usart);
void USART_Disable(USART_T* usart);
void USART_ConfigPrescaler(USART_T* usart, uint8_t div);
void USART_EnableOverSampling8(USART_T* usart);
void USART_DisableOverSampling8(USART_T* usart);
void USART_EnableOverSampling(USART_T* usart);
void USART_DisableOverSampling(USART_T* usart);

/** Data transfers */
void USART_TxData(USART_T* usart, uint16_t data);
uint16_t USART_RxData(USART_T* usart);

/** Multi-Processor Communication */
void USART_Address(USART_T* usart, uint8_t address);
void USART_EnableMuteMode(USART_T* usart);
void USART_DisableMuteMode(USART_T* usart);
void USART_ConfigWakeUp(USART_T* usart, USART_WAKEUP_T wakeup);

/** LIN mode */
void USART_ConfigLINBreakDetectLength(USART_T* usart, USART_LBDL_T length);
void USART_EnableLIN(USART_T* usart);
void USART_DisableLIN(USART_T* usart);
void USART_TxBreak(USART_T* usart);

/** Half-duplex mode */
void USART_EnableHalfDuplex(USART_T* usart);
void USART_DisableHalfDuplex(USART_T* usart);

/** Smartcard mode */
void USART_ConfigGuardTime(USART_T* usart, uint8_t guardTime);
void USART_EnableSmartCard(USART_T* usart);
void USART_DisableSmartCard(USART_T* usart);
void USART_EnableSmartCardNACK(USART_T* usart);
void USART_DisableSmartCardNACK(USART_T* usart);

/** IrDA mode */
void USART_ConfigIrDA(USART_T* usart, USART_IRDALP_T IrDAMode);

void USART_EnableIrDA(USART_T* usart);
void USART_DisableIrDA(USART_T* usart);

/** DMA transfers management */
void USART_EnableDMA(USART_T* usart, USART_DMA_T dmaReq);
void USART_DisableDMA(USART_T* usart, USART_DMA_T dmaReq);

/** Interrupts and flags management */
void USART_EnableInterrupt(USART_T* usart, USART_INT_T interrupt);
void USART_DisableInterrupt(USART_T* usart, USART_INT_T interrupt);
uint8_t USART_ReadStatusFlag(USART_T* usart, USART_FLAG_T flag);
void USART_ClearStatusFlag(USART_T* usart, USART_FLAG_T flag);
uint8_t USART_ReadIntFlag(USART_T* usart, USART_INT_T flag);
void USART_ClearIntFlag(USART_T* usart, USART_INT_T flag);

/**@} end of group USART_Fuctions*/
/**@} end of group USART_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_USART_H */
