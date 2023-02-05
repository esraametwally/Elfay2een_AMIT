/*
 * lab_03_Keypad.c
 *
 *  Created on: Jan 22, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include "Dio.h"
#include "BcdSevSeg.h"
#include "Keypad.h"
#include "util/delay.h"

void lab_03_keypad(void)
{
	uint8 NumFromKp =0 ;
	Dio_Init();
	Keypad_Init();

	while(1)
	{
		NumFromKp = Keypad_GetPressedButton();
		/*read the pressed button from the keypad*/
		/*display the number on SevSegments*/
		if(NumFromKp != 255)
		{
			BcdSevSeg_Enable(BcdSevSeg_1);
			BcdSevSeg_Disable(BcdSevSeg_0);
			BcdSevSeg_DisplayNum(NumFromKp%10);
			_delay_ms(10);

			/*display the number on SevSegments*/
			BcdSevSeg_Disable(BcdSevSeg_1);
			BcdSevSeg_Enable(BcdSevSeg_0);
			BcdSevSeg_DisplayNum(NumFromKp/10);
			_delay_ms(10);
		}
		else
		{
			BcdSevSeg_Disable(BcdSevSeg_1);
			BcdSevSeg_Disable(BcdSevSeg_0);

		}
	}
}


