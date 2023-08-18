/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-08-17       *************************************/
/************* SWC     :   Watch Dog Timer  *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/

#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/BIT_MATH.h"
#include"WDT_Config.h"
#include"WDT_Private.h"


ES_t WDT_enu_Enable(u8 Copy_u8_Time){
    u8 Local_enu_errorState = STATE_OK;
    if(Copy_u8_Time<8){
        /*Enable With Input Time*/
        WDT_WDTCR_REG |= Copy_u8_Time;
        SET_BIT(WDT_WDTCR_REG,WDE);
    }else{
        Local_enu_errorState = STATE_NOT_OK;
    }
    return Local_enu_errorState;

}
ES_t WDT_enu_Disable(void){
    /*Disable Sequance*/
    WDT_WDTCR_REG |= ((1<<WDTOE) | (1<<WDE));
    WDT_WDTCR_REG = 0x00;
}