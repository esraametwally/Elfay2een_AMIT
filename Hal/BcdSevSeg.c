/*
 * BcdSevSeg.c
 *
 *  Created on: Jan 22, 2021
 *      Author: Israa Mohamed
 */

#include "Dio.h"
#include "Bit_Man.h"
#include "BcdSevSeg_Cfg.h"
#include "BcdSevSeg.h"

void BcdSevSeg_Enable(BcdSevSeg_Type SevSegNum)
{
	/* set level high to enable pin of corresponding SevSegment*/
	if(SevSegNum == BcdSevSeg_0)
	{
		Dio_WriteChannel(BCDSEVSEG_0_ENABLE_PIN, STD_HIGH);
	}
	else if(SevSegNum == BcdSevSeg_1)
	{

		Dio_WriteChannel(BCDSEVSEG_1_ENABLE_PIN, STD_HIGH);
	}


}
void BcdSevSeg_Disable(BcdSevSeg_Type SevSegNum)
{
	/* set level low to disable pin of corresponding SevSegment*/
	if(SevSegNum == BcdSevSeg_0)
	{
		Dio_WriteChannel(BCDSEVSEG_0_ENABLE_PIN, STD_LOW);
	}
	else if(SevSegNum == BcdSevSeg_1)
	{

		Dio_WriteChannel(BCDSEVSEG_1_ENABLE_PIN, STD_LOW);
	}

}
void BcdSevSeg_DisplayNum(uint8 NumToDisplay)
{

	Dio_WriteChannel(BCD_SEVSEG_PIN_0,GET_BIT(NumToDisplay,0));
	Dio_WriteChannel(BCD_SEVSEG_PIN_1,GET_BIT(NumToDisplay,1));
	Dio_WriteChannel(BCD_SEVSEG_PIN_2,GET_BIT(NumToDisplay,2));
	Dio_WriteChannel(BCD_SEVSEG_PIN_3,GET_BIT(NumToDisplay,3));

}
