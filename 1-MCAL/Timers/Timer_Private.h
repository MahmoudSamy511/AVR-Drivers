/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H
#include"../../5-LIB/TYPEDEF.h"
/*****************************Timer0 Registers Addresses*********************/
#define TIMER_TIMSK_REG            *((volatile u8 *)0x59)
#define TIMER_TIFR_REG             *((volatile u8 *)0x58)
#define TIMER0_TCCR0_REG           *((volatile u8 *)0x53)
#define TIMER0_TCNT0_REG           *((volatile u8 *)0x52)
#define TIMER0_OCR0_REG            *((volatile u8 *)0x5c)
/*****************************Timer0 Registers Bits*********************/
#define WGM00                  6
#define WGM01                  3
#define COM00                  4
#define COM01                  5
#define TOIE0                  0
#define OCIE0                  1
#define TOV0                   0
#define OCF0                   1
/*****************************Timer1 Registers Addresses*********************/
#define TIMER1_TCCR1A_REG           *((volatile u8 *)0X4F)
#define TIMER1_TCCR1B_REG           *((volatile u8 *)0x4E)
#define TIMER1_TCNT1L_REG           *((volatile u8 *)0x4C)
#define TIMER1_TCNT1H_REG           *((volatile u8 *)0x4D)
#define TIMER1_OCR1AH_REG           *((volatile u8 *)0x4B)
#define TIMER1_OCR1AL_REG           *((volatile u8 *)0x4A)
#define TIMER1_OCR1BH_REG           *((volatile u8 *)0x49)
#define TIMER1_OCR1BL_REG           *((volatile u8 *)0x48)
#define TIMER1_ICR1H_REG            *((volatile u8 *)0x47)
#define TIMER1_ICR1L_REG            *((volatile u8 *)0x46)

#define TIMER1_OCR1A_REG            *((volatile u16 *)0x4A)
#define TIMER1_OCR1B_REG            *((volatile u16 *)0x48)
#define TIMER1_ICR1_REG             *((volatile u16 *)0x46)
#define TIMER1_TCNT1_REG            *((volatile u16 *)0x4C)
/*****************************Timer1 Registers Bits**************************/
#define WGM11                  1
#define WGM10                  0
#define WGM12                  3
#define WGM13                  4
#define COM1A0                 6
#define COM1A1                 7    


/***************************Protypes Of ISR(Timer0) Functions*********************/
void __vector_10(void)    __attribute__((signal));
void __vector_11(void)    __attribute__((signal));
/*****************************Options Macros**********************/
#define NORMAL_MODE                         0
#define CTC_MODE                            1
#define FAST_PWM_INVERTING                  2
#define FAST_PWM_NON_INVERTING              3
#define PHASE_CORRECT_PWM_INVERTING         4    
#define PHASE_CORRECT_PWM_NON_INVERTING     5        

#define F_CPU_CLK                           1
#define CLK_8                               2
#define CLK_64                              3
#define CLK_256                             4
#define CLK_1024                            5
#define EXTERNAL_FALLING_EDGE               6           
#define EXTERNAL_RISING_EDGE                7            
#define SERVO_MAX_ANGLE                180
#define RESET_CLK_SOURCE              0XF8
#endif
