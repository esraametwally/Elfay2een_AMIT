/*
 * lab_11_SwitchDebounce.c
 *
 *  Created on: Feb 19, 2021
 *      Author: Muhammad.Elzeiny
 */

#include "Std_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"
#define SWITCH_01_CHANNEL           Dio_Channel_B0

static Dio_ChannelLevelType Swich_01_State;

/*Periodic  task ~5 ms to update the State of the switch */

void Switch_StateUpdateTask(void)
{
	static Dio_ChannelLevelType CurrentState,PreviousState;
	static uint8 SampleCounter;

	CurrentState = Dio_ReadChannel(SWITCH_01_CHANNEL);

	if(CurrentState == PreviousState)
	{
		SampleCounter++;
		if(SampleCounter >= 5)
		{
			/*Update Switch State*/
			Swich_01_State = CurrentState;
			SampleCounter = 0;
		}
	}
	else
	{

		SampleCounter =0;
	}

	PreviousState = CurrentState;
}

void lab_11_SwitchDebounce(void)
{
	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250);
	while(1)
	{
		if(Swich_01_State == STD_HIGH)
		{
			Dio_WriteChannel(Dio_Channel_C2,STD_HIGH);

		}
		else
		{

			Dio_WriteChannel(Dio_Channel_C2,STD_LOW);

		}

	}


}
