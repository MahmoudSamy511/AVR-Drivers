/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-09-02   *************************************/
/************* SWC     :   I2C          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/*Option For Mode:
                        1-I2C_MASTER
                        2-I2C_SLAVE 
*/
/*Option For Prescaler:
                        1-NO_PRESCALER
                        2-_4_PRESCALER 
                        2-_16_PRESCALER 
                        2-_64_PRESCALER 
*/
/*****************I2C Configurations***************/
#define I2C_MODE           I2C_MASTER
#define F_CPU              16000000UL
#define I2C_SPEED          200           //KHZ
#define I2C_PRESCALER      _4_PRESCALER   

#endif
