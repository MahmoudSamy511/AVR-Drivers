/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/BIT_MATH.h"

#include"Timer_Private.h"
#include"Timer_Config.h"

static u8 Timer0_u8_Prescaler = TIMER0_PRESCALER;
/*Global Pointer To Function */
static  void(*Timers_pf_Timer0[2])(void) = {NULL};
ES_t Timers_enu_Timer0Init(void){
/*************** Timer 0 Mode ****************/
    #if TIMER0_MODE == NORMAL_MODE
    CLR_BIT(TIMER0_TCCR0_REG,WGM00);
    CLR_BIT(TIMER0_TCCR0_REG,WGM01);
    //Enable OverFlow Interrupt
    SET_BIT(TIMER_TIMSK_REG,TOIE0);
    //PreLoad Value
    TIMER0_TCNT0_REG = TIMER0_PRELOAD_VALUE;
    #elif TIMER0_MODE == CTC_MODE
    CLR_BIT(TIMER0_TCCR0_REG,WGM00);
    SET_BIT(TIMER0_TCCR0_REG,WGM01);
    //Enable CTC Interrupt
    SET_BIT(TIMER_TIMSK_REG,OCIE0);
    //Set Compare match unit Register Value
    TIMER0_OCR0_REG = TIMER0_OCR_VALUE;
    #elif TIMER0_MODE == FAST_PWM_INVERTING
    //Fast
    SET_BIT(TIMER0_TCCR0_REG,WGM00);
	SET_BIT(TIMER0_TCCR0_REG,WGM01);
    //Inverting
    SET_BIT(TIMER0_TCCR0_REG,COM01);
	SET_BIT(TIMER0_TCCR0_REG,COM00);
    #elif TIMER0_MODE == FAST_PWM_NON_INVERTING
    //Fast 
    SET_BIT(TIMER0_TCCR0_REG,WGM00);
	SET_BIT(TIMER0_TCCR0_REG,WGM01);
    //Non Inverting
    SET_BIT(TIMER0_TCCR0_REG,COM01);
	CLR_BIT(TIMER0_TCCR0_REG,COM00);
    #elif TIMER0_MODE == PHASE_CORRECT_PWM_INVERTING
    //Phase Correct
    SET_BIT(TIMER0_TCCR0_REG,WGM00);
	CLR_BIT(TIMER0_TCCR0_REG,WGM01);
    //Inverting
    SET_BIT(TIMER0_TCCR0_REG,COM01);
	SET_BIT(TIMER0_TCCR0_REG,COM00);
    #elif TIMER0_MODE == PHASE_CORRECT_PWM_NON_INVERTING
    //Phase Correct
    SET_BIT(TIMER0_TCCR0_REG,WGM00);
	CLR_BIT(TIMER0_TCCR0_REG,WGM01);
    //NON Inverting
    SET_BIT(TIMER0_TCCR0_REG,COM01);
	CLR_BIT(TIMER0_TCCR0_REG,COM00);
   #endif
/***************Set PreScaler Value ****************/
	TIMER0_TCCR0_REG |= TIMER0_PRESCALER;
    return STATE_OK;
}
ES_t Timers_enu_Timer1Init(void){
    //Select Timer1 Mode ==> Mode 14
    SET_BIT(TIMER1_TCCR1A_REG,WGM11);
    CLR_BIT(TIMER1_TCCR1A_REG,WGM10);
    SET_BIT(TIMER1_TCCR1B_REG,WGM12);
    SET_BIT(TIMER1_TCCR1B_REG,WGM13);
    //Select Action on OC1A ==> NON Inverting
    SET_BIT(TIMER1_TCCR1A_REG,COM1A1);
    CLR_BIT(TIMER1_TCCR1A_REG,COM1A0);
    //Set Top Value Of ICR1
    TIMER1_ICR1_REG = 39999;
    /***************Set PreScaler Value ****************/
	TIMER1_TCCR1B_REG |= TIMER1_PRESCALER;
}
ES_t Timers_enu_SetServoAngle(u8 Copy_u8_servoAngle){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_servoAngle<=SERVO_MAX_ANGLE){
        TIMER1_OCR1A_REG = (1000+(Copy_u8_servoAngle*1000UL)/SERVO_MAX_ANGLE)*2;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_Timer0SetCallBack(void(*Copy_pf)(void),u8 Copy_u8_Mode){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_pf != NULL && Copy_u8_Mode<2 ){
        Timers_pf_Timer0[Copy_u8_Mode] = Copy_pf;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_Timer0SetCLKSource(u8 Copy_u8_CLK_Source){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_CLK_Source < 8){
        //Clear Old Value of Prescaler
        TIMER0_TCCR0_REG &= RESET_CLK_SOURCE;
        TIMER0_TCCR0_REG |= Copy_u8_CLK_Source;
        Timer0_u8_Prescaler = Copy_u8_CLK_Source;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_Timer0SetCompareMatchValue(u8 Copy_u8_Value){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_Value<=255){
        TIMER0_OCR0_REG = Copy_u8_Value;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
/*****CTC Mode*****/
void __vector_10(void){
    if((Timer0_u8_Prescaler == EXTERNAL_FALLING_EDGE) || (Timer0_u8_Prescaler == EXTERNAL_RISING_EDGE)){
        if(Timers_pf_Timer0[CTC_MODE] != NULL)
            Timers_pf_Timer0[CTC_MODE]();
    }
    else{
    static u16 Local_u16_CounterCTC = 0;
    Local_u16_CounterCTC++;
    if(Local_u16_CounterCTC == 20000){
        Local_u16_CounterCTC = 0;
    if(Timers_pf_Timer0[CTC_MODE] != NULL)
        Timers_pf_Timer0[CTC_MODE]();
    }
    }

}
/*****Normal Mode*****/
void __vector_11(void){
    if((Timer0_u8_Prescaler == EXTERNAL_FALLING_EDGE) || (Timer0_u8_Prescaler == EXTERNAL_RISING_EDGE)){
        if(Timers_pf_Timer0[NORMAL_MODE] != NULL)
            Timers_pf_Timer0[NORMAL_MODE]();
    }
    else{
    static u16 Local_u16_CounterOVF = 0;
    Local_u16_CounterOVF++;
    if(Local_u16_CounterOVF == 7813){
        /*clear overflow counter*/
        Local_u16_CounterOVF = 0;
        /*update preload Value*/
        TIMER0_TCNT0_REG = TIMER0_PRELOAD_VALUE;
        /*calling App function*/
        if(Timers_pf_Timer0[NORMAL_MODE] != NULL)
            Timers_pf_Timer0[NORMAL_MODE]();
    }
    }
    
}



