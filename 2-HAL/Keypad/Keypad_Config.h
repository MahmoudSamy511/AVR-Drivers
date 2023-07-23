/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-06   *************************************/
/************* SWC     :   Keypad       *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/*Options for Ports: 1- DIO_U8_PORTA
                     2- DIO_U8_PORTB
                     3- DIO_U8_PORTC
                     4- DIO_U8_PORTD 
*/

/*Options For Pins:  1- DIO_U8_PIN0
                     2- DIO_U8_PIN1
                     3- DIO_U8_PIN2
                     4- DIO_U8_PIN3     
                     5- DIO_U8_PIN4    
                     6- DIO_U8_PIN5
                     7- DIO_U8_PIN6
                     8- DIO_U8_PIN7 
*/   
/*********** Configure Your Keys *************/
#define KEYPAD_KEYS                     {{'7','8','9','/'},\
                                         {'4','5','6','*'},\
                                         {'1','2','3','-'},\
                                         {'C','0','=','+'}}
/*********** Configure Rows Port and Pins *************/
#define KEYPAD_U8_ROWS_PORT             DIO_U8_PORTB
#define KEYPAD_U8_ROW1_PIN              DIO_U8_PIN4
#define KEYPAD_U8_ROW2_PIN              DIO_U8_PIN5
#define KEYPAD_U8_ROW3_PIN              DIO_U8_PIN6
#define KEYPAD_U8_ROW4_PIN              DIO_U8_PIN7
/*********** Configure Columns Port and Pins *************/
#define KEYPAD_U8_COLUMNS_PORT          DIO_U8_PORTD
#define KEYPAD_U8_COLUMN1_PIN           DIO_U8_PIN2
#define KEYPAD_U8_COLUMN2_PIN           DIO_U8_PIN3
#define KEYPAD_U8_COLUMN3_PIN           DIO_U8_PIN4
#define KEYPAD_U8_COLUMN4_PIN           DIO_U8_PIN5



#endif
