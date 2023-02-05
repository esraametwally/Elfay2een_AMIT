/*
 * lab_08_Pwm.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Muhammad.Elzeiny
 */

#include "util/delay.h"
#include"Std_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"
#include "Scheduler.h"

void Task_Pwm(void)/*~ 5 ms*/
{

	static uint8 CounterFlag = 0;
	if(CounterFlag == 0)
	{
		Dio_WriteChannel(Dio_Channel_D0,STD_HIGH);
		CounterFlag++;
	}
	else if(CounterFlag == 1)
	{
		Dio_WriteChannel(Dio_Channel_D0,STD_LOW);
		CounterFlag++;
	}
	else if(CounterFlag == 3)
	{
		CounterFlag =0;
	}
	else
	{
		CounterFlag++;
	}


}

void lab_08_Pwm(void)
{
	static uint8 MotorSpeed = 0;

	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250);
	while(1)
	{
		Gpt_GeneratePwm(MotorSpeed++);
		if(MotorSpeed == 100)
		{
			MotorSpeed = 0;
		}
		_delay_ms(100);



	}

}

void lab_08_MotorDir(void)
{
	 Dio_Init();


    while(1)
    {

     	Dio_WriteChannel(Dio_Channel_D1,STD_HIGH);
     	Dio_WriteChannel(Dio_Channel_D0,STD_LOW);


    }



}
