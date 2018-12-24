_systemInit:
;Click_Vacuum_STM.c,34 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Vacuum_STM.c,36 :: 		mikrobus_i2cInit( _MIKROBUS1, &_VACUUM_I2C_CFG[0] );
MOVW	R0, #lo_addr(__VACUUM_I2C_CFG+0)
MOVT	R0, #hi_addr(__VACUUM_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Vacuum_STM.c,37 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Vacuum_STM.c,38 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Vacuum_STM.c,39 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Vacuum_STM.c,41 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Vacuum_STM.c,43 :: 		vacuum_i2cDriverInit( (T_VACUUM_P)&_MIKROBUS1_GPIO, (T_VACUUM_P)&_MIKROBUS1_I2C, 0x4D );
MOVS	R2, #77
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_vacuum_i2cDriverInit+0
;Click_Vacuum_STM.c,44 :: 		vacuum_calibration();
BL	_vacuum_calibration+0
;Click_Vacuum_STM.c,45 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Vacuum_STM.c,47 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Vacuum_STM.c,49 :: 		mikrobus_logWrite("Vacuum (voltage) : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr1_Click_Vacuum_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Vacuum_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Vacuum_STM.c,50 :: 		Vacuum_volt = vacuum_getVoltage();
BL	_vacuum_getVoltage+0
MOVW	R1, #lo_addr(_Vacuum_volt+0)
MOVT	R1, #hi_addr(_Vacuum_volt+0)
STR	R0, [R1, #0]
;Click_Vacuum_STM.c,51 :: 		FloatToStr(Vacuum_volt, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Vacuum_STM.c,52 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Vacuum_STM.c,53 :: 		mikrobus_logWrite(" V", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr2_Click_Vacuum_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Vacuum_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Vacuum_STM.c,55 :: 		mikrobus_logWrite("Percentage of vacuum: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr3_Click_Vacuum_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Vacuum_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Vacuum_STM.c,56 :: 		Vacuum = vacuum_getPercentageOfVacuum();
BL	_vacuum_getPercentageOfVacuum+0
MOVW	R1, #lo_addr(_Vacuum+0)
MOVT	R1, #hi_addr(_Vacuum+0)
STR	R0, [R1, #0]
;Click_Vacuum_STM.c,57 :: 		FloatToStr(Vacuum, demoText);
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_Vacuum_STM.c,58 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Vacuum_STM.c,60 :: 		mikrobus_logWrite(" ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr4_Click_Vacuum_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Vacuum_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Vacuum_STM.c,61 :: 		Delay_ms(300);
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_Vacuum_STM.c,62 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Vacuum_STM.c,64 :: 		void main()
;Click_Vacuum_STM.c,66 :: 		systemInit();
BL	_systemInit+0
;Click_Vacuum_STM.c,67 :: 		applicationInit();
BL	_applicationInit+0
;Click_Vacuum_STM.c,69 :: 		while (1)
L_main4:
;Click_Vacuum_STM.c,71 :: 		applicationTask();
BL	_applicationTask+0
;Click_Vacuum_STM.c,72 :: 		}
IT	AL
BAL	L_main4
;Click_Vacuum_STM.c,73 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
