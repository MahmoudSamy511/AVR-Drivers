/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-04-27   *************************************/
/************* SWC     :   DIO          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
/*Lib Layer*/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/BIT_MATH.h"
#include"../../5-LIB/ERROR_STATE.h"
/*MCAL*/
#include"DIO_private.h"
#include"DIO_config.h"


ES_t DIO_enu_Init(void){
    DIO_U8_DDRA_REG = Conc(DIO_U8_PA7_INITIAL_DIRECTION,DIO_U8_PA6_INITIAL_DIRECTION,DIO_U8_PA5_INITIAL_DIRECTION,DIO_U8_PA4_INITIAL_DIRECTION,
                           DIO_U8_PA3_INITIAL_DIRECTION,DIO_U8_PA2_INITIAL_DIRECTION,DIO_U8_PA1_INITIAL_DIRECTION,DIO_U8_PA0_INITIAL_DIRECTION);
    DIO_U8_DDRB_REG = Conc(DIO_U8_PB7_INITIAL_DIRECTION,DIO_U8_PB6_INITIAL_DIRECTION,DIO_U8_PB5_INITIAL_DIRECTION,DIO_U8_PB4_INITIAL_DIRECTION,
                           DIO_U8_PB3_INITIAL_DIRECTION,DIO_U8_PB2_INITIAL_DIRECTION,DIO_U8_PB1_INITIAL_DIRECTION,DIO_U8_PB0_INITIAL_DIRECTION);

    DIO_U8_DDRC_REG = Conc(DIO_U8_PC7_INITIAL_DIRECTION,DIO_U8_PC6_INITIAL_DIRECTION,DIO_U8_PC5_INITIAL_DIRECTION,DIO_U8_PC4_INITIAL_DIRECTION,
                           DIO_U8_PC3_INITIAL_DIRECTION,DIO_U8_PC2_INITIAL_DIRECTION,DIO_U8_PC1_INITIAL_DIRECTION,DIO_U8_PC0_INITIAL_DIRECTION);

    DIO_U8_DDRD_REG = Conc(DIO_U8_PD7_INITIAL_DIRECTION,DIO_U8_PD6_INITIAL_DIRECTION,DIO_U8_PD5_INITIAL_DIRECTION,DIO_U8_PD4_INITIAL_DIRECTION,
                           DIO_U8_PD3_INITIAL_DIRECTION,DIO_U8_PD2_INITIAL_DIRECTION,DIO_U8_PD1_INITIAL_DIRECTION,DIO_U8_PD0_INITIAL_DIRECTION);

    DIO_U8_PORTA_REG = Conc(DIO_U8_PA7_INITIAL_VALUE,DIO_U8_PA6_INITIAL_VALUE,DIO_U8_PA5_INITIAL_VALUE,DIO_U8_PA4_INITIAL_VALUE,
                            DIO_U8_PA3_INITIAL_VALUE,DIO_U8_PA2_INITIAL_VALUE,DIO_U8_PA1_INITIAL_VALUE,DIO_U8_PA0_INITIAL_VALUE);

    DIO_U8_PORTB_REG = Conc(DIO_U8_PB7_INITIAL_VALUE,DIO_U8_PB6_INITIAL_VALUE,DIO_U8_PB5_INITIAL_VALUE,DIO_U8_PB4_INITIAL_VALUE,
                            DIO_U8_PB3_INITIAL_VALUE,DIO_U8_PB2_INITIAL_VALUE,DIO_U8_PB1_INITIAL_VALUE,DIO_U8_PB0_INITIAL_VALUE);

    DIO_U8_PORTC_REG = Conc(DIO_U8_PC7_INITIAL_VALUE,DIO_U8_PC6_INITIAL_VALUE,DIO_U8_PC5_INITIAL_VALUE,DIO_U8_PC4_INITIAL_VALUE,
                            DIO_U8_PC3_INITIAL_VALUE,DIO_U8_PC2_INITIAL_VALUE,DIO_U8_PC1_INITIAL_VALUE,DIO_U8_PC0_INITIAL_VALUE);

    DIO_U8_PORTD_REG = Conc(DIO_U8_PD7_INITIAL_VALUE,DIO_U8_PD6_INITIAL_VALUE,DIO_U8_PD5_INITIAL_VALUE,DIO_U8_PD4_INITIAL_VALUE,
                            DIO_U8_PD3_INITIAL_VALUE,DIO_U8_PD2_INITIAL_VALUE,DIO_U8_PD1_INITIAL_VALUE,DIO_U8_PD0_INITIAL_VALUE);
    return SATE_OK;
}
ES_t DIO_enu_SetPinDirection (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 Copy_u8_PinDirection)
{
    u8 Local_u8_ErrorState = SATE_OK;
    if((Copy_u8_PortId <= DIO_U8_PORTD) && (Copy_u8_PinId <= DIO_U8_PIN7) && ((Copy_u8_PinDirection == DIO_U8_OUTPUT)||(Copy_u8_PinDirection == DIO_U8_INPUT))){
        switch (Copy_u8_PortId)
        {
        case DIO_U8_PORTA:
            switch (Copy_u8_PinDirection)
            {
                case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRA_REG,Copy_u8_PinId); break;
                case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRA_REG,Copy_u8_PinId); break; 
            }
        break;
        case DIO_U8_PORTB:
            switch (Copy_u8_PinDirection)
            {
                case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRB_REG,Copy_u8_PinId); break;
                case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRB_REG,Copy_u8_PinId); break; 
            }
        break;
        case DIO_U8_PORTC:
            switch (Copy_u8_PinDirection)
            {
                case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRC_REG,Copy_u8_PinId); break;
                case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRC_REG,Copy_u8_PinId); break; 
            } 
        break;
        case DIO_U8_PORTD:
            switch (Copy_u8_PinDirection)
            {
                case DIO_U8_OUTPUT:SET_BIT(DIO_U8_DDRD_REG,Copy_u8_PinId); break;
                case DIO_U8_INPUT: CLR_BIT(DIO_U8_DDRD_REG,Copy_u8_PinId); break; 
            } 
        break;
        }
    }
    else
    {
        Local_u8_ErrorState = SATE_NOT_OK;
    }
    return Local_u8_ErrorState;
}

ES_t DIO_enu_SetPinValue(u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 Copy_u8_PinValue){
    u8 Local_u8_ErrorState = SATE_OK;
    if((Copy_u8_PortId <= DIO_U8_PORTD) && (Copy_u8_PinId <= DIO_U8_PIN7) && ((Copy_u8_PinValue == DIO_U8_HIGH)||(Copy_u8_PinValue == DIO_U8_LOW))){
        switch (Copy_u8_PortId)
        {
        case DIO_U8_PORTA:
            switch (Copy_u8_PinValue)
            {
                case DIO_U8_HIGH:SET_BIT(DIO_U8_PORTA_REG,Copy_u8_PinId); break;
                case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTA_REG,Copy_u8_PinId); break; 
            }
        break;
        case DIO_U8_PORTB:
            switch (Copy_u8_PinValue)
            {
                case DIO_U8_HIGH:SET_BIT(DIO_U8_PORTB_REG,Copy_u8_PinId); break;
                case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTB_REG,Copy_u8_PinId); break; 
            }
        break;
        case DIO_U8_PORTC:
            switch (Copy_u8_PinValue)
            {
                case DIO_U8_HIGH:SET_BIT(DIO_U8_PORTC_REG,Copy_u8_PinId); break;
                case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTC_REG,Copy_u8_PinId); break; 
            } 
        break;
        case DIO_U8_PORTD:
            switch (Copy_u8_PinValue)
            {
                case DIO_U8_HIGH:SET_BIT(DIO_U8_PORTD_REG,Copy_u8_PinId); break;
                case DIO_U8_LOW: CLR_BIT(DIO_U8_PORTD_REG,Copy_u8_PinId); break; 
            } 
        break;
        }
    }
    else
    {
        Local_u8_ErrorState = SATE_NOT_OK;
    }
    return Local_u8_ErrorState;
}

ES_t DIO_enu_GetPinValue(u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinValue){
    u8 Local_u8_ErrorState = SATE_OK;
    u8 Local_u8_PinValue ;
    if((Copy_u8_PortId <= DIO_U8_PORTD) && (Copy_u8_PinId <= DIO_U8_PIN7) && (Copy_pu8_ReturnPinValue != NULL))
    {
        switch (Copy_u8_PortId)
        {
            case DIO_U8_PORTA:Local_u8_PinValue = GET_BIT(DIO_U8_PINA_REG,Copy_u8_PinId);
            if(Local_u8_PinValue == DIO_U8_LOW) {*Copy_pu8_ReturnPinValue = DIO_U8_LOW;}
            else {*Copy_pu8_ReturnPinValue = DIO_U8_HIGH;}
            break;
            case DIO_U8_PORTB:Local_u8_PinValue = GET_BIT(DIO_U8_PORTB_REG,Copy_u8_PinId);
            if(Local_u8_PinValue == DIO_U8_LOW) {*Copy_pu8_ReturnPinValue = DIO_U8_LOW;}
            else {*Copy_pu8_ReturnPinValue = DIO_U8_HIGH;}
            break;
            case DIO_U8_PORTC:Local_u8_PinValue = GET_BIT(DIO_U8_PORTC_REG,Copy_u8_PinId);
            if(Local_u8_PinValue == DIO_U8_LOW) {*Copy_pu8_ReturnPinValue = DIO_U8_LOW;}
            else {*Copy_pu8_ReturnPinValue = DIO_U8_HIGH;}
            break;
            case DIO_U8_PORTD:Local_u8_PinValue = GET_BIT(DIO_U8_PORTD_REG,Copy_u8_PinId);
            if(Local_u8_PinValue == DIO_U8_LOW) {*Copy_pu8_ReturnPinValue = DIO_U8_LOW;}
            else {*Copy_pu8_ReturnPinValue = DIO_U8_HIGH;}
            break;
        }
    }
    else
    {
        Local_u8_ErrorState = SATE_NOT_OK;
    }
    return Local_u8_ErrorState;
}

ES_t DIO_enu_SetPortDirection(u8 Copy_u8_PortId, u8 Copy_u8_PortDirection){
    u8 Local_u8_ErrorState = SATE_OK;
    if((Copy_u8_PortId <= DIO_U8_PORTD) &&((Copy_u8_PortDirection == DIO_U8_OUTPUT)||(Copy_u8_PortDirection == DIO_U8_INPUT))){
        switch (Copy_u8_PortId)
        {
        case DIO_U8_PORTA:
            switch (Copy_u8_PortDirection)
            {
            case DIO_U8_OUTPUT: DIO_U8_DDRA_REG = DIO_U8_SETPORT_OUTPUT; break;
            case DIO_U8_INPUT: DIO_U8_DDRA_REG =  DIO_U8_SETPORT_INPUT; break;
            }
        break;
        case DIO_U8_PORTB:
            switch (Copy_u8_PortDirection)
                {
                case DIO_U8_OUTPUT: DIO_U8_DDRB_REG = DIO_U8_SETPORT_OUTPUT; break;
                case DIO_U8_INPUT: DIO_U8_DDRB_REG =  DIO_U8_SETPORT_INPUT; break;
                }
         break;
        case DIO_U8_PORTC:
            switch (Copy_u8_PortDirection)
                {
                case DIO_U8_OUTPUT: DIO_U8_DDRC_REG = DIO_U8_SETPORT_OUTPUT; break;
                case DIO_U8_INPUT: DIO_U8_DDRC_REG = DIO_U8_SETPORT_INPUT; break;
                }
        break;
        case DIO_U8_PORTD:
            switch (Copy_u8_PortDirection)
                {
                case DIO_U8_OUTPUT: DIO_U8_DDRD_REG = DIO_U8_SETPORT_OUTPUT; break;
                case DIO_U8_INPUT: DIO_U8_DDRD_REG = DIO_U8_SETPORT_INPUT; break;
                }
        break;
        }
    }else{
        Local_u8_ErrorState = SATE_NOT_OK;
    }
    return Local_u8_ErrorState;
}

ES_t DIO_enu_SetPortValue(u8 Copy_u8_PortId, u8 Copy_u8_PortValue){
	u8 Local_u8_ErrorState = SATE_OK;
	    if((Copy_u8_PortId <= DIO_U8_PORTD)){
	        switch (Copy_u8_PortId)
	        {
	        case DIO_U8_PORTA:DIO_U8_PORTA_REG = Copy_u8_PortValue; break;
	        case DIO_U8_PORTB:DIO_U8_PORTB_REG = Copy_u8_PortValue; break;
	        case DIO_U8_PORTC:DIO_U8_PORTC_REG = Copy_u8_PortValue; break;
	        case DIO_U8_PORTD:DIO_U8_PORTD_REG = Copy_u8_PortValue; break;
	        }
	    }else{
	        Local_u8_ErrorState = SATE_NOT_OK;
	    }
	    return Local_u8_ErrorState;
}

ES_t DIO_enu_GetPortValue(u8 Copy_u8_PortId, u8 * Copy_u8_ReturnPortValue){
    u8 Local_u8_ErrorState = SATE_OK;
    if((Copy_u8_PortId<= DIO_U8_PORTD) && (Copy_u8_ReturnPortValue != NULL)){
        switch (Copy_u8_PortId)
        {
        case DIO_U8_PORTA: *Copy_u8_ReturnPortValue = DIO_U8_PINA_REG;break;
        case DIO_U8_PORTB: *Copy_u8_ReturnPortValue = DIO_U8_PINB_REG;break;
        case DIO_U8_PORTC: *Copy_u8_ReturnPortValue = DIO_U8_PINC_REG;break;
        case DIO_U8_PORTD: *Copy_u8_ReturnPortValue = DIO_U8_PIND_REG;break;
        }
    }
    else{
        Local_u8_ErrorState = SATE_NOT_OK;
    }
    return Local_u8_ErrorState;
}
