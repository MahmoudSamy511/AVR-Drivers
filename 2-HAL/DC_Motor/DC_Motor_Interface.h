/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-21   *************************************/
/************* SWC     :   DC Motor     *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/TYPEDEF.h"

#define CW                  1
#define CCW                 0  
#define MOTOR1              0
#define MOTOR2              1
ES_t DC_Motor_enu_Init(u8 Copy_u8_M1_State,u8 Copy_u8_M2_State);

ES_t DC_Motor_enu_Rotate(u8 Copy_u8_Motor,u8 Copy_u8_Direction);

ES_t DC_Motor_enu_Stop(u8 Copy_u8_Motor);



#endif