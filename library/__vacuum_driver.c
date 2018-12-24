/*
    __vacuum_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__vacuum_driver.h"
#include "__vacuum_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __VACUUM_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static float _pressure = 1023.0;
/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __VACUUM_DRV_SPI__

void vacuum_spiDriverInit(T_VACUUM_P gpioObj, T_VACUUM_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __VACUUM_DRV_I2C__

void vacuum_i2cDriverInit(T_VACUUM_P gpioObj, T_VACUUM_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __VACUUM_DRV_UART__

void vacuum_uartDriverInit(T_VACUUM_P gpioObj, T_VACUUM_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
/* ----------------------------------------------------------- IMPLEMENTATION */

uint16_t vacuum_readData()
{
    uint8_t readReg[ 2 ];
    uint16_t readData;
    
    hal_i2cStart();
    hal_i2cRead(_slaveAddress, readReg, 2, END_MODE_STOP);

    readData = readReg[ 0 ];
    readData = readData << 8;
    readData = readData | readReg[ 1 ];
    
    return readData;
}

float vacuum_getVoltage()
{
    uint16_t readData;
    float voltage;

    readData = vacuum_readData();
    voltage = (readData * 5.0) / 4096.0;
    
    return voltage;
}

float vacuum_getPressure()
{
    uint16_t pressure;
    float pressure_mBar;

    pressure = vacuum_readData();
    pressure_mBar = ((pressure - 2400.0) / ((13107.0) / 100.0));
    pressure_mBar *= 100.0;// mBar
    
    return pressure_mBar;
}

float vacuum_getPercentageOfVacuum()
{
    float pressure_mBar;
    float vacuum;
    
    pressure_mBar = vacuum_getPressure();
    vacuum = (_pressure - pressure_mBar)/18.0;
    
    if( vacuum < 1 )
    {
        return 0;
    }
    else if( vacuum > 100 )
    {
        return 100;
    }
    
    return  vacuum;
}

void vacuum_calibration()
{
    float pressure_mBar;
    _pressure = vacuum_getPressure();
}


/* -------------------------------------------------------------------------- */
/*
  __vacuum_driver.c

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