/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-09-02   *************************************/
/************* SWC     :   EEPROM       *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

ES_t EEPROM_enu_Write(u16 Copy_u8_Location,u8 Copy_u8_Data);
ES_t EEPROM_enu_Read(u16 Copy_u8_Location,u8 *Copy_u8_receivedData);

#endif