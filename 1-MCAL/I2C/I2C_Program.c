/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-09-02   *************************************/
/************* SWC     :   I2C          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/BIT_MATH.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/ISR_Functions.h"
#include"../../1-MCAL/WDT/WDT_Interface.h"

#include"I2C_Config.h"
#include"I2C_Private.h"

static void I2C_enu_clearAndCheckFlag(void){
    //Clear Flag
    SET_BIT(I2C_TWCR,TWINT);
    //Wait Flag
    while((!GET_BIT(I2C_TWCR,TWINT)));
}
ES_t I2C_enu_Init(void){
    /*  1-Select Prescaler
    2- Set TWBR REG
    3- Enable ACK
    4- Enable I2C
*/
    #if I2C_MODE == I2C_MASTER
    //1-Select Prescaler
    CLR_BIT(I2C_TWSR,TWPS0);
    CLR_BIT(I2C_TWSR,TWPS1);
    //2-Set TWBR REG
    I2C_TWBR = ((F_CPU/I2C_SPEED)-16)/(2*I2C_PRESCALER);
    //3- Enable ACK
    SET_BIT(I2C_TWCR,TWEA);
    //4- Enable I2C
    SET_BIT(I2C_TWCR,TWEN);
    #elif I2C_MODE == I2C_SLAVE
    //1- Enable ACK
    SET_BIT(I2C_TWCR,TWEA);
    //2- Enable I2C
    SET_BIT(I2C_TWCR,TWEN);
    #endif
    return STATE_OK;
}
ES_t I2C_enu_setSlaveAddress(u8 Copy_u8_slaveAddress){
    // Set Slave Address
    I2C_TWAR = (Copy_u8_slaveAddress<<1);
    return STATE_OK;
}
ES_t I2C_enu_Start(void){
    //1- Enable Start Condition
    SET_BIT(I2C_TWCR,TWSTA);
    I2C_enu_clearAndCheckFlag();
    return STATE_OK;
}
ES_t I2C_enu_Stop(void){
    //1- Enable Stop Condition
    SET_BIT(I2C_TWCR,TWSTO);
    //2- Clear Flag
    SET_BIT(I2C_TWCR,TWINT);
    return STATE_OK;
}
ES_t I2C_enu_writeData(u16 Copy_u8_slaveAddress ,u8 Copy_u8_Data){
    if (Copy_u8_slaveAddress != NONE)
    {
        // 1- Write Slave Address
        I2C_TWDR = (Copy_u8_slaveAddress << 1);
        // 2-Set Write Operation
        CLR_BIT(I2C_TWDR, TWD0);
        // 3-Start Bit
        CLR_BIT(I2C_TWCR, TWSTA);
        I2C_enu_clearAndCheckFlag();
    }
        // 4- Write Data
        I2C_TWDR = Copy_u8_Data;
        I2C_enu_clearAndCheckFlag();
    return STATE_OK;
}
ES_t I2C_enu_readData(u8 Copy_u8_slaveAddress,u8 *Copy_pu8_receivedByte){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_pu8_receivedByte != NULL){
        #if I2C_MODE == I2C_MASTER
        //1- Write Slave Address
        I2C_TWDR = (Copy_u8_slaveAddress<<1);
        //2- Set Read Operation
        SET_BIT(I2C_TWDR,TWD0);
        //3-Start Bit
        CLR_BIT(I2C_TWCR,TWSTA);
        I2C_enu_clearAndCheckFlag();
        //4- Check Data Received
        I2C_enu_clearAndCheckFlag();
        //5-Read Data
        *Copy_pu8_receivedByte= I2C_TWDR;
        #elif I2C_MODE == I2C_SLAVE
        //Wait to recieve Slave Address
        while( (TWSR & 0xf8) != 0x60);
        I2C_enu_clearAndCheckFlag();
        //Wait to recieve Data
        while( (TWSR & 0xf8) != 0x80);
        *Copy_pu8_receivedByte = I2C_TWDR;
        #endif
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;

}
