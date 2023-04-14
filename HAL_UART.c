#include "HAL_UART.h"
extern uint8_t pwm6_duty,pwm7_duty,mode;
uint8_t text_rx[20],data_rx;
static uint8_t flag;
void UART_Tx()/*串口发送函数*/
{
		
    static uint8_t text_s[20];
    sprintf((char*)text_s,"PA=%d%%\n\t",pwm6_duty);
    HAL_UART_Transmit(&huart1,(uint8_t*)text_s,sizeof(text_s),50);
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)/*串口中断接收回调函数*/
{
			HAL_UART_Receive_IT(&huart1,&data_rx,1);
			text_rx[flag++]=data_rx;
}
