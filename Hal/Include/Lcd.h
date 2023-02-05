/*
 * Lcd.h
 *
 *  Created on: Jan 29, 2021
 *      Author: future
 */

#ifndef AMITLATTE_HAL_INCLUDE_LCD_H_
#define AMITLATTE_HAL_INCLUDE_LCD_H_

#include "Std_Types.h"

void Lcd_Init(void);
void Lcd_WriteChar(uint8 CharToDisplay);
void Lcd_WriteCommand(uint8 CommandNum);
void Lcd_WriteString(uint8* Ptr2String,uint8 Row,uint8 Coloum);
void Lcd_StoreCustomChar(uint8* Ptr2CustomChar,uint8 CGRamIdx);
void Lcd_DisplayCustomChar(uint8 CGRamIdx,uint8 Row, uint8 Coloum);

#endif /* AMITLATTE_HAL_INCLUDE_LCD_H_ */
