/*!
 * @file       apm32f4xx_fmc.h
 *
 * @brief      This file contains all the functions prototypes for the FMC firmware library
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

#ifndef __APM32F4XX_FMC_H
#define __APM32F4XX_FMC_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup FMC_Driver FMC Driver
  @{
*/

/** @addtogroup FMC_Enumerations Enumerations
  @{
*/

/**
 * @brief FMC Status
 */
typedef enum
{
    FMC_BUSY = 1,
    FMC_ERROR_RD,
    FMC_ERROR_PGS,
    FMC_ERROR_PGP,
    FMC_ERROR_PGA,
    FMC_ERROR_WRP,
    FMC_ERROR_PROGRAM,
    FMC_ERROR_OPERATION,
    FMC_COMPLETE
} FMC_STATUS_T;

/**
 * @brief FMC Latency
 */
typedef enum
{
    FMC_LTNCY_0    = ((uint8_t)0x0000),
    FMC_LTNCY_1    = ((uint8_t)0x0001),
    FMC_LTNCY_2    = ((uint8_t)0x0002),
    FMC_LTNCY_3    = ((uint8_t)0x0003),
    FMC_LTNCY_4    = ((uint8_t)0x0004),
    FMC_LTNCY_5    = ((uint8_t)0x0005),
    FMC_LTNCY_6    = ((uint8_t)0x0006),
    FMC_LTNCY_7    = ((uint8_t)0x0007),
    FMC_LTNCY_8    = ((uint8_t)0x0008),
    FMC_LTNCY_9    = ((uint8_t)0x0009),
    FMC_LTNCY_10   = ((uint8_t)0x000A),
    FMC_LTNCY_11   = ((uint8_t)0x000B),
    FMC_LTNCY_12   = ((uint8_t)0x000C),
    FMC_LTNCY_13   = ((uint8_t)0x000D),
    FMC_LTNCY_14   = ((uint8_t)0x000E),
    FMC_LTNCY_15   = ((uint8_t)0x000F)
} FMC_LATENCY_T;

/**
 * @brief FMC Voltage Range
 */
typedef enum
{
    FMC_VOLTAGE_1  = (uint8_t)0x00,
    FMC_VOLTAGE_2  = (uint8_t)0x01,
    FMC_VOLTAGE_3  = (uint8_t)0x02,
    FMC_VOLTAGE_4  = (uint8_t)0x03,
} FMC_VOLTAGE_T;

/**
 * @brief FMC Sectors
 */
typedef enum
{
    FMC_SECTOR_0   = ((uint16_t)0x0000),
    FMC_SECTOR_1   = ((uint16_t)0x0008),
    FMC_SECTOR_2   = ((uint16_t)0x0010),
    FMC_SECTOR_3   = ((uint16_t)0x0018),
    FMC_SECTOR_4   = ((uint16_t)0x0020),
    FMC_SECTOR_5   = ((uint16_t)0x0028),
    FMC_SECTOR_6   = ((uint16_t)0x0030),
    FMC_SECTOR_7   = ((uint16_t)0x0038),
    FMC_SECTOR_8   = ((uint16_t)0x0040),
    FMC_SECTOR_9   = ((uint16_t)0x0048),
    FMC_SECTOR_10  = ((uint16_t)0x0050),
    FMC_SECTOR_11  = ((uint16_t)0x0058),
    FMC_SECTOR_12  = ((uint16_t)0x0080),
    FMC_SECTOR_13  = ((uint16_t)0x0088),
    FMC_SECTOR_14  = ((uint16_t)0x0090),
    FMC_SECTOR_15  = ((uint16_t)0x0098),
    FMC_SECTOR_16  = ((uint16_t)0x00A0),
    FMC_SECTOR_17  = ((uint16_t)0x00A8),
    FMC_SECTOR_18  = ((uint16_t)0x00B0),
    FMC_SECTOR_19  = ((uint16_t)0x00B8),
    FMC_SECTOR_20  = ((uint16_t)0x00C0),
    FMC_SECTOR_21  = ((uint16_t)0x00C8),
    FMC_SECTOR_22  = ((uint16_t)0x00D0),
    FMC_SECTOR_23  = ((uint16_t)0x00D8)
} FMC_SECTOR_T;

/**
 * @brief Option Bytes Write Protection
 */
typedef enum
{
    FMC_OPT_WRP_SECTOR_0   = (uint32_t)0x00000001,
    FMC_OPT_WRP_SECTOR_1   = (uint32_t)0x00000002,
    FMC_OPT_WRP_SECTOR_2   = (uint32_t)0x00000004,
    FMC_OPT_WRP_SECTOR_3   = (uint32_t)0x00000008,
    FMC_OPT_WRP_SECTOR_4   = (uint32_t)0x00000010,
    FMC_OPT_WRP_SECTOR_5   = (uint32_t)0x00000020,
    FMC_OPT_WRP_SECTOR_6   = (uint32_t)0x00000040,
    FMC_OPT_WRP_SECTOR_7   = (uint32_t)0x00000080,
    FMC_OPT_WRP_SECTOR_8   = (uint32_t)0x00000100,
    FMC_OPT_WRP_SECTOR_9   = (uint32_t)0x00000200,
    FMC_OPT_WRP_SECTOR_10  = (uint32_t)0x00000400,
    FMC_OPT_WRP_SECTOR_11  = (uint32_t)0x00000800,

    FMC_OPT_WRP_SECTOR_12  = (uint32_t)0x00000001,
    FMC_OPT_WRP_SECTOR_13  = (uint32_t)0x00000002,
    FMC_OPT_WRP_SECTOR_14  = (uint32_t)0x00000004,
    FMC_OPT_WRP_SECTOR_15  = (uint32_t)0x00000008,
    FMC_OPT_WRP_SECTOR_16  = (uint32_t)0x00000010,
    FMC_OPT_WRP_SECTOR_17  = (uint32_t)0x00000020,
    FMC_OPT_WRP_SECTOR_18  = (uint32_t)0x00000040,
    FMC_OPT_WRP_SECTOR_19  = (uint32_t)0x00000080,
    FMC_OPT_WRP_SECTOR_20  = (uint32_t)0x00000100,
    FMC_OPT_WRP_SECTOR_21  = (uint32_t)0x00000200,
    FMC_OPT_WRP_SECTOR_22  = (uint32_t)0x00000400,
    FMC_OPT_WRP_SECTOR_23  = (uint32_t)0x00000800,
    FMC_OPT_WRP_SECTOR_All = (uint32_t)0x00000FFF
} FMC_OPT_WRP_T;

/**
 * @brief FMC Option Bytes Read Protection
 */
typedef enum
{
    FMC_OPT_RDP_LV0 =(uint8_t)0xAA,
    FMC_OPT_RDP_LV1 =(uint8_t)0x55
} FMC_OPT_RDP_T;

/**
 * @brief FMC Option Bytes Independent Watchdog
 */
typedef enum
{
    FMC_OPT_IWDT_SOFT = (uint8_t)0x20,
    FMC_OPT_IWDT_HARD = (uint8_t)0x00
} FMC_OPT_IWDT_T;

/**
 * @brief FMC Option Bytes nRST STOP
 */
typedef enum
{
    FMC_OPT_STOP_NORST = (uint8_t)0x40,
    FMC_OPT_STOP_RST   = (uint8_t)0x00
} FMC_OPT_STOP_T;

/**
 * @brief FMC Option Bytes nRST STDBY
 */
typedef enum
{
    FMC_OPT_STDBY_NORST = (uint8_t)0x80,
    FMC_OPT_STDBY_RST   = (uint8_t)0x00
} FMC_OPT_STDBY_T;

/**
 * @brief FMC BOR Reset Level
 */
typedef enum
{
    FMC_OPT_BOR_LV3 = (uint8_t)0x00,
    FMC_OPT_BOR_LV2 = (uint8_t)0x04,
    FMC_OPT_BOR_LV1 = (uint8_t)0x08,
    FMC_OPT_BOR_OFF = (uint8_t)0x0C
} FMC_OPT_BOR_T;

/**
 * @brief FMC Dual Boot
 */
typedef enum
{
    FMC_OPT_BOOTEN  = (uint8_t)0x10,
    FMC_OPT_BOOTDIS = (uint8_t)0x00
} FMC_OPT_BOOT_T;

/**
 * @brief FMC Interrupts
 */
typedef enum
{
    FMC_INT_OC  = (uint32_t)0x01000000,
    FMC_INT_ERR = (uint32_t)0x02000000
} FMC_INT_T;

/**
 * @brief FMC Flags
 */
typedef enum
{
    FMC_FLAG_ENDOP  = (uint32_t)0x00000001,
    FMC_FLAG_ERROP  = (uint32_t)0x00000002,
    FMC_FLAG_ERRWRP = (uint32_t)0x00000010,
    FMC_FLAG_ERRPGA = (uint32_t)0x00000020,
    FMC_FLAG_ERRPGP = (uint32_t)0x00000040,
    FMC_FLAG_ERRPGS = (uint32_t)0x00000080,
    FMC_FLAG_BUSY   = (uint32_t)0x00010000
} FMC_FLAG_T;

/**
 * @brief FMC Program Parallelism
 */
typedef enum
{
    FMC_PSIZE_BYTE        = (uint32_t)0x00000000,
    FMC_PSIZE_HALF_WORD   = (uint32_t)0x00000100,
    FMC_PSIZE_WORD        = (uint32_t)0x00000200,
    FMC_PSIZE_DOUBLE_WORD = (uint32_t)0x00000300
} FMC_PSIZE_T;

/**@} end of group FMC_Enumerations*/

/** @addtogroup FMC_Macros Macros
  @{
*/

#define PMC_RDP_KEY            ((uint16_t)0x00A5)
#define FMC_KEY1               ((uint32_t)0x45670123)
#define FMC_KEY2               ((uint32_t)0xCDEF89AB)
#define FMC_OPT_KEY1           ((uint32_t)0x08192A3B)
#define FMC_OPT_KEY2           ((uint32_t)0x4C5D6E7F)

/** FMC ACCTRL register Bits definition */
#define FMC_ACCTRL_PREFEN      ((uint32_t)0x00000100)
#define FMC_ACCTRL_ICACHEEN    ((uint32_t)0x00000200)
#define FMC_ACCTRL_DCACHEEN    ((uint32_t)0x00000400)
#define FMC_ACCTRL_ICACHERST   ((uint32_t)0x00000800)
#define FMC_ACCTRL_DCACHERST   ((uint32_t)0x00001000)

/** FMC CTRL register Bits definition */
#define FMC_CTRL_PG            ((uint32_t)0x00000001)
#define FMC_CTRL_SERS          ((uint32_t)0x00000002)
#define FMC_CTRL_MERS          ((uint32_t)0x00000004)
#define FMC_CTRL_SNUM          ((uint32_t)0x00000008)
#define FMC_CTRL_START         ((uint32_t)0x00010000)
#define FMC_CTRL_LOCK          ((uint32_t)0x80000000)

/** FMC OPTCTRL register Bits definition */
#define FMC_OPTCTRL_OPTLOCK    ((uint32_t)0x00000001)
#define FMC_OPTCTRL_OPTSTART   ((uint32_t)0x00000002)
#define FMC_OPTCTRL_BORLVL     ((uint32_t)0x0000000C)

/** ACCTRL  register byte 0 (Bits[7:0]) base address */
#define ACCTRL_BYTE0_ADDRESS          ((uint32_t)0x40023C00)

/** OPTCTRL register byte 0 (Bits[7:0]) base address */
#define OPTCTRL_BYTE0_ADDRESS         ((uint32_t)0x40023C14)

/** OPTCTRL register byte 1 (Bits[15:8]) base address */
#define OPTCTRL_BYTE1_ADDRESS         ((uint32_t)0x40023C15)

/** OPTCTRL register byte 2 (Bits[23:16]) base address */
#define OPTCTRL_BYTE2_ADDRESS         ((uint32_t)0x40023C16)

/** OPTCTRL register byte 3 (Bits[31:24]) base address */
#define OPTCTRL_BYTE3_ADDRESS         ((uint32_t)0x40023C17)

/**@} end of group FMC_Macros*/

/** @addtogroup FMC_Fuctions Fuctions
  @{
*/

/** FMC Interface configuration functions */
void FMC_ConfigLatency(FMC_LATENCY_T latency);
void FMC_EnablePrefetchBuffer(void);
void FMC_DisablePrefetchBuffer(void);
void FMC_EnableInstructionCache(void);
void FMC_DisableInstructionCache(void);
void FMC_EnableDataCache(void);
void FMC_DisableDataCache(void);
void FMC_ResetInstructionCache(void);
void FMC_ResetDataCache(void);

/** FMC Memory Programming functions */
void FMC_Unlock(void);
void FMC_Lock(void);
FMC_STATUS_T FMC_EraseSector(FMC_SECTOR_T sector, FMC_VOLTAGE_T voltageRange);
FMC_STATUS_T FMC_EraseAllSectors(FMC_VOLTAGE_T voltageRange);
FMC_STATUS_T FMC_ProgramDoubleWord(uint32_t address, uint64_t data);
FMC_STATUS_T FMC_ProgramWord(uint32_t address, uint32_t data);
FMC_STATUS_T FMC_ProgramHalfWord(uint32_t address, uint16_t data);
FMC_STATUS_T FMC_ProgramByte(uint32_t address, uint8_t data);

/** Option Bytes Programming functions */
void FMC_UnlockOptionByte(void);
void FMC_LockOptionByte(void);
void FMC_OPT_EnableWriteProtect(FMC_OPT_WRP_T wrp);
void FMC_OPT_DisableWriteProtect(FMC_OPT_WRP_T wrp);
void FMC_OPT_ConfigReadProtect(FMC_OPT_RDP_T rdp);
void FMC_OPT_ConfigUser(FMC_OPT_IWDT_T iwdt, FMC_OPT_STOP_T stop, FMC_OPT_STDBY_T stdby);
void FMC_OPT_ConfigBrownoutReset(FMC_OPT_BOR_T bor);
FMC_STATUS_T FMC_OPT_Launch(void);
uint8_t FMC_OPT_ReadUser(void);
uint16_t FMC_OPT_ReadWriteProtect(void);
uint8_t FMC_OPT_ReadProtectLevel(void);
uint8_t FMC_OPT_ReadBrownoutReset(void);

/** Interrupts and flags management functions */
void FMC_EnableInterrupt(uint32_t interrupt);
void FMC_DisableInterrupt(uint32_t interrupt);
uint8_t FMC_ReadStatusFlag(FMC_FLAG_T flag);
void FMC_ClearStatusFlag(uint32_t flag);
FMC_STATUS_T FMC_ReadStatus(void);
FMC_STATUS_T FMC_WaitForLastOperation(void);

/**@} end of group FMC_Fuctions*/
/**@} end of group FMC_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_FMC_H */
