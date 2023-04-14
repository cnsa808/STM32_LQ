#ifndef _KEY_H_
#define _KEY_H_
#include "main.h"
#include "PWM.h"
#include "lcd.h"
#include "stdio.h"
#include "LED.h"
#include "tim.h"
#include "HAL_UART.h"
#include "HAL_ADC.h"
#define key1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)
#define key2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)
#define key3 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)
#define key4 HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)
void KEY_Set(void);
void PWM_Display(void);
void TIM_Display(void);
void UART_Display(void);
void LED_Set(uint8_t LED_Scan);
void ADC_Display(void);
#endif

