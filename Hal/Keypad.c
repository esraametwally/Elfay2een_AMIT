/*
 * Keypad.c
 *
 *  Created on: Jan 22, 2021
 *      Author: Israa Mohamed
 */
#include "Bit_Man.h"
#include "Dio.h"
#include "Keypad_Cfg.h"
#include "Keypad.h"

static uint8 PressedButton;
static void CheckCOl(uint8 ActivatedRowNum);
void Keypad_Init(void)
{
	/*attach internal pullup resistors on Col pins by setting pin input and put 1 on the pin*/
    Dio_WriteChannel(KEYPAD_COL_0_PIN,Dio_ChannelLevel_High);
    Dio_WriteChannel(KEYPAD_COL_1_PIN,Dio_ChannelLevel_High);
    Dio_WriteChannel(KEYPAD_COL_2_PIN,Dio_ChannelLevel_High);
    Dio_WriteChannel(KEYPAD_COL_3_PIN,Dio_ChannelLevel_High);


}
uint8 Keypad_GetPressedButton(void)
{
	PressedButton = KEYPAD_NOT_PRESSED_VAL;
	/*Active Row_0  and de-active Row_1, Row_2, Row_3 (WRITE CHANNELs)*/
    Dio_WriteChannel(KEYPAD_ROW_0_PIN, KEYPAD_LEVEL_ACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_1_PIN,KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_2_PIN,KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_3_PIN,KEYPAD_LEVEL_DEACTIVE);

    CheckCOl(0);

    Dio_WriteChannel(KEYPAD_ROW_0_PIN, KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_1_PIN,KEYPAD_LEVEL_ACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_2_PIN,KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_3_PIN,KEYPAD_LEVEL_DEACTIVE);
    CheckCOl(1);

    Dio_WriteChannel(KEYPAD_ROW_0_PIN, KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_1_PIN,KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_2_PIN,KEYPAD_LEVEL_ACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_3_PIN,KEYPAD_LEVEL_DEACTIVE);
    CheckCOl(2);

    Dio_WriteChannel(KEYPAD_ROW_0_PIN, KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_1_PIN,KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_2_PIN,KEYPAD_LEVEL_DEACTIVE);
    Dio_WriteChannel(KEYPAD_ROW_3_PIN,KEYPAD_LEVEL_ACTIVE);
    CheckCOl(3);

   return PressedButton;
}


static void CheckCOl(uint8 ActivatedRowNum)
{
    if(Dio_ReadChannel(KEYPAD_COL_0_PIN) == KEYPAD_LEVEL_ACTIVE)
    {
    	PressedButton = ActivatedRowNum*4;
    }
    else if(Dio_ReadChannel(KEYPAD_COL_1_PIN) == KEYPAD_LEVEL_ACTIVE)
    {
    	PressedButton = (ActivatedRowNum*4)+1;
    }
    else if(Dio_ReadChannel(KEYPAD_COL_2_PIN) == KEYPAD_LEVEL_ACTIVE)
    {
    	PressedButton = (ActivatedRowNum*4)+2;
    }
    else if(Dio_ReadChannel(KEYPAD_COL_3_PIN) == KEYPAD_LEVEL_ACTIVE)
    {
    	PressedButton = (ActivatedRowNum*4)+3;
    }

}
