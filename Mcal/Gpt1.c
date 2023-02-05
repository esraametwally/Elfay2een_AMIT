/*
 * Gpt1.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Israa Mohamed
 */

#define GPT1_MODE_NORMAL    0x00
#define GPT1_MODE_CTC_OCR   0x01
#define GPT1_MODE_CTC_ICR   0x02




#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "Gpt1_Cfg.h"
#include "Gpt1.h"

static T_Steps,Ton_Steps;
void Gpt1_Init(void)
{
   /*Set Timer1 Mode */
#if GPT1_MODE_SELECTOR==GPT1_MODE_NORMAL
	/*
     TCCR1A = TCCR1A &0b11111100;
     TCCR1B = TCCR1B &0b11100111;
     */

#elif GPT1_MODE_SELECTOR==GPT1_MODE_CTC_OCR
     TCCR1A = TCCR1A &0b11111100;
     SET_BIT(TCCR1B,3);
     CLR_BIT(TCCR1B,4);

#elif GPT1_MODE_SELECTOR==GPT1_MODE_CTC_ICR
     TCCR1A = TCCR1A &0b11111100;
     SET_BIT(TCCR1B,3);
     SET_BIT(TCCR1B,4);
#endif
#if GPT1_ICU_EN == ENABLE
   /*TODO: Configure Input Capture Unit e.g. Enable ICU Interrupt*/
   /**/
#endif

}

void Gpt1_StartTimer(uint16 TargetSteps)
{
    OCRA = TargetSteps;
    /*Set Prescaler*/
    TCCR1B &= 0b11111000;
	TCCR1B = TCCR1B | (GPT1_PRESCALER_SELECTOR&0b00000111);
}
void Gpt1_StopTimer(void)
{
    /*Clear prescaler to Stop timer*/
	TCCR1B = TCCR1B & 0b11111000;
}
uint16 Gpt1_GetElapsedCount(void)
{

   return TCNT1;
}
#if GPT1_ICU_EN == ENABLE
void Gpt1_MeasurePwm(uint32* Ptr2Ton_us, uint32* Ptr2T_us)
{
	/*TODO: Calculate Ton \ T based on Ton_Steps and T_Steps*/


}
#endif
void __vector_6(void) __attribute__((signal,used));
void __vector_6(void)
{
	static uint16 Flag = 0,t0,t1,t2;

	if(Flag == 0)
	{
        t0 = ICR1;
		Flag =1;
	}
	else if(Flag == 1)
	{

        t1 = ICR1;
		Flag =2;

	}
	else if (Flag == 2)
	{

        t2 = ICR1;
        T_Steps = t2-t0;
        Ton_Steps = t1-t0;
		Flag = 0;
	}

}
