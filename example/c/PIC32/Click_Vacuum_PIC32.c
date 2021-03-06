/*
Example for Vacuum Click

    Date          : sep 2018.
    Author        : Katarina Perendic

Test configuration PIC32 :
    
    MCU                : P32MX795F512L
    Dev. Board         : EasyPIC Fusion v7
    PIC32 Compiler ver : v4.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initialization driver init and calibration of the chip to start measuring
- Application Task - (code snippet) - Reads vacuum percentage that sensor reads

*/

#include "Click_Vacuum_types.h"
#include "Click_Vacuum_config.h"

float Vacuum;
float Vacuum_volt;
char demoText[50];

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_VACUUM_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    vacuum_i2cDriverInit( (T_VACUUM_P)&_MIKROBUS1_GPIO, (T_VACUUM_P)&_MIKROBUS1_I2C, 0x4D );
    vacuum_calibration();
}

void applicationTask()
{
    mikrobus_logWrite("Vacuum (voltage) : ", _LOG_TEXT);
    Vacuum_volt = vacuum_getVoltage();
    FloatToStr(Vacuum_volt, demoText);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" V", _LOG_LINE);
    
    mikrobus_logWrite("Percentage of vacuum: ", _LOG_TEXT);
    Vacuum = vacuum_getPercentageOfVacuum();
    FloatToStr(Vacuum, demoText);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    mikrobus_logWrite(" ", _LOG_LINE);
    Delay_ms(300);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}