/*
    __vacuum_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __vacuum_driver.h
@brief    Vacuum Driver
@mainpage Vacuum Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   VACUUM
@brief      Vacuum Click Driver
@{

| Global Library Prefix | **VACUUM** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **sep 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _VACUUM_H_
#define _VACUUM_H_

/** 
 * @macro T_VACUUM_P
 * @brief Driver Abstract type 
 */
#define T_VACUUM_P    const uint8_t*

/** @defgroup VACUUM_COMPILE Compilation Config */              /** @{ */

//  #define   __VACUUM_DRV_SPI__                            /**<     @macro __VACUUM_DRV_SPI__  @brief SPI driver selector */
   #define   __VACUUM_DRV_I2C__                            /**<     @macro __VACUUM_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __VACUUM_DRV_UART__                           /**<     @macro __VACUUM_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup VACUUM_VAR Variables */                           /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup VACUUM_INIT Driver Initialization */              /** @{ */

#ifdef   __VACUUM_DRV_SPI__
void vacuum_spiDriverInit(T_VACUUM_P gpioObj, T_VACUUM_P spiObj);
#endif
#ifdef   __VACUUM_DRV_I2C__
void vacuum_i2cDriverInit(T_VACUUM_P gpioObj, T_VACUUM_P i2cObj, uint8_t slave);
#endif
#ifdef   __VACUUM_DRV_UART__
void vacuum_uartDriverInit(T_VACUUM_P gpioObj, T_VACUUM_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void vacuum_gpioDriverInit(T_VACUUM_P gpioObj);
                                                                       /** @} */
/** @defgroup VACUUM_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Function for reads 12 bit ADC data
 *
 * @retval ADC value
 */
uint16_t vacuum_readData();

/**
 * @brief Voltage reading function
 *
 * @retval Voltage returned by the sensor
 */
float vacuum_getVoltage();

/**
 * @brief Function for converting ADC value to pressure data
 *
 * @retval Pressure data in mBar
 */
float vacuum_getPressure();

/**
 * @brief Function for converting ADC value to percentage of Vacuum
 *
 * @retval percentage of Vacuum
 */
float vacuum_getPercentageOfVacuum();

/**
 * @brief Sensor calibration
 */
void vacuum_calibration();





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Vacuum_STM.c
    @example Click_Vacuum_TIVA.c
    @example Click_Vacuum_CEC.c
    @example Click_Vacuum_KINETIS.c
    @example Click_Vacuum_MSP.c
    @example Click_Vacuum_PIC.c
    @example Click_Vacuum_PIC32.c
    @example Click_Vacuum_DSPIC.c
    @example Click_Vacuum_AVR.c
    @example Click_Vacuum_FT90x.c
    @example Click_Vacuum_STM.mbas
    @example Click_Vacuum_TIVA.mbas
    @example Click_Vacuum_CEC.mbas
    @example Click_Vacuum_KINETIS.mbas
    @example Click_Vacuum_MSP.mbas
    @example Click_Vacuum_PIC.mbas
    @example Click_Vacuum_PIC32.mbas
    @example Click_Vacuum_DSPIC.mbas
    @example Click_Vacuum_AVR.mbas
    @example Click_Vacuum_FT90x.mbas
    @example Click_Vacuum_STM.mpas
    @example Click_Vacuum_TIVA.mpas
    @example Click_Vacuum_CEC.mpas
    @example Click_Vacuum_KINETIS.mpas
    @example Click_Vacuum_MSP.mpas
    @example Click_Vacuum_PIC.mpas
    @example Click_Vacuum_PIC32.mpas
    @example Click_Vacuum_DSPIC.mpas
    @example Click_Vacuum_AVR.mpas
    @example Click_Vacuum_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __vacuum_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */