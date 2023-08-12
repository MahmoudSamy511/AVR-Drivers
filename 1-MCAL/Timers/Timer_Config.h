/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H
/********************************************/
/*Options For Timer0 Mode:
                    1- NORMAL_MODE
                    2- CTC_MODE
                    3- FAST_PWM_INVERTING
                    4- FAST_PWM_NON_INVERTING
                    5- PHASE_CORRECT_PWM_INVERTING
                    6- PHASE_CORRECT_PWM_NON_INVERTING
/*Options For Timer1 Mode:
                    1- NORMAL_MODE
                    2- CTC_MODE
                    3- FAST_PWM_INVERTING
                    4- FAST_PWM_NON_INVERTING
                    5- PHASE_CORRECT_PWM_INVERTING
                    6- PHASE_CORRECT_PWM_NON_INVERTING
*/
/*Options For Timer1 PreScaler:
                    1- F_CPU_CLK
                    2- CLK_8
                    3- CLK_64
                    4- CLK_256
                    5- CLK_1024
                    6- EXTERNAL_FALLING_EDGE
                    7- EXTERNAL_RISING_EDGE
*/
/**********************Choose Timer Mode*************/
#define TIMER0_MODE             PHASE_CORRECT_PWM_NON_INVERTING
/**********************Choose Prescaler*************/
#define TIMER0_PRESCALER        CLK_8
#define TIMER1_PRESCALER        CLK_8
/**********************Choose Prescaler*************/
#define TIMER0_PRELOAD_VALUE        128    
#define TIMER0_OCR_VALUE            0

#define F_CPU                       16000000UL


#endif
