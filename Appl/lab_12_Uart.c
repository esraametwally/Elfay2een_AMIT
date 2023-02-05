/*
 * lab_12_Uart.c
 *
 *  Created on: Feb 20, 2021
 *      Author: Muhammad.Elzeiny
 */

#include "Std_Types.h"
#include "Cpu_GlobalInt.h"
#include "Gpt.h"
#include "Lcd.h"
#include "Uart.h"
#include "Dio.h"
/*Tx Periodic Task ~500ms*/
void UartTx_Task(void)
{
	static Std_RetType RetVal = E_OK;
	uint8 DataToTransmit[]= "Ahmed ";
	if(RetVal == E_OK)
	{
		RetVal = Uart_StartTansmit(DataToTransmit, sizeof(DataToTransmit) );
	}
}

/*Tx Periodic Task ~60ms*/
void UartRx_Task(void)
{
	static Std_RetType RetVal = E_OK;
	uint8 ReceivedData[16]= {0};
	uint32 Size = 0;
	if(RetVal == E_OK)
	{
		RetVal =Uart_GetReceivedData(ReceivedData,&Size);
		Lcd_WriteCommand(0x01);
		Lcd_WriteString(ReceivedData,0,0);
	}

}

void lab_12_uart(void)
{
	Dio_Init();
	Lcd_Init();
	Gpt_Init();
	Gpt_StartTimer(250);
	Uart_Init();
	ENABLE_GLOBAL_INTTERUPT();

	while(1)
	{

	}
}

