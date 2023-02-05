
#include "util/delay.h"
#include "Std_Types.h"
#include "BcdSevSeg.h"
#include "Dio.h"
void lab_02_BcdSevSeg(void)
{
	uint8 i,Num=0;
	Dio_Init();
	while(1)
	{
		/*read the pressed button from the keypad*/

			for (i = 0; i < 50; ++i)
			{

				/*display the number on SevSegments*/
				BcdSevSeg_Enable(BcdSevSeg_1);
				BcdSevSeg_Disable(BcdSevSeg_0);
				BcdSevSeg_DisplayNum(Num%10);
				_delay_ms(10);

				/*display the number on SevSegments*/
				BcdSevSeg_Disable(BcdSevSeg_1);
				BcdSevSeg_Enable(BcdSevSeg_0);
				BcdSevSeg_DisplayNum(Num/10);
				_delay_ms(10);

			}

			Num++;
			if(Num > 99)Num=0;


}
}
