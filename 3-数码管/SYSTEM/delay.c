#include "delay.h"
 
//��ʱ���������뼶��
void delay_ms(uint32_t nms)
{
	uint32_t tmp;
	while(nms--)
	{
		SysTick->LOAD = 168000000/8/1000;	//������ֵ����ʱ1ms
		SysTick->VAL = 0;					//��յ�ǰֵ
		SysTick->CTRL |= 0x1;				//��ʼ����
		do
		{
			tmp = SysTick->CTRL;			//��ȡCTRL״̬
		}while((tmp&0x1) && !(0x1<<16));
 
		SysTick->VAL = 0;					//��յ�ǰֵ
		SysTick->CTRL &= 0;					//�رռ���
	}
}
 
//��ʱ������΢�뼶��
void delay_us(uint32_t nus)
{
	uint32_t tmp;
	while(nus--)
	{
		SysTick->LOAD = 168000000/8/1000000;	//������ֵ����ʱ1us
		SysTick->VAL = 0;					//��յ�ǰֵ
		SysTick->CTRL |= 0x1;				//��ʼ����
		do
		{
			tmp = SysTick->CTRL;			//��ȡCTRL״̬
		}while((tmp&0x1) && !(0x1<<16));
 
		SysTick->VAL = 0;					//��յ�ǰֵ
		SysTick->CTRL &= 0;					//�رռ���
	}
 
}

