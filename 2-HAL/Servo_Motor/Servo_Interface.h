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

ES_t Servo_enu_Init(void);
ES_t Servo_enu_SetAngle(u8 Copy_u8_Angle);
ES_t Servo_enu_Stop(void);

#endif