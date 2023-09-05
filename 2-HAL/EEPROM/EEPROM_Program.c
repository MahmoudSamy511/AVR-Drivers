/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-09-02   *************************************/
/************* SWC     :   EEPROM       *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/BIT_MATH.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/ISR_Functions.h"
#define F_CPU  16000000UL
#include<util/delay.h>

#include"../../1-MCAL/DIO/DIO_interface.h"
#include"../../1-MCAL/I2C/I2C_Interface.h"

#include"EEPROM_Config.h"
#include"EEPROM_Private.h"

ES_t EEPROM_enu_Write(u16 Copy_u8_Location,u8 Copy_u8_Data){
    I2C_enu_Start();
    I2C_enu_writeData(0x50|(A2_PIN <<2)|(Copy_u8_Location>>8),(u8)Copy_u8_Location);
    I2C_enu_writeData(NONE,Copy_u8_Data);
    I2C_enu_Stop();
    _delay_ms(10);
    return STATE_OK;
}
ES_t EEPROM_enu_Read(u16 Copy_u8_Location,u8 *Copy_u8_receivedData){
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_u8_receivedData != NULL)
    {
        I2C_enu_Start();
        I2C_enu_writeData(0x50 | (A2_PIN << 2) | (Copy_u8_Location >> 8), (u8)Copy_u8_Location);
        I2C_enu_Start();
        I2C_enu_readData(0x50 | (A2_PIN << 2) | (Copy_u8_Location >> 8), Copy_u8_receivedData);
        I2C_enu_Stop();
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}

