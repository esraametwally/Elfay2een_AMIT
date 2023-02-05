/*
 * lab_07_Scheduling.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Esraa Mohammed
 */
#include"Std_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"
#include "Scheduler.h"
#include "BcdSevSeg_Cfg.h"
#include "BcdSevSeg.h"

uint8 Flag =0;
void Task_01(void)
{
	if(Flag==0)
	{
		/*display the number on SevSegments*/
		BcdSevSeg_Enable(BcdSevSeg_1);
		BcdSevSeg_Disable(BcdSevSeg_0);
		BcdSevSeg_DisplayNum(3);
		Flag=1;
	}
	else if (Flag==1)
	{

		/*display the number on SevSegments*/
		BcdSevSeg_Disable(BcdSevSeg_1);
		BcdSevSeg_Enable(BcdSevSeg_0);
		BcdSevSeg_DisplayNum(4);
		Flag=0;
	}
}
void Task_02(void)
{

}

void Task_03(void)
{

}

void lab_07_User(void)
{
	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250); /* 250 steps prescaler=64 FReqSys=16MHz ~= 1ms*/

	while(1)
	{


	}

}

