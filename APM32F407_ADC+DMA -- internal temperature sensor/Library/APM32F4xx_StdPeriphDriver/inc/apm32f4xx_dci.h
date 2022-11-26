/*!
 * @file        apm32f4xx_dci.h
 *
 * @brief       This file contains all the functions prototypes for the DCI firmware library
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

#ifndef __APM32F4XX_DCI_H
#define __APM32F4XX_DCI_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup DCI_Driver DCI Driver
  @{
*/

/** @addtogroup DCI_Enumerations Enumerations
  @{
*/

/**
 * @brief DCI Capture Mode
 */
typedef enum
{
    DCI_CAPTURE_MODE_CONTINUOUS,
    DCI_CAPTURE_MODE_SNAPSHOT
} DCI_CAPTURE_MODE_T;

/**
 * @brief DCI Synchronization Mode
 */
typedef enum
{
    DCI_SYNCHRO_MODE_HARDWARE,
    DCI_SYNCHRO_MODE_EMBEDDED
} DCI_SYNCHRO_MODEVAL_T;

/**
 * @brief DCI Pixel Clock Polarity
 */
typedef enum
{
    DCI_PCK_POL_FALLING,
    DCI_PCK_POL_RISING
} DCI_PCK_POL_T;

/**
 * @brief DCI VSYNC Polarity
 */
typedef enum
{
    DCI_VSYNC_POL_LOW,
    DCI_VSYNC_POL_HIGH
} DCI_VSYNC_POL_T;

/**
 * @brief DCI HSYNC Polarity
 */
typedef enum
{
    DCI_HSYNC_POL_LOW,
    DCI_HSYNC_POL_HIGH
} DCI_HSYNC_POL_T;

/**
 * @brief DCI Capture Rate
 */
typedef enum
{
    DCI_CAPTURE_RATE_ALL_FRAME,
    DCI_CAPTURE_RATE_1OF2_FRAME,
    DCI_CAPTURE_RATE_1OF4_FRAME
} DCI_CAPTURE_RATE_T;

/**
 * @brief DCI Extended Data Mode
 */
typedef enum
{
    DCI_EXTENDED_DATA_MODE_8B,
    DCI_EXTENDED_DATA_MODE_10B,
    DCI_EXTENDED_DATA_MODE_12B,
    DCI_EXTENDED_DATA_MODE_14B
} DCI_EXTENDED_DATA_MODE_T;

/**
 * @brief DCI interrupt sources
 */
typedef enum
{
    DCI_INT_CC    =((uint16_t)0x0001),
    DCI_INT_OVR   =((uint16_t)0x0002),
    DCI_INT_ERR   =((uint16_t)0x0004),
    DCI_INT_VSYNC =((uint16_t)0x0008),
    DCI_INT_LINE  =((uint16_t)0x0010),
} DCI_INT_T;

/**
 * @brief DCI flags
 */
typedef enum
{
    /** DCI RINTSTS register */
    DCI_FLAG_CCI        =((uint16_t)0x0001),
    DCI_FLAG_OVRI       =((uint16_t)0x0002),
    DCI_FLAG_ERRI       =((uint16_t)0x0004),
    DCI_FLAG_VSYNCI     =((uint16_t)0x0008),
    DCI_FLAG_LINEI      =((uint16_t)0x0010),
    /** DCI MINTSTS register */
    DCI_FLAG_CCMI       =((uint16_t)0x1001),
    DCI_FLAG_OVRMI      =((uint16_t)0x1002),
    DCI_FLAG_ERRMI      =((uint16_t)0x1004),
    DCI_FLAG_VSYNCMI    =((uint16_t)0x1008),
    DCI_FLAG_LINEMI     =((uint16_t)0x1010),
    /** DCI STS register */
    DCI_FLAG_HSYNC      =((uint16_t)0x2001),
    DCI_FLAG_VSYNC      =((uint16_t)0x2002),
    DCI_FLAG_FNE        =((uint16_t)0x2004),
} DCI_FLAG_T;

/**@} end of group DCI_Enumerations*/

/** @addtogroup DCI_Structure Data Structure
  @{
*/

/**
 * @brief DCI Config structure definition
 */
typedef struct
{
    DCI_CAPTURE_MODE_T        captureMode;      //!< Specifies the Capture Mode: Continuous or Snapshot.

    DCI_SYNCHRO_MODEVAL_T     synchroMode;      //!< Specifies the Synchronization Mode: Hardware or Embedded.

    DCI_PCK_POL_T             pckPolarity;      //!< Specifies the Pixel clock polarity: Falling or Rising.

    DCI_VSYNC_POL_T           vsyncPolarity;    //!< Specifies the Vertical synchronization polarity: High or Low.

    DCI_HSYNC_POL_T           hsyncPolarity;    //!< Specifies the Horizontal synchronization polarity: High or Low.

    DCI_CAPTURE_RATE_T        capturerate;      //!< Specifies the frequency of frame capture: All, 1/2 or 1/4.

    DCI_EXTENDED_DATA_MODE_T  extendedDataMode; //!< Specifies the data width: 8-bit, 10-bit, 12-bit or 14-bit.
} DCI_Config_T;

/**
 * @brief DCI CROP Init structure definition
 */
typedef struct
{
    uint16_t    verticalStartLine;      //!< Vertical start line count from which the image capture(between 0x00 and 0x1FFF).

    uint16_t    horizontalOffsetCount;  //!< number of pixel clocks to count before starting a capture(between 0x00 and 0x3FFF).

    uint16_t    verticalLineCount;      //!< number of lines to be captured from the starting point(between 0x00 and 0x3FFF).

    uint16_t    captureCount;           //!< number of pixel clocks to be captured from the starting(between 0x00 and 0x3FFF).
} DCI_CropConfig_T;

/**
  * @brief   DCI Embedded Synchronisation CODE Init structure definition
  */
typedef struct
{
    uint8_t     frameStartCode;      //!< Specifies the code of the frame start delimiter.
    uint8_t     lineStartCode;       //!< Specifies the code of the line start delimiter.
    uint8_t     lineEndCode;         //!< Specifies the code of the line end delimiter.
    uint8_t     frameEndCode;        //!< Specifies the code of the frame end delimiter.
} DCI_CodeConfig_T;

/**@} end of group DCI_Structure*/

/** @addtogroup DCI_Fuctions Fuctions
  @{
*/

/** DCI Configuration */
void DCI_Rest(void);
void DCI_Config(DCI_Config_T* dciConfig);
void DCI_ConfigStructInit(DCI_Config_T* dciConfig);
void DCI_ConfigCROP(DCI_CropConfig_T* cropConfig);
void DCI_EnableCROP(void);
void DCI_DisableCROP(void);
void DCI_ConfigSynchroCode(DCI_CodeConfig_T* codeConfig);
void DCI_EnableJPEG(void);
void DCI_DisableJPEG(void);

/** DCI Image capture */
void DCI_Enable(void);
void DCI_Disable(void);
void DCI_EnableCapture(void);
void DCI_DisableCapture(void);
uint32_t DCI_ReadData(void);

/** Interrupts and flags */
void DCI_EnableInterrupt(uint32_t interrupt);
void DCI_DisableInterrupt(uint32_t interrupt);
uint16_t DCI_ReadStatusFlag(DCI_FLAG_T flag);
void DCI_ClearStatusFlag(uint16_t flag);
uint16_t DCI_ReadIntFlag(DCI_INT_T flag);
void DCI_ClearIntFlag(uint16_t flag);

/**@} end of group DCI_Fuctions*/
/**@} end of group DCI_Driver */
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_DCI_H */

