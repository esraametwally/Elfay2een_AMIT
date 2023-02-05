/*
 * Gpt.h
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */

#ifndef AMITLATTE_MCAL_INCLUDE_GPT_H_
#define AMITLATTE_MCAL_INCLUDE_GPT_H_
#include "Std_Types.h"

void Gpt_Init(void);
void Gpt_StartTimer(uint8 TargetSteps);
void Gpt_StopTimer(void);
uint8 Gpt_GetElapsedCount(void);
void Gpt_GeneratePwm(uint8 DutyCycle);


#endif /* AMITLATTE_MCAL_INCLUDE_GPT_H_ */
