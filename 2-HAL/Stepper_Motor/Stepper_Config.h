/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-07-21       *************************************/
/************* SWC     :   Stepper Motor    *************************************/
/************* Version :   1.0          `   *************************************/
/********************************************************************************/
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
/*********** Configure Stepper Motor *************/
#define ROTATION_TYPE                HALF_STEP

#define STEP_ANGLE                   90

#define STEPPER_MOTOR_PORT          DIO_U8_PORTB
#define STEPPER_MOTOR_PIN1          DIO_U8_PIN0          
#define STEPPER_MOTOR_PIN2          DIO_U8_PIN1
#define STEPPER_MOTOR_PIN3          DIO_U8_PIN2
#define STEPPER_MOTOR_PIN4          DIO_U8_PIN3
