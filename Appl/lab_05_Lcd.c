/*
 * lab_05_Lcd.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Israa Mohamed
 */

#include "Dio.h"
#include "Lcd.h"
#include "util/delay.h"

void lab_05_lcd(void)
{
	uint8 CustomCharArr[8]={0x01,0x01,0x1b,0x15,0x11,0xa,0x4,0x00};
	uint8 CustomCharArr_2[8]={0x11,0x1B,0x1F,0x15,0x1F,0xa,0x04,0x00};

	uint8 i=0,x;
	Dio_Init();
	Lcd_Init();
    Lcd_StoreCustomChar(CustomCharArr,0);
    Lcd_StoreCustomChar(CustomCharArr_2,1);
	while (1)
	{
        Lcd_WriteCommand(0x01);
	    Lcd_DisplayCustomChar(0,1,0);
	    Lcd_DisplayCustomChar(1,0,0);
	    _delay_ms(500);


	}

}
