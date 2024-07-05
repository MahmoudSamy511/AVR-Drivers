/**********************************************************************************/
/************* Name    :   Mahmoud Samy       *************************************/
/************* Date    :   2023-07-05         *************************************/
/************* SWC     :   Simple Scheduler   *************************************/
/************* Version :   1.0                *************************************/
/**********************************************************************************/

#include"../../1-MCAL/Timers/Timer_Interface.h"
#include"../../1-MCAL/GI/GI_Interface.h"

#include"RTOS_Interface.h"
#include"RTOS_Config.h"
#include"RTOS_Private.h"

/*Array of Tasks*/
Task_t RTOS_Tasks[RTOS_MAX_TASKS];
ES_t RTOS_enu_Init(void){
    GI_enu_Enable();
    Timers_enu_SetTimerValue(TIMER0,RTOS_PRELOAD_VALUE);
    Timers_enu_SetCallBack(TIMER0,RTOS_enu_timerConfig,NORMAL_MODE);
    Timers_enu_Init(TIMER0,NORMAL_MODE,CLK_8);
}

ES_t RTOS_enu_CreateTask(u8 Copy_u8Priority ,u16 Copy_u16FirstDelay, u16 Copy_u16Periodicity , void (*Copy_ptr)(void) ){
    u8 local_u8errorState = STATE_OK;
    if((Copy_u8Priority < RTOS_MAX_TASKS) && (Copy_ptr != NULL)){
        RTOS_Tasks[Copy_u8Priority].firstDelay = Copy_u16FirstDelay;
        RTOS_Tasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
        RTOS_Tasks[Copy_u8Priority].TaskHandler = Copy_ptr;
    }else{
        local_u8errorState = STATE_NOT_OK;
    }
    return local_u8errorState;
}

static void RTOS_enu_Scheduler(void){
    u8 local_u8TaskIndex;
    //Loop for all tasks 
    for(local_u8TaskIndex = 0; local_u8TaskIndex < RTOS_MAX_TASKS; local_u8TaskIndex++){\
    //Check if the task is ready
        if(RTOS_Tasks[local_u8TaskIndex].firstDelay == 0){
            //Execute the task
            RTOS_Tasks[local_u8TaskIndex].TaskHandler();
            //Set the first delay to the periodicity - 1
            RTOS_Tasks[local_u8TaskIndex].firstDelay = RTOS_Tasks[local_u8TaskIndex].Periodicity - 1;
        }else{
            //Decrement the first delay to move a step forward
            RTOS_Tasks[local_u8TaskIndex].firstDelay--;
        }
    }
}

static void RTOS_enu_timerConfig(void){
    static u8 local_u8Counter = 0;
    local_u8Counter++;
    if(local_u8Counter == RTOS_NUMBER_OF_OVF){
        local_u8Counter = 0;
        RTOS_enu_Scheduler();
        Timers_enu_SetTimerValue(TIMER0,RTOS_PRELOAD_VALUE);
    }
}