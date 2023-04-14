#ifndef _KEY_H_
#define _KEY_H_
#include "main.h"
#include "lcd.h"
#include "hal_tim.h"
#include "hal_adc.h"
#include "stdio.h"
#include "hal_pwm.h"
#include "hal_ic.h"
#include "hal_uart.h"
#include "stdbool.h"
#define key1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)
#define key2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)
#define key3 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)
#define key4 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)
/*用户代码区域*/
void KEY_Set(void);
void TIM_Display(void);
void LED_Display(unsigned char scanf);
void ADC_Display(void);
void PWM_Display(void);
void IC_Display(void);
void UART_Tx(void);
/*user code end */
#endif
