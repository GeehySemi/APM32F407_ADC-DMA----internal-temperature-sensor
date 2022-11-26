/*!
 * @file        apm32f4xx_dma.h
 *
 * @brief       This file contains all the functions prototypes for the DMA firmware library.
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

#ifndef __APM32F4XX_DMA_H
#define __APM32F4XX_DMA_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup DMA_Driver DMA Driver
  @{
*/

/** @addtogroup DMA_Enumerations Enumerations
  @{
*/

/**
 * @brief DMA channel
 */
typedef enum
{
    DMA_CHANNEL_0,
    DMA_CHANNEL_1,
    DMA_CHANNEL_2,
    DMA_CHANNEL_3,
    DMA_CHANNEL_4,
    DMA_CHANNEL_5,
    DMA_CHANNEL_6,
    DMA_CHANNEL_7
} DMA_CHANNEL_T;

/**
 * @brief DMA Transmission direction
 */
typedef enum
{
    DMA_DIR_PERIPHERALTOMEMORY,
    DMA_DIR_MEMORYTOPERIPHERAL,
    DMA_DIR_MEMORYTOMEMORY
} DMA_DIR_T;

/**
 * @brief DMA Peripheral address increment
 */
typedef enum
{
    DMA_PERIPHERAL_INC_DISABLE,
    DMA_PERIPHERAL_INC_ENABLE
} DMA_PERIPHERAL_INC_T;

/**
 * @brief DMA Memory address increment
 */
typedef enum
{
    DMA_MEMORY_INC_DISABLE,
    DMA_MEMORY_INC_ENABLE
} DMA_MEMORY_INC_T;

/**
 * @brief DMA Peripheral Data Size
 */
typedef enum
{
    DMA_PERIPHERAL_DATA_SIZE_BYTE,
    DMA_PERIPHERAL_DATA_SIZE_HALFWORD,
    DMA_PERIPHERAL_DATA_SIZE_WOED
} DMA_PERIPHERAL_DATA_SIZE_T;

/**
 * @brief DMA Memory Data Size
 */
typedef enum
{
    DMA_MEMORY_DATA_SIZE_BYTE,
    DMA_MEMORY_DATA_SIZE_HALFWORD,
    DMA_MEMORY_DATA_SIZE_WOED
} DMA_MEMORY_DATA_SIZE_T;

/**
 * @brief DMA Mode
 */
typedef enum
{
    DMA_MODE_NORMAL,
    DMA_MODE_CIRCULAR
} DMA_LOOP_MODE_T;

/**
 * @brief DMA priority level
 */
typedef enum
{
    DMA_PRIORITY_LOW,
    DMA_PRIORITY_MEDIUM,
    DMA_PRIORITY_HIGH,
    DMA_PRIORITY_VERYHIGH
} DMA_PRIORITY_T;

/**
 * @brief DMA fifo direct mode
 */
typedef enum
{
    DMA_FIFOMODE_DISABLE,
    DMA_FIFOMODE_ENABLE
} DMA_FIFOMODE_T;

/**
 * @brief DMA fifo threshold select
 */
typedef enum
{
    DMA_FIFOTHRESHOLD_QUARTER,
    DMA_FIFOTHRESHOLD_HALFFULL,
    DMA_FIFOTHRESHOLD_3QUARTERS,
    DMA_FIFOTHRESHOLD_FULL
} DMA_FIFOTHRESHOLD_T;

/**
 * @brief DMA memory burst
 */
typedef enum
{
    DMA_MEMORYBURST_SINGLE,
    DMA_MEMORYBURST_INC4,
    DMA_MEMORYBURST_INC8,
    DMA_MEMORYBURST_INC16
} DMA_MEMORYBURST_T;

/**
 * @brief DMA peripheral burst
 */
typedef enum
{
    DMA_PERIPHERALBURST_SINGLE,
    DMA_PERIPHERALBURST_INC4,
    DMA_PERIPHERALBURST_INC8,
    DMA_PERIPHERALBURST_INC16
} DMA_PERIPHERALBURST_T;

/**
 * @brief DMA fifo status level
 */
typedef enum
{
    DMA_FIFOSTATUS_LESS1QUARTER,
    DMA_FIFOSTATUS_1QUARTER,
    DMA_FIFOSTATUS_HalfFull,
    DMA_FIFOSTATUS_3QUARTERS,
    DMA_FIFOSTATUS_EMPTY,
    DMA_FIFOSTATUS_FULL
} DMA_FIFOSTATUS_T;

/**
 * @brief DMA Flag
 */
typedef enum
{
    DMA_FLAG_FEIFLG0   =  0x10000001,

    DMA_FLAG_DMEIFLG0  =  0x10000004,
    DMA_FLAG_TEIFLG0   =  0x10000008,
    DMA_FLAG_HTIFLG0   =  0x10000010,
    DMA_FLAG_TCIFLG0   =  0x10000020,
    DMA_FLAG_FEIFLG1   =  0x10000040,

    DMA_FLAG_DMEIFLG1  =  0x10000100,
    DMA_FLAG_TEIFLG1   =  0x10000200,
    DMA_FLAG_HTIFLG1   =  0x10000400,
    DMA_FLAG_TCIFLG1   =  0x10000800,

    DMA_FLAG_FEIFLG2   =  0x10010000,

    DMA_FLAG_DMEIFLG2  =  0x10040000,
    DMA_FLAG_TEIFLG2   =  0x10080000,
    DMA_FLAG_HTIFLG2   =  0x10100000,
    DMA_FLAG_TCIFLG2   =  0x10200000,
    DMA_FLAG_FEIFLG3   =  0x10400000,

    DMA_FLAG_DMEIFLG3  =  0x11000000,
    DMA_FLAG_TEIFLG3   =  0x12000000,
    DMA_FLAG_HTIFLG3   =  0x14000000,
    DMA_FLAG_TCIFLG3   =  0x18000000,

    DMA_FLAG_FEIFLG4   =  0x20000001,

    DMA_FLAG_DMEIFLG4  =  0x20000004,
    DMA_FLAG_TEIFLG4   =  0x20000008,
    DMA_FLAG_HTIFLG4   =  0x20000010,
    DMA_FLAG_TCIFLG4   =  0x20000020,
    DMA_FLAG_FEIFLG5   =  0x20000040,

    DMA_FLAG_DMEIFLG5  =  0x20000100,
    DMA_FLAG_TEIFLG5   =  0x20000200,
    DMA_FLAG_HTIFLG5   =  0x20000400,
    DMA_FLAG_TCIFLG5   =  0x20000800,

    DMA_FLAG_FEIFLG6   =  0x20010000,

    DMA_FLAG_DMEIFLG6  =  0x20040000,
    DMA_FLAG_TEIFLG6   =  0x20080000,
    DMA_FLAG_HTIFLG6   =  0x20100000,
    DMA_FLAG_TCIFLG6   =  0x20200000,
    DMA_FLAG_FEIFLG7   =  0x20400000,

    DMA_FLAG_DMEIFLG7  =  0x21000000,
    DMA_FLAG_TEIFLG7   =  0x22000000,
    DMA_FLAG_HTIFLG7   =  0x24000000,
    DMA_FLAG_TCIFLG7   =  0x28000000
} DMA_FLAG_T;

/**
 * @brief DMA Interrupt Flag
 */
typedef enum
{
    DMA_INT_FEIFLG  = 0x01,
    DMA_INT_DMEIFLG = 0x02,
    DMA_INT_TEIFLG  = 0x04,
    DMA_INT_HTIFLG  = 0x08,
    DMA_INT_TCIFLG  = 0x10
} DMA_INT_T;

/**
 * @brief DMA Interrupts Flag
 */
typedef enum
{
    DMA_INT_FEIFLG0   =  0x20000001,

    DMA_INT_DMEIFLG0  =  0x00001004,
    DMA_INT_TEIFLG0   =  0x00002008,
    DMA_INT_HTIFLG0   =  0x00004010,
    DMA_INT_TCIFLG0   =  0x00008020,

    DMA_INT_FEIFLG1   =  0x20000040,

    DMA_INT_DMEIFLG1  =  0x00001100,
    DMA_INT_TEIFLG1   =  0x00002200,
    DMA_INT_HTIFLG1   =  0x00004400,
    DMA_INT_TCIFLG1   =  0x00008800,

    DMA_INT_FEIFLG2   =  0x20010000,

    DMA_INT_DMEIFLG2  =  0x00041000,
    DMA_INT_TEIFLG2   =  0x00082000,
    DMA_INT_HTIFLG2   =  0x00104000,
    DMA_INT_TCIFLG2   =  0x00208000,

    DMA_INT_FEIFLG3   =  0x20400000,

    DMA_INT_DMEIFLG3  =  0x01001000,
    DMA_INT_TEIFLG3   =  0x02002000,
    DMA_INT_HTIFLG3   =  0x04004000,
    DMA_INT_TCIFLG3   =  0x08008000,

    DMA_INT_FEIFLG4   =  0x50000001,

    DMA_INT_DMEIFLG4  =  0x10001004,
    DMA_INT_TEIFLG4   =  0x10002008,
    DMA_INT_HTIFLG4   =  0x10004010,
    DMA_INT_TCIFLG4   =  0x10008020,

    DMA_INT_FEIFLG5   =  0x50000040,

    DMA_INT_DMEIFLG5  =  0x10001100,
    DMA_INT_TEIFLG5   =  0x10002200,
    DMA_INT_HTIFLG5   =  0x10004400,
    DMA_INT_TCIFLG5   =  0x10008800,

    DMA_INT_FEIFLG6   =  0x50010000,

    DMA_INT_DMEIFLG6  =  0x10041000,
    DMA_INT_TEIFLG6   =  0x10082000,
    DMA_INT_HTIFLG6   =  0x10104000,
    DMA_INT_TCIFLG6   =  0x10208000,

    DMA_INT_FEIFLG7   =  0x50400000,

    DMA_INT_DMEIFLG7  =  0x11001000,
    DMA_INT_TEIFLG7   =  0x12002000,
    DMA_INT_HTIFLG7   =  0x14004000,
    DMA_INT_TCIFLG7   =  0x18008000

} DMA_INT_FLAG_T;

/**
 * @brief DMA peripheral increment offset
 */
typedef enum
{
    DMA_PERIOSIZE_PSIZE,
    DMA_PERIOSIZE_WORDALIGNED
} DMA_PERIOSIZE_T;

/**
 * @brief DMA flow controller
 */
typedef enum
{
    DMA_FLOWCTRL_MEMORY,
    DMA_FLOWCTRL_PERIPHERAL
} DMA_FLOWCTRL_T;

/**
 * @brief DMA memory targets
 */
typedef enum
{
    DMA_MEMORY_0,
    DMA_MEMORY_1
} DMA_MEMORY_T;

/**@} end of group DMA_Enumerations*/

/** @addtogroup DMA_Structure Data Structure
  @{
*/

/**
 * @brief DMA Config struct definition
 */
typedef struct
{
    DMA_CHANNEL_T              channel;
    uint32_t                   peripheralBaseAddr;
    uint32_t                   memoryBaseAddr;
    DMA_DIR_T                  dir;
    uint32_t                   bufferSize;
    DMA_PERIPHERAL_INC_T       peripheralInc;
    DMA_MEMORY_INC_T           memoryInc;
    DMA_PERIPHERAL_DATA_SIZE_T peripheralDataSize;
    DMA_MEMORY_DATA_SIZE_T     memoryDataSize;
    DMA_LOOP_MODE_T            loopMode;
    DMA_PRIORITY_T             priority;
    DMA_FIFOMODE_T             fifoMode;
    DMA_FIFOTHRESHOLD_T        fifoThreshold;
    DMA_MEMORYBURST_T          memoryBurst;
    DMA_PERIPHERALBURST_T      peripheralBurst;
} DMA_Config_T;

/**@} end of group DMA_Structure*/

/** @addtogroup DMA_Fuctions Fuctions
  @{
*/

/** DMA Reset and Configuration */
void DMA_Reset(DMA_Stream_T* stream);
void DMA_Config(DMA_Stream_T* stream, DMA_Config_T* dmaConfig);
void DMA_ConfigStructInit( DMA_Config_T* dmaConfig);
void DMA_Enable(DMA_Stream_T* stream);
void DMA_Disable(DMA_Stream_T* stream);

/** Stream Configuration  */
void DMA_ConfigPeriphIncOffsetSize(DMA_Stream_T* stream, DMA_PERIOSIZE_T perioSize);
void DMA_ConfigFlowController(DMA_Stream_T* stream, DMA_FLOWCTRL_T flowController);

/** DMA Data Number */
void DMA_ConfigDataNumber(DMA_Stream_T* stream, uint16_t dataNumber);
uint16_t DMA_ReadDataNumber(DMA_Stream_T* stream);

/** DMA Double Buffer mode */
void DMA_ConfigBufferMode(DMA_Stream_T* stream, uint32_t memory1BaseAddr, DMA_MEMORY_T currentMemory);
void DMA_EnableDoubleBufferMode(DMA_Stream_T* stream);
void DMA_DisableDoubleBufferMode(DMA_Stream_T* stream);
void DMA_ConfigMemoryTarget(DMA_Stream_T* stream, uint32_t memoryBaseAddr, DMA_MEMORY_T memoryTarget);
uint32_t DMA_ReadCurrentMemoryTarget(DMA_Stream_T* stream);

/** DMA Interrupts and flags　*/
uint8_t DMA_ReadCmdStatus(DMA_Stream_T* stream);
uint32_t DMA_ReadFIFOFlag(DMA_Stream_T* stream);

uint8_t DMA_ReadStatusFlag(DMA_Stream_T* stream, DMA_FLAG_T flag);
void DMA_ClearStatusFlag(DMA_Stream_T* stream, uint32_t flag);

void DMA_EnableInterrupt(DMA_Stream_T* stream, uint32_t interrupt);
void DMA_DisableInterrupt(DMA_Stream_T* stream, uint32_t interrupt);
uint8_t DMA_ReadIntFlag(DMA_Stream_T* stream, DMA_INT_FLAG_T flag);
void DMA_ClearIntFlag(DMA_Stream_T* stream, uint32_t flag);

/**@} end of group DMA_Fuctions*/
/**@} end of group DMA_Driver */
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /*__APM32F4XX_DMA_H */
