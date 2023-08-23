/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-22   *************************************/
/************* SWC     :    UART        *************************************/
/************* Version :    1.0         *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/BIT_MATH.h"
#include"../../5-LIB/ERROR_STATE.h"

#include"UART_Config.h"
#include"UART_Private.h"
static void(*UART_pf_TX)(void) =NULL;
static void(*UART_pf_RX)(void) =NULL;
static u8 *UART_pu8_String = NULL;

ES_t UART_enu_Init(void){
    u16 Local_u16_boudRateValue = 0;
    u8 Local_u8_UCSRCValue = UCSRC_INITIAL_VALUE;
/****************** UART Mode ****************/
    #if UART_MODE == ASYNCH_NORMAL_MODE
    CLR_BIT(UART_UCSRA_REG,U2X);
    //CLR_BIT(UART_UCSRA_REG,MPCM);
    CLR_BIT(Local_u8_UCSRCValue,UMSEL);
    Local_u16_boudRateValue = (F_CPU/(16UL*UART_BAUD_RATE))-1;
    #elif UART_MODE == ASYNCH_DOUBLE_SPEED
    SET_BIT(UART_UCSRA_REG,U2X);
    //CLR_BIT(UART_UCSRA_REG,MPCM);
    CLR_BIT(Local_u8_UCSRCValue,UMSEL);
    Local_u16_boudRateValue = (F_CPU/(8UL*UART_BAUD_RATE))-1;
    #elif UART_MODE == SYNCHRONOUS
    CLR_BIT(UART_UCSRA_REG,U2X);
    //CLR_BIT(UART_UCSRA_REG,MPCM);
    SET_BIT(Local_u8_UCSRCValue,UMSEL);
    Local_u16_boudRateValue = (F_CPU/(2UL*UART_BAUD_RATE))-1;
    #endif
/****************** UART Stop Bits ****************/
    #if UART_STOP_BITS == ONE_BIT
    CLR_BIT(Local_u8_UCSRCValue,USBS);
    #elif UART_STOP_BITS == TWO_BITS
    SET_BIT(Local_u8_UCSRCValue,USBS);
    #endif
/******************UART Data Bits ****************/
    #if UART_DATA_BITS == _5_BITS
    CLR_BIT(UART_UCSRB_REG,UCZ2);
    CLR_BIT(Local_u8_UCSRCValue,UCZ1);
    CLR_BIT(Local_u8_UCSRCValue,UCZ0);
    #elif UART_DATA_BITS == _6_BITS
    CLR_BIT(UART_UCSRB_REG,UCZ2);
    CLR_BIT(Local_u8_UCSRCValue,UCZ1);
    SET_BIT(Local_u8_UCSRCValue,UCZ0);
    #elif UART_DATA_BITS == _7_BITS
    CLR_BIT(UART_UCSRB_REG,UCZ2);
    SET_BIT(Local_u8_UCSRCValue,UCZ1);
    CLR_BIT(Local_u8_UCSRCValue,UCZ0);
    #elif UART_DATA_BITS == _8_BITS
    CLR_BIT(UART_UCSRB_REG,UCZ2);
    SET_BIT(Local_u8_UCSRCValue,UCZ1);
    SET_BIT(Local_u8_UCSRCValue,UCZ0);
    #elif UART_DATA_BITS == _9_BITS
    SET_BIT(UART_UCSRB_REG,UCZ2);
    SET_BIT(Local_u8_UCSRCValue,UCZ1);
    SET_BIT(Local_u8_UCSRCValue,UCZ0);
    #endif
/******************UART Parity Bit****************/
    #if UART_PARITY_BIT == NONE
    CLR_BIT(Local_u8_UCSRCValue,UPM1);
    CLR_BIT(Local_u8_UCSRCValue,UPM0);
    #elif UART_PARITY_BIT == ODD_PARITY
    SET_BIT(Local_u8_UCSRCValue,UPM1);
    SET_BIT(Local_u8_UCSRCValue,UPM0);
    #elif UART_PARITY_BIT == EVEN_PARITY
    SET_BIT(Local_u8_UCSRCValue,UPM1);
    CLR_BIT(Local_u8_UCSRCValue,UPM0);
    #endif   
/************** Update UCSRC REG ********************/
    UART_UCSRC_REG = Local_u8_UCSRCValue;
/************** Baud Rate Value***********************/
    UART_UBRRL_REG = (u8)Local_u16_boudRateValue;
    UART_UBRRH_REG = (u8)(Local_u16_boudRateValue>>8);
/************** Enable (RX-TX) ************************/
    SET_BIT(UART_UCSRB_REG,RXEN);
    SET_BIT(UART_UCSRB_REG,TXEN);
}
ES_t UART_enu_sendChar(u8 Copy_u8_Char){
    u16 Local_u16_timeOutCounter = 0;
    /*Wait Transmit register is empty*/
    while((!GET_BIT(UART_UCSRA_REG,UDRE))&& (Local_u16_timeOutCounter<50000)){Local_u16_timeOutCounter++;}
    /*Send Byte Value*/
    UART_UDR_REG = Copy_u8_Char;
}
ES_t UART_enu_recieveChar(u8 *Copy_pu8_recievedChar){
    u8 Local_u8_errorState = STATE_OK;
    u16 Local_u16_timeOutCounter = 0;
    if(Copy_pu8_recievedChar!= NULL){
        /*Wait The Data Is Recieved */
        while((!GET_BIT(UART_UCSRA_REG,RXC))&&(Local_u16_timeOutCounter<50000)){Local_u16_timeOutCounter++;}
        *Copy_pu8_recievedChar = UART_UDR_REG;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t UART_enu_sendString(u8 *Copy_pu8_String){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_pu8_String!=NULL){
    u16 Local_u16_timeOutCounter = 0;
    for(u8 Local_u8_Iterator =0;Copy_pu8_String[Local_u8_Iterator]!='\0';Local_u8_Iterator++){
        /*Wait Transmit register is empty*/
        while((!GET_BIT(UART_UCSRA_REG,UDRE))&&(Local_u16_timeOutCounter<50000)){Local_u16_timeOutCounter++;}
        UART_UDR_REG = Copy_pu8_String[Local_u8_Iterator];
    }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t UART_enu_recieveString(u8 *Copy_pu8_recievedString,u8 Copy_u8_messageSize){
    u8 Local_u8_Iterator = 0;
    u16 Local_u16_timeOutCounter = 0;
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_pu8_recievedString!= NULL){
        while(Local_u8_Iterator < Copy_u8_messageSize){
            while((!GET_BIT(UART_UCSRA_REG,RXC)) && (Local_u16_timeOutCounter<50000)){Local_u16_timeOutCounter++;}
            Copy_pu8_recievedString[Local_u8_Iterator] = UART_UDR_REG;
            Local_u8_Iterator++;
        }
        Copy_pu8_recievedString[Local_u8_Iterator] = '\0';
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
/*************ISR(Recieve)**********/
void __vector_13(void){
    if(UART_pf_RX != NULL)
        UART_pf_RX();
}
/*************ISR(Transmit)**********/
void __vector_15(void){
    if(UART_pf_TX != NULL)
        UART_pf_RX();

}