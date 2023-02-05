/*
 * Spi.h
 *
 *  Created on: Feb 26, 2021
 *      Author: Muhammad.Elzeiny
 */

#ifndef AMITLATTE_MCAL_INCLUDE_SPI_H_
#define AMITLATTE_MCAL_INCLUDE_SPI_H_
#include "Std_Types.h"
void Spi_Init(void);
Std_RetType Spi_StartTransmission(uint8* TxDataPtr, uint32 Size);
Std_RetType Spi_GetResievedMsg(uint8* RxDataPtr, uint32* Ptr2Size);
#endif /* AMITLATTE_MCAL_INCLUDE_SPI_H_ */
