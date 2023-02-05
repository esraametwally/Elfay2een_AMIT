/*
 * lab_13_Spi.c
 *
 *  Created on: Feb 26, 2021
 *      Author: Muhammad.Elzeiny
 */
#include "Std_Types.h"
#include "util/delay.h"
#include <stdlib.h>
#include "Dio.h"
#include "Spi.h"
#include "Cpu_GlobalInt.h"
#include "Lcd.h"
#include "Exti.h"

void lab_13_Spi(void)
{
	uint8 ReceivedData[16]= {0};
	uint32 Size = 0;
	uint8 RxMsg[]="Mohamed";
	static Std_RetType RetVal = E_OK;
	Spi_Init();
	Dio_Init();
	Lcd_Init();
	ENABLE_GLOBAL_INTTERUPT();

	while(1)
	{
		RetVal = Spi_StartTransmission(RxMsg, sizeof(RxMsg) );
		RetVal =Uart_GetReceivedData(ReceivedData,&Size);

		/*Todo : Display Received Message on Lcd*/
		Lcd_WriteString(RxMsg,0,0);
		_delay_ms(1000);
		Lcd_WriteCommand(0x01);
	}
}

