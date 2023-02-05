/*
 * lab_0_Temp.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Israa Mohamed
 */

#include "Dio.h"
#include "Lcd.h"
#include "Lcd_Cfg.h"
#include "Adc.h"
#include "util/delay.h"
#include <stdlib.h>

void lab_0_Temp(void)
{
	Dio_Init();
	Lcd_Init();
	Adc_Init();

	uint16 Result = 0;
	uint8 BuffString[5];
	uint8 Temp=0;


	while(1)
	{

		Adc_StartConversion(Adc_Channel_A0);
		while( Adc_GetVoltage_mV(&Result) == E_NOT_OK);
		/*to get the integer number*/
		Temp = (Result/10);
		/*convert from integer to ASCII to present on LCD*/
		itoa(Temp, BuffString,10);
		/*Go home*/
		Lcd_WriteCommand(RETURN_HOME);
		/*Send the result to LCD*/
		Lcd_WriteString(BuffString,0,0);

	}

}
