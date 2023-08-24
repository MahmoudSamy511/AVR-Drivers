/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-31   *************************************/
/************* SWC     :    ADC         *************************************/
/************* Version :    1.0         *************************************/
/****************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H
#include"../../5-LIB/TYPEDEF.h"
/************************ ADC Registers **********************************/
#define ADMUX_REG    *((volatile u8 *)0x27)
#define ADCSRA_REG   *((volatile u8 *)0x26)
#define ADCH_REG     *((volatile u8 *)0x25)
#define ADCL_REG     *((volatile u8 *)0x24)  
#define SFIOR_REG    *((volatile u8 *)0x50)
#define ADC_REG      *((volatile u16 *)0x24)   //Read ADCL & ADCH In One Cycle.
/********************** Bits Of ADMUX Register ***************************/
#define REFS1                           7
#define REFS0                           6
#define ADLAR                           5
/********************* Bits Of ADCSRA Register ***************************/
#define ADEN                            7
#define ADSC                            6
#define ADATE                           5
#define ADIF                            4
#define ADIE                            3
#define ADPS2                           2
#define ADPS1                           1
#define ADPS0                           0
/********************* Bits Of SFOIR Register ***************************/
#define ADTS2                           2
#define ADTS1                           1
#define ADTS0                           0
/************************** ADC Channels *********************************/
#define ADC_U8_CHANNEL0                 0
#define ADC_U8_CHANNEL1                 1
#define ADC_U8_CHANNEL2                 2 
#define ADC_U8_CHANNEL3                 3
#define ADC_U8_CHANNEL4                 4
#define ADC_U8_CHANNEL5                 5
#define ADC_U8_CHANNEL6                 6
#define ADC_U8_CHANNEL7                 7
/**************************************************************************/
#define CLEAR_MUX_BITS                  0xE0
#define MAX_NUM_OF_CHANNELS             32

#define AVCC                             1
#define AREF                             0
#define INTERNAL_VOLTAGE_REF             3

#define DISABLE_AUTO_TRIGG               1
#define AUTO_TRIGG_FREE_RUNNING          2
#define AUTO_TRIGG_EXTERNAL_INTERRUPT    3

#define RIGHT_ADJUST                     0
#define LEFT_ADJUST                      1

#define DIV_BY_2                         1
#define DIV_BY_4                         2
#define DIV_BY_8                         3
#define DIV_BY_16                        4
#define DIV_BY_32                        5
#define DIV_BY_64                        6
#define DIV_BY_128                       7

#define ADC_U32_TIMEOUT_MAX_VALUE   50000


#endif