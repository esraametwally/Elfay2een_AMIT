/*
 * lab_0_Temp.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Israa Mohamed
 */

#include "Dio.h"
#include "Lcd.h"
#include "Adc.h"
#include "util/delay.h"
#include "Lcd_Cfg.h"
#include <stdlib.h>

void lab_0_Temp2_F(void)
{
	Dio_Init();
	Lcd_Init();
	Adc_Init();

	uint16 Result = 0;
	uint8 BuffString[5];
	uint8 BuffString_2[5];
	uint8 Temp=0;
	uint8 Temp_Prev=0;



	while(1)
	{

		Adc_StartConversion(Adc_Channel_A0);
		while( Adc_GetVoltage_mV(&Result) == E_NOT_OK);

		Temp = Result/10;
		Temp_Prev=(Result%10);

		itoa(Temp,BuffString,10);

		Lcd_WriteCommand(RETURN_HOME);
		Lcd_WriteString(BuffString,0,0);
		Lcd_WriteChar('.');
		itoa(Temp_Prev, BuffString_2,10);
		Lcd_WriteString(BuffString_2,0,3);

	}

}
