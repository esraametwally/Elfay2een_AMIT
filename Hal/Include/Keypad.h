/*
 * Keypad.h
 *
 *  Created on: Jan 22, 2021
 *      Author: future
 */

#ifndef AMITLATTE_HAL_INCLUDE_KEYPAD_H_
#define AMITLATTE_HAL_INCLUDE_KEYPAD_H_

#include "Std_Types.h"

void Keypad_Init(void);
uint8 Keypad_GetPressedButton(void);

#endif /* AMITLATTE_HAL_INCLUDE_KEYPAD_H_ */
