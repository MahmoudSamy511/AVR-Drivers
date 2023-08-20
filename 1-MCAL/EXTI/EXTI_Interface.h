/*****************************************************************************/
/************* Name    :   Mahmoud Samy **************************************/
/************* Date    :   2023-07-27   **************************************/
/************* SWC     :   EXTI          *************************************/
/************* Version :   1.0          **************************************/
/*****************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

/************************* Options *********************/
#define EXTI0                       0
#define EXTI1                       1
#define EXTI2                       2

#define LOW_LEVEL                   0
#define ANY_LOGICAL_CHANGE          1
#define FALLING_EDGE                2
#define RISING_EDGE                 3


ES_t EXTI_enu_Enable(u8 Copy_u8_EXTI_Index,u8 Copy_u8_EXTI_Edge);

ES_t EXTI_enu_setSenseControl(u8 Copy_u8_EXTI_Index,u8 Copy_u8_EXTI_Edge);

ES_t EXTI_enu_Disable(u8 Copy_u8_EXTI_Index);

ES_t EXTI_enu_setCallBack(void(*Copy_pf_ISR)(void), u8 Copy_u8_ISR_Index);




#endif

