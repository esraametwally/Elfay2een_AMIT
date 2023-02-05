/*
 * Uart.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Muhammad.Elzeiny
 */

#ifndef AMITLATTE_COMMON_UART_H_
#define AMITLATTE_COMMON_UART_H_
#include "Std_Types.h"
void Uart_Init(void);
Std_RetType Uart_StartTansmit(uint8* TxDataPtr, uint32 Size);
Std_RetType Uart_GetReceivedData(uint8* RxdataPtr, uint32* Ptr2Size);

#endif /* AMITLATTE_COMMON_UART_H_ */
