#include "PWM.h"
uint8_t pwm6_duty=10,pwm7_duty=10;

void PWM_Set()
{
	__HAL_TIM_SetCompare(&htim16,TIM_CHANNEL_1,pwm6_duty);
	__HAL_TIM_SetCompare(&htim17,TIM_CHANNEL_1,pwm7_duty);
}
