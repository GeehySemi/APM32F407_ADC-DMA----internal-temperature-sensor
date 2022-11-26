/*!
 * @file        apm32f4xx_sdio.h
 *
 * @brief       This file contains all the functions prototypes for the SDIO firmware
 *              library.
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

#ifndef __APM32F4XX_SDIO_H
#define __APM32F4XX_SDIO_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup SDIO_Driver SDIO Driver
  @{
*/

/** @addtogroup SDIO_Enumerations Enumerations
  @{
*/

/**
 * @brief SDIO clock edge
 */
typedef enum
{
    SDIO_CLOCK_EDGE_RISING,
    SDIO_CLOCK_EDGE_FALLING
} SDIO_CLOCK_EDGE_T;

/**
 * @brief SDIO clock bypass
 */
typedef enum
{
    SDIO_CLOCK_BYPASS_DISABLE,
    SDIO_CLOCK_BYPASS_ENABLE
} SDIO_CLOCK_BYPASS_T;

/**
 * @brief    SDIO clock power save
 */
typedef enum
{
    SDIO_CLOCK_POWER_SAVE_DISABLE,
    SDIO_CLOCK_POWER_SAVE_ENABLE
} SDIO_CLOCK_POWER_SAVE_T;

/**
 * @brief SDIO bus wide
 */
typedef enum
{
    SDIO_BUS_WIDE_1B,
    SDIO_BUS_WIDE_4B,
    SDIO_BUS_WIDE_8B
} SDIO_BUS_WIDE_T;

/**
 * @brief SDIO hardware flow control
 */
typedef enum
{
    SDIO_HARDWARE_FLOW_CONTROL_DISABLE,
    SDIO_HARDWARE_FLOW_CONTROL_ENABLE
}SDIO_HARDWARE_FLOW_CONTROL_T;

/**
 * @brief SDIO power state
 */
typedef enum
{
    SDIO_POWER_STATE_OFF = 0x00,
    SDIO_POWER_STATE_ON  = 0x03
}SDIO_POWER_STATE_T;

/**
 * @brief SDIO response
 */
typedef enum
{
    SDIO_RESPONSE_NO    = (uint8_t)0x00,
    SDIO_RESPONSE_SHORT = (uint8_t)0x01,
    SDIO_RESPONSE_LONG  = (uint8_t)0x03
}SDIO_RESPONSE_T;

/**
 * @brief SDIO wait interrupt state
 */
typedef enum
{
    SDIO_WAIT_NO   = (uint8_t)0x00,
    SDIO_WAIT_INT  = (uint8_t)0x01,
    SDIO_WAIT_PEND = (uint8_t)0x02
}SDIO_WAIT_T;

/**
 * @brief SDIO CPSM state
 */
typedef enum
{
    SDIO_CPSM_DISABLE,
    SDIO_CPSM_ENABLE
}SDIO_CPSM_T;

/**
 * @brief SDIO response registers
 */
typedef enum
{
    SDIO_RES1 = ((uint8_t)0x00),
    SDIO_RES2 = ((uint8_t)0x04),
    SDIO_RES3 = ((uint8_t)0x08),
    SDIO_RES4 = ((uint8_t)0x0C)
}SDIO_RES_T;

/**
 * @brief SDIO data block size
 */
typedef enum
{
    SDIO_DATA_BLOCKSIZE_1B,
    SDIO_DATA_BLOCKSIZE_2B,
    SDIO_DATA_BLOCKSIZE_4B,
    SDIO_DATA_BLOCKSIZE_8B,
    SDIO_DATA_BLOCKSIZE_16B,
    SDIO_DATA_BLOCKSIZE_32B,
    SDIO_DATA_BLOCKSIZE_64B,
    SDIO_DATA_BLOCKSIZE_128B,
    SDIO_DATA_BLOCKSIZE_256B,
    SDIO_DATA_BLOCKSIZE_512B,
    SDIO_DATA_BLOCKSIZE_1024B,
    SDIO_DATA_BLOCKSIZE_2048B,
    SDIO_DATA_BLOCKSIZE_4096B,
    SDIO_DATA_BLOCKSIZE_8192B,
    SDIO_DATA_BLOCKSIZE_16384B
}SDIO_DATA_BLOCKSIZE_T;

/**
 * @brief SDIO transfer direction
 */
typedef enum
{
    SDIO_TRANSFER_DIR_TO_CARD,
    SDIO_TRANSFER_DIR_TO_SDIO
}SDIO_TRANSFER_DIR_T;

/**
 * @brief SDIO transfer type
 */
typedef enum
{
    SDIO_TRANSFER_MODE_BLOCK,
    SDIO_TRANSFER_MODE_STREAM
}SDIO_TRANSFER_MODE_T;

/**
 * @brief SDIO DPSM state
 */
typedef enum
{
    SDIO_DPSM_DISABLE,
    SDIO_DPSM_ENABLE
}SDIO_DPSM_T;

/**
 * @brief SDIO flag
 */
typedef enum
{
    SDIO_FLAG_COMRESP  = ((uint32_t)0x00000001),
    SDIO_FLAG_DBDR     = ((uint32_t)0x00000002),
    SDIO_FLAG_CMDRESTO = ((uint32_t)0x00000004),
    SDIO_FLAG_DATATO   = ((uint32_t)0x00000008),
    SDIO_FLAG_TXUDRER  = ((uint32_t)0x00000010),
    SDIO_FLAG_RXOVRER  = ((uint32_t)0x00000020),
    SDIO_FLAG_CMDRES   = ((uint32_t)0x00000040),
    SDIO_FLAG_CMDSENT  = ((uint32_t)0x00000080),
    SDIO_FLAG_DATAEND  = ((uint32_t)0x00000100),
    SDIO_FLAG_SBE      = ((uint32_t)0x00000200),
    SDIO_FLAG_DBCP     = ((uint32_t)0x00000400),
    SDIO_FLAG_CMDACT   = ((uint32_t)0x00000800),
    SDIO_FLAG_TXACT    = ((uint32_t)0x00001000),
    SDIO_FLAG_RXACT    = ((uint32_t)0x00002000),
    SDIO_FLAG_TXFHF    = ((uint32_t)0x00004000),
    SDIO_FLAG_RXFHF    = ((uint32_t)0x00008000),
    SDIO_FLAG_TXFF     = ((uint32_t)0x00010000),
    SDIO_FLAG_RXFF     = ((uint32_t)0x00020000),
    SDIO_FLAG_TXFE     = ((uint32_t)0x00040000),
    SDIO_FLAG_RXFE     = ((uint32_t)0x00080000),
    SDIO_FLAG_TXDA     = ((uint32_t)0x00100000),
    SDIO_FLAG_RXDA     = ((uint32_t)0x00200000),
    SDIO_FLAG_SDIOINT  = ((uint32_t)0x00400000),
    SDIO_FLAG_ATAEND   = ((uint32_t)0x00800000)
}SDIO_FLAG_T;

/**
 * @brief SDIO interrupt sources
 */
typedef enum
{
    SDIO_INT_COMRESP  = ((uint32_t)0x00000001),
    SDIO_INT_DBDR     = ((uint32_t)0x00000002),
    SDIO_INT_CMDRESTO = ((uint32_t)0x00000004),
    SDIO_INT_DATATO   = ((uint32_t)0x00000008),
    SDIO_INT_TXUDRER  = ((uint32_t)0x00000010),
    SDIO_INT_RXOVRER  = ((uint32_t)0x00000020),
    SDIO_INT_CMDRES   = ((uint32_t)0x00000040),
    SDIO_INT_CMDSENT  = ((uint32_t)0x00000080),
    SDIO_INT_DATAEND  = ((uint32_t)0x00000100),
    SDIO_INT_SBE      = ((uint32_t)0x00000200),
    SDIO_INT_DBCP     = ((uint32_t)0x00000400),
    SDIO_INT_CMDACT   = ((uint32_t)0x00000800),
    SDIO_INT_TXACT    = ((uint32_t)0x00001000),
    SDIO_INT_RXACT    = ((uint32_t)0x00002000),
    SDIO_INT_TXFHF    = ((uint32_t)0x00004000),
    SDIO_INT_RXFHF    = ((uint32_t)0x00008000),
    SDIO_INT_TXFF     = ((uint32_t)0x00010000),
    SDIO_INT_RXFF     = ((uint32_t)0x00020000),
    SDIO_INT_TXFE     = ((uint32_t)0x00040000),
    SDIO_INT_RXFE     = ((uint32_t)0x00080000),
    SDIO_INT_TXDA     = ((uint32_t)0x00100000),
    SDIO_INT_RXDA     = ((uint32_t)0x00200000),
    SDIO_INT_SDIOINT  = ((uint32_t)0x00400000),
    SDIO_INT_ATAEND   = ((uint32_t)0x00800000)
}SDIO_INT_T;

/**
 * @brief SDIO read wait mode
 */
typedef enum
{
    SDIO_READ_WAIT_MODE_DATA2,
    SDIO_READ_WAIT_MODE_CLK
}SDIO_READ_WAIT_MODE_T;

/**@} end of group SDIO_Enumerations*/

/** @addtogroup SDIO_Structure Data Structure
  @{
*/

/**
 * @brief SDIO Config structure definition
 */
typedef struct
{
    SDIO_CLOCK_EDGE_T            clockEdge;           //!< Specifies the clock transition on which the bit capture is made.
    SDIO_CLOCK_BYPASS_T          clockBypass;         //!< Specifies whether the SDIO Clock divider bypass is enabled or disabled.
    SDIO_CLOCK_POWER_SAVE_T      clockPowerSave;      //!< Specifies whether SDIO Clock output is enabled or disabled when the bus is idle.
    SDIO_BUS_WIDE_T              busWide;             //!< Specifies the SDIO bus width.
    SDIO_HARDWARE_FLOW_CONTROL_T hardwareFlowControl; //!< Specifies whether the SDIO hardware flow control is enabled or disabled.
    uint8_t                      clockDiv;            //!< This parameter can be a value between 0x00 and 0xFF.
} SDIO_Config_T;

/**
 * @brief SDIO Command Config structure definition
 */
typedef struct
{
    uint32_t           argument; /**
                                  * Specifies the SDIO command argument which is sentto a card as part of a command message.
                                  * If a command contains an argument, it must be loaded into this register before writing
                                  * the command to the command register
                                  */
    uint32_t           cmdIndex; //!< It must be lower than 0x40.
    SDIO_RESPONSE_T    response;
    SDIO_WAIT_T        wait;     //!< Specifies whether SDIO wait for interrupt request
    SDIO_CPSM_T        CPSM;     //!< Specifies whether SDIO Command path state machine (CPSM)
} SDIO_CmdConfig_T;

/**
 * @brief SDIO Data Config
 */
typedef struct
{
    uint32_t              dataTimeOut;
    uint32_t              dataLength;
    SDIO_DATA_BLOCKSIZE_T dataBlockSize;
    SDIO_TRANSFER_DIR_T   transferDir;
    SDIO_TRANSFER_MODE_T  transferMode;
    SDIO_DPSM_T           DPSM; //!< Specifies whether SDIO Data path state machine(DPSM)
} SDIO_DataConfig_T;

/**@} end of group SDIO_Structure*/

/** @addtogroup SDIO_Fuctions Fuctions
  @{
*/

/** SDIO reset and configuration */
void SDIO_Reset(void);
void SDIO_Config(SDIO_Config_T* sdioConfig);
void SDIO_ConfigStructInit(SDIO_Config_T* sdioConfig);
void SDIO_EnableClock(void);
void SDIO_DisableClock(void);
void SDIO_ConfigPowerState(SDIO_POWER_STATE_T powerState);
uint32_t SDIO_ReadPowerState(void);

/** DMA */
void SDIO_EnableDMA(void);
void SDIO_DisableDMA(void);

/** Command */
void SDIO_TxCommand(SDIO_CmdConfig_T *cmdConfig);
void SDIO_TxCommandStructInit(SDIO_CmdConfig_T* cmdconfig);
uint8_t SDIO_ReadCommandResponse(void);
uint32_t SDIO_ReadResponse(SDIO_RES_T res);

/** SDIO data configuration */
void SDIO_ConfigData(SDIO_DataConfig_T* dataConfig);
void SDIO_ConfigDataStructInit(SDIO_DataConfig_T* dataConfig);
uint32_t SDIO_ReadDataCounter(void);
void SDIO_WriteData(uint32_t data);
uint32_t SDIO_ReadData(void);
uint32_t SDIO_ReadFIFOCount(void);

/** SDIO mode */
void SDIO_EnableStartReadWait(void);
void SDIO_DisableStartReadWait(void);
void SDIO_EnableStopReadWait(void);
void SDIO_DisableStopReadWait(void);
void SDIO_ConfigSDIOReadWaitMode(SDIO_READ_WAIT_MODE_T readWaitMode);
void SDIO_EnableSDIO(void);
void SDIO_DisableSDIO(void);
void SDIO_EnableTxSDIOSuspend(void);
void SDIO_DisableTxSDIOSuspend(void);
void SDIO_EnableCommandCompletion(void);
void SDIO_DisableCommandCompletion(void);
void SDIO_EnableCEATAInterrupt(void);
void SDIO_DisableCEATAInterrupt(void);
void SDIO_EnableTxCEATA(void);
void SDIO_DisableTxCEATA(void);

/** Interrupt and flags */
void SDIO_EnableInterrupt(uint32_t interrupt);
void SDIO_DisableInterrupt(uint32_t interrupt);
uint8_t SDIO_ReadStatusFlag(SDIO_FLAG_T flag);
void SDIO_ClearStatusFlag(uint32_t flag);
uint8_t SDIO_ReadIntFlag(SDIO_INT_T flag);
void SDIO_ClearIntFlag(uint32_t flag);

/**@} end of group SDIO_Fuctions*/
/**@} end of group SDIO_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_SDIO_H */
