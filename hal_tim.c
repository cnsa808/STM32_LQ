#include "hal_tim.h"
uint8_t Sec,Min,Hour;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)/*中断回调函数*/
{
	if(htim==&htim1)
	{
		Sec++;if(Sec>=60){Sec=0;Min++;if(Min>=60){Min=0;Hour++;if(Hour>=24){Hour=0;}}}
	}
}
