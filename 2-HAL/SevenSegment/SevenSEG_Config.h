/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-07-08       *************************************/
/************* SWC     :   Senven Segment   *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/
#ifndef SEVENSEG_CONFIG_H
#define SEVENSEG_CONFIG_H
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

/*Options For Enable Pin:       1- INTERNAL
                                2- EXTERNAL
*/

/*********Choose Your Enable Pin Mode************/
#define  SEVEN_SEGMENT_ENABLE_PIN     INTERNAL
#define  SEVEN_SEGMENT_U8_E_PORT    DIO_U8_PORTC
#define  SEVEN_SEGMENT_U8_E_PIN     DIO_U8_PIN6
/*********Choose Your Seven Segment Port & Pins************/
#define  SEVEN_SEGMENT_U8_PORT      DIO_U8_PORTA
#define  PIN_U8_A                   DIO_U8_PIN1
#define  PIN_U8_B                   DIO_U8_PIN2
#define  PIN_U8_C                   DIO_U8_PIN3
#define  PIN_U8_D                   DIO_U8_PIN4
#define  PIN_U8_E                   DIO_U8_PIN5
#define  PIN_U8_F                   DIO_U8_PIN6
#define  PIN_U8_G                   DIO_U8_PIN7


#endif