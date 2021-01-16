#ifndef BIT_MAN_H
#define BIT_MAN_H

#include "Std_Types.h"

#define GET_BIT(Reg,BitOffset)     ((Reg>>BitOffset)&(0x01u))
#define SET_BIT(Reg,Bitoffset)     Reg=(Reg | (1<<Bitoffset))
#define CLR_BIT(Reg,Bitoffset)     Reg=(Reg & (~(1<<Bitoffset)))
#define TOGGLE_BIT(Reg,BitOffset)  Reg = Reg^(1<<BitOffset)
#endif
