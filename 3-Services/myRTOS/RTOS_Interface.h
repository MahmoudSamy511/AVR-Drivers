/**********************************************************************************/
/************* Name    :   Mahmoud Samy       *************************************/
/************* Date    :   2023-07-05         *************************************/
/************* SWC     :   Simple Scheduler   *************************************/
/************* Version :   1.0                *************************************/
/**********************************************************************************/
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/TYPEDEF.h"

ES_t RTOS_enu_Init(void);
ES_t RTOS_enu_CreateTask(u8 Copy_u8Priority ,u16 Copy_u16FirstDelay, u16 Copy_u16Periodicity , void (*Copy_ptr)(void) );







#endif