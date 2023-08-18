/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-17   *************************************/
/************* SWC     :   Servo Motor  *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

#include"../../1-MCAL/DIO/DIO_interface.h"
#include"../../1-MCAL/Timers/Timer_Interface.h"

#include"Servo_Config.h"
#include"Servo_Private.h"

ES_t Servo_enu_Init(void){
    DIO_enu_SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_OUTPUT);
    Timers_enu_Init(TIMER1,FAST_PWM_NON_INVERTING,CLK_8);
    Timers_enu_Timer1_setTopValue(SERVO_COMPLETE_CYCLE_TICKS-1);
}
ES_t Servo_enu_SetAngle(u8 Copy_u8_Angle){
    ES_t Local_u8_errorState = STATE_OK;
    if(Copy_u8_Angle<=SERVO_MAX_ANGLE){
        u16 Servo_u16_OCR1A_Value = ((SERVO_MIN_TIME+(Copy_u8_Angle*SERVO_MIN_TIME)/SERVO_MAX_ANGLE)*2)-1;
        Timers_enu_Timer1SetCompareValue(COMPARE_UNIT_A,Servo_u16_OCR1A_Value);
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Servo_enu_Stop(void){
    Timers_enu_Stop(TIMER1);
    return STATE_OK;
}
