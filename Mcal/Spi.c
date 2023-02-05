/*
 * Spi.c
 *
 *  Created on: Feb 26, 2021
 *      Author: Israa Mohamed
 */
#include "Std_Types.h"
#include "Bit_Man.h"
#include "Mcu_Hw.h"
#include "Spi_Cfg.h"
#include "Spi.h"

#define SPI_DATA_ORDER_LSB                                  0x01
#define SPI_DATA_ORDER_MSB                                  0x00

#define SPI_MODE_SLAVE                                      0x00
#define SPI_MODE_MASTER                                     0x01

#define SPI_LEADING_EDGE_RISING                             0x00
#define SPI_LEADING_EDGE_FALLING                            0x01

#define SPI_SAMPLE_ON_LEADING                               0x00
#define SPI_SETUP_ON_LEADING                                0x01

#define SPI_PRESCALER_4                                     0x00
#define SPI_PRESCALER_16                                    0x01
#define SPI_PRESCALER_64                                    0x02
#define SPI_PRESCALER_128                                   0x03

static uint8 Spi_Rx_Buffer [SPI_MAX_RX_BUFFER_SIZE];
static uint32 SpiRxBuffer_Index = 0;

void Spi_Init(void)
{
	/*TODO : Configure Data order Lsb\Msb */
	SPCR.B.DORD = SPI_DATA_ORDER_SELECTOR;

	/*TODO: Configure Mode Master\Slave */
	SPCR.B.MSTR = SPI_MODE_SELECTOR;

	/*TODO: Configure Clock phase and Clock polarity*/
	SPCR.B.CPOL = SPI_CLOCK_POLARITY_SELECTOR;
	SPCR.B.CPHA = SPI_CLOCK_PHASE_SELECTOR;

	/*TODO: Configure Pre-scaler */
	SPCR.B.SPR = SPI_PRESCALER_SELECTOR;

	/*TODO: Enable Interrupt if configured */
	SPCR.B.SPIE = SPI_INTERRUPT_EN;

	/*TODO: Enable SPI */
	SPCR.B.SPE = STD_HIGH;
}
Std_RetType Spi_StartTransmission(uint8* TxDataPtr, uint32 Size)
{
	Std_RetType RetVal = E_OK;
	uint32 i;
	if((TxDataPtr != NULL) && (Size > 0))
	{
		for (i = 0; i < Size; ++i)
		{
			/*TODO Transmit Data */
			SPDR = TxDataPtr[i];
			/*TODO: Polling until Msg has been transmitted */
			while (SPSR.B.SPIF == 0);

			if(SpiRxBuffer_Index < SPI_MAX_RX_BUFFER_SIZE)
	        {
	        	Spi_Rx_Buffer [SpiRxBuffer_Index] = SPDR;
	        	SpiRxBuffer_Index++;
	        }

		}
	}
	else
	{
		RetVal = E_NOT_OK;
	}

	return RetVal;
}
Std_RetType Spi_GetResievedMsg(uint8* RxDataPtr, uint32* Ptr2Size)
{
	uint32 i;
	Std_RetType RetVal = E_OK;
	if(SpiRxBuffer_Index != 0)
	{
		for (i = 0; i < SpiRxBuffer_Index; ++i)
		{
			RxDataPtr[i] = Spi_Rx_Buffer[i];

		}
		*Ptr2Size = SpiRxBuffer_Index;
		SpiRxBuffer_Index = 0;
	}
	else
	{
		RetVal = E_NOT_OK;
	}
	return RetVal;
}
/*Serial Transfer Complete Interrupt */
void __vector_12(void) __attribute__((signal,used));
void __vector_12(void)
{

}
