/*
 * Gpt2.h
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */

#ifndef AMITLATTE_MCAL_INCLUDE_GPT2_H_
#define AMITLATTE_MCAL_INCLUDE_GPT2_H_
#include "Std_Types.h"

void Gpt2_Init(void);
void Gpt2_StartTimer(uint8 TargetSteps);
void Gpt2_StopTimer(void);
uint8 Gpt2_GetElapsedCount(void);
void Gpt2_GeneratePwm(uint8 DutyCycle);


#endif /* AMITLATTE_MCAL_INCLUDE_GPT2_H_ */
