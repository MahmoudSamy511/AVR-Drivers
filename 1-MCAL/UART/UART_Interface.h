/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-22   *************************************/
/************* SWC     :    UART        *************************************/
/************* Version :    1.0         *************************************/
/****************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

ES_t UART_enu_Init(void);
// Busy Wait With Time Out Mechanism
ES_t UART_enu_sendChar(u8 Copy_u8_Char);
ES_t UART_enu_recieveChar(u8 *Copy_pu8_recievedChar);
ES_t UART_enu_sendString(u8 *Copy_pu8_String);
ES_t UART_enu_recieveString(u8 *Copy_pu8_recievedString,u8 Copy_u8_messageSize);
// Non Blocking Mechanism and Generate Interrupt
ES_t UART_enu_sendStringWithInterrupt(u8 *Copy_pu8_String,void(*Copy_pf)(void));
ES_t UART_enu_recievedStringWithInterrupt(u8 *Copy_pu8_recievedString,u8 Copy_u8_messageSize,void(*Copy_pf)(void));


#endif