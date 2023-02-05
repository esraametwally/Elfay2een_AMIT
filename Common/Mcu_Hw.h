/*
 * Mcu_Hw.h
 *
 *  Created on: Jan 15, 2021
 *      Author: power system
 */

#ifndef MCU_HW_H_
#define MCU_HW_H_
#include "Std_Types.h"
/*DIO Register */
#define  DDRA     (*((volatile uint8*)0x3A))
#define  DDRC     (*((volatile uint8*)0x34))
#define  DDRD     (*((volatile uint8*)0x31))
#define  DDRB     (*((volatile uint8*)0x37))

#define  PORTA    (*((volatile uint8*)0x3B))
#define  PORTB    (*((volatile uint8*)0x38))
#define  PORTC    (*((volatile uint8*)0x35))
#define  PORTD    (*((volatile uint8*)0x32))

#define  PINA     (*((volatile uint8*)0x39))
#define  PINB     (*((volatile uint8*)0x36))
#define  PINC     (*((volatile uint8*)0x33))
#define  PIND     (*((volatile uint8*)0x30))

#define  MCUCR    (*((volatile uint8*)0x55))
#define  MCUCSR   (*((volatile uint8*)0x54))
#define  GICR     (*((volatile uint8*)0x5B))
#define  SREG     (*((volatile uint8*)0x5F))

/* TIMER0 REGISTER */
#define TCCR0      (*((volatile uint8*)0x53))
#define TCNT0      (*((volatile uint8*)0x52))
#define OCR0       (*((volatile uint8*)0x5C))
#define TIMSK      (*((volatile uint8*)0x59))

/* TIMER2 REGISTER */
#define TCCR2      (*((volatile uint8*)0x45))
#define TCNT2      (*((volatile uint8*)0x44))
#define OCR2       (*((volatile uint8*)0x43))

/* Timer1 Registers */
#define TCNT1H     (*((volatile uint8*)0x4D))
#define TCNT1L     (*((volatile uint8*)0x4C))
#define TCNT1      (*((volatile uint16*)0x4C))
#define OCRA       (*((volatile uint16*)0x4A))
#define OCRB       (*((volatile uint16*)0x48))
#define TCCR1A     (*((volatile uint8*)0x4F))
#define TCCR1B     (*((volatile uint8*)0x4E))
#define ICR1       (*((volatile uint16*)0x46))

/*ADC registers */
typedef struct
{
	uint8 ADPS  : 3;
	uint8 ADIE  : 1;
	uint8 ADIF  : 1;
	uint8 ADATE : 1;
	uint8 ADSC  : 1;
	uint8 ADEN  : 1;
}ADCSRA_StrBit;
typedef union
{
	ADCSRA_StrBit B;
	uint8 R;
}ADCSRA_TAG;

typedef struct
{
	uint8 MUX : 5;
	uint8 ADLAR:1;
	uint8 REFS :2;
}ADMUC_StrBit;
typedef union
{
	ADMUC_StrBit B;
	uint8 R;

}ADMUX_TAG;


#define ADCSRA             (*(volatile ADCSRA_TAG*)0x26)
#define ADMUX              (*(volatile ADMUX_TAG*)0x27)
#define ADC                (*(volatile uint16*)0x24)
#define ADCL               (*(volatile uint8*)0x24)
#define ADCH               (*(volatile uint8*)0x25)
#define SFIOR              (*(volatile uint8*)0x50)

/*UART Registers*/
typedef struct
{
	uint8 MPCM:1;
	uint8 U2X:1;
	uint8 PE:1;
	uint8 DOR:1;
	uint8 FE:1;
	uint8 UDRE:1;
	uint8 TXC:1;
	uint8 RXC:1;
}UCSRA_StrBFType;
typedef union
{
	uint8 R;
	UCSRA_StrBFType B;

}UCSRA_TAG;

typedef struct
{
	uint8 TXB8:1;
	uint8 RXB8:1;
	uint8 UCSZ2:1;
	uint8 TXEN:1;
	uint8 RXEN:1;
	uint8 UDRIE:1;
	uint8 TXCIE:1;
	uint8 RXCIE:1;
}UCSRB_StrBFType;
typedef union
{
	uint8 R;
	UCSRB_StrBFType B;

}UCSRB_TAG;
typedef struct
{
	uint8 UCPOL:1;
	uint8 UCSZ:2;
	uint8 USBS:1;
	uint8 UPM:2;
	uint8 UMSEL:1;
	uint8 URSEL:1;
}UCSRC_StrBFType;
typedef union
{
	uint8 R;
	UCSRC_StrBFType B;

}UCSRC_TAG;

#define UDR                (*(volatile uint8*)0x2C)
#define UBRRL              (*(volatile uint8*)0x29)
#define UCSRA              (*(volatile UCSRA_TAG*)0x2B)
#define UCSRB              (*(volatile UCSRB_TAG*)0x2A)
#define UCSRC              (*(volatile UCSRC_TAG*)0x40)
/*SPI REGESTERS*/

typedef struct
{
	uint8 SPR :2;
	uint8 CPHA:1;
	uint8 CPOL:1;
	uint8 MSTR:1;
	uint8 DORD:1;
	uint8 SPE :1;
	uint8 SPIE:1;

}SPCR_StrBFType;
typedef union
{
	uint8 R;
	SPCR_StrBFType B;

}SPCR_TAG;
typedef struct
{
	uint8 SPI2X :1;
	uint8 REV   :5;
	uint8 WCOL  :1;
	uint8 SPIF  :1;

}SPSR_StrBFType;
typedef union
{
	uint8 R;
	SPSR_StrBFType B;

}SPSR_TAG;
#define SPCR              ((*(volatile SPCR_TAG*)0x2D))
#define SPSR              ((*(volatile SPSR_TAG*)0x2E))
#define SPDR              ((*(volatile uint8*)0x2F))
/*TODO: Define Hw Registers in Spi Module */
#endif /* MCU_HW_H_ */
