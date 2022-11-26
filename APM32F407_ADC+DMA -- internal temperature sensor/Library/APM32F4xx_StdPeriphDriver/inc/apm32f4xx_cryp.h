/*!
 * @file        apm32f4xx_cryp.h
 *
 * @brief       This file contains all the functions prototypes for the CRYP firmware library
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

#ifndef __APM32F4XX_CRYP_H
#define __APM32F4XX_CRYP_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup CRYP_Driver CRYP Driver
  @{
*/

/** @addtogroup CRYP_Enumerations Enumerations
  @{
*/

/**
 * @brief CRYP Algorithm Direction
 */
typedef enum
{
    CRYP_ALGODIR_ENCRYPT,
    CRYP_ALGODIR_DECRYPT
} CRYP_ALGODIR_T;

/**
 * @brief CRYP Algorithm Mode
 */
typedef enum
{
    /** TDES Modes */
    CRYP_ALGOMODE_TDES_ECB = 0x00,
    CRYP_ALGOMODE_TDES_CBC = 0x01,
    /** DES Modes */
    CRYP_ALGOMODE_DES_ECB  = 0x02,
    CRYP_ALGOMODE_DES_CBC  = 0x03,
    /** AES Modes */
    CRYP_ALGOMODE_AES_ECB  = 0x04,
    CRYP_ALGOMODE_AES_CBC  = 0x05,
    CRYP_ALGOMODE_AES_CTR  = 0x06,
    CRYP_ALGOMODE_AES_KEY  = 0x07
} CRYP_ALGOMODE_T;

/**
 * @brief CRYP Data Type
 */
typedef enum
{
    CRYP_DATATYPE_32B,
    CRYP_DATATYPE_16B,
    CRYP_DATATYPE_8B,
    CRYP_DATATYPE_1B
} CRYP_DATATYPE_T;

/**
 * @brief CRYP Key Size (only AES)
 */
typedef enum
{
    CRYP_KEYSIZE_128B,
    CRYP_KEYSIZE_192B,
    CRYP_KEYSIZE_256B
} CRYP_KEYSIZE_T;

/**
  * @brief CRYP flag
  */
typedef enum
{
    /** CRYP STS register */
    CRYP_FLAG_IFEMPT   =  0x01,
    CRYP_FLAG_IFFULL   =  0x02,
    CRYP_FLAG_OFEMPT   =  0x04,
    CRYP_FLAG_OFFULL   =  0x08,
    CRYP_FLAG_BUSY     =  0x10,
    /** CRYP INTSTS register */
    CRYP_FLAG_INISTS   =  0x21,
    CRYP_FLAG_OUTISTS  =  0x22
} CRYP_FLAG_T;

/**
 * @brief CRYP interrupt
 */
typedef enum
{
    CRYP_INT_IN  = 0x01,
    CRYP_INT_OUT = 0x02
} CRYP_INT_T;

/**
 * @brief CRYP Encryption/Decryption_mode
 */
typedef enum
{
    CRYP_MODE_DECRYPT  = 0x00,
    CRYP_MODE_ENCRYPT  = 0x01
} CRYP_MODE_T;

/**
 * @brief CRYP DMA transfer request
 */
typedef enum
{
    CRYP_DMAREQ_DATAIN  =  0x01,
    CRYP_DMAREQ_DATAOUT =  0x02
} CRYP_DMAREQ_T;

/**@} end of group CRYP_Enumerations*/

/** @addtogroup CRYP_Structure Data Structure
  @{
*/

/**
 * @brief CRYP Config structure definition
 */
typedef struct
{
    CRYP_ALGODIR_T      algoDir;
    CRYP_ALGOMODE_T     algoMode;
    CRYP_DATATYPE_T     dataType;
    CRYP_KEYSIZE_T      keySize;
} CRYP_Config_T;

/**
 * @brief   CRYP KeyConfig structure definition
 */
typedef struct
{
    uint32_t          key0Left;
    uint32_t          key0Right;
    uint32_t          key1Left;
    uint32_t          key1Right;
    uint32_t          key2Left;
    uint32_t          key2Right;
    uint32_t          key3Left;
    uint32_t          key3Right;
} CRYP_KeyConfig_T;

/**
 * @brief   CRYP Initialization Vectors (IV) structure definition
 */
typedef struct
{
    uint32_t          IV0Left;
    uint32_t          IV0Right;
    uint32_t          IV1Left;
    uint32_t          IV1Right;
} CRYP_IVConfig_T;

/**
 * @brief  CRYP context swapping structure definition
 */
typedef struct
{
    /** Current Configuration */
    uint32_t    curCTRL;
    /** IV */
    uint32_t    IV0L;
    uint32_t    IV0R;
    uint32_t    IV1L;
    uint32_t    IV1R;
    /** KEY */
    uint32_t    K0L;
    uint32_t    K0R;
    uint32_t    K1L;
    uint32_t    K1R;
    uint32_t    K2L;
    uint32_t    K2R;
    uint32_t    K3L;
    uint32_t    K3R;
} CRYP_Context_T;

/**@} end of group CRYP_Structure*/

/** @addtogroup CRYP_Fuctions Fuctions
  @{
*/

/** CRYP Configuration */
void CRYP_Reset(void);
void CRYP_Config(CRYP_Config_T* crypConfig);
void CRYP_ConfigStructInit(CRYP_Config_T* crypConfig);
void CRYP_ConfigKey(CRYP_KeyConfig_T* keyConfig);
void CRYP_ConfigKeyStructInit(CRYP_KeyConfig_T* keyConfig);
void CRYP_ConfigIV(CRYP_IVConfig_T* IVConfig);
void CRYP_ConfigIVStructInit(CRYP_IVConfig_T* IVConfig);
void CRYP_Enable(void);
void CRYP_Disable(void);
void CRYP_FlushFIFO(void);

/** CRYP Data processing */
void CRYP_InData(uint32_t Data);
uint32_t CRYP_OutData(void);

/** CRYP Context swapping */
uint32_t CRYP_SaveContext(CRYP_Context_T* context, CRYP_KeyConfig_T* keyConfig);
void CRYP_RestoreContext(CRYP_Context_T* context);

/** CRYP DMA */
void CRYP_EnableDMA(CRYP_DMAREQ_T dmaReq);
void CRYP_DisableDMA(CRYP_DMAREQ_T dmaReq);

/** CRYP Interrupt and flag */
void CRYP_EnableInterrupt(uint8_t interrupt);
void CRYP_DisableInterrupt(uint8_t interrupt);
uint8_t CRYP_ReadIntFlag(CRYP_INT_T flag);
uint8_t CRYP_ReadStatusFlag(CRYP_FLAG_T flag);
uint8_t CRYP_ReadCmdStatus(void);

/** High Level AES */
uint8_t CRYP_AES_ECB(CRYP_MODE_T mode, uint8_t *key,    uint16_t keysize,
                       uint8_t *input, uint32_t length, uint8_t  *output);

uint8_t CRYP_AES_CBC(CRYP_MODE_T mode, uint8_t *key,    uint16_t keysize,
                                       uint8_t IV[16],  uint8_t  *input,
                                       uint32_t length, uint8_t  *output);

uint8_t CRYP_AES_CTR(CRYP_MODE_T mode, uint8_t  *key,   uint16_t keysize,
                                       uint8_t  IV[16], uint8_t  *input,
                                       uint32_t length, uint8_t  *output);

/** High Level DES */
uint8_t CRYP_DES_ECB(CRYP_MODE_T mode, uint8_t key[8], uint8_t *input,
                                      uint32_t length, uint8_t *output);

uint8_t CRYP_DES_CBC(CRYP_MODE_T mode, uint8_t key[8],  uint8_t *input,
                        uint8_t IV[8], uint32_t length, uint8_t *output);

/** High Level TDES */
uint8_t CRYP_TDES_ECB(CRYP_MODE_T mode, uint8_t key[24], uint8_t *input,
                                       uint32_t length,  uint8_t *output);

uint8_t CRYP_TDES_CBC(CRYP_MODE_T mode,uint8_t key[24], uint8_t *input,
                        uint8_t IV[8], uint32_t length, uint8_t *output);

/**@} end of group CRYP_Fuctions*/
/**@} end of group CRYP_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_CRYP_H */
