#include "hal_adc.h"

double Get_adc1()
{
	static double Get_value;
	HAL_ADC_Start(&hadc1);
	if(HAL_OK==HAL_ADC_PollForConversion(&hadc1,100))
	{
		Get_value=HAL_ADC_GetValue(&hadc1);
	}
	return Get_value;
}

double Get_adc2()
{
	static double Get_value;
	HAL_ADC_Start(&hadc2);
	if(HAL_OK==HAL_ADC_PollForConversion(&hadc2,100))
	{
		Get_value=HAL_ADC_GetValue(&hadc2);
	}
	return Get_value;
}
