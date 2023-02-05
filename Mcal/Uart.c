/*
 * Uart.c
 *
 *  Created on: Feb 20, 2021
 *      Author: Israa Mohamed
 */
#include "Std_Types.h"
#include "Bit_Man.h"
#include "Mcu_Hw.h"
#include "Uart_Cfg.h"
#include "Uart.h"

#define UART_STOP_BITS_SIZE_1                   0x0
#define UART_STOP_BITS_SIZE_2                   0x1
#define UART_PARITY_MODE_DISABLE               0x00
#define UART_PARITY_MODE_EVEN                  0x02
#define UART_PARITY_MODE_ODD                   0x03
#define UART_DATA_SIZE_5                        0x0
#define UART_DATA_SIZE_6                        0x1
#define UART_DATA_SIZE_7                        0x2
#define UART_DATA_SIZE_8                        0x3

static uint8 Uart_Rx_Buffer[UART_MAX_RX_BUFFER_SIZE];
static uint32 UartRxBuffer_Index = 0;
void Uart_Init(void)
{
	/*to access UCSRC register*/
	UCSRC.B.URSEL = 0x1;
	/*TODO : Configure Stop bits 1-2 */
	UCSRC.B.USBS = UART_STOP_BITS_SIZE_SELECTOR;
	/*TODO: Configure Parity Mode */
	UCSRC.B.UPM = UART_PARITY_MODE_SELECTOR;
	/*TODO : Configure Data bits number */
	UCSRC.B.UCSZ = UART_DATA_SIZE_SELECTOR;

	/*Configure Baude rate */
	UBRRL = BAUDE_RATE_UBRR;
	/*Enable configured Interrupts */
	UCSRB.B.RXCIE = UART_RX_COMPLETE_INT_EN;
	UCSRB.B.TXCIE = UART_TX_COMPLETE_INT_EN;
	UCSRB.B.UDRIE = UART_TXBUFFER_READY_INT_EN;

	/*Enable Tx and Rx pin based on Cfg */
	UCSRB.B.RXEN = UART_RX_EN;
	UCSRB.B.TXEN = UART_TX_EN;

}
Std_RetType Uart_StartTansmit(uint8* TxDataPtr, uint32 Size)
{
	uint32 i;
	Std_RetType RetVal = E_OK;
	if( (TxDataPtr != NULL) && (Size!=0))
	{
		for (i = 0; i < Size; ++i)
		{
			/*Polling On Transmission complete*/
			while(UCSRA.B.UDRE == 0);
			UDR = TxDataPtr[i];

		}
	}
	else
	{
		RetVal = E_NOT_OK;
	}

	return RetVal;
}
Std_RetType Uart_GetReceivedData(uint8* RxdataPtr, uint32* Ptr2Size)
{
	uint32 i;
	Std_RetType RetVal = E_OK;
	if(UartRxBuffer_Index != 0)
	{
		for (i = 0; i < UartRxBuffer_Index; ++i)
		{
			RxdataPtr[i] = Uart_Rx_Buffer[i];
		}
		*Ptr2Size = UartRxBuffer_Index;
		UartRxBuffer_Index =0;
	}
	else
	{
		/*Rx Buffer is empty no received data */
		RetVal = E_NOT_OK;
	}
	return RetVal;
}

/*Rx complete ISR*/
void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{
	if(UartRxBuffer_Index < UART_MAX_RX_BUFFER_SIZE)
	{
		/* read UDR and Store Receive Data in Uart_RxBuffer*/
		Uart_Rx_Buffer[UartRxBuffer_Index] = UDR;
		UartRxBuffer_Index++;
	}

}





