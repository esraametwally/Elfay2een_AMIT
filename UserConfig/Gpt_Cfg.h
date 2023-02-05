/*
 * Gpt_Cfg.h
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */

#ifndef AMITLATTE_USERCONFIG_GPT_CFG_H_
#define AMITLATTE_USERCONFIG_GPT_CFG_H_
/*
 * PLEASE choose from the followings
 *
 * GPT_PRESCALER_1       0x01
 * GPT_PRESCALER_8       0x02
 * GPT_PRESCALER_64      0x03
 * GPT_PRESCALER_256     0x04
 * GPT_PRESCALER_1024    0x05
 *
 * */
#define GPT_PRESCALER_SELECTOR     0x03
/*
 * PLEASE choose from the followings
 * GPT_TIMER_MODE_ONESHOT          0x00
 * GPT_TIMER_MODE_CONTINOUSE       0x01
 * */
#define GPT_TIMER_MODE_SELECTOR    GPT_TIMER_MODE_CONTINOUSE

#define GPT_INTERRUPT_OVF_EN          DISABLE
#define GPT_INTERRUPT_CTC_EN          ENABLE    /**/
#define GPT_OUTPUT_COMPARE_OC0        ENABLE

#define GPT_CALLBACK_PTR              Scheduler_Process
/*
 * PLEASE SELCT FROM THE FOLLOWING
 * GPT_WAVEFORM_GEN_NORMAL         0x00
 * GPT_WAVEFORM_GEN_CTC            0x02
 * GPT_WAVEFORM_GEN_FAST_PWM       0x03
 * GPT_WAVEFORM_GEN_PHASE_CORRECT  0x01
 *
 * */
#define GPT_WAVEFORM_GEN_MODE         GPT_WAVEFORM_GEN_CTC
#endif /* AMITLATTE_USERCONFIG_GPT_CFG_H_ */
