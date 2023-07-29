/*****************************************************************************/
/************* Name    :   Mahmoud Samy **************************************/
/************* Date    :   2023-07-27   **************************************/
/************* SWC     :   GI            *************************************/
/************* Version :   1.0          **************************************/
/*****************************************************************************/

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/BIT_MATH.h"

#include"GI_Private.h"

ES_t GI_enu_Enable(void){
    SET_BIT(EXTI_U8_SREG,EXTI_U8_IBIT);
    return STATE_OK;
}
ES_t GI_enu_Disable(void){
    CLR_BIT(EXTI_U8_SREG,EXTI_U8_IBIT);
    return STATE_OK;
}
