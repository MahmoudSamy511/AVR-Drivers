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
static u8 Timer0_u8_Prescaler , Timer1_u8_Prescaler;
/*Global Pointer To Function */
static  void(*Timers_pf_Timer0[2])(void) = {NULL};
static  void(*Timers_pf_Timer1[3])(void)= {NULL};
ES_t Timers_enu_Init(u8 Copy_u8_TimerNo,u8 Copy_u8_Mode,u8 Copy_u8_Prescaler){
u8 Local_u8_errorState = STATE_OK;
if((Copy_u8_TimerNo<2)&& (Copy_u8_Mode < 7)&&(Copy_u8_Prescaler<8)){
    switch (Copy_u8_TimerNo)
    {
    case TIMER0:
        switch (Copy_u8_Mode)
        {
        case NORMAL_MODE:
            CLR_BIT(TIMER0_TCCR0_REG, WGM00);
            CLR_BIT(TIMER0_TCCR0_REG, WGM01);
            // Enable OverFlow Interrupt
            SET_BIT(TIMER_TIMSK_REG, TOIE0);
        break;
        case CTC_MODE:
            CLR_BIT(TIMER0_TCCR0_REG, WGM00);
            SET_BIT(TIMER0_TCCR0_REG, WGM01);
            // Enable CTC Interrupt
            SET_BIT(TIMER_TIMSK_REG, OCIE0);
        break;
        case FAST_PWM_INVERTING:
            // Fast
            SET_BIT(TIMER0_TCCR0_REG, WGM00);
            SET_BIT(TIMER0_TCCR0_REG, WGM01);
            // Inverting
            SET_BIT(TIMER0_TCCR0_REG, COM01);
            SET_BIT(TIMER0_TCCR0_REG, COM00);
        break;
        case FAST_PWM_NON_INVERTING:
            // Fast
            SET_BIT(TIMER0_TCCR0_REG, WGM00);
            SET_BIT(TIMER0_TCCR0_REG, WGM01);
            // Non Inverting
            SET_BIT(TIMER0_TCCR0_REG, COM01);
            CLR_BIT(TIMER0_TCCR0_REG, COM00);
        break;
        case PHASE_CORRECT_PWM_INVERTING:
            // Phase Correct
            SET_BIT(TIMER0_TCCR0_REG, WGM00);
            CLR_BIT(TIMER0_TCCR0_REG, WGM01);
            // Inverting
            SET_BIT(TIMER0_TCCR0_REG, COM01);
            SET_BIT(TIMER0_TCCR0_REG, COM00);
        break;
        case PHASE_CORRECT_PWM_NON_INVERTING:
            // Phase Correct
            SET_BIT(TIMER0_TCCR0_REG, WGM00);
            CLR_BIT(TIMER0_TCCR0_REG, WGM01);
            // NON Inverting
            SET_BIT(TIMER0_TCCR0_REG, COM01);
            CLR_BIT(TIMER0_TCCR0_REG, COM00);
        break;
        }
    TIMER0_TCCR0_REG |= Copy_u8_Prescaler;
    Timer0_u8_Prescaler = Copy_u8_Prescaler;
    break;
    case TIMER1:
        switch (Copy_u8_Mode)
        {
        case NORMAL_MODE:
            CLR_BIT(TIMER1_TCCR1A_REG, WGM10);
            CLR_BIT(TIMER1_TCCR1A_REG, WGM11);
            CLR_BIT(TIMER1_TCCR1B_REG, WGM12);
            CLR_BIT(TIMER1_TCCR1B_REG, WGM13);
            SET_BIT(TIMER_TIMSK_REG, TOIE1);
        break;
        case CTC_MODE_A:
            CLR_BIT(TIMER1_TCCR1A_REG, WGM10);
            CLR_BIT(TIMER1_TCCR1A_REG, WGM11);
            SET_BIT(TIMER1_TCCR1B_REG, WGM12);
            CLR_BIT(TIMER1_TCCR1B_REG, WGM13);
            SET_BIT(TIMER_TIMSK_REG, OCIE1A);
        break;
        case CTC_MODE_B:
            CLR_BIT(TIMER1_TCCR1A_REG, WGM10);
            CLR_BIT(TIMER1_TCCR1A_REG, WGM11);
            CLR_BIT(TIMER1_TCCR1B_REG, WGM12);
            CLR_BIT(TIMER1_TCCR1B_REG, WGM13);
            SET_BIT(TIMER_TIMSK_REG, OCIE1B);
        break;
        case FAST_PWM_NON_INVERTING:
            CLR_BIT(TIMER1_TCCR1A_REG, WGM10);
            SET_BIT(TIMER1_TCCR1A_REG, WGM11);
            SET_BIT(TIMER1_TCCR1B_REG, WGM12);
            SET_BIT(TIMER1_TCCR1B_REG, WGM13);
            SET_BIT(TIMER1_TCCR1A_REG, COM1A1);
            CLR_BIT(TIMER1_TCCR1A_REG, COM1A0);
        break;
        case PHASE_CORRECT_PWM_NON_INVERTING:
            SET_BIT(TIMER1_TCCR1A_REG, WGM10);
            SET_BIT(TIMER1_TCCR1A_REG, WGM11);
            CLR_BIT(TIMER1_TCCR1B_REG, WGM12);
            SET_BIT(TIMER1_TCCR1B_REG, WGM13);
            SET_BIT(TIMER1_TCCR1A_REG, COM1A1);
            CLR_BIT(TIMER1_TCCR1A_REG, COM1A0);
        break;
        }
    TIMER1_TCCR1B_REG |= Copy_u8_Prescaler;
    Timer1_u8_Prescaler = Copy_u8_Prescaler;
    break;
    }
}else{
    Local_u8_errorState = STATE_NOT_OK;
}
return Local_u8_errorState;
}
ES_t Timers_enu_SetCallBack(u8 Copy_u8_TimerNo,void(*Copy_pf)(void),u8 Copy_u8_Mode){
    u8 Local_u8_errorState = STATE_OK;
    if((Copy_u8_TimerNo<2)&(Copy_pf != NULL) && (Copy_u8_Mode<7)){
        switch (Copy_u8_TimerNo)
        {
        case TIMER0:
            Timers_pf_Timer0[Copy_u8_Mode] = Copy_pf;
        break;
        case TIMER1:
            Timers_pf_Timer1[Copy_u8_Mode] = Copy_pf;
        break;
        }
        
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_SetCLKSource(u8 Copy_u8_TimerNo,u8 Copy_u8_CLK_Source){
    u8 Local_u8_errorState = STATE_OK;
    if((Copy_u8_CLK_Source < 8) && (Copy_u8_TimerNo < 2)){
        switch (Copy_u8_TimerNo)
        {
        case TIMER0:
            // Clear Old Value of Prescaler
            TIMER0_TCCR0_REG &= CLEAR_CLK_SOURCE;
            TIMER0_TCCR0_REG |= Copy_u8_CLK_Source;
            Timer0_u8_Prescaler = Copy_u8_CLK_Source;
        break;
        case TIMER1:
            // Clear Old Value of Prescaler
            TIMER1_TCCR1B_REG &= CLEAR_CLK_SOURCE;
            TIMER1_TCCR1B_REG |= Copy_u8_CLK_Source;
            Timer1_u8_Prescaler = Copy_u8_CLK_Source;
        break;
        }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_delay_ms(u32 Copy_u32_Time)
{
    TIMER0_TCCR0_REG |= Timer0_u8_Prescaler;
    u16 local_u16_OVF_Time = 256 * 8 / F_CPU;
    u16 local_u16_NumOfOVF = (Copy_u32_Time * 1000) / local_u16_OVF_Time;
    u16 local_u16_proLoad = (((Copy_u32_Time * 1000) % local_u16_OVF_Time) * F_CPU) / 8;
    TIMER0_TCNT0_REG = 256 - local_u16_proLoad;
    u16 local_u16_counter = 0;
    while (local_u16_counter != (local_u16_NumOfOVF + 1))
    {
        while (GET_BIT(TIMER_TIFR_REG, TOV0) != 0)
        {
        SET_BIT(TIMER_TIFR_REG, TOV0);
        local_u16_counter++;
        }
    }
    TIMER0_TCCR0_REG &= CLEAR_CLK_SOURCE;
}
ES_t Timers_enu_SetTimerValue(u8 Copy_u8_TimerNo,u16 Copy_u8_Value){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_TimerNo < 3){
        switch (Copy_u8_TimerNo)
        {
        case TIMER0:
            TIMER0_TCNT0_REG = Copy_u8_Value;
        break;
        case TIMER1:
            TIMER1_TCNT1_REG = Copy_u8_Value;
        break;
        }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_GetTimerValue(u8 Copy_u8_TimerNo,u16 *Copy_u8_Value){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_TimerNo < 3){
        switch (Copy_u8_TimerNo)
        {
        case TIMER0:
            *Copy_u8_Value = TIMER0_TCNT0_REG;
        break;
        case TIMER1:
            *Copy_u8_Value = TIMER1_TCNT1_REG;
        break;
        }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;

}
ES_t Timers_enu_Timer0SetCompareValue(u8 Copy_u8_Value){
    TIMER0_OCR0_REG = Copy_u8_Value;
    return STATE_OK;
}
ES_t Timers_enu_Timer1_setTopValue(u16 Copy_u16_Value){
        TIMER1_ICR1_REG = Copy_u16_Value;
}
ES_t Timers_enu_Timer1SetCompareValue(u8 Copy_u8_compareREG ,u16 Copy_u8_Value){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_compareREG < 2){
        switch (Copy_u8_compareREG)
        {
        case COMPARE_UNIT_A:
            TIMER1_OCR1A_REG = Copy_u8_Value;
        break;
        case COMPARE_UNIT_B:
            TIMER1_OCR1B_REG = Copy_u8_Value;
        break;
        }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_Stop(u8 Copy_u8_TimerNo){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_TimerNo<2){
        switch (Copy_u8_TimerNo)
        {
        case TIMER0:
        TIMER0_TCCR0_REG &= CLEAR_CLK_SOURCE;
        TIMER0_TCNT0_REG = TIMER0_OCR0_REG = 0;
        break;
        case TIMER1:
        TIMER1_TCCR1B_REG &= CLEAR_CLK_SOURCE;
        TIMER1_TCNT1_REG = TIMER1_OCR1A_REG = TIMER1_OCR1B_REG = 0;
        break;
        }
    }else{
        Local_u8_errorState =STATE_NOT_OK;
    }
    return Local_u8_errorState;
}

/*****ISR(Timer1) CTC Mode A*****/
void __vector_7(void){
    if (Timers_pf_Timer1[CTC_MODE_A] != NULL)
        Timers_pf_Timer1[CTC_MODE_A]();
}
/*****ISR(Timer1) CTC Mode B*****/
void __vector_8(void){
    if (Timers_pf_Timer1[CTC_MODE_B] != NULL)
        Timers_pf_Timer1[CTC_MODE_B]();
}
/*****ISR(Timer1) Normal Mode*****/
void __vector_9(void){
    if (Timers_pf_Timer1[NORMAL_MODE] != NULL)
        Timers_pf_Timer1[NORMAL_MODE]();
}
/*****ISR(Timer0) CTC Mode*****/
void __vector_10(void){
    if (Timers_pf_Timer0[CTC_MODE] != NULL)
        Timers_pf_Timer0[CTC_MODE]();
}
/*****ISR(Timer0) Normal Mode*****/
void __vector_11(void){
    if (Timers_pf_Timer0[NORMAL_MODE] != NULL)
        Timers_pf_Timer0[NORMAL_MODE]();
}



