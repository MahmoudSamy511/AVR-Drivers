/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-08-17       *************************************/
/************* SWC     :   Watch Dog Timer  *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/TYPEDEF.h"



#define TIME_16_3_MS        0
#define TIME_32_5_MS        1
#define TIME_65_MS          2
#define TIME_0_13_S         3
#define TIME_0_26_S         4
#define TIME_0_52_S         5
#define TIME_1_0_S          6
#define TIME_2_1_S          7   

ES_t WDT_enu_Enable(u8 Copy_u8_Time);
ES_t WDT_enu_Disable(void);





#endif