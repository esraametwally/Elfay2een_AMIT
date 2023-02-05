/*
 * lab_11_Adc.c
 *
 *  Created on: Feb 19, 2021
 *      Author: Israa Mohamed
 */

#include "Dio.h"
#include "Lcd.h"
#include "Adc.h"
#include "util/delay.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"

void Adc_LcdTask(void)
{
	Std_RetType Ret;
	uint16 Result = 0;
	uint8 BuffString[5];
	Adc_StartConversion(Adc_Channel_A0);
	while( Adc_GetVoltage_mV(&Result) == E_NOT_OK);
	itoa(Result, BuffString,10);
	Lcd_WriteCommand(0x01);
	Lcd_WriteString(BuffString,0,0);
}

void lab_11_Adc(void)
{
	Dio_Init();
	Lcd_Init();
	Adc_Init();
    Gpt_Init();
    Gpt_StartTimer(250);
    ENABLE_GLOBAL_INTTERUPT();

	while(1)
	{

	}

}
