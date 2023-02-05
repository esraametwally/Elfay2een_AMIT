/*
 * Lcd_Cfg.h
 *
 *  Created on: Jan 29, 2021
 *      Author: future
 */

#ifndef AMITLATTE_USERCONFIG_LCD_CFG_H_
#define AMITLATTE_USERCONFIG_LCD_CFG_H_

#include "Dio.h"

#define LCD_D4                                                   Dio_Channel_C4
#define LCD_D5                                                   Dio_Channel_C5
#define LCD_D6                                                   Dio_Channel_C6
#define LCD_D7                                                   Dio_Channel_C7

#define LCD_RS                                                   Dio_Channel_A7
#define LCD_RW                                                   Dio_Channel_A6
#define LCD_E                                                    Dio_Channel_A5

#define CLEAR_DISPLAY_SCREEN                                     0x01u
#define RETURN_HOME                                              0x02u
#define DECREMENT_CURSOR                                         0x04u  /*shift cursor to left*/
#define INCREMENT_CURSOR                                         0x06u  /*shift cursor to right*/
#define SHIFT_DISPLAY_RIGHT                                      0x05u
#define SHIFT_DISPLAY_LEFT                                       0x07u
#define DISPLAY_OFF_CURSOR_OFF                                   0x08u
#define DISPLAY_OFF_CURSOR_ON                                    0x0Au
#define DISPLAY_ON_CURSOR_OFF                                    0x0Cu
#define DISPLAY_ON_CURSOR_BLINKING                               0x0Eu
#define SHIFT_CIRSOR_POSITION_TO_LEFT                            0x10u
#define SHIFT_CIRSOR_POSITION_TO_RIGHT                           0x14u
#define SHIFT_THE_ENTIRE_DISPLAYTO_THE_LEFT                      0x18u
#define SHIFT_THE_ENTIRE_DISPLAYTO_THE_RIGHT                     0x1Cu
#define FORCE_CURSOR_TO_BEGINNING_OF_1ST_LINE                    0x80u
#define FORCE_CURSOR_TO_BEGINNING_OF_2ST_LINE                    0xC0u
#define TWO_LINES_4_BITS                                         0x28u
#define TWO_LINES_8_BITS                                         0x38u






#endif /* AMITLATTE_USERCONFIG_LCD_CFG_H_ */
