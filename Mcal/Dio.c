/*
 * Dio.c
 *
 *  Created on: Jan 15, 2021
 *      Author: power system
 */
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "Dio.h"
#include "Dio_Cfg.h"

#define NUM_OF_CHANNELS_IN_PORT      8

extern const Dio_CfgUnionType DioCfgUnion;

extern Dio_ChannelType InternalPullUpCfgChannels[NUM_OF_ATTACHED_CHANNELS];
void Dio_Init(void)
{
	uint8 i;
	Dio_ChannelType ChannelId;
	DDRA = DioCfgUnion.CfgDirArr[0];
	DDRB = DioCfgUnion.CfgDirArr[1];
	DDRC = DioCfgUnion.CfgDirArr[2];
	DDRD = DioCfgUnion.CfgDirArr[3];


	/*attach internal pullup resestors to configured channels*/
	for (i = 0; i < NUM_OF_ATTACHED_CHANNELS; ++i)
	{
		ChannelId = InternalPullUpCfgChannels[i];
		Dio_WriteChannel(ChannelId,STD_HIGH);

	}

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_ChannelLevelType ChannelLevel)
{
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;
	uint8 BitOffset = ChannelId%NUM_OF_CHANNELS_IN_PORT;

	if (ChannelLevel==STD_HIGH)
	{
		switch(PortNum)
		{
		case Dio_Port_A :
			SET_BIT(PORTA,BitOffset);
			break;

		case Dio_Port_B :
			SET_BIT(PORTB,BitOffset);
			break;

		case Dio_Port_C :
			SET_BIT(PORTC,BitOffset);
			break;

		case Dio_Port_D :
			SET_BIT(PORTD,BitOffset);
			break;

		default :
		break;
		}
	}
	else if (ChannelLevel==STD_LOW)
	{
		switch(PortNum)
		{
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

		default :
		break;
		}
	}

}
Dio_ChannelLevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_ChannelLevelType level_return;
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;
	uint8 BitOffset = ChannelId%NUM_OF_CHANNELS_IN_PORT;


	switch(PortNum)
	{
	case Dio_Port_A :
		level_return = GET_BIT(PINA,BitOffset);
		break;

	case Dio_Port_B :
		level_return = GET_BIT(PINB,BitOffset);
		break;

	case Dio_Port_C :
		level_return = GET_BIT(PINC,BitOffset);
		break;

	case Dio_Port_D :
		level_return = GET_BIT(PIND,BitOffset);
		break;

	default :
	break;

	}

	return level_return;

}
uint8 Dio_ReadPORT(Dio_ChannelType ChannelId)
{
	uint8 port_return;
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;



	switch(PortNum)
	{
	case Dio_Port_A :
		port_return = PINA;
		break;

	case Dio_Port_B :
		port_return = PINB;
		break;

	case Dio_Port_C :
		port_return = PINC;
		break;

	case Dio_Port_D :
		port_return = PIND;
		break;

	default :
	break;
	return port_return;
	}



}
void Dio_WritePORT(Dio_ChannelType ChannelId,uint8 value)
{
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;



	switch(PortNum)
	{
	case Dio_Port_A :
		PORTA=value;
		break;

	case Dio_Port_B :
		PORTB=value;
		break;

	case Dio_Port_C :
		PORTC=value;
		break;

	case Dio_Port_D :
		PORTD=value;
		break;

	default :
	break;
	}



}
void Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_PortType PortNum = ChannelId/NUM_OF_CHANNELS_IN_PORT;
	uint8 BitOffset = ChannelId%NUM_OF_CHANNELS_IN_PORT;


	switch(PortNum)
	{
	case Dio_Port_A :
		TOGGLE_BIT(PORTA,BitOffset);
		break;

	case Dio_Port_B :
		TOGGLE_BIT(PORTB,BitOffset);
		break;

	case Dio_Port_C :
		TOGGLE_BIT(PORTC,BitOffset);
		break;

	case Dio_Port_D :
		TOGGLE_BIT(PORTD,BitOffset);
		break;

	default :
	break;
	}





}
