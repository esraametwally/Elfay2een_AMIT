#ifndef MCU_HW_H
#define MCU_HW_H

#include "Std_Types.h"

#define DDRA (*((volatile uint8*)0x3Au))
#define DDRB (*((volatile uint8*)0x37u))
#define DDRC (*((volatile uint8*)0x34u))
#define DDRD (*((volatile uint8*)0x31u))

#define PORTA (*((volatile uint8*)0x3Bu))
#define PORTB (*((volatile uint8*)0x38u))
#define PORTC (*((volatile uint8*)0x35u))
#define PORTD (*((volatile uint8*)0x32u))

#define PINA (*((volatile uint8*)0x39u))
#define PINB (*((volatile uint8*)0x36u))
#define PINC (*((volatile uint8*)0x33u))
#define PIND (*((volatile uint8*)0x30u))




#endif
