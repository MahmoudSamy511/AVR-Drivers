/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-31   *************************************/
/************* SWC     :    ADC         *************************************/
/************* Version :    1.0         *************************************/
/****************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

/********************************Options For Channels********************/
#define ADC_U8_CHANNEL0         0
#define ADC_U8_CHANNEL1         1
#define ADC_U8_CHANNEL2         2 
#define ADC_U8_CHANNEL3         3
#define ADC_U8_CHANNEL4         4
#define ADC_U8_CHANNEL5         5
#define ADC_U8_CHANNEL6         6
#define ADC_U8_CHANNEL7         7

ES_t ADC_enu_Init(void);
ES_t ADC_enu_GetDigitalValueSynchNonBlocking(u8 Copy_u8_channelNb, u16 * Copy_pu16_DigitalValue);
ES_t ADC_enu_GetDigitalValueASynch(u8 Copy_u8_channelNb, u8(* Copy_pf_Notification)(void));




#endif