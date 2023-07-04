/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define LCD_U8_MODE_8BIT         8
#define LCD_U8_MODE_4BIT         4

#define FUN_SET_8BIT_2LINES_5X7      0x38
#define DIS_ON_CURSOR_ON_BLINKING    0x0f
#define DISPLAY_CLEAR                0x01
#define ENTRY_MOOD                   0x06
#define D4_D7_2LINES                 0x28
#define FourBIT_INIT1                0x33
#define FourBIT_INIT2                0x32

#define LINE1                          0
#define LINE2                          1

#define ADDRESS_OF_LINE1               0x80
#define ADDRESS_OF_LINE2               0xc0

#define CHAR_0                          0
#define CHAR_1                          1                 
#define CHAR_2                          2
#define CHAR_3                          3
#define CHAR_4                          4
#define CHAR_5                          5
#define CHAR_6                          6
#define CHAR_7                          7

#define SHIFT_4BIT                      4

#define ADDRESS_OF_CGRAM             0x40
#define MAX_CHARACTERS                8






#endif
