/**********************************************************************************/
/************* Name    :   Mahmoud Samy       *************************************/
/************* Date    :   2023-07-05         *************************************/
/************* SWC     :   Simple Scheduler   *************************************/
/************* Version :   1.0                *************************************/
/**********************************************************************************/
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

#include"../../5-LIB/TYPEDEF.h"

typedef struct
{
    u16 firstDelay;     // unit of firstDelay time:  depends on scheduler tick time
    u16 Periodicity;   // unit of Periodicity time:  depends on scheduler tick time
    void (*TaskHandler)(void);

}Task_t;


static void RTOS_enu_Scheduler(void);
static void RTOS_enu_timerConfig(void);




#endif