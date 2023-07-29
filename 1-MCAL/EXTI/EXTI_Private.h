/*****************************************************************************/
/************* Name    :   Mahmoud Samy **************************************/
/************* Date    :   2023-07-27   **************************************/
/************* SWC     :   EXTI          *************************************/
/************* Version :   1.0          **************************************/
/*****************************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H
#include"../../5-LIB/TYPEDEF.h"

/********************************Registers Addresses******************/
#define EXTI_U8_MCUCR       *((volatile u8 *)0x55)           //Control Edge Register[EXTI0,EXTI1]
#define EXTI_U8_MCUCSR      *((volatile u8 *)0x54)           //Control Edge Register[EXTI2]
#define EXTI_U8_GICR        *((volatile u8 *)0x5B)           //External interrupts Enable Register
#define EXTI_U8_GIFR        *((volatile u8 *)0x5A)           //External interrupts Flags Register
/**********************************Control Bits**********************/
#define EXTI_U8_ISC00               0    
#define EXTI_U8_ISC01               1
#define EXTI_U8_ISC10               2
#define EXTI_U8_ISC11               3
#define EXTI_U8_ISC2                6
/**********************************PIE Macros**************************/
#define EXTI_U8_IN0                 6
#define EXTI_U8_IN1                 7
#define EXTI_U8_IN2                 5
/*************Options For Interrupts & Change Cases*********************/
#define EXTI0                       0
#define EXTI1                       1
#define EXTI2                       2

#define LOW_LEVEL                   0
#define ANY_LOGICAL_CHANGE          1
#define FALLING_EDGE                2
#define RISING_EDGE                 3
/************************* Prototypes For ISR Functions*********************/
void __vector_1(void)     __attribute__((signal));
void __vector_2(void)     __attribute__((signal));
void __vector_3(void)     __attribute__((signal));

/*************************************************************************/
#define MAX_CHANGE_CASES            3
#define NUM_OF_ISR_FUNCTIONS        3


#endif