/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*Options for Ports: 1- DIO_U8_PORTA
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

/*Options for Mode: 1- LCD_U8_MODE_8BIT
                    2- LCD_U8_MODE_4BIT */

#define LCD_U8_MODE             LCD_U8_MODE_4BIT

#define LCD_U8_RS_PORT          DIO_U8_PORTA
#define LCD_U8_RW_PORT          DIO_U8_PORTA
#define LCD_U8_E_PORT           DIO_U8_PORTA

#define LCD_U8_RS_PIN           DIO_U8_PIN2
#define LCD_U8_RW_PIN           DIO_U8_PIN3
#define LCD_U8_E_PIN            DIO_U8_PIN4

#define LCD_U8_DATA_PORT        DIO_U8_PORTB






#endif
