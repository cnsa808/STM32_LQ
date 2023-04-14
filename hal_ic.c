#include "hal_ic.h"
uint frp1=0,frp2=0;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	uint crl_value1=0,crl_value2=0;
	if(htim==&htim2)
	{
		crl_value1=HAL_TIM_ReadCapturedValue(&htim2,TIM_CHANNEL_1);
		__HAL_TIM_SetCounter(&htim2,0);
		frp1=(80000000/80)/crl_value1;
	}
	if(htim==&htim3)
	{
		crl_value2=HAL_TIM_ReadCapturedValue(&htim3,TIM_CHANNEL_1);
		__HAL_TIM_SetCounter(&htim3,0);
		frp2=(80000000/80)/crl_value2;
	}
}
