/*
 * lab_10_Icu.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Muhammad.Elzeiny
 */
#include <stdlib.h>
#include "util/delay.h"
#include"Std_Types.h"
#include "Dio.h"
#include "Gpt2.h"
#include "Cpu_GlobalInt.h"
#include "Gpt1.h"
#include "Lcd.h"

static uint32 T_us,Ton_us;

void lab_10_Icu(void)
{
	uint8 StringBuffer[8];
	Dio_Init();
	Lcd_Init();
    Gpt1_Init();
    Gpt2_Init();
    Gpt2_GeneratePwm(30);
    Gpt1_StartTimer(65535);
    ENABLE_GLOBAL_INTTERUPT();

	while(1)
	{
		Gpt1_MeasurePwm(&Ton_us,&T_us);
        /*TODO : Clear LCD to Write new Reading */
        Lcd_WriteCommand(0x01);
		itoa(Ton_us,StringBuffer,10); /* Convert integer 'Ton_us' to String 'StringBuffer' */
        Lcd_WriteString("Ton = ",0,0);
        Lcd_WriteString(StringBuffer,0,8);


        itoa(T_us,StringBuffer,10);
        Lcd_WriteString("T = ",1,0);
        Lcd_WriteString(StringBuffer,1,8);
        _delay_ms(500);
	}



}

