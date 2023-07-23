/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-21   *************************************/
/************* SWC     :   DC Motor     *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef DC_MOTOR_CONFIG_H
#define DC_MOTOR_CONFIG_H

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

/******************************* Configure Motor 1 ******************/
#define MOTOR_ENA_PORT      DIO_U8_PORTC
#define MOTOR_ENA_PIN       DIO_U8_PIN4
#define MOTOR_IN1_PORT      DIO_U8_PORTC
#define MOTOR_IN1_PIN       DIO_U8_PIN0
#define MOTOR_IN2_PORT      DIO_U8_PORTC
#define MOTOR_IN2_PIN       DIO_U8_PIN1

/******************************* Configure Motor 2 ******************/
#define MOTOR_ENB_PORT      DIO_U8_PORTC
#define MOTOR_ENB_PIN       DIO_U8_PIN5
#define MOTOR_IN3_PORT      DIO_U8_PORTC
#define MOTOR_IN3_PIN       DIO_U8_PIN2
#define MOTOR_IN4_PORT      DIO_U8_PORTC
#define MOTOR_IN4_PIN       DIO_U8_PIN3


#endif
