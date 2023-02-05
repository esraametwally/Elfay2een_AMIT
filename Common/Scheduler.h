/*
 * Scheduler.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Israa Mohamed
 */

#ifndef AMITLATTE_COMMON_SCHEDULER_H_
#define AMITLATTE_COMMON_SCHEDULER_H_
#include "Std_Types.h"
typedef enum
{
	TaskStatus_Suspend,
	TaskStatus_Active
}TaskStatusType;
typedef struct
{
	uint8 TaskId;
	Ptr2FuncType TaskPtr;
	uint32 Periodicity;
	TaskStatusType TaskStatus;
}Scheduler_TaskType;

void Scheduler_SetTaskStatus(uint8 TaskId,TaskStatusType LocTaskStatus);
void Scheduler_SetTaskPeriodicity(uint8 TaskId,uint32 LocPeriodicity);

#endif /* AMITLATTE_COMMON_SCHEDULER_H_ */
