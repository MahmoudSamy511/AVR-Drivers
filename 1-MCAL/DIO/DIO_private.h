/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-04-27   *************************************/
/************* SWC     :   DIO          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H
#include"../../5-LIB/TYPEDEF.h"
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

/*Macros for Registers*/
#define DIO_U8_PORTA_REG  *((volatile u8*)0x3B)
#define DIO_U8_DDRA_REG   *((volatile u8*)0x3A)
#define DIO_U8_PINA_REG   *((volatile u8*)0x39)

#define DIO_U8_PORTB_REG  *((volatile u8*)0x38)
#define DIO_U8_DDRB_REG   *((volatile u8*)0x37)
#define DIO_U8_PINB_REG   *((volatile u8*)0x36)

#define DIO_U8_PORTC_REG  *((volatile u8*)0x35)
#define DIO_U8_DDRC_REG   *((volatile u8*)0x34)
#define DIO_U8_PINC_REG   *((volatile u8*)0x33)

#define DIO_U8_PORTD_REG  *((volatile u8*)0x32)
#define DIO_U8_DDRD_REG   *((volatile u8*)0x31)
#define DIO_U8_PIND_REG   *((volatile u8*)0x30)

/*Macros For Pins Direction*/
#define DIO_U8_INITIAL_INPUT    0
#define DIO_U8_INITIAL_OUTPUT   1

/*Macros For Pins Values*/
#define DIO_U8_OUTPUT_LOW       0
#define DIO_U8_OUTPUT_HIGH      1
#define DIO_U8_INPUT_FLOATING   0
#define DIO_U8_INPUT_PULLUP     1

/*Macros For Port Direction*/
#define DIO_U8_SETPORT_OUTPUT     0xff
#define DIO_U8_SETPORT_INPUT      0x00


/*Function to concatenate pin values*/
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)          Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)     0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
