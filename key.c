#include "key.h"
static unsigned char mode,TX_s;
static char buf[50];
static char length;
static	int rx_s=0;
extern uint8_t Sec,Min,Hour,pwm6_duty,pwm7_duty,rx,xx[20];
extern uint frp1,frp2;
void KEY_Set()/*按键触发操作函数*/
{	
	static uint8_t key1_s,key2_s,key3_s,key4_s;
	if(key1==0){HAL_Delay(10);key1_s=1;}if(key1==1&&key1_s==1){key1_s=0;mode++,LCD_Clear(White);if(mode>4)mode=0;}
	if(key2==0&&mode==2){HAL_Delay(10);key2_s=1;}if(key2==1&&key2_s==1){key2_s=0;pwm6_duty+=10;if(pwm6_duty>=100)pwm6_duty=10;}
	if(key3==0&&mode==2){HAL_Delay(10);key3_s=1;}if(key3==1&&key3_s==1){key3_s=0;pwm7_duty+=10;if(pwm7_duty>=100)pwm7_duty=10;}
	if(key4==0){HAL_Delay(10);key4_s=1;}if(key4==1&&key4_s==1){key4_s=0;TX_s=1;}
}

void TIM_Display()/*定时器显示函数*/
{
	if(mode==0)
	{
		LCD_DisplayStringLine(Line2,(unsigned char*)"        Time");
		LCD_DisplayStringLine(Line3,(unsigned char*)"        ****");
		LCD_DisplayChar(Line5,320-(16*6),Hour/10+48);
		LCD_DisplayChar(Line5,320-(16*7),Hour%10+48);
		LCD_DisplayChar(Line5,320-(16*8),':');
		LCD_DisplayChar(Line5,320-(16*9),Min/10+48);
		LCD_DisplayChar(Line5,320-(16*10),Min%10+48);
		LCD_DisplayChar(Line5,320-(16*11),':');
		LCD_DisplayChar(Line5,320-(16*12),Sec/10+48);
		LCD_DisplayChar(Line5,320-(16*13),Sec%10+48);
	}
}

void ADC_Display()/*ADC显示函数*/
{
	if(mode==1)
	{
		static double value,value1;
		static char text[20];
		sprintf(text,"        ADC");
		LCD_DisplayStringLine(Line2,(unsigned char*)text);
		value=Get_adc1();
		sprintf(text,"      V=%.2fV",value*3.3/4096);
		LCD_DisplayStringLine(Line4,(unsigned char *)text);
		value1=Get_adc2();
		sprintf(text,"      V=%.2fV",value1*3.3/4096);
		LCD_DisplayStringLine(Line6,(unsigned char *)text);
	}
}	

void PWM_Display()/*PWM显示函数*/
{	
	static char text[20];
	if(mode==2)
	{
		LCD_DisplayStringLine(Line2,(unsigned char *)"        PWM");
		sprintf(text,"      PA6=%d%%   ",pwm6_duty);
		LCD_DisplayStringLine(Line4,(unsigned char *)text);
		sprintf(text,"      PA7=%d%%   ",pwm7_duty);
		LCD_DisplayStringLine(Line6,(unsigned char *)text);
	}
}

void IC_Display()/*NE555输入捕获（频率采集）*/
{
	static char text[20];
	if(mode==3)
	{
		LCD_DisplayStringLine(Line2,(unsigned char *)"        IC");
		sprintf(text,"      frp1=%d      ",frp1);
		LCD_DisplayStringLine(Line4,(unsigned char *)text);
		sprintf(text,"      frp2=%d      ",frp2);
		LCD_DisplayStringLine(Line6,(unsigned char *)text);
	}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if(rx=='#'){rx_s=1;}
	if(rx_s==1&&rx!='#'&&rx!='@')
	{
		buf[length++]=rx;
	}
	if(rx=='@')
	{
		rx_s=0;
		if(mode==4)	
		LCD_DisplayStringLine(Line4,(uint8_t *)buf);
	}
	HAL_UART_Receive_IT(&huart1,&rx,1);
}


void UART_Tx()
{
		if(TX_s==1)
		{
			sprintf((char*)xx,"addadada\r\n");
			HAL_UART_Transmit_IT(&huart1,xx,sizeof(xx));
			TX_s=0;
		}
}

void LED_Display(unsigned char scanf)/*LED显示函数*/
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_All,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,scanf<<8,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
}


