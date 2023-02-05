/*
 * Scheduler.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Israa Mohamed
 */
#include "Std_Types.h"
#include "Scheduler.h"

extern Scheduler_TaskType Tasks[];
extern const uint8 Scheduler_NumOfTasks;
/******************STATIC_CODE***************/

void Scheduler_SetTaskStatus(uint8 TaskId,TaskStatusType LocTaskStatus)
{
     Tasks[TaskId].TaskStatus = LocTaskStatus;
}
void Scheduler_SetTaskPeriodicity(uint8 TaskId,uint32 LocPeriodicity)
{
     Tasks[TaskId].Periodicity = LocPeriodicity;
}
/*Periodic Task 1ms*/
void Scheduler_Process(void)
{
	uint8 i;
	static uint32 counter = 0;
	for (i = 0; i < Scheduler_NumOfTasks; ++i)
	{
		if( ((counter%Tasks[i].Periodicity) == 0) && (counter!=0) )
		{
			if(Tasks[i].TaskStatus == TaskStatus_Active)
			{
				Tasks[i].TaskPtr();
			}
		}
	}

	counter++;
}
