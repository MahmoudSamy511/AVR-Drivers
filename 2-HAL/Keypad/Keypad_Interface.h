/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-06   *************************************/
/************* SWC     :   Keypad       *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"


#define KEYPAD_U8_NO_KEY_PRESSED      0xff

ES_t Keypad_enu_Init();
ES_t Keypad_enu_getKey(u8 * Copy_pu8_ReturnedKey);




#endif
