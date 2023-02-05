/*
 * lab_04_Exti.c
 *
 *  Created on: Jan 23, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include "Dio.h"
#include "Cpu_GlobalInt.h"
#include "Exti.h"


void User_ExtiCallBack(void)
{
	Dio_FlipChannel(Dio_Channel_C7);

}
void lab_04_Exti(void)
{
	Dio_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Exti_Init();


	while(1)
	{

	}

}
