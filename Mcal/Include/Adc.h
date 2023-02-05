/*
 * Adc.h
 *
 *  Created on: Feb 19, 2021
 *      Author: Israa Mohamed
 */

#ifndef AMITLATTE_MCAL_INCLUDE_ADC_H_
#define AMITLATTE_MCAL_INCLUDE_ADC_H_

#include "Std_Types.h"
typedef enum
{
    Adc_Channel_A0,
    Adc_Channel_A1,
    Adc_Channel_A2,
    Adc_Channel_A3,
    Adc_Channel_A4,
    Adc_Channel_A5,
    Adc_Channel_A6,
    Adc_Channel_A7,
	Adc_Channel_Testing_1_22 = 0x1E,
	Adc_Channel_Testing_0 = 0x1F
}Adc_ChannelType;
void Adc_Init(void);
void Adc_StartConversion(Adc_ChannelType ChannelId);
Std_RetType Adc_GetConversionResult(uint16 * Ptr2Result);
Std_RetType Adc_GetVoltage_mV(uint16 * Ptr2Voltage_mv);

#endif /* AMITLATTE_MCAL_INCLUDE_ADC_H_ */
