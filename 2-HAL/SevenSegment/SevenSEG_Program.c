/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-07-08       *************************************/
/************* SWC     :   Senven Segment   *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/

#include"../../1-MCAL/DIO/DIO_interface.h"


#include"SevenSEG_Interface.h"
#include"SevenSEG_Private.h"


u8 SevenSeg_au8_Numbers[SEVEVN_SEGMENTS_MAX_NUM] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,
                                                    0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
                                                    
ES_t sevenSeg_enu_init(SevenSeg_t * Copy_SevenSeg_t_Seg){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_SevenSeg_t_Seg != NULL){
        DIO_enu_SetPinDirection(Copy_SevenSeg_t_Seg->Enable_Port, Copy_SevenSeg_t_Seg->Enable_Pin, DIO_U8_OUTPUT);
        DIO_enu_SetPinValue(Copy_SevenSeg_t_Seg->Enable_Port, Copy_SevenSeg_t_Seg->Enable_Pin,(Copy_SevenSeg_t_Seg->Type + 1)/2);
        DIO_enu_SetPortDirection(Copy_SevenSeg_t_Seg->Port,DIO_U8_OUTPUT);
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;

    return STATE_OK;

}

ES_t sevenSeg_enu_displayNum(SevenSeg_t * Copy_SevenSeg_t_Seg,u8 Copy_u8_Num)
{
    u8 Local_u8_errorState = STATE_OK;
    if((Copy_u8_Num< SEVEVN_SEGMENTS_MAX_NUM) && (Copy_SevenSeg_t_Seg != NULL)){
        u8 Local_u8_counter = 0;
        if (Copy_SevenSeg_t_Seg->Type == COMMON_ANODE){
            for (u8 Local_u8_iterator = Copy_SevenSeg_t_Seg->Start_Pin; Local_u8_iterator <= Copy_SevenSeg_t_Seg->End_Pin; Local_u8_iterator++)
            {
                DIO_enu_SetPinValue(Copy_SevenSeg_t_Seg->Port,Local_u8_iterator,(~SevenSeg_au8_Numbers[Copy_u8_Num]>>(Local_u8_counter++)) & MASK_BIT);
            }
        }else{
            for (u8 Local_u8_iterator = Copy_SevenSeg_t_Seg->Start_Pin; Local_u8_iterator <= Copy_SevenSeg_t_Seg->End_Pin; Local_u8_iterator++)
            {
                DIO_enu_SetPinValue(Copy_SevenSeg_t_Seg->Port,Local_u8_iterator,(SevenSeg_au8_Numbers[Copy_u8_Num]>>(Local_u8_counter++)) & MASK_BIT);
            }
        }
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
