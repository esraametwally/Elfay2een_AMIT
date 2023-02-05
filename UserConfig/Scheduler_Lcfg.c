/*
 * Scheduler_Lcfg.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Israa Mohamed
 */
#include "Scheduler.h"

/*
 *
 * Please declare the functions here
*/
extern void UartTx_Task(void);

/***************CONFIGURATION***************/
#define SCHEDULER_NUM_OF_TASKS      1

Scheduler_TaskType Tasks[SCHEDULER_NUM_OF_TASKS] =
{
		{0,UartTx_Task,500,TaskStatus_Active }
};
/**************************/
const uint8 Scheduler_NumOfTasks = SCHEDULER_NUM_OF_TASKS;

