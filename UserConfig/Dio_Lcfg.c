/*
 * Dio_Lcfg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-Wattaneya
 */

#define DIO_CHANNEL_DIR_INPUT        0
#define DIO_CHANNEL_DIR_OUTPUT       1

#include "Std_Types.h"
#include "Dio.h"

const Dio_CfgUnionType DioCfgUnion = {
		{
				DIO_CHANNEL_DIR_INPUT,  /* Dio_Channel_A0_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A1_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A2_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A3_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A4_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A5_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A6_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_A7_Direction */


				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B0_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B1_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B2_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B3_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B4_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B5_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B6_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_B7_Direction */



				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C0_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C1_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C2_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C3_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C4_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C5_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C6_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_C7_Direction */


				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D0_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D1_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D2_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D3_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D4_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D5_Direction */
				DIO_CHANNEL_DIR_OUTPUT,  /* Dio_Channel_D6_Direction */
				DIO_CHANNEL_DIR_OUTPUT   /* Dio_Channel_D7_Direction */
		}
};
