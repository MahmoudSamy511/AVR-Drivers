/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define LCD_U8_MODE_8BIT                 8
#define LCD_U8_MODE_4BIT                 4
/*************************** LCD Commands ***********************/
#define FOURBIT_INIT1					0x33
#define FOURBIT_INIT2                   0x32
#define FUN_SET_8BIT_2LINES_5X7         0x38
#define FUN_SET_4BIT_2LINES_5X7         0x28
#define DIS_ON_CURSOR_ON_BLINKING       0x0f
#define DIS_ON_CURSOR_OFF               0x0c
#define DISPLAY_CLEAR                   0x01
#define ENTRY_MOOD                      0x06
/*************************** LCD Addresses ***********************/
#define ADDRESS_OF_LINE1                0x80
#define ADDRESS_OF_LINE2                0xc0
#define ADDRESS_OF_CGRAM                0x40
/*************************** LCD Private Macros *********************/
#define SHIFT_7BIT						7
#define SHIFT_6BIT						6
#define SHIFT_5BIT						5
#define SHIFT_4BIT						4
#define SHIFT_3BIT						3
#define SHIFT_2BIT						2
#define SHIFT_1BIT						1
#define SHIFT_0BIT						0
#define LINE1                           0
#define LINE2                           1
#define MAX_CHARACTERS                  8
#define MASK_BIT       				    1

#endif
