/*
 * Gpt2.c
 *
 *  Created on: Jan 30, 2021
 *      Author: Israa Mohamed
 */
#define  GPT2_WAVEFORM_GEN_NORMAL         0x00
#define  GPT2_WAVEFORM_GEN_CTC            0x02
#define  GPT2_WAVEFORM_GEN_FAST_PWM       0x03
#define  GPT2_WAVEFORM_GEN_PHASE_CORRECT  0x01


#define  GPT2_TIMER_MODE_ONESHOT          0x00
#define  GPT2_TIMER_MODE_CONTINOUSE       0x01

#include "Std_Types.h"
#include "Bit_Man.h"
#include "Mcu_Hw.h"
#include "Gpt2_Cfg.h"
#include "Gpt2.h"

Ptr2FuncType CallBackFunc = GPT2_CALLBACK_PTR;



void Gpt2_Init(void)
{

#if (GPT2_WAVEFORM_GEN_MODE==GPT2_WAVEFORM_GEN_CTC) /*CTC MODE*/
	/*TODO: Set Timer_mode to CTC */
	SET_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);

	/*TODO: Enable Timer Interrupt based on configuration */

# if GPT2_OUTPUT_COMPARE_OC0==ENABLE
	SET_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);
# endif
# if GPT2_INTERRUPT_CTC_EN == ENABLE
	SET_BIT(TIMSK,7);
# endif /* GPT2_INTERRUPT_EN == ENABLE */

# if GPT2_INTERRUPT_OVF_EN == ENABLE
	SET_BIT(TIMSK,6);
# endif /* GPT2_INTERRUPT_EN == ENABLE */


#elif (GPT2_WAVEFORM_GEN_MODE==GPT2_WAVEFORM_GEN_NORMAL) /*NORMAL MODE*/

	/*TODO: Set Timer_mode to CTC */
	CLR_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);

	/*TODO: Enable Timer Interrupt based on configuration */

# if GPT2_OUTPUT_COMPARE_OC0==ENABLE
	SET_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);
# endif
# if GPT2_INTERRUPT_CTC_EN == ENABLE
	SET_BIT(TIMSK,7);
# endif /* GPT2_INTERRUPT_EN == ENABLE */

# if GPT2_INTERRUPT_OVF_EN == ENABLE
	SET_BIT(TIMSK,6);
# endif /* GPT2_INTERRUPT_EN == ENABLE */


#elif (GPT2_WAVEFORM_GEN_MODE==GPT2_WAVEFORM_GEN_FAST_PWM)
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

	/*Generate non-inverting PWM*/
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#elif (GPT2_WAVEFORM_GEN_MODE==GPT2_WAVEFORM_GEN_PHASE_CORRECT)
	CLR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

	/*Generate non-inverting PWM*/
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);

#endif /*(GPT2_WAVEFORM_GEN_MODE*/



}
void Gpt2_StartTimer(uint8 TargetSteps)
{
	/*TODO: Write the TargetSteps into OCR2 register */
	OCR2 = TargetSteps;
	/*TODO: Set Prescaler */
	TCCR2 = TCCR2 | (GPT2_PRESCALER_SELECTOR&0b00000111);
}

void Gpt2_StopTimer(void)
{
	/*TODO : Clear Prescaler field i.e. Disable Timer clock */
	TCCR2 = (TCCR2&0b11111000);
}
uint8 Gpt2_GetElapsedCount(void)
{
	/*return TCNT2 value */
	return TCNT2;

}

void Gpt2_GeneratePwm(uint8 DutyCycle)
{

	Gpt2_StartTimer(((DutyCycle)*256)/100);

}
/*TIMER2_COMP interrupt*/
void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	/*Check on Timer mode: if mode== one-shot then disable Timer2 */
#if (GPT2_TIMER_MODE_SELECTOR == GPT2_TIMER_MODE_ONESHOT)
	Gpt2_StopTimer();
#endif
	/*call the callback function*/
	if (CallBackFunc != NULL)
	{
		CallBackFunc();
	}
}

