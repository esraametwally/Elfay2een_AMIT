/*
 * Cpu_GlobalInt.h
 *
 *  Created on: Jan 23, 2021
 *      Author: future
 */

#ifndef AMITLATTE_MCAL_INCLUDE_CPU_GLOBALINT_H_
#define AMITLATTE_MCAL_INCLUDE_CPU_GLOBALINT_H_

#include "Bit_Man.h"
#include "Mcu_Hw.h"

#define ENABLE_GLOBAL_INTTERUPT()      SET_BIT(SREG,7)
#define DISABLE_GLOBAL_INTTERUPT()    CLR_BIT(SREG,7)


#endif /* AMITLATTE_MCAL_INCLUDE_CPU_GLOBALINT_H_ */
