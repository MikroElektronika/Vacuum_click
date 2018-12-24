#line 1 "C:/Users/katarina.perendic/Desktop/Vacuum click/example/c/ARM/STM/STM_AppDemo/Click_Vacuum_STM.c"
#line 1 "c:/users/katarina.perendic/desktop/vacuum click/example/c/arm/stm/stm_appdemo/click_vacuum_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdbool.h"



 typedef char _Bool;
#line 1 "c:/users/katarina.perendic/desktop/vacuum click/example/c/arm/stm/stm_appdemo/click_vacuum_config.h"
#line 1 "c:/users/katarina.perendic/desktop/vacuum click/example/c/arm/stm/stm_appdemo/click_vacuum_types.h"
#line 19 "c:/users/katarina.perendic/desktop/vacuum click/example/c/arm/stm/stm_appdemo/click_vacuum_config.h"
const uint32_t _VACUUM_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 70 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
void vacuum_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 77 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
void vacuum_gpioDriverInit( const uint8_t*  gpioObj);
#line 86 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
uint16_t vacuum_readData();
#line 93 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
float vacuum_getVoltage();
#line 100 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
float vacuum_getPressure();
#line 107 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
float vacuum_getPercentageOfVacuum();
#line 112 "c:/users/katarina.perendic/desktop/vacuum click/library/__vacuum_driver.h"
void vacuum_calibration();
#line 30 "C:/Users/katarina.perendic/Desktop/Vacuum click/example/c/ARM/STM/STM_AppDemo/Click_Vacuum_STM.c"
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
 vacuum_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x4D );
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
