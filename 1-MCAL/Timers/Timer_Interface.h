/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

ES_t Timers_enu_Timer0Init(void);

ES_t Timers_enu_Timer1Init(void);
ES_t Timers_enu_SetServoAngle(u8 Copy_u8_servoAngle);

ES_t Timers_enu_Timer0SetCallBack(void(*Copy_pf)(void),u8 Copy_u8_Mode);

ES_t Timers_enu_Timer0SetCLKSource(u8 Copy_u8_CLK_Source);

ES_t Timers_enu_Timer0SetTime(u16 Copy_u8_Time);

ES_t Timers_enu_Timer0SetCompareMatchValue(u8 Copy_u8_Value);

#define CTC_MODE                        1
#define NORMAL_MODE                     0

#define F_CPU_CLK                       1
#define CLK_8                           2
#define CLK_64                          3
#define CLK_256                         4
#define CLK_1024                        5
#define EXTERNAL_FALLING_EDGE           6           
#define EXTERNAL_RISING_EDGE            7  



#endif