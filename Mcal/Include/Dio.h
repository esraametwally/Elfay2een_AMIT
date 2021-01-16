/*
 * Dio.h
 *
 *  Created on: Jan 15, 2021
 *      Author: power system
 */

#ifndef MERNAH_REPO_MCAL_INCLUDE_DIO_H_
#define MERNAH_REPO_MCAL_INCLUDE_DIO_H_
#include "Std_Types.h"

typedef struct
{
	uint8 Dio_Dir_A0 : 1;
	uint8 Dio_Dir_A1 : 1;
	uint8 Dio_Dir_A2 : 1;
	uint8 Dio_Dir_A3 : 1;
	uint8 Dio_Dir_A4 : 1;
	uint8 Dio_Dir_A5 : 1;
	uint8 Dio_Dir_A6 : 1;
	uint8 Dio_Dir_A7 : 1;

	uint8 Dio_Dir_B0 : 1;
	uint8 Dio_Dir_B1 : 1;
	uint8 Dio_Dir_B2 : 1;
	uint8 Dio_Dir_B3 : 1;
	uint8 Dio_Dir_B4 : 1;
	uint8 Dio_Dir_B5 : 1;
	uint8 Dio_Dir_B6 : 1;
	uint8 Dio_Dir_B7 : 1;

	uint8 Dio_Dir_C0 : 1;
	uint8 Dio_Dir_C1 : 1;
	uint8 Dio_Dir_C2 : 1;
	uint8 Dio_Dir_C3 : 1;
	uint8 Dio_Dir_C4 : 1;
	uint8 Dio_Dir_C5 : 1;
	uint8 Dio_Dir_C6 : 1;
	uint8 Dio_Dir_C7 : 1;

	uint8 Dio_Dir_D0 : 1;
	uint8 Dio_Dir_D1 : 1;
	uint8 Dio_Dir_D2 : 1;
	uint8 Dio_Dir_D3 : 1;
	uint8 Dio_Dir_D4 : 1;
	uint8 Dio_Dir_D5 : 1;
	uint8 Dio_Dir_D6 : 1;
	uint8 Dio_Dir_D7 : 1;
}Dio_StrBFType;
typedef union
{
	Dio_StrBFType DIR_B;
	uint8 CfgDirArr[4];

}Dio_CfgUnionType;
typedef enum
{
	Dio_Port_A,
	Dio_Port_B,
	Dio_Port_C,
	Dio_Port_D
}Dio_PortType;


typedef enum
{
	Dio_Channel_A0,
	Dio_Channel_A1,
	Dio_Channel_A2,
	Dio_Channel_A3,
	Dio_Channel_A4,
	Dio_Channel_A5,
	Dio_Channel_A6,
	Dio_Channel_A7,

	Dio_Channel_B0,
	Dio_Channel_B1,
	Dio_Channel_B2,
	Dio_Channel_B3,
	Dio_Channel_B4,
	Dio_Channel_B5,
	Dio_Channel_B6,
	Dio_Channel_B7,

	Dio_Channel_C0,
	Dio_Channel_C1,
	Dio_Channel_C2,
	Dio_Channel_C3,
	Dio_Channel_C4,
	Dio_Channel_C5,
	Dio_Channel_C6,
	Dio_Channel_C7,

	Dio_Channel_D0,
	Dio_Channel_D1,
	Dio_Channel_D2,
	Dio_Channel_D3,
	Dio_Channel_D4,
	Dio_Channel_D5,
	Dio_Channel_D6,
	Dio_Channel_D7
}Dio_ChannelType;
typedef enum
{
	Dio_ChannelLevel_Low,
	Dio_ChannelLevel_High
}Dio_ChannelLevelType;
extern void Dio_Init(void);
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_ChannelLevelType ChannelLevel);
extern Dio_ChannelLevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
extern void Dio_FlipChannel(Dio_ChannelType ChannelId);
extern Dio_ChannelLevelType Dio_ReadPORT(Dio_ChannelType ChannelId);
extern void Dio_WritePORT(Dio_ChannelType ChannelId,uint8 value);
#endif /* MERNAH_REPO_MCAL_INCLUDE_DIO_H_ */
