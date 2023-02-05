/*
 * Gpt1_Cfg.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Muhammad.Elzeiny
 */

#ifndef AMITLATTE_USERCONFIG_GPT1_CFG_H_
#define AMITLATTE_USERCONFIG_GPT1_CFG_H_

/*
 *
 * GPT1_MODE_NORMAL    0x00
 * GPT1_MODE_CTC_OCR   0x01
 * GPT1_MODE_CTC_ICR   0x02
 *
 * */
#define GPT1_MODE_SELECTOR              GPT1_MODE_NORMAL

/*
 * PLEASE choose from the followings
 *
 * GPT1_PRESCALER_1       0x01
 * GPT1_PRESCALER_8       0x02
 * GPT1_PRESCALER_64      0x03
 * GPT1_PRESCALER_256     0x04
 * GPT1_PRESCALER_1024    0x05
 *
 * */
#define GPT1_PRESCALER_SELECTOR     0x03U

#define GPT1_ICU_EN                 ENABLE
#endif /* AMITLATTE_USERCONFIG_GPT1_CFG_H_ */
