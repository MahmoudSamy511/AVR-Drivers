/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-04-27   *************************************/
/************* SWC     :   DIO          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H
/*Initial Directions For All Pins*/
/*Options: DIO_U8_INITIAL_OUTPUT
           DIO_U8_INITIAL_INPUT*/
/*PORTA*/
#define DIO_U8_PA0_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA1_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA2_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA3_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA4_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA5_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA6_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PA7_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT 
/*PORTB*/
#define DIO_U8_PB0_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PB1_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PB2_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PB3_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PB4_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PB5_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PB6_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PB7_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
/*PORTC*/
#define DIO_U8_PC0_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PC1_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PC2_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PC3_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PC4_INITIAL_DIRECTION                    DIO_U8_INITIAL_OUTPUT
#define DIO_U8_PC5_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PC6_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PC7_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
/*PORTD*/
#define DIO_U8_PD0_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD1_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD2_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD3_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD4_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD5_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD6_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
#define DIO_U8_PD7_INITIAL_DIRECTION                    DIO_U8_INITIAL_INPUT
/*Initial Values For All Pins*/
/*Options: DIO_U8_OUTPUT_HIGH
           DIO_U8_OUTPUT_LOW
           DIO_U8_INPUT_FLOATING
           DIO_U8_INPUT_PULLUP
           */
/*PORTA*/
#define DIO_U8_PA0_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA1_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA2_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA3_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA4_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA5_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA6_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PA7_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING 
/*PORTB*/   
#define DIO_U8_PB0_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PB1_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PB2_INITIAL_VALUE                        DIO_U8_OUTPUT_HIGH
#define DIO_U8_PB3_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PB4_INITIAL_VALUE                        DIO_U8_OUTPUT_HIGH
#define DIO_U8_PB5_INITIAL_VALUE                        DIO_U8_OUTPUT_HIGH
#define DIO_U8_PB6_INITIAL_VALUE                        DIO_U8_OUTPUT_HIGH
#define DIO_U8_PB7_INITIAL_VALUE                        DIO_U8_OUTPUT_HIGH
/*PORTC*/   
#define DIO_U8_PC0_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PC1_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PC2_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PC3_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PC4_INITIAL_VALUE                        DIO_U8_OUTPUT_LOW
#define DIO_U8_PC5_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PC6_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PC7_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
/*PORTD*/   
#define DIO_U8_PD0_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PD1_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PD2_INITIAL_VALUE                        DIO_U8_INPUT_PULLUP
#define DIO_U8_PD3_INITIAL_VALUE                        DIO_U8_INPUT_PULLUP
#define DIO_U8_PD4_INITIAL_VALUE                        DIO_U8_INPUT_PULLUP
#define DIO_U8_PD5_INITIAL_VALUE                        DIO_U8_INPUT_PULLUP
#define DIO_U8_PD6_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING
#define DIO_U8_PD7_INITIAL_VALUE                        DIO_U8_INPUT_FLOATING


#endif
