/*****************************************************************************/
/************* Name    :   Mahmoud Samy **************************************/
/************* Date    :   2023-07-27   **************************************/
/************* SWC     :   EXTI          *************************************/
/************* Version :   1.0          **************************************/
/*****************************************************************************/

#include "../../5-LIB/TYPEDEF.h"
#include "../../5-LIB/ERROR_STATE.h"
#include "../../5-LIB/BIT_MATH.h"
#include "../../5-LIB/ISR_Functions.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"

/*Global Array of Pointers To Function*/
static void (*Apf_EXTI[NUM_OF_ISR_FUNCTIONS])(void) = {NULL};

ES_t EXTI_enu_Enable(u8 Copy_u8_EXTI_Index, u8 Copy_u8_EXTI_Edge)
{
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_u8_EXTI_Index <= EXTI2 && Copy_u8_EXTI_Edge <= MAX_CHANGE_CASES)
    {
        switch (Copy_u8_EXTI_Index)
        {
        case EXTI0:
            switch (Copy_u8_EXTI_Edge)
            {
            case LOW_LEVEL:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            case ANY_LOGICAL_CHANGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            case FALLING_EDGE:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            case RISING_EDGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            }
            SET_BIT(EXTI_U8_GICR, EXTI_U8_IN0);
            break;
        case EXTI1:
            switch (Copy_u8_EXTI_Edge)
            {
            case LOW_LEVEL:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            case ANY_LOGICAL_CHANGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            case FALLING_EDGE:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            case RISING_EDGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            }
            SET_BIT(EXTI_U8_GICR, EXTI_U8_IN1);
            break;
        case EXTI2:
            switch (Copy_u8_EXTI_Edge)
            {
            case FALLING_EDGE:
                CLR_BIT(EXTI_U8_MCUCSR, EXTI_U8_ISC2);
                break;
            case RISING_EDGE:
                SET_BIT(EXTI_U8_MCUCSR, EXTI_U8_ISC2);
                break;
            default:
                Local_u8_errorState = STATE_NOT_OK;
                break;
            }
            SET_BIT(EXTI_U8_GICR, EXTI_U8_IN1);
            break;
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t EXTI_enu_Disable(u8 Copy_u8_EXTI_Index)
{
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_u8_EXTI_Index <= EXTI2)
    {
        switch (Copy_u8_EXTI_Index)
        {
        case EXTI0:
            CLR_BIT(EXTI_U8_GICR, EXTI_U8_IN0);
            break;
        case EXTI1:
            CLR_BIT(EXTI_U8_GICR, EXTI_U8_IN1);
            break;
        case EXTI2:
            CLR_BIT(EXTI_U8_GICR, EXTI_U8_IN2);
            break;
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t EXTI_enu_setSenseControl(u8 Copy_u8_EXTI_Index,u8 Copy_u8_EXTI_Edge){
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_u8_EXTI_Index <= EXTI2 && Copy_u8_EXTI_Edge <= MAX_CHANGE_CASES)
    {
        switch (Copy_u8_EXTI_Index)
        {
        case EXTI0:
            switch (Copy_u8_EXTI_Edge)
            {
            case LOW_LEVEL:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            case ANY_LOGICAL_CHANGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            case FALLING_EDGE:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            case RISING_EDGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC00);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC01);
                break;
            }
            break;
        case EXTI1:
            switch (Copy_u8_EXTI_Edge)
            {
            case LOW_LEVEL:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            case ANY_LOGICAL_CHANGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            case FALLING_EDGE:
                CLR_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            case RISING_EDGE:
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC10);
                SET_BIT(EXTI_U8_MCUCR, EXTI_U8_ISC11);
                break;
            }
            break;
        case EXTI2:
            switch (Copy_u8_EXTI_Edge)
            {
            case FALLING_EDGE:
                CLR_BIT(EXTI_U8_MCUCSR, EXTI_U8_ISC2);
                break;
            case RISING_EDGE:
                SET_BIT(EXTI_U8_MCUCSR, EXTI_U8_ISC2);
                break;
            default:
                Local_u8_errorState = STATE_NOT_OK;
                break;
            }
            break;
        }
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t EXTI_enu_setCallBack(void (*Copy_pf_ISR)(void), u8 Copy_u8_ISR_Index)
{
    u8 Local_u8_errorState = STATE_OK;
    if (Copy_pf_ISR != NULL && Copy_u8_ISR_Index <= EXTI2)
    {
        Apf_EXTI[Copy_u8_ISR_Index] = Copy_pf_ISR;
    }
    else
    {
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ISR(EXTI_INT0)
{
    if (Apf_EXTI[EXTI0] != NULL)
        Apf_EXTI[EXTI0]();
}
ISR(EXTI_INT1)
{
    if (Apf_EXTI[EXTI1] != NULL)
        Apf_EXTI[EXTI1]();
}

ISR(EXTI_INT2)
{
    if (Apf_EXTI[EXTI2] != NULL)
        Apf_EXTI[EXTI2]();
}
