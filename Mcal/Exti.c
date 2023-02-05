/*
 * Exti.c
 *
 *  Created on: Jan 23, 2021
 *      Author: Israa Mohamed
 */

#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "Std_Types.h"
#include "Exti_Cfg.h"
#include "Exti.h"

void EXTI_0_CALLBACK_PTR(void);
void EXTI_1_CALLBACK_PTR(void);
void EXTI_2_CALLBACK_PTR(void);



void Exti_Init(void)
{

	/*init Exti according to CFG */
	/* Init EXTI 0 */
#if (EXTI_0_ENABLE==ENABLE)
	/*Configure sense mode */
	MCUCR = MCUCR & (0b11111100); /*Clear before Write */
	MCUCR = MCUCR | EXTI_0_SENSE_MODE_SELECTOR;

	/*enable Exti 0*/
	SET_BIT(GICR, 6);

#endif

#if (EXTI_1_ENABLE==ENABLE)
	/*Configure sense mode */
	MCUCR = MCUCR & (0b11110011); /*Clear before Write */
	MCUCR = MCUCR | (EXTI_1_SENSE_MODE_SELECTOR<<2);

	/*enable Exti 1*/
	SET_BIT(GICR, 7);
#endif

#if (EXTI_2_ENABLE==ENABLE)
	/*Configure sense mode */
	MCUCSR = MCUCSR & (0b10111111); /*Clear before Write */
	MCUCSR = MCUCSR | (EXTI_2_SENSE_MODE_SELECTOR<<6);

	/*enable Exti 2*/
	SET_BIT(GICR, 5);
#endif
}

/* ISR for EXTI 0*/
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{

	if(EXTI_0_CALLBACK_PTR != (void*)0)
	{
		EXTI_0_CALLBACK_PTR();
	}

}
/* ISR for EXTI 1*/
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{

	if(EXTI_1_CALLBACK_PTR != (void*)0)
		{
			EXTI_1_CALLBACK_PTR();
		}

}
/* ISR for EXTI 2*/
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{

	if(EXTI_2_CALLBACK_PTR != (void*)0)
		{
			EXTI_2_CALLBACK_PTR();
		}
}




