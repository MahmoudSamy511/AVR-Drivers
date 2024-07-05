/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-07-08       *************************************/
/************* SWC     :   Senven Segment   *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/
#ifndef SEVENSEG_INTERFACE_H
#define SEVENSEG_INTERFACE_H

#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/TYPEDEF.h"

 /*Options for Ports:1- DIO_U8_PORTA
                     2- DIO_U8_PORTB
                     3- DIO_U8_PORTC
                     4- DIO_U8_PORTD */

/*Options For Pins:  1- DIO_U8_PIN0
                     2- DIO_U8_PIN1
                     3- DIO_U8_PIN2
                     4- DIO_U8_PIN3     
                     5- DIO_U8_PIN4    
                     6- DIO_U8_PIN5
                     7- DIO_U8_PIN6
                     8- DIO_U8_PIN7 */

/*Options For Enable Pin:       1- COMMON_ANODE
                                2- COMMON_CATHODE
                                3- FARES_KIT
*/

#define COMMON_CATHODE          0
#define COMMON_ANODE            1
#define FARES_KIT               2

typedef struct 
{
    u8 Port;
    u8 Start_Pin;
    u8 End_Pin;
    u8 Type;
    u8 Enable_Port;
    u8 Enable_Pin;

}SevenSeg_t;

ES_t sevenSeg_enu_init(SevenSeg_t * Copy_SevenSeg_t_Seg);
ES_t sevenSeg_enu_displayNum(SevenSeg_t * Copy_SevenSeg_t_Seg,u8 Copy_u8_Num);


#endif