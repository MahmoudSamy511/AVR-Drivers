/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-31   *************************************/
/************* SWC     :   SPI        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/BIT_MATH.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/ISR_Functions.h"

#include"../../1-MCAL/DIO/DIO_interface.h"

#include"SPI_Config.h"
#include"SPI_Private.h"

ES_t SPI_enu_Init(void){
    //Mode
    #if SPI_MODE == SPI_MASTER
    //MOSI --> OUTPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_OUTPUT);
    //MISO --> INPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_INPUT);
    //CLK --> OUTPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN7,DIO_U8_OUTPUT);
    //SS --> OUTPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_OUTPUT);
    DIO_enu_SetPinValue(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_HIGH);
    SET_BIT(SPI_SPCR,MSTR);
    #elif  SPI_MODE == SPI_SLAVE
    //MOSI --> INPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_INPUT);
    //MISO --> OUTPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_OUTPUT);
    //CLK --> INPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN7,DIO_U8_INPUT);
    //SS --> INPUT
    DIO_enu_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_INPUT);
    CLR_BIT(SPI_SPCR,MSTR);
    #endif
    //Data Order
    #if SPI_DATA_ORDER == LSB
    SET_BIT(SPI_SPCR,DORD);
    #elif  SPI_DATA_ORDER == MSB
    CLR_BIT(SPI_SPCR,DORD);
    #endif
    //Clock Polarity 
    #if SPI_CLOCK_POLARITY == LEADING_RISING
    CLR_BIT(SPI_SPCR,CPOL);
    #elif #if SPI_CLOCK_POLARITY == LEADING_FALLING
    SET_BIT(SPI_SPCR,CPOL);
    #endif
    //Clock Phase 
    #if SPI_CLOCK_PHASE== LEADING_SAMPLE
    CLR_BIT(SPI_SPCR,CPHA);
    #elif SPI_CLOCK_PHASE== LEADING_SETUP
    SET_BIT(SPI_SPCR,CPHA);
    #endif
    //Clock Prescaler 
    #if SPI_CLOCK_PRESCALER == DIV_2
    CLR_BIT(SPI_SPCR,SPR0);
    CLR_BIT(SPI_SPCR,SPR1);
    SET_BIT(SPI_SPSR,SPI2X);
    #elif SPI_CLOCK_PRESCALER == DIV_4
    CLR_BIT(SPI_SPCR,SPR0);
    CLR_BIT(SPI_SPCR,SPR1);
    CLR_BIT(SPI_SPSR,SPI2X);
    #elif SPI_CLOCK_PRESCALER == DIV_8
    SET_BIT(SPI_SPCR,SPR0);
    CLR_BIT(SPI_SPCR,SPR1);
    SET_BIT(SPI_SPSR,SPI2X);
    #elif SPI_CLOCK_PRESCALER == DIV_16
    SET_BIT(SPI_SPCR,SPR0);
    CLR_BIT(SPI_SPCR,SPR1);
    CLR_BIT(SPI_SPSR,SPI2X);
    #elif SPI_CLOCK_PRESCALER == DIV_32
    CLR_BIT(SPI_SPCR,SPR0);
    SET_BIT(SPI_SPCR,SPR1);
    SET_BIT(SPI_SPSR,SPI2X);
    #elif SPI_CLOCK_PRESCALER == DIV_64
    SET_BIT(SPI_SPCR,SPR0);
    SET_BIT(SPI_SPCR,SPR1);
    SET_BIT(SPI_SPSR,SPI2X);
    #elif SPI_CLOCK_PRESCALER == DIV_128
    SET_BIT(SPI_SPCR,SPR0);
    SET_BIT(SPI_SPCR,SPR1);
    CLR_BIT(SPI_SPSR,SPI2X);
    #endif
    //Enable SPI
    SET_BIT(SPI_SPCR,SPE);
    return STATE_OK;
}
ES_t SPI_enu_Transceive(u8 Copy_u8_Data ,u8 *Copy_u8_recievedData){
        //Send Data
        SPI_SPDR = Copy_u8_Data;
        while ((!GET_BIT(SPI_SPSR,SPIF)));
        //Receive Data
        *Copy_u8_recievedData = SPI_SPDR;
        return STATE_OK;
}
