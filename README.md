![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Vacuum Click

- **CIC Prefix**  : VACUUM
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : sep 2018.

---

### Software Support

We provide a library for the Vacuum Click on our [LibStock](https://libstock.mikroe.com/projects/view/2572/vacuum-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver.
The library includes function for reads ADC data and function for converting ADC value to percentage of Vacuum and pressure in mBar.
The user also has the function for sensor calibration.

Key functions :

- ``` void vacuum_calibration() ``` - Sensor calibration
- ``` uint16_t vacuum_readData() ``` - Function for reads 12 bit ADC data
- ``` float vacuum_getVoltage() ``` - Function for converting ADC value to pressure data
- ``` float vacuum_getPercentageOfVacuum() ``` - Function for converting ADC value to percentage of Vacuum

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initialization driver init and calibration of the chip to start measuring
- Application Task - (code snippet) - Reads vacuum percentage that sensor reads


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2572/vacuum-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
