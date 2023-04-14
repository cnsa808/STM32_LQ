#include "HAL_ADC.h"

double Get_Adc1()
{	
	double ADC_Value;
	HAL_ADC_Start(&hadc1);
	if(HAL_OK==HAL_ADC_PollForConversion(&hadc1,10))
	{
		ADC_Value=HAL_ADC_GetValue(&hadc1);
	}
	return ADC_Value;
}

double Get_Adc2()
{
	double ADC_Value;
	HAL_ADC_Start(&hadc2);
	if(HAL_OK==HAL_ADC_PollForConversion(&hadc2,10))
	{
		ADC_Value=HAL_ADC_GetValue(&hadc2);
	}
	return ADC_Value;
}
