/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-31   *************************************/
/************* SWC     :    ADC         *************************************/
/************* Version :    1.0         *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/BIT_MATH.h"
#include"../../5-LIB/ISR_Functions.h"

#include"ADC_Private.h"
#include"ADC_Config.h"
/********************Global Pointer to Notification Function***********************/
static void(* ADC_pf_Notification)(u16) = NULL;
/****************************ADC busy Flag*****************************************/
static u8 ADC_u8_busyFlag = 0;
ES_t ADC_enu_Init(void){
/**********************Voltage Referance******************/
    #if ADC_REF_VOLTAGE == AVCC
    CLR_BIT(ADMUX_REG,REFS1);
    SET_BIT(ADMUX_REG,REFS0);
    #elif ADC_REF_VOLTAGE == AREF
    CLR_BIT(ADMUX_REG,REFS1);
    CLR_BIT(ADMUX_REG,REFS0);
    #elif ADC_REF_VOLTAGE == INTERNAL_VOLTAGE_REF
    SET_BIT(ADMUX_REG,REFS1);
    SET_BIT(ADMUX_REG,REFS0);
    #endif
/**********************Presentation************************/
    #if ADC_PRESENTATION_MODE == RIGHT_ADJUST
    CLR_BIT(ADMUX_REG,ADLAR);
    #elif ADC_PRESENTATION_MODE == LEFT_ADJUST
    SET_BIT(ADMUX_REG,ADLAR);
    #endif
/****************Conversion Mode**************************/
    #if ADC_CONVERSION_MODE == DISABLE_AUTO_TRIGG
    CLR_BIT(ADCSRA_REG,ADATE);
    #elif ADC_CONVERSION_MODE == AUTO_TRIGG_FREE_RUNNING
    SET_BIT(ADCSRA_REG,ADATE);
    CLR_BIT(SFIOR_REG,ADTS2);
    CLR_BIT(SFIOR_REG,ADTS1);
    CLR_BIT(SFIOR_REG,ADTS0);
    #elif ADC_CONVERSION_MODE == AUTO_TRIGG_EXTERNAL_INTERRUPT
    SET_BIT(ADCSRA_REG,ADATE);
    CLR_BIT(SFIOR_REG,ADTS2);
    SET_BIT(SFIOR_REG,ADTS1);
    CLR_BIT(SFIOR_REG,ADTS0);
    #endif
/*******************Division Factor*********************/
    ADCSRA_REG |= ADC_DIVISION_FACTOR;
/******************* Enable ADC **********************/
    SET_BIT(ADCSRA_REG,ADEN);
    return STATE_OK;
}
ES_t ADC_enu_GetDigitalValueSynchNonBlocking(u8 Copy_u8_channelNb, u16 * Copy_pu16_DigitalValue){
    u8 Local_u8_errorState = STATE_OK;
    u32 Local_u32_timeOutCounter = 0;
    if((Copy_u8_channelNb<MAX_NUM_OF_CHANNELS) && (Copy_pu16_DigitalValue!= NULL) && (!ADC_u8_busyFlag) ){
        //Set busy Flag for ADC
        ADC_u8_busyFlag = 1;
        //Clear MUX4...0
        ADMUX_REG &= CLEAR_MUX_BITS;
        //Select Channel
        ADMUX_REG |= Copy_u8_channelNb;
        //Start Conversion
        SET_BIT(ADCSRA_REG,ADSC);
        //Wait -> ADC Flag = 1 (Timeout Mechanism)
        while((!GET_BIT(ADCSRA_REG,ADIF)) && (Local_u32_timeOutCounter<ADC_U32_TIMEOUT_MAX_VALUE))
        {Local_u32_timeOutCounter++;}
        //Check For ADC Peripheral
        if(GET_BIT(ADCSRA_REG,ADIF)){
            //Clear ADC Flag & busy Flag
            ADC_u8_busyFlag = 0;
            SET_BIT(ADCSRA_REG,ADIF);
            //Read Digital Value
            *Copy_pu16_DigitalValue = ADC_REG;
        }else{
            Local_u8_errorState = STATE_NOT_OK;
        }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t ADC_enu_GetDigitalValueASynch(u8 Copy_u8_channelNb, void(* Copy_pf_Notification)(u16)){
    u8 Local_u8_errorState = STATE_OK;
    if((Copy_u8_channelNb<MAX_NUM_OF_CHANNELS) && (Copy_pf_Notification!= NULL) && (!ADC_u8_busyFlag)){
        //Set busy Flag for ADC
        ADC_u8_busyFlag = 1;
        //update Global Pointer to Function
        ADC_pf_Notification = Copy_pf_Notification;
        //Enable ADC Interrupt
        SET_BIT(ADCSRA_REG,ADIE);
        //Clear MUX4...0
        ADMUX_REG &= CLEAR_MUX_BITS;
        //Select Channel
        ADMUX_REG |= Copy_u8_channelNb;
        //Start Conversion
        SET_BIT(ADCSRA_REG,ADSC);
    }else{
        Local_u8_errorState= STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
/***************ISR Function OF ADC*************/
ISR(ADC){
    if(ADC_pf_Notification !=NULL){
        //Disable Interrupt & busy Flag
        CLR_BIT(ADCSRA_REG,ADIE);
        ADC_u8_busyFlag = 0;
        //Calling Notification Func
        ADC_pf_Notification(ADC_REG);
    }
}