#ifndef STD_TYPE_H
#define STD_TYPE_H

#include "Platform_Types.h"


typedef void (*Ptr2FuncType)(void);

#define TRUE 1
#define FALSE 0

#define ENABLE 1
#define DISABLE 0

#define STD_ON 1
#define STD_OFF 0
#define STD_HIGH                1u
#define STD_LOW                 0u
#define NULL                    (void*)0

typedef uint8 Std_RetType;
#define E_OK             0
#define E_NOT_OK         1

#endif
