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

ES_t Timers_enu_Init(u8 Copy_u8_TimerNo, u8 Copy_u8_Mode,u8 Copy_u8_Prescaler);
ES_t Timers_enu_SetCallBack(u8 Copy_u8_TimerNo,void(*Copy_pf)(void),u8 Copy_u8_Mode);
ES_t Timers_enu_SetCLKSource(u8 Copy_u8_TimerNo,u8 Copy_u8_CLK_Source);
ES_t Timers_enu_delay_ms(u32 Copy_u32_Time);
ES_t Timers_enu_SetTimerValue(u8 Copy_u8_TimerNo,u16 Copy_u8_Value);
ES_t Timers_enu_GetTimerValue(u8 Copy_u8_TimerNo,u16 *Copy_u8_Value);
ES_t Timers_enu_Timer0SetCompareValue(u8 Copy_u8_Value);
ES_t Timers_enu_Timer1_setTopValue(u16 Copy_u16_Value);
ES_t Timers_enu_Timer1SetCompareValue(u8 Copy_u8_compareREG ,u16 Copy_u8_Value);
ES_t Timers_enu_Stop(u8 Copy_u8_TimerNo);

ES_t Timers_enu_ICUReadValue(u16 * Copy_ICR1_Value);
ES_t Timers_enu_ICUSetTriggerEdge(u8 Copy_Trigger);
ES_t Timers_enu_ICUSetCallBack(void (*Copy_pf_ICU)(void));
ES_t Timers_enu_ICUInterruptEnabled();
ES_t Timers_enu_ICUInterruptDisabled();



#define TIMER0                              0                     
#define TIMER1                              1 

#define NORMAL_MODE                         0
#define CTC_MODE                            1
#define CTC_MODE_A                          1
#define CTC_MODE_B                          2 
#define FAST_PWM_INVERTING                  3
#define FAST_PWM_NON_INVERTING              4
#define PHASE_CORRECT_PWM_INVERTING         5    
#define PHASE_CORRECT_PWM_NON_INVERTING     6
#define FAST_PWM_NON_INVERTING_COMA         7
#define FAST_PWM_NON_INVERTING_COMB         8
#define PHASE_CORRECT_PWM_NON_INVERTING_COMA        9
#define PHASE_CORRECT_PWM_NON_INVERTING_COMB        10 

#define COMPARE_UNIT_A                      0
#define COMPARE_UNIT_B                      1

#define F_CPU_CLK                           1
#define CLK_8                               2
#define CLK_64                              3
#define CLK_256                             4
#define CLK_1024                            5
#define EXTERNAL_FALLING_EDGE               6           
#define EXTERNAL_RISING_EDGE                7  

#define ICU_FALLING_EDGE                             0           
#define ICU_RISING_EDGE                              1    


#endif