#ifndef BIT_MAN_H
#define BIT_MAN_H

#include "Std_Types.h"

#define SET_BIT(Reg,Bitoffset)    Reg=(Reg | (1<<Bitoffset))
#define CLR_BIT(Reg,Bitoffset)  Reg=(Reg & (~(1<<Bitoffset)))
#define TOGGLE_BIT(Reg,Bitoffset) Reg=Reg&(~(1<<Bitoffset))
#endif
