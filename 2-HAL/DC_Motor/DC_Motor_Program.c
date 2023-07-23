/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-21   *************************************/
/************* SWC     :   DC Motor     *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include "../../5-LIB/ERROR_STATE.h"
#include "../../5-LIB/TYPEDEF.h"

#include "../../1-MCAL/DIO/DIO_interface.h"

#include "../../2-HAL/DC_Motor/DC_Motor_Config.h"
#include "../../2-HAL/DC_Motor/DC_Motor_Private.h"

ES_t DC_Motor_enu_Init(u8 Copy_u8_M1_State, u8 Copy_u8_M2_State)
{
    u8 Local_u8_errorState = STATE_OK;
    if ((Copy_u8_M1_State == 1 || Copy_u8_M1_State == 0) && (Copy_u8_M2_State == 1 || Copy_u8_M2_State == 0))
    {
        if (Copy_u8_M1_State == CONNECTED)
        {
            DIO_enu_SetPinDirection(MOTOR_ENA_PORT, MOTOR_ENA_PIN, DIO_U8_OUTPUT);
            DIO_enu_SetPinDirection(MOTOR_IN1_PORT, MOTOR_IN1_PIN, DIO_U8_OUTPUT);
            DIO_enu_SetPinDirection(MOTOR_IN2_PORT, MOTOR_IN2_PIN, DIO_U8_OUTPUT);
        }
        if (Copy_u8_M2_State == CONNECTED)
        {
            DIO_enu_SetPinDirection(MOTOR_ENB_PORT, MOTOR_ENB_PIN, DIO_U8_OUTPUT);
            DIO_enu_SetPinDirection(MOTOR_IN3_PORT, MOTOR_IN3_PIN, DIO_U8_OUTPUT);
            DIO_enu_SetPinDirection(MOTOR_IN4_PORT, MOTOR_IN4_PIN, DIO_U8_OUTPUT);
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t DC_Motor_enu_Rotate(u8 Copy_u8_Motor, u8 Copy_u8_Direction)
{
    u8 Local_u8_errorState = STATE_OK;
    switch (Copy_u8_Motor)
    {
    case MOTOR1:
        switch (Copy_u8_Direction)
        {
        case CW:
            DIO_enu_SetPinValue(MOTOR_ENA_PORT, MOTOR_ENA_PIN, DIO_U8_HIGH);
            DIO_enu_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, DIO_U8_HIGH);
            DIO_enu_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, DIO_U8_LOW);
            break;
        case CCW:
            DIO_enu_SetPinValue(MOTOR_ENB_PORT, MOTOR_ENA_PIN, DIO_U8_HIGH);
            DIO_enu_SetPinValue(MOTOR_IN1_PORT, MOTOR_IN1_PIN, DIO_U8_LOW);
            DIO_enu_SetPinValue(MOTOR_IN2_PORT, MOTOR_IN2_PIN, DIO_U8_HIGH);
            
            break;
        default:
            Local_u8_errorState = STATE_NOT_OK;
            break;
        }
        break;
    case MOTOR2:
        switch (Copy_u8_Direction)
        {
        case CW:
            DIO_enu_SetPinValue(MOTOR_ENB_PORT, MOTOR_ENB_PIN, DIO_U8_HIGH);
            DIO_enu_SetPinValue(MOTOR_IN3_PORT, MOTOR_IN3_PIN, DIO_U8_HIGH);
            DIO_enu_SetPinValue(MOTOR_IN4_PORT, MOTOR_IN4_PIN, DIO_U8_LOW);
            break;
        case CCW:
            DIO_enu_SetPinValue(MOTOR_ENB_PORT, MOTOR_ENB_PIN, DIO_U8_HIGH);
            DIO_enu_SetPinValue(MOTOR_IN3_PORT, MOTOR_IN3_PIN, DIO_U8_LOW);
            DIO_enu_SetPinValue(MOTOR_IN4_PORT, MOTOR_IN4_PIN, DIO_U8_HIGH);

            break;
        default:
            Local_u8_errorState = STATE_NOT_OK;
            break;
        }
        break;
        break;
    default:
        Local_u8_errorState = STATE_NOT_OK;
        break;
    }
    return Local_u8_errorState;
}
ES_t DC_Motor_enu_Stop(u8 Copy_u8_Motor)
{
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_u8_Motor == MOTOR1)
    {
        DIO_enu_SetPinValue(MOTOR_ENA_PORT, MOTOR_ENA_PIN, DIO_U8_LOW);
    }
    else if (Copy_u8_Motor == MOTOR2)
    {
        DIO_enu_SetPinValue(MOTOR_ENB_PORT, MOTOR_ENB_PIN, DIO_U8_LOW);
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
