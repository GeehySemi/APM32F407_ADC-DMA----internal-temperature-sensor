/*!
 * @file        apm32f4xx_wwdt.h
 *
 * @brief       This file contains all the functions prototypes for the WWDT firmware library
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

#ifndef __APM32F4XX_WWDT_H
#define __APM32F4XX_WWDT_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "apm32f4xx.h"

/** @addtogroup Peripherals_Library Standard Peripheral Library
  @{
*/

/** @addtogroup WWDT_Driver WWDT Driver
  @{
*/

/** @addtogroup  WWDT_Enumerations Enumerations
  @{
*/

/**
 * @brief WWDT Timebase(Prescaler)
 */
typedef enum
{
    WWDT_TIME_BASE_1,
    WWDT_TIME_BASE_2,
    WWDT_TIME_BASE_4,
    WWDT_TIME_BASE_8
}WWDT_TIME_BASE_T;

/**@} end of group WWDT_Enumerations*/

/** @addtogroup  WWDT_Fuctions Fuctions
  @{
*/

/** WWDT reset */
void WWDT_Reset(void);

/** Config WWDT Timebase */
void WWDT_ConfigTimebase(WWDT_TIME_BASE_T timeBase);

/** Config Window Data */
void WWDT_ConfigWindowData(uint8_t windowData);

/** Config Couter */
void WWDT_ConfigCounter(uint8_t counter);

/** Enable WWDT and Early Wakeup interrupt */
void WWDT_EnableEWI(void); //5
void WWDT_Enable(uint8_t count);

/** Read Flag and Clear Flag */
uint8_t WWDT_ReadFlag(void);
void WWDT_ClearFlag(void);

/**@} end of group WWDT_Fuctions*/
/**@} end of group WWDT_Driver */
/**@} end of group Peripherals_Library*/

#ifdef __cplusplus
}
#endif

#endif /* __APM32F4XX_WWDT_H */
