/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

#define LCD_U8_CHAR0                          0
#define LCD_U8_CHAR1                          1
#define LCD_U8_CHAR2                          2
#define LCD_U8_CHAR3                          3
#define LCD_U8_CHAR4                          4
#define LCD_U8_CHAR5                          5
#define LCD_U8_CHAR6                          6
#define LCD_U8_CHAR7                          7

ES_t LCD_enu_Init(void);

ES_t LCD_enu_SendCmnd(u8 Copy_u8_Cmdn);

ES_t LCD_enu_SendChar(u8 Copy_u8_Char);

ES_t LCD_enu_SendString(u8 * Copy_pu8_String);

ES_t LCD_enu_SendNum(u32 Copy_u32_Num);

ES_t LCD_enu_SetCursor(u8 Copy_u8_lineNum,u8 Copy_u8_Location);

ES_t LCD_enu_Clear(void);

ES_t LCD_enu_sendCustomChar(u8 Copy_u8_charNum,u8 * Copy_pu8_charArray,u8 Copy_u8_lineNum,u8 Copy_u8_Location);





#endif
