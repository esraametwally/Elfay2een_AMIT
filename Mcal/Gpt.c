/*
 * Gpt.c
 *
 *  Created on: Jan 30, 2021
 *      Author: Israa Mohamed
 */
#define  GPT_WAVEFORM_GEN_NORMAL         0x00
#define  GPT_WAVEFORM_GEN_CTC            0x02
#define  GPT_WAVEFORM_GEN_FAST_PWM       0x03
#define  GPT_WAVEFORM_GEN_PHASE_CORRECT  0x01


#define  GPT_TIMER_MODE_ONESHOT          0x00
#define  GPT_TIMER_MODE_CONTINOUSE       0x01

#include "Std_Types.h"
#include "Bit_Man.h"
#include "Mcu_Hw.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"


void Gpt_Init(void)
{

#if (GPT_WAVEFORM_GEN_MODE==GPT_WAVEFORM_GEN_CTC) /*CTC MODE*/
	/*TODO: Set Timer_mode to CTC */
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	/*TODO: Enable Timer Interrupt based on configuration */

# if GPT_OUTPUT_COMPARE_OC0==ENABLE
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
# endif
# if GPT_INTERRUPT_CTC_EN == ENABLE
	SET_BIT(TIMSK,1);
# endif /* GPT_INTERRUPT_EN == ENABLE */

# if GPT_INTERRUPT_OVF_EN == ENABLE
	SET_BIT(TIMSK,0);
# endif /* GPT_INTERRUPT_EN == ENABLE */


#elif (GPT_WAVEFORM_GEN_MODE==GPT_WAVEFORM_GEN_NORMAL) /*NORMAL MODE*/

	/*TODO: Set Timer_mode to CTC */
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	/*TODO: Enable Timer Interrupt based on configuration */

# if GPT_OUTPUT_COMPARE_OC0==ENABLE
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
# endif
# if GPT_INTERRUPT_CTC_EN == ENABLE
	SET_BIT(TIMSK,1);
# endif /* GPT_INTERRUPT_EN == ENABLE */

# if GPT_INTERRUPT_OVF_EN == ENABLE
	SET_BIT(TIMSK,0);
# endif /* GPT_INTERRUPT_EN == ENABLE */


#elif (GPT_WAVEFORM_GEN_MODE==GPT_WAVEFORM_GEN_FAST_PWM)
    SET_BIT(TCCR0,3);
    SET_BIT(TCCR0,6);

    /*Generate non-inverting PWM*/
    CLR_BIT(TCCR0,4);
    SET_BIT(TCCR0,5);

#elif (GPT_WAVEFORM_GEN_MODE==GPT_WAVEFORM_GEN_PHASE_CORRECT)
    CLR_BIT(TCCR0,3);
    SET_BIT(TCCR0,6);

    /*Generate non-inverting PWM*/
    CLR_BIT(TCCR0,4);
    SET_BIT(TCCR0,5);

#endif /*(GPT_WAVEFORM_GEN_MODE*/



}
void Gpt_StartTimer(uint8 TargetSteps)
{
	/*TODO: Write the TargetSteps into OCR0 register */
    OCR0 = TargetSteps;
	/*TODO: Set Prescaler */
	TCCR0 = TCCR0 | (GPT_PRESCALER_SELECTOR&0b00000111);
}

void Gpt_StopTimer(void)
{
	/*TODO : Clear Prescaler field i.e. Disable Timer clock */
	TCCR0 = (TCCR0&0b11111000);
}
uint8 Gpt_GetElapsedCount(void)
{
	/*return TCNT0 value */
    return TCNT0;

}

void Gpt_GeneratePwm(uint8 DutyCycle)
{

	Gpt_StartTimer(((DutyCycle)*256)/100);

}
/*TIMER0_COMP interrupt*/
void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	/*Check on Timer mode: if mode== one-shot then disable Timer0 */
#if (GPT_TIMER_MODE_SELECTOR == GPT_TIMER_MODE_ONESHOT)
	Gpt_StopTimer();
#endif
	/*call the callback function*/

	GPT_CALLBACK_PTR();
}

