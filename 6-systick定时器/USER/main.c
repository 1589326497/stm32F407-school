/*
����systick��ʱ��ʵ����ʱʵ�� 1�������һ��λ�Ͷ���λ������

*/


#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
#include "SEG_8.h"
#include "led.h"
#include "timer.h"
extern mark;
int main(void)
{ 	 
	delay_init(168);
	SEG_Init();
	TIM3_init(1000-1,72-1);//��ʱ1��  ���ж����޸�mark
	while(1)
	{
		if(mark)
		{
			SEG_display(0,1);
			SEG_display(0,3);
		}
		else
		{
			SEG_display(0,2);
			SEG_display(0,4);
		}
		
		
	}
}
