/*
 * Dio.c
 *
 *  Created on: Jan 15, 2021
 *      Author: Israa Mohamed
 */
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "Dio.h"

#define NUM_OF_CHANNELS_IN_PORT      8

extern const Dio_CfgUnionType DioCfgUnion ;
void Dio_Init(void)
{
	/*set direction*/
   DDRA = DioCfgUnion.CfgDirArr[0];
   DDRB = DioCfgUnion.CfgDirArr[1];
   DDRC = DioCfgUnion.CfgDirArr[2];
   DDRD = DioCfgUnion.CfgDirArr[3];

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_ChannelLevelType ChannelLevel)
{
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;
	uint8 BitOffset = ChannelId%NUM_OF_CHANNELS_IN_PORT;
	if(ChannelLevel == STD_HIGH)
	{
		switch (PortNum) {
		case Dio_Port_A:
			SET_BIT(PORTA,BitOffset);
			break;
		case Dio_Port_B:
			SET_BIT(PORTB,BitOffset);
			break;
		case Dio_Port_C:
			SET_BIT(PORTC,BitOffset);
			break;
		case Dio_Port_D:
			SET_BIT(PORTD,BitOffset);
			break;
		default:
			break;
		}

	}
	else
	{

		switch (PortNum) {
		case Dio_Port_A:
			CLR_BIT(PORTA,BitOffset);
			break;
		case Dio_Port_B:
			CLR_BIT(PORTB,BitOffset);
			break;
		case Dio_Port_C:
			CLR_BIT(PORTC,BitOffset);
			break;
		case Dio_Port_D:
			CLR_BIT(PORTD,BitOffset);
			break;
		default:
			break;
		}
	}
}
Dio_ChannelLevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;
	uint8 BitOffset = ChannelId%NUM_OF_CHANNELS_IN_PORT;
	Dio_ChannelLevelType RetVal = 0;
	switch (PortNum) {
	case Dio_Port_A:
		RetVal= GET_BIT(PINA,BitOffset);
		break;
	case Dio_Port_B:
		RetVal =GET_BIT(PINB,BitOffset);
		break;
	case Dio_Port_C:
		RetVal= GET_BIT(PINC,BitOffset);
		break;
	case Dio_Port_D:
		RetVal= GET_BIT(PIND,BitOffset);
		break;
	default:
		break;

	}
	return RetVal;
}
void Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;
	uint8 BitOffset = ChannelId%NUM_OF_CHANNELS_IN_PORT;

	switch (PortNum) {
	case Dio_Port_A:
		TOGGLE_BIT(PORTA,BitOffset);
		break;
	case Dio_Port_B:
		TOGGLE_BIT(PORTB,BitOffset);
		break;
	case Dio_Port_C:
		TOGGLE_BIT(PORTC,BitOffset);
		break;
	case Dio_Port_D:
		TOGGLE_BIT(PORTD,BitOffset);
		break;
	default:
		break;
	}

}

void Dio_WritePort(Dio_PortType PortId,uint8 Val)
{
	switch (PortId) {
	case Dio_Port_A:
		PORTA = Val;
		break;
	case Dio_Port_B:
		PORTB = Val;
		break;
	case Dio_Port_C:
		PORTC = Val;
		break;
	case Dio_Port_D:
		PORTD = Val;
		break;
	default:
		break;
	}
}

uint8 Dio_ReadPort(Dio_PortType PortId)
{
	uint8 RetVal = 0;
	switch (PortId) {
	case Dio_Port_A:
		RetVal = PINA;
		break;
	case Dio_Port_B:
		RetVal = PINB;
		break;
	case Dio_Port_C:
		RetVal = PINC;
		break;
	case Dio_Port_D:
		RetVal = PIND;
		break;
	default:
		break;
	}
	return RetVal;
}


