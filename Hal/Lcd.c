/*
 * Lcd.c
 *
 *  Created on: Jan 29, 2021
 *      Author: Israa Mohamed
 */
#include "Std_Types.h"
#include "Bit_Man.h"
#include "Dio.h"
#include "Lcd_Cfg.h"
#include "Lcd.h"
#include "util/delay.h"

void Lcd_Init(void)
{
	_delay_ms(15);
	Lcd_WriteCommand(RETURN_HOME);
	Lcd_WriteCommand(INCREMENT_CURSOR);
	Lcd_WriteCommand(TWO_LINES_4_BITS);
	Lcd_WriteCommand(DISPLAY_ON_CURSOR_OFF);
	Lcd_WriteCommand(CLEAR_DISPLAY_SCREEN);

}
void Lcd_WriteChar(uint8 CharToDisplay)
{
	/*TODO : Set RS PIN to start writing data */
	Dio_WriteChannel(LCD_RS,STD_HIGH);

	/* TODO: Clear RW PIN */
	Dio_WriteChannel(LCD_RW,STD_LOW);

	/*TODO: Write Most 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CharToDisplay,4));
	Dio_WriteChannel(LCD_D5, GET_BIT(CharToDisplay,5));
	Dio_WriteChannel(LCD_D6, GET_BIT(CharToDisplay,6));
	Dio_WriteChannel(LCD_D7, GET_BIT(CharToDisplay,7));

	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);

	/*TODO: Write Least 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CharToDisplay,0));
	Dio_WriteChannel(LCD_D5, GET_BIT(CharToDisplay,1));
	Dio_WriteChannel(LCD_D6, GET_BIT(CharToDisplay,2));
	Dio_WriteChannel(LCD_D7, GET_BIT(CharToDisplay,3));
	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);


}
void Lcd_WriteString(uint8* Ptr2String,uint8 Row,uint8 Coloum)
{
	/*Elmazedi go to x,y*/
	uint8 var;
	var=0x80|((Row*0x40)+Coloum);
	uint8 i=0;
	Lcd_WriteCommand(var);

	while (Ptr2String[i]!='\0')
	{

		Lcd_WriteChar(Ptr2String[i]);
		i++;
	}
}
void Lcd_WriteCommand(uint8 CommandNum)
{
	/*TODO : Clear RS PIN to start writing command */
	Dio_WriteChannel(LCD_RS,STD_LOW);
	/* TODO: Clear RW PIN */
	Dio_WriteChannel(LCD_RW,STD_LOW);
	/*TODO: Write Most 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CommandNum,4));
	Dio_WriteChannel(LCD_D5, GET_BIT(CommandNum,5));
	Dio_WriteChannel(LCD_D6, GET_BIT(CommandNum,6));
	Dio_WriteChannel(LCD_D7, GET_BIT(CommandNum,7));

	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);


	/*TODO: Write Least 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CommandNum,0));
	Dio_WriteChannel(LCD_D5, GET_BIT(CommandNum,1));
	Dio_WriteChannel(LCD_D6, GET_BIT(CommandNum,2));
	Dio_WriteChannel(LCD_D7, GET_BIT(CommandNum,3));
	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);
}

void Lcd_StoreCustomChar(uint8* Ptr2CustomChar,uint8 CGRamIdx)
{
	uint8 i;
	/* AC -> CGRAM   0b01<Address>*/
	Lcd_WriteCommand(0b01000000 | (CGRamIdx*8));
	for (i = 0; i < 8; ++i) {
		Lcd_WriteChar(Ptr2CustomChar[i]);
	}
	/*Return Home  */
	Lcd_WriteCommand(0x02);

}
void Lcd_DisplayCustomChar(uint8 CGRamIdx,uint8 Row, uint8 Coloum)
{
	uint8 var;
	/*go to desired position*/
	var=0x80|((Row*0x40)+Coloum);
	Lcd_WriteCommand(var);
	/*Write index of custom character in CGRAM */
	Lcd_WriteChar(CGRamIdx);


}
