/*
 * Keypad_Cfg.h
 *
 *  Created on: Jan 22, 2021
 *      Author: future
 */

#ifndef AMITLATTE_USERCONFIG_KEYPAD_CFG_H_
#define AMITLATTE_USERCONFIG_KEYPAD_CFG_H_

#define  KEYPAD_ROW_0_PIN       Dio_Channel_C4
#define  KEYPAD_ROW_1_PIN       Dio_Channel_C5
#define  KEYPAD_ROW_2_PIN       Dio_Channel_C6
#define  KEYPAD_ROW_3_PIN       Dio_Channel_C7

#define  KEYPAD_COL_0_PIN       Dio_Channel_C0
#define  KEYPAD_COL_1_PIN       Dio_Channel_C1
#define  KEYPAD_COL_2_PIN       Dio_Channel_C2
#define  KEYPAD_COL_3_PIN       Dio_Channel_C3

#define KEYPAD_LEVEL_ACTIVE      STD_LOW
#define KEYPAD_LEVEL_DEACTIVE    STD_HIGH

#define KEYPAD_NOT_PRESSED_VAL   255


#endif /* AMITLATTE_USERCONFIG_KEYPAD_CFG_H_ */
