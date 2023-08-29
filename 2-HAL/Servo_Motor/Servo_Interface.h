/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-17   *************************************/
/************* SWC     :   Servo Motor  *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"


#define MOTOR_1       1
#define MOTOR_2       2

ES_t Servo_enu_Init(u8 Copy_Motor_PD4_State,u8 Copy_Motor_PD5_State);
ES_t Servo_enu_SetAngle(u8 Copy_Motor,u8 Copy_u8_Angle);
ES_t Servos_enu_Stop(void);

#endif