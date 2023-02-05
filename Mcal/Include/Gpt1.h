/*
 * Gpt_1.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Muhammad.Elzeiny
 */

#ifndef AMITLATTE_MCAL_INCLUDE_GPT1_H_
#define AMITLATTE_MCAL_INCLUDE_GPT1_H_

void Gpt1_Init(void);
void Gpt1_StartTimer(uint16 TargetSteps);
void Gpt1_StopTimer(void);
uint16 Gpt1_GetElapsedCount(void);
void Gpt1_MeasurePwm(uint32* Ptr2Ton_us, uint32* Ptr2T_us);


#endif /* AMITLATTE_MCAL_INCLUDE_GPT1_H_ */
