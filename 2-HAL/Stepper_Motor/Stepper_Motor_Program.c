/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-07-21       *************************************/
/************* SWC     :   Stepper Motor    *************************************/
/************* Version :   1.0          `   *************************************/
/********************************************************************************/
#include "../../5-LIB/ERROR_STATE.h"
#include "../../5-LIB/TYPEDEF.h"
#include<util/delay.h>
#include "../../1-MCAL/DIO/DIO_interface.h"

#include "../../2-HAL/Stepper_Motor/Stepper_Config.h"
#include "../../2-HAL/Stepper_Motor/Stepper_Motor_Private.h"


#define  delay   125

ES_t STEP_Motor_enu_Init()
{
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN1, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN2, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN3, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN4, DIO_U8_OUTPUT);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN1, DIO_U8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN2, DIO_U8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN3, DIO_U8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN4, DIO_U8_LOW);

    return STATE_OK;
}
ES_t STEP_Motor_enu_Rotate(u8 Copy_u8_Direction, u16 Copy_u16_Angle)
{
    u8 Local_u8_errorState = STATE_OK;
    if ((Copy_u8_Direction == CW || Copy_u8_Direction == CCW) && (Copy_u16_Angle >= 0 && Copy_u16_Angle <= 360))
    {
        u8 state = MOTOR_PINS_STATE; // 0000 1111
        u16 Local_u16_numOFSteps = Copy_u16_Angle / STEP_ANGLE;
        if (Copy_u8_Direction == CW)
        {
            for (u8 Local_u8_Iterator = 0; Local_u8_Iterator < Local_u16_numOFSteps; Local_u8_Iterator++)
            {
                state &=  3<<(Local_u8_Iterator%4);
                if((Local_u8_Iterator%4) == 3) state = EDGE_STATE;
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN4, (state>>SHIFT_0BIT)&MASK_BIT);
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN3, (state>>SHIFT_1BIT)&MASK_BIT);
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN2, (state>>SHIFT_2BIT)&MASK_BIT);
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN1, (state>>SHIFT_3BIT)&MASK_BIT);
                _delay_ms(delay);
                state = 0x0F;
            }
        }
        else if (Copy_u8_Direction == CCW)
        {
            for (u8 Local_u8_Iterator = 0; Local_u8_Iterator < Local_u16_numOFSteps; Local_u8_Iterator++)
            {
                state &=  3<<(Local_u8_Iterator%4);
                if((Local_u8_Iterator%4) == 3) state = EDGE_STATE;
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN1, (state>>SHIFT_0BIT)&MASK_BIT);
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN2, (state>>SHIFT_1BIT)&MASK_BIT);
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN3, (state>>SHIFT_2BIT)&MASK_BIT);
                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN4, (state>>SHIFT_3BIT)&MASK_BIT);
                _delay_ms(delay);
                state = 0x0F;
            }
        }
    }else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}

ES_t STEP_Motor_enu_Stop()
{
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN1, DIO_U8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN2, DIO_U8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN3, DIO_U8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, STEPPER_MOTOR_PIN4, DIO_U8_LOW);
    _delay_ms(delay);
    return STATE_OK;
}


