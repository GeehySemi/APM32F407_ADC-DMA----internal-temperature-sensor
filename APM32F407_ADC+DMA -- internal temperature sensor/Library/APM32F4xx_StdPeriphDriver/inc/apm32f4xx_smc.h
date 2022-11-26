/*!
 * @file        apm32f4xx_smc.h
 *
 * @brief       This file contains all the functions prototypes for the SMC firmware library
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

#ifndef __APM32F4XX_SMC_H
#define __APM32F4XX_SMC_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup SMC_Driver SMC Driver
  @{
*/

/** @addtogroup SMC_Enumerations Enumerations
  @{
*/

/**
 * @brief SMC NORSRAM Bank
 */
typedef enum
{
    SMC_BANK1_NORSRAM_1,
    SMC_BANK1_NORSRAM_2,
    SMC_BANK1_NORSRAM_3,
    SMC_BANK1_NORSRAM_4
} SMC_BANK1_NORSRAM_T;

/**
 * @brief SMC NAND and PC Card Bank
 */
typedef enum
{
    SMC_BANK2_NAND,
    SMC_BANK3_NAND,
    SMC_BANK4_PCCARD
} SMC_BANK_NAND_T;

/**
 * @brief SMC_Data_Address_Bus_Multiplexing
 */
typedef enum
{
    SMC_DATA_ADDRESS_MUX_DISABLE,
    SMC_DATA_ADDRESS_MUX_ENABLE
} SMC_DATA_ADDRESS_MUX_T;

/**
 * @brief SMC_Memory_Type
 */
typedef enum
{
    SMC_MEMORY_TYPE_SRAM,
    SMC_MEMORY_TYPE_PARAM,
    SMC_MEMORY_TYPE_NOR
} SMC_MEMORY_TYPE_T;

/**
 * @brief SMC_Data_Width
 */
typedef enum
{
    SMC_MEMORY_DATA_WIDTH_8BIT,
    SMC_MEMORY_DATA_WIDTH_16BIT
} SMC_MEMORY_DATA_WIDTH_T;

/**
 * @brief SMC_Burst_Access_Mode
 */
typedef enum
{
    SMC_BURST_ACCESS_MODE_DISABLE,
    SMC_BURST_ACCESS_MODE_ENABLE
} SMC_BURST_ACCESS_MODE_T;

/**
 * @brief SMC_AsynchronousWait
 */
typedef enum
{
    SMC_ASYNCHRONOUS_WAIT_DISABLE,
    SMC_ASYNCHRONOUS_WAIT_ENABLE
} SMC_ASYNCHRONOUS_WAIT_T;

/**
 * @brief SMC_Wait_Signal_Polarity
 */
typedef enum
{
    SMC_WAIT_SIGNAL_POLARITY_LOW,
    SMC_WAIT_SIGNAL_POLARITY_HIGH
} SMC_WAIT_SIGNAL_POLARITY_T;

/**
 * @brief SMC Wrapped burst Mode
 */
typedef enum
{
    SMC_WRAP_MODE_DISABLE,
    SMC_WRAP_MODE_ENABLE
} SMC_WRAP_MODE_T;

/**
 * @brief SMC Wait Timing
 */
typedef enum
{
    SMC_WAIT_SIGNAL_ACTIVE_BEFORE_WAIT_STATE,
    SMC_WAIT_SIGNAL_ACTIVE_DURING_WAIT_STATE
} SMC_WAIT_SIGNAL_ACTIVE_T;

/**
 * @brief SMC Write Operation
 */
typedef enum
{
    SMC_WRITE_OPERATION_DISABLE,
    SMC_WRITE_OPERATION_ENABLE
} SMC_WRITE_OPERATION_T;

/**
 * @brief SMC Wait Signal
 */
typedef enum
{
    SMC_WAITE_SIGNAL_DISABLE,
    SMC_WAITE_SIGNAL_ENABLE
} SMC_WAITE_SIGNAL_T;

/**
 * @brief SMC Extended Mode
 */
typedef enum
{
    SMC_EXTENDEN_MODE_DISABLE,
    SMC_EXTENDEN_MODE_ENABLE
} SMC_EXTENDEN_MODE_T;

/**
 * @brief SMC Write Burst
 */
typedef enum
{
    SMC_WRITE_BURST_DISABLE,
    SMC_WRITE_BURST_ENABLE
} SMC_WRITE_BURST_T;

/**
 * @brief SMC WAIT FEATURE
 */
typedef enum
{
    SMC_WAIT_FEATURE_DISABLE,
    SMC_WAIT_FEATURE_ENABLE
} SMC_WAIT_FEATURE_T;

/**
 * @brief SMC ECC
 */
typedef enum
{
    SMC_ECC_DISABLE,
    SMC_ECC_ENABLE
} SMC_ECC_T;

/**
 * @brief SMC ECC Page Size
 */
typedef enum
{
    SMC_ECC_PAGE_SIZE_BYTE_256,
    SMC_ECC_PAGE_SIZE_BYTE_512,
    SMC_ECC_PAGE_SIZE_BYTE_1024,
    SMC_ECC_PAGE_SIZE_BYTE_2048,
    SMC_ECC_PAGE_SIZE_BYTE_4096,
    SMC_ECC_PAGE_SIZE_BYTE_8192
} SMC_ECC_PAGE_SIZE_BYTE_T;

/**
 * @brief SMC Access Mode
 */
typedef enum
{
    SMC_ACCESS_MODE_A,
    SMC_ACCESS_MODE_B,
    SMC_ACCESS_MODE_C,
    SMC_ACCESS_MODE_D
} SMC_ACCESS_MODE_T;

/**
 * @brief SMC Interrupt sources
 */
typedef enum
{
    SMC_INT_EDGE_RISING  = 0x00000008,
    SMC_INT_LEVEL_HIGH   = 0x00000010,
    SMC_INT_EDGE_FALLING = 0x00000020
} SMC_INT_T;

/**
 * @brief SMC Flags
 */
typedef enum
{
    SMC_FLAG_EDGE_RISING  = 0x00000001,
    SMC_FLAG_LEVEL_HIGH   = 0x00000002,
    SMC_FLAG_EDGE_FALLING = 0x00000004,
    SMC_FLAG_FIFO_EMPTY   = 0x00000040
} SMC_FLAG_T;

/**@} end of group SMC_Enumerations*/

/** @addtogroup SMC_Structure Data Structure
  @{
*/

/**
 * @brief Timing parameters for NOR/SRAM Banks
 */
typedef struct
{
    uint8_t           addressSetupTime;
    uint8_t           addressHodeTime;
    uint8_t           dataSetupTime;
    uint8_t           busTurnaroundTime;
    uint8_t           clockDivision;
    uint8_t           dataLatency;
    SMC_ACCESS_MODE_T accessMode;
} SMC_NORSRAMTimingConfig_T;

/**
 * @brief SMC NOR/SRAM Config structure
 */
typedef struct
{
    SMC_BANK1_NORSRAM_T        bank;
    SMC_DATA_ADDRESS_MUX_T     dataAddressMux;
    SMC_MEMORY_TYPE_T          memoryType;
    SMC_MEMORY_DATA_WIDTH_T    memoryDataWidth;
    SMC_BURST_ACCESS_MODE_T    burstAcceesMode;
    SMC_ASYNCHRONOUS_WAIT_T    asynchronousWait;
    SMC_WAIT_SIGNAL_POLARITY_T waitSignalPolarity;
    SMC_WRAP_MODE_T            wrapMode;
    SMC_WAIT_SIGNAL_ACTIVE_T   waitSignalActive;
    SMC_WRITE_OPERATION_T      writeOperation;
    SMC_WAITE_SIGNAL_T         waiteSignal;
    SMC_EXTENDEN_MODE_T        extendedMode;
    SMC_WRITE_BURST_T          writeBurst;
    SMC_NORSRAMTimingConfig_T* readWriteTimingStruct;
    SMC_NORSRAMTimingConfig_T* writeTimingStruct;
} SMC_NORSRAMConfig_T;

/**
 * @brief Timing parameters for NAND and PCCARD Banks
 */
typedef struct
{
    uint8_t setupTime;
    uint8_t waitSetupTime;
    uint8_t holdSetupTime;
    uint8_t HiZSetupTime;
} SMC_NAND_PCCARDTimingConfig_T;

/**
 * @brief SMC NAND Config structure
 */
typedef struct
{
    SMC_BANK_NAND_T                bank;
    SMC_WAIT_FEATURE_T             waitFeature;
    SMC_MEMORY_DATA_WIDTH_T        memoryDataWidth;
    SMC_ECC_T                      ECC;
    SMC_ECC_PAGE_SIZE_BYTE_T       ECCPageSize;
    uint8_t                        TCLRSetupTime;
    uint8_t                        TARSetupTime;
    SMC_NAND_PCCARDTimingConfig_T* commonSpaceTimingStruct;
    SMC_NAND_PCCARDTimingConfig_T* attributeSpaceTimingStruct;
} SMC_NANDConfig_T;

/**
 * @brief SMC PCCARD Config structure
 */
typedef struct
{
    SMC_WAIT_FEATURE_T             waitFeature;
    uint32_t                       TCLRSetupTime;
    uint32_t                       TARSetupTime;
    SMC_NAND_PCCARDTimingConfig_T* commonSpaceTimingStruct;
    SMC_NAND_PCCARDTimingConfig_T* attributeSpaceTimingStruct;
    SMC_NAND_PCCARDTimingConfig_T* IOSpaceTimingStruct;
} SMC_PCCARDConfig_T;

/**@} end of group SMC_Structure*/

/** @addtogroup SMC_Fuctions Fuctions
  @{
*/

/** SMC reset */
void SMC_ResetNORSRAM(SMC_BANK1_NORSRAM_T bank);
void SMC_ResetNAND(SMC_BANK_NAND_T bank);
void SMC_ResetPCCard(void);

/** SMC Configuration */
void SMC_ConfigNORSRAM(SMC_NORSRAMConfig_T* smcNORSRAMConfig);
void SMC_ConfigNAND(SMC_NANDConfig_T* smcNANDConfig);
void SMC_ConfigPCCard(SMC_PCCARDConfig_T* smcPCCardConfig);
void SMC_ConfigNORSRAMStructInit(SMC_NORSRAMConfig_T* smcNORSRAMConfig);
void SMC_ConfigNANDStructInit(SMC_NANDConfig_T* smcNANDConfig);
void SMC_ConfigPCCardStructInit(SMC_PCCARDConfig_T* smcPCCardConfig);

/** SMC bank control */
void SMC_EnableNORSRAM(SMC_BANK1_NORSRAM_T bank);
void SMC_DisableNORSRAM(SMC_BANK1_NORSRAM_T bank);
void SMC_EnableNAND(SMC_BANK_NAND_T bank);
void SMC_DisableNAND(SMC_BANK_NAND_T bank);
void SMC_EnablePCCARD(void);
void SMC_DisablePCCARD(void);
void SMC_EnableNANDECC(SMC_BANK_NAND_T bank);
void SMC_DisableNANDECC(SMC_BANK_NAND_T bank);
uint32_t SMC_ReadECC(SMC_BANK_NAND_T bank);

/** Interrupt and flag */
void SMC_EnableInterrupt(SMC_BANK_NAND_T bank, uint32_t interrupt);
void SMC_DisableInterrupt(SMC_BANK_NAND_T bank, uint32_t interrupt);
uint16_t SMC_ReadStatusFlag(SMC_BANK_NAND_T bank, SMC_FLAG_T flag);
void SMC_ClearStatusFlag(SMC_BANK_NAND_T bank, uint32_t flag);
uint16_t SMC_ReadIntFlag(SMC_BANK_NAND_T bank, SMC_INT_T flag);
void SMC_ClearIntFlag(SMC_BANK_NAND_T bank, uint32_t flag);

/**@} end of group SMC_Fuctions*/
/**@} end of group SMC_Driver */
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_SMC_H */
