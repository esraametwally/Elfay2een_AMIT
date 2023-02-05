/*
 * BcdSevSeg.h
 *
 *  Created on: Jan 22, 2021
 *      Author: future
 */

#ifndef MERNAH_REPO_HAL_INCLUDE_BCDSEVSEG_H_
#define MERNAH_REPO_HAL_INCLUDE_BCDSEVSEG_H_

#include "Std_Types.h"
typedef enum
{
	BcdSevSeg_0,
	BcdSevSeg_1
}BcdSevSeg_Type;
extern void BcdSevSeg_Enable(BcdSevSeg_Type SevSegNum);
extern void BcdSevSeg_Disable(BcdSevSeg_Type SevSegNum);
extern void BcdSevSeg_DisplayNum(uint8 NumToDisplay);

#endif /* MERNAH_REPO_HAL_INCLUDE_BCDSEVSEG_H_ */
