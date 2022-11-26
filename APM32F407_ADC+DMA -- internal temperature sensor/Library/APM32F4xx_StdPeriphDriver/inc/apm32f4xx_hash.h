/*!
 * @file        apm32f4xx_hash.c
 *
 * @brief       This file provides all the HASH firmware functions
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


#ifndef __APM32F4XX_HASH_H
#define __APM32F4XX_HASH_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup HASH_Driver HASH Driver
  @{
*/

/** @addtogroup HASH_Enumerations Enumerations
  @{
*/

/**
 * @brief HASH Algo Selection
 */
typedef enum
{
    HASH_ALGO_SELECTION_SHA1,
    HASH_ALGO_SELECTION_MD5
} HASH_ALGO_SELECTION_T;

/**
 * @brief HASH processor Algorithm Mode
 */
typedef enum
{
    HASH_ALGO_MODE_HASH,
    HASH_ALGO_MODE_HMAC
} HASH_ALGO_MODE_T;

/**
 * @brief HASH Data Type
 */
typedef enum
{
    HASH_DATA_TYPE_32B,
    HASH_DATA_TYPE_16B,
    HASH_DATA_TYPE_8B,
    HASH_DATA_TYPE_1B
} HASH_DATA_TYPE_T;

/**
 * @brief HASH HMAC Long key only for HMAC mode
 */
typedef enum
{
    HASH_HMAC_KEY_TYPE_SHORTKEY,
    HASH_HMAC_KEY_TYPE_LONGKEY
} HASH_HMAC_KEY_TYPE_T;

/**
 * @brief HASH interrupts
 */
typedef enum
{
    HASH_INT_INDATAINT  = BIT0,
    HASH_INT_DCALCINT   = BIT1,
} HASH_INT_T;

/**
 * @brief HASH flag
 */
typedef enum
{
    HASH_FLAG_INDATAINT    = BIT0,
    HASH_FLAG_DCALCINT     = BIT1,
    HASH_FLAG_DMA          = BIT2,
    HASH_FLAG_BUSY         = BIT3,
    HASH_FLAG_DINNEMPT     = BIT12
} HASH_FLAG_T;

/**
 * @brief HASH interrupt flag
 */
typedef enum
{
    HASH_INT_FLAG_INDATA    = BIT0,
    HASH_INT_FLAG_DCALC     = BIT1
} HASH_INT_FLAG_T;

/**@} end of group HASH_Enumerations*/

/** @addtogroup HASH_Structure Data Structure
  @{
*/

/**
 * @brief HASH Init structure
 */
typedef struct
{
    HASH_ALGO_SELECTION_T    algoSelect;    //!< SHA-1 or MD5.
    HASH_ALGO_MODE_T         algoMode;      //!< HASH or HMAC.
    HASH_DATA_TYPE_T         dataType;      //!< 32-bit data, 16-bit data, 8-bit data or bit string.
    HASH_HMAC_KEY_TYPE_T     hmacKeyType;   //!< HMAC Short key or HMAC Long Key.
} HASH_Config_T;

/**
 * @brief HASH message digest result structure
 */
typedef struct
{
    uint32_t Data[5];     /** Message digest result :
                             5x 32bit words for SHA-1 or
                             4x 32bit words for MD5 */
} HASH_MessageDigest_T;

/**
 * @brief HASH context swapping structure
 */
typedef struct
{
    uint32_t HASH_INT;
    uint32_t HASH_START;
    uint32_t HASH_CTRL;
    uint32_t HASH_CTSWAP[51];
} HASH_Context_T;

/**@} end of group HASH_Structure*/

/** @addtogroup HASH_Fuctions Fuctions
  @{
*/

/** HASH Reset */
void HASH_Reset(void);

/** Configuration */
void HASH_Config(HASH_Config_T* hashConfig);
void HASH_ConfigStructInit(HASH_Config_T* hashConfig);
void HASH_ResetProceCore(void);

/** Message Digest start */
void HASH_ConfigLastWordValidBitsNbr(uint16_t validNumber);
void HASH_WritesInputData(uint32_t data);
uint8_t HASH_ReadInFIFOWordsNbr(void);
void HASH_ReadDigest(HASH_MessageDigest_T* messageDigest);
void HASH_StartDigest(void);

/** Context swapping */
void HASH_ReadContext(HASH_Context_T* contextRead);
void HASH_WriteContext(HASH_Context_T* contextWrite);

/** Regular Channels DMA */
void HASH_EnableDMA(void);
void HASH_DisableDMA(void);

/** Injected channels Configuration */
void HASH_EnableInterrupt(uint32_t interrupt);
void HASH_DisableInterrupt(uint32_t interrupt);
uint8_t HASH_ReadFlagStatus(HASH_FLAG_T flag);
void HASH_ClearStatusFlag(HASH_FLAG_T flag);
uint8_t HASH_ReadIntFlag(HASH_INT_FLAG_T flag);
void HASH_ClearIntFlag(HASH_INT_FLAG_T flag);

/** Waits for processing data */
uint8_t HASH_WaitForCompute(uint32_t timeOut);

/** High Level SHA1 Compute */
uint8_t HASH_ComputeSHA1(uint8_t* inBuffer, uint32_t lenBuffer,
                         uint8_t outBuffer[20]);
uint8_t HMAC_ComputeSHA1(uint8_t* key, uint32_t lenkey, uint8_t* inBuffer,
                         uint32_t lenBuffer, uint8_t outBuffer[20]);

/** High Level MD5 Compute */
uint8_t HASH_ComputeMD5(uint8_t* inBuffer, uint32_t lenBuffer,
                        uint8_t outBuffer[16]);
uint8_t HMAC_ComputeMD5(uint8_t* key, uint32_t keylen, uint8_t* inBuffer,
                        uint32_t lenBuffer, uint8_t outBuffer[16]);

/**@} end of group HASH_Fuctions*/
/**@} end of group HASH_Driver */
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /*__APM32F4XX_HASH_H */
