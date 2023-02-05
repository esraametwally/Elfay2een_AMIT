/*
 * lab_06_Counter.c
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include"Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"



void lab_06_timer(void)
{
	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250); /* 250 steps prescaler=64 FReqSys=16MHz ~= 1ms*/
	while(1)
	{


	}
}
