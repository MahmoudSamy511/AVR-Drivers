/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/

/*Lib Layer*/
#include "../../5-LIB/TYPEDEF.h"
#include "../../5-LIB/ERROR_STATE.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../1-MCAL/DIO/DIO_interface.h"
/*HAL*/
#include "../../2-HAL/LCD/LCD_Private.h"
#include "../../2-HAL/LCD/LCD_Config.h"
ES_t LCD_enu_SendCmnd(u8 Copy_u8_Cmdn)
{
#if LCD_U8_MODE == LCD_U8_MODE_8BIT
    /* RS = 0 */
    DIO_enu_SetPinValue(LCD_U8_RS_PORT, LCD_U8_RS_PIN, DIO_U8_LOW);
    /* RW = 0 */
    DIO_enu_SetPinValue(LCD_U8_RW_PORT, LCD_U8_RW_PIN, DIO_U8_LOW);
    /*Write Command*/
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D7, (Copy_u8_Cmdn >> SHIFT_7BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D6, (Copy_u8_Cmdn >> SHIFT_6BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D5, (Copy_u8_Cmdn >> SHIFT_5BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D4, (Copy_u8_Cmdn >> SHIFT_4BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D3, (Copy_u8_Cmdn >> SHIFT_3BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D2, (Copy_u8_Cmdn >> SHIFT_2BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D1, (Copy_u8_Cmdn >> SHIFT_1BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D0, (Copy_u8_Cmdn >> SHIFT_0BIT) & MASK_BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_LOW);
    return STATE_OK;
#elif LCD_U8_MODE == LCD_U8_MODE_4BIT
    /*Send Command at 4-bit mode*/
    /* RS = 0 */
    DIO_enu_SetPinValue(LCD_U8_RS_PORT, LCD_U8_RS_PIN, DIO_U8_LOW);
    /* RW = 0 */
    DIO_enu_SetPinValue(LCD_U8_RW_PORT, LCD_U8_RW_PIN, DIO_U8_LOW);
    /*Write Command*/
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D7, (Copy_u8_Cmdn >> SHIFT_7BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D6, (Copy_u8_Cmdn >> SHIFT_6BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D5, (Copy_u8_Cmdn >> SHIFT_5BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D4, (Copy_u8_Cmdn >> SHIFT_4BIT) & MASK_BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_LOW);
    /*Write the rest of the cmnd*/
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D7, (Copy_u8_Cmdn >> SHIFT_3BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D6, (Copy_u8_Cmdn >> SHIFT_2BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D5, (Copy_u8_Cmdn >> SHIFT_1BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D4, (Copy_u8_Cmdn >> SHIFT_0BIT) & MASK_BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_LOW);
    return STATE_OK;
#endif
}
ES_t LCD_enu_SendChar(u8 Copy_u8_Char)
{
#if LCD_U8_MODE == LCD_U8_MODE_8BIT
    /* RS = 1 */
    DIO_enu_SetPinValue(LCD_U8_RS_PORT, LCD_U8_RS_PIN, DIO_U8_HIGH);
    /* RW = 0 */
    DIO_enu_SetPinValue(LCD_U8_RW_PORT, LCD_U8_RW_PIN, DIO_U8_LOW);
    /*Write Char*/
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D7, (Copy_u8_Char >> SHIFT_7BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D6, (Copy_u8_Char >> SHIFT_6BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D5, (Copy_u8_Char >> SHIFT_5BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D4, (Copy_u8_Char >> SHIFT_4BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D3, (Copy_u8_Char >> SHIFT_3BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D2, (Copy_u8_Char >> SHIFT_2BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D1, (Copy_u8_Char >> SHIFT_1BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D0, (Copy_u8_Char >> SHIFT_0BIT) & MASK_BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_LOW);
    return STATE_OK;
#elif LCD_U8_MODE == LCD_U8_MODE_4BIT
    /* RS = 1 */
    DIO_enu_SetPinValue(LCD_U8_RS_PORT, LCD_U8_RS_PIN, DIO_U8_HIGH);
    /* RW = 0 */
    DIO_enu_SetPinValue(LCD_U8_RW_PORT, LCD_U8_RW_PIN, DIO_U8_LOW);
    /*Write Char*/
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D7, (Copy_u8_Char >> SHIFT_7BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D6, (Copy_u8_Char >> SHIFT_6BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D5, (Copy_u8_Char >> SHIFT_5BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D4, (Copy_u8_Char >> SHIFT_4BIT) & MASK_BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_LOW);
    /*Write Char*/
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D7, (Copy_u8_Char >> SHIFT_3BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D6, (Copy_u8_Char >> SHIFT_2BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D5, (Copy_u8_Char >> SHIFT_1BIT) & MASK_BIT);
    DIO_enu_SetPinValue(LCD_U8_DATA_PORT, D4, (Copy_u8_Char >> SHIFT_0BIT) & MASK_BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_LOW);
    return STATE_OK;
#endif
}
ES_t LCD_enu_SendString(u8 *Copy_pu8_String)
{
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_pu8_String != NULL)
    {
        for (u8 i = 0; Copy_pu8_String[i] != '\0'; i++)
        {
            LCD_enu_SendChar(Copy_pu8_String[i]);
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t LCD_enu_SendNum(u32 Copy_u32_Num)
{
    u8 Local_u8_numArr[10], Local_u8_iterator1 = 0;
    s8 Local_u8_iterator2 = 0;
    if (Copy_u32_Num == 0)
        LCD_enu_SendChar('0');
    else
    {
        while (Copy_u32_Num != 0)
        {
            Local_u8_numArr[Local_u8_iterator1] = Copy_u32_Num % 10;
            Copy_u32_Num /= 10;
            Local_u8_iterator1++;
        }
        for (Local_u8_iterator2 = Local_u8_iterator1 - 1; Local_u8_iterator2 >= 0; Local_u8_iterator2--)
        {
            LCD_enu_SendChar(Local_u8_numArr[Local_u8_iterator2] + '0');
        }
    }
    return STATE_OK;
}
ES_t LCD_enu_SetCursor(u8 Copy_u8_lineNum, u8 Copy_u8_Location)
{
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_u8_Location < MAX_NUM_OF_LOCATIONS)
    {
        switch (Copy_u8_lineNum)
        {
        case LINE1:LCD_enu_SendCmnd(ADDRESS_OF_LINE1 + Copy_u8_Location);break;
        case LINE2:LCD_enu_SendCmnd(ADDRESS_OF_LINE2 + Copy_u8_Location);break;
        default:Local_u8_errorState = STATE_NOT_OK;break;
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t LCD_enu_Init(void)
{
    DIO_enu_SetPinDirection(LCD_U8_RS_PORT, LCD_U8_RS_PIN, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_RW_PORT, LCD_U8_RW_PIN, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_E_PORT, LCD_U8_E_PIN, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D7, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D6, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D5, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D4, DIO_U8_OUTPUT);
#if LCD_U8_MODE == LCD_U8_MODE_8BIT
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D3, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D2, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D1, DIO_U8_OUTPUT);
    DIO_enu_SetPinDirection(LCD_U8_DATA_PORT, D0, DIO_U8_OUTPUT);
    _delay_ms(35);
    LCD_enu_SendCmnd(FUN_SET_8BIT_2LINES_5X7);
    _delay_us(40);
    LCD_enu_SendCmnd(LCD_U8_CURSOR);
    _delay_us(40);
    LCD_enu_SendCmnd(DISPLAY_CLEAR);
    _delay_ms(2);
    LCD_enu_SendCmnd(ENTRY_MOOD);
    return STATE_OK;
#elif LCD_U8_MODE == LCD_U8_MODE_4BIT
    _delay_ms(35);
    LCD_enu_SendCmnd(FOURBIT_INIT1);
    LCD_enu_SendCmnd(FOURBIT_INIT2);
    LCD_enu_SendCmnd(FUN_SET_4BIT_2LINES_5X7);
    _delay_us(40);
    LCD_enu_SendCmnd(LCD_U8_CURSOR);
    _delay_us(40);
    LCD_enu_SendCmnd(DISPLAY_CLEAR);
    _delay_ms(2);
    LCD_enu_SendCmnd(ENTRY_MOOD);
    return STATE_OK;
#endif
}
ES_t LCD_enu_Clear(void)
{
    LCD_enu_SendCmnd(DISPLAY_CLEAR);
    _delay_ms(2);
    return STATE_OK;
}
ES_t LCD_enu_sendCustomChar(u8 Copy_u8_charNum, u8 *Copy_pu8_charArray, u8 Copy_u8_lineNum, u8 Copy_u8_Location)
{
    u8 Local_u8_errorState = STATE_OK;
    if ((Copy_pu8_charArray != NULL) && (Copy_u8_charNum < MAX_CHARACTERS) && (Copy_u8_lineNum < NUM_OF_LINES) && (Copy_u8_Location < MAX_NUM_OF_LOCATIONS))
    {
        LCD_enu_SendCmnd(ADDRESS_OF_CGRAM + (Copy_u8_charNum * MAX_CHARACTERS));
        for (u8 Local_u8_Counter = 0; Local_u8_Counter < MAX_CHARACTERS; Local_u8_Counter++)
        {
            LCD_enu_SendChar(Copy_pu8_charArray[Local_u8_Counter]);
        }
        LCD_enu_SetCursor(Copy_u8_lineNum, Copy_u8_Location);
        LCD_enu_SendChar(Copy_u8_charNum);
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
