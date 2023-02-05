/*
 * Exti_Cfg.h
 *
 *  Created on: Jan 23, 2021
 *      Author: future
 */

#ifndef AMITLATTE_USERCONFIG_EXTI_CFG_H_
#define AMITLATTE_USERCONFIG_EXTI_CFG_H_


#define EXTI_0_ENABLE					ENABLE   /* Channel D2*/
#define EXTI_1_ENABLE					DISABLE  /* Channel D3*/
#define EXTI_2_ENABLE					DISABLE   /* Channel B2*/
/*
 * Please choose from the followings
EXTI_SENSE_MODE_LOWLEVEL     0x00
EXTI_SENSE_MODE_ONCHANGE     0x01
EXTI_SENSE_MODE_FALLINGEDGE  0x10
EXTI_SENSE_MODE_RISINGEDGE   0x11
 *
 */

#define EXTI_0_SENSE_MODE_SELECTOR     0x01
#define EXTI_1_SENSE_MODE_SELECTOR     0x01

/* Please choose from the followings

EXTI_SENSE_MODE_FALLINGEDGE  0x00
EXTI_SENSE_MODE_RISINGEDGE   0x01
 *
 */
#define EXTI_2_SENSE_MODE_SELECTOR     0x00u

#define EXTI_0_CALLBACK_PTR            User_PwmMeterWithExti_CallBack
#define EXTI_1_CALLBACK_PTR            User_ExtiCallBack
#define EXTI_2_CALLBACK_PTR            User_ExtiCallBack

#endif /* AMITLATTE_USERCONFIG_EXTI_CFG_H_ */
