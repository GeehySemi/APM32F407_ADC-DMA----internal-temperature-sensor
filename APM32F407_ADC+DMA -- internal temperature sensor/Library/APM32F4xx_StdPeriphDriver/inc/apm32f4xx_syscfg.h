/*!
 * @file        apm32f4xx_syscfg.h
 *
 * @brief       This file contains all the functions prototypes for the SYSCFG firmware library
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

#ifndef __APM32F4XX_SYSCFG_H
#define __APM32F4XX_SYSCFG_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup SYSCFG_Driver SYSCFG Driver
  @{
*/

/** @addtogroup SYSCFG_Enumerations Enumerations
  @{
*/

/**
 * @brief SYSCFG EINT Port Sources
 */
typedef enum
{
    SYSCFG_PORT_GPIOA, //!< EXTI_Port Source GPIOA
    SYSCFG_PORT_GPIOB, //!< EXTI_Port Source GPIOB
    SYSCFG_PORT_GPIOC, //!< EXTI_Port Source GPIOC
    SYSCFG_PORT_GPIOD, //!< EXTI_Port Source GPIOD
    SYSCFG_PORT_GPIOE, //!< EXTI_Port Source GPIOE
    SYSCFG_PORT_GPIOF, //!< EXTI_Port Source GPIOF
    SYSCFG_PORT_GPIOG, //!< EXTI_Port Source GPIOG
    SYSCFG_PORT_GPIOH, //!< EXTI_Port Source GPIOH
    SYSCFG_PORT_GPIOI  //!< EXTI_Port Source GPIOI
} SYSCFG_PORT_T;

/**
 * @brief SYSCFG EINT Pin Sources
 */
typedef enum
{
    SYSCFG_PIN_0,  //!< Pin Source 0
    SYSCFG_PIN_1,  //!< Pin Source 1
    SYSCFG_PIN_2,  //!< Pin Source 2
    SYSCFG_PIN_3,  //!< Pin Source 3
    SYSCFG_PIN_4,  //!< Pin Source 4
    SYSCFG_PIN_5,  //!< Pin Source 5
    SYSCFG_PIN_6,  //!< Pin Source 6
    SYSCFG_PIN_7,  //!< Pin Source 7
    SYSCFG_PIN_8,  //!< Pin Source 8
    SYSCFG_PIN_9,  //!< Pin Source 9
    SYSCFG_PIN_10, //!< Pin Source 10
    SYSCFG_PIN_11, //!< Pin Source 11
    SYSCFG_PIN_12, //!< Pin Source 12
    SYSCFG_PIN_13, //!< Pin Source 13
    SYSCFG_PIN_14, //!< Pin Source 14
    SYSCFG_PIN_15  //!< Pin Source 15
} SYSCFG_PIN_T;

/**
 * @brief SYSCFG Memory Remap Config
 */
typedef enum
{
    SYSCFG_REMAP_FLASH,
    SYSCFG_REMAP_SYSTEM_FLASH,
    SYSCFG_REMAP_SMC_BANK1,
    SYSCFG_REMAP_SRAM
} SYSCFG_REMAP_T;

/**
 * @brief SYSCFG Ethernet PHY interface selection
 */
typedef enum
{
    SYSCFG_INTERFACE_MII,  //!< SYSCFG Media Interface MII
    SYSCFG_INTERFACE_RMII  //!< SYSCFG Media Interface RMII
} SYSCFG_INTERFACE_T;

/**@} end of group SYSCFG_Enumerations*/

/** @addtogroup SYSCFG_Fuctions Fuctions
  @{
*/

void SYSCFG_Reset(void);
void SYSCFG_ConfigMemoryRemap(SYSCFG_REMAP_T memory);
void SYSCFG_ConfigEINTLine(SYSCFG_PORT_T port, SYSCFG_PIN_T pin);
void SYSCFG_ConfigMediaInterface(SYSCFG_INTERFACE_T media);

/** Compensation Cell */
void SYSCFG_EnableCompensationCell(void);
void SYSCFG_DisableCompensationCell(void);
uint8_t SYSCFG_ReadCompensationCellStatus(void);

/**@} end of group SYSCFG_Fuctions*/
/**@} end of group SYSCFG_Driver*/
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /*__APM32F4XX_SYSCFG_H */
