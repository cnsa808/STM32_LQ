#include "key.h"
static uint8_t mode,Sec=50,Min=59,Hour=23;
extern uint8_t pwm6_duty,pwm7_duty,text_rx[20];
void KEY_Set()/*按键触发判断函数*/
{	
	static uint8_t key1_s,key2_s,key3_s,key4_s;
	if(key1==1){HAL_Delay(10);key1_s=1;}if(key1_s==1&&key1==0){key1_s=0;pwm6_duty+=10;if(pwm6_duty>=100)pwm6_duty=10;}
	if(key2==1){HAL_Delay(10);key2_s=1;}if(key2_s==1&&key2==0){key2_s=0;pwm7_duty+=10;if(pwm7_duty>=100)pwm7_duty=10;}
	if(key3==1){HAL_Delay(10);key3_s=1;}if(key3_s==1&&key3==0){key3_s=0;/*后续添加按键三触发对应操作*/}
	if(key4==1){HAL_Delay(10);key4_s=1;}if(key4_s==1&&key4==0){key4_s=0;mode++,LCD_Clear(White);if(mode>=4)mode=0;}
}

void LED_Set(uint8_t LED_Scan)/*LED显示函数*/
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_All,GPIO_PIN_SET); 
	HAL_GPIO_WritePin(GPIOC,LED_Scan<<8,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}

void TIM_Display()/*时间显示函数*/
{
	if(mode==0)
	{
		LCD_DisplayStringLine(Line2,(uint8_t*)"        Time        ");
		LCD_DisplayStringLine(Line3,(uint8_t*)"        ****        ");
		LCD_DisplayChar(Line4,(320-(16*6)),(Hour/10)+48);
		LCD_DisplayChar(Line4,(320-(16*7)),(Hour%10)+48);
		LCD_DisplayChar(Line4,(320-(16*8)),':');
		LCD_DisplayChar(Line4,(320-(16*9)),(Min/10)+48);
		LCD_DisplayChar(Line4,(320-(16*10)),(Min%10)+48);
		LCD_DisplayChar(Line4,(320-(16*11)),':');
		LCD_DisplayChar(Line4,(320-(16*12)),(Sec/10)+48);
		LCD_DisplayChar(Line4,(320-(16*13)),(Sec%10)+48);
	}
}

void PWM_Display()/*PWM显示函数*/
{
	if(mode==1)
	{
		static char text[20];
		LCD_DisplayStringLine(Line1,(uint8_t*)"        Para        ");
		sprintf(text,"      PA6:%d%%    ",pwm6_duty);
		LCD_DisplayStringLine(Line3,(uint8_t*)text);
		sprintf(text,"      PA7:%d%%    ",pwm7_duty);
		LCD_DisplayStringLine(Line5,(uint8_t*)text);
	}
}

void ADC_Display()/*ADC显示函数*/
{	
	if(mode==2)
	{
		static char text[20];
		static double	value,value1;
		value=Get_Adc1();
		value1=Get_Adc2();
		sprintf(text,"      V1=%.2fV     ",(value*3.3/4096));
		LCD_DisplayStringLine(Line4,(uint8_t*)text);
		sprintf(text,"      V2=%.2fV     ",(value1*3.3/4096));
		LCD_DisplayStringLine(Line5,(uint8_t*)text);
		LCD_DisplayStringLine(Line2,(uint8_t*)"        ADC");
	}
}

void UART_Display()/*串口显示函数*/
{
	if(mode==3)
	{ 
		LCD_DisplayStringLine(Line4,(uint8_t*)text_rx);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)/*中断回调函数*/
{
	if(htim==&htim1)
	{
		Sec++;if(Sec>=60){Sec=0;Min++;if(Min>=60){Min=0;Hour++;if(Hour>=24){Hour=0;}}}
	}
}
