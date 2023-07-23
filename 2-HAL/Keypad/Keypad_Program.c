/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-06   *************************************/
/************* SWC     :   Keypad       *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
/*LIB*/
#include "../../5-LIB/ERROR_STATE.h"
#include "../../5-LIB/BIT_MATH.h"
#include "../../5-LIB/TYPEDEF.h"
/*Processor Speed*/
#define F_CPU 16000000UL
#include <util/delay.h>
/*MCAL*/
#include "../../1-MCAL/DIO/DIO_interface.h"
/*HAL*/
#include "Keybad_Private.h"
#include "Keybad_Config.h"

const u8 Keypad_Au8_Keys[4][4] = KEYPAD_KEYS;
const u8 Keypad_Au8_RowsPins[4] = {KEYPAD_U8_ROW1_PIN, KEYPAD_U8_ROW2_PIN, KEYPAD_U8_ROW3_PIN, KEYPAD_U8_ROW4_PIN};
const u8 Keypad_Au8_ColsPins[4] = {KEYPAD_U8_COLUMN1_PIN, KEYPAD_U8_COLUMN2_PIN, KEYPAD_U8_COLUMN3_PIN, KEYPAD_U8_COLUMN4_PIN};

ES_t Keypad_enu_Init()
{
    /*Configure Rows And Columns Pins*/
    for (u8 Local_u8_iterator = 0; Local_u8_iterator < 4; Local_u8_iterator++)
    {
        DIO_enu_SetPinDirection(KEYPAD_U8_ROWS_PORT, Keypad_Au8_RowsPins[Local_u8_iterator], DIO_U8_OUTPUT);
        DIO_enu_SetPinValue(KEYPAD_U8_ROWS_PORT, Keypad_Au8_RowsPins[Local_u8_iterator], DIO_U8_HIGH);
        DIO_enu_SetPinDirection(KEYPAD_U8_COLUMNS_PORT, Keypad_Au8_ColsPins[Local_u8_iterator], DIO_U8_INPUT);
        DIO_enu_SetPinValue(KEYPAD_U8_COLUMNS_PORT, Keypad_Au8_ColsPins[Local_u8_iterator], DIO_U8_HIGH);
    }
    return STATE_OK;
}

ES_t Keypad_enu_getKey(u8 *Copy_pu8_ReturnedKey)
{
    u8 Local_u8_errorState = STATE_OK, Local_u8_rowsCounter, Local_u8_colsCounter, Local_u8_ReturnedState = 0, Local_u8_Flag = 0;
    if (Copy_pu8_ReturnedKey != NULL)
    {
        *Copy_pu8_ReturnedKey = NO_KEY_PRESSED;
        /*Activate Each Row*/
        for (Local_u8_rowsCounter = 0; Local_u8_rowsCounter < 4; Local_u8_rowsCounter++)
        {
            DIO_enu_SetPinValue(KEYPAD_U8_ROWS_PORT, Keypad_Au8_RowsPins[Local_u8_rowsCounter], DIO_U8_LOW);
            /*Check Which Input Pin Has Zero*/
            for (Local_u8_colsCounter = 0; Local_u8_colsCounter < 4; Local_u8_colsCounter++)
            {
                DIO_enu_GetPinValue(KEYPAD_U8_COLUMNS_PORT, Keypad_Au8_ColsPins[Local_u8_colsCounter], &Local_u8_ReturnedState);
                if (!Local_u8_ReturnedState) // Switch is Pressed
                {
                    // Bouncing Handling
                    _delay_ms(20);
                    DIO_enu_GetPinValue(KEYPAD_U8_COLUMNS_PORT, Keypad_Au8_ColsPins[Local_u8_colsCounter], &Local_u8_ReturnedState);
                    // Check if pin still low
                    while (!Local_u8_ReturnedState)
                    {
                        DIO_enu_GetPinValue(KEYPAD_U8_COLUMNS_PORT, Keypad_Au8_ColsPins[Local_u8_colsCounter], &Local_u8_ReturnedState);
                    }
                    *Copy_pu8_ReturnedKey = Keypad_Au8_Keys[Local_u8_rowsCounter][Local_u8_colsCounter];
                    Local_u8_Flag = 1;
                    break;
                }
            }
            // Deactivate the current Row
            DIO_enu_SetPinValue(KEYPAD_U8_ROWS_PORT, Keypad_Au8_RowsPins[Local_u8_rowsCounter], DIO_U8_HIGH);
            if (Local_u8_Flag)
            {
                break;
            }
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
