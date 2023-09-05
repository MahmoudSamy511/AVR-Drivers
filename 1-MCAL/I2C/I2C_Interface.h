/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-09-02   *************************************/
/************* SWC     :   I2C          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

#define NONE  1000


ES_t I2C_enu_Init(void);
ES_t I2C_enu_setSlaveAddress(u8 Copy_u8_slaveAddress);
ES_t I2C_enu_Start(void);
ES_t I2C_enu_Stop(void);
ES_t I2C_enu_writeData(u16 Copy_u8_slaveAddress ,u8 Copy_u8_Data);
ES_t I2C_enu_readData(u8 Copy_u8_slaveAddress,u8 *Copy_pu8_receivedByte);



#endif