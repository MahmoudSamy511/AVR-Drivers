/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-04-27   *************************************/
/************* SWC     :   DIO          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

/*Macros for PORTS*/
#define DIO_U8_PORTA     0
#define DIO_U8_PORTB     1
#define DIO_U8_PORTC     2
#define DIO_U8_PORTD     3

/*Macros for PINS*/
#define DIO_U8_PIN0      0
#define DIO_U8_PIN1      1
#define DIO_U8_PIN2      2
#define DIO_U8_PIN3      3
#define DIO_U8_PIN4      4
#define DIO_U8_PIN5      5
#define DIO_U8_PIN6      6
#define DIO_U8_PIN7      7

/*Macros for Pin Direction*/
#define DIO_U8_INPUT     0
#define DIO_U8_OUTPUT    1

/*Macros for Pin Value*/
#define DIO_U8_LOW       0
#define DIO_U8_HIGH      1

/*Functions Prototypes*/
ES_t DIO_enu_Init           	(void);

ES_t DIO_enu_SetPinDirection    (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 Copy_u8_PinDirection);

ES_t DIO_enu_SetPinValue        (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 Copy_u8_PinValue);

ES_t DIO_enu_GetPinValue        (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinValue);

ES_t DIO_enu_SetPortDirection   (u8 Copy_u8_PortId, u8 Copy_u8_PortDirection);

ES_t DIO_enu_SetPortValue       (u8 Copy_u8_PortId, u8 Copy_u8_PortValue);

ES_t DIO_enu_GetPortValue       (u8 Copy_u8_PortId, u8 * Copy_u8_ReturnPortValue);


#endif
