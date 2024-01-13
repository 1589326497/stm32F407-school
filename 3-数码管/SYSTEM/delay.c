#include "delay.h"
 
//延时函数：毫秒级别
void delay_ms(uint32_t nms)
{
	uint32_t tmp;
	while(nms--)
	{
		SysTick->LOAD = 168000000/8/1000;	//计数初值，延时1ms
		SysTick->VAL = 0;					//清空当前值
		SysTick->CTRL |= 0x1;				//开始计数
		do
		{
			tmp = SysTick->CTRL;			//获取CTRL状态
		}while((tmp&0x1) && !(0x1<<16));
 
		SysTick->VAL = 0;					//清空当前值
		SysTick->CTRL &= 0;					//关闭计数
	}
}
 
//延时函数：微秒级别
void delay_us(uint32_t nus)
{
	uint32_t tmp;
	while(nus--)
	{
		SysTick->LOAD = 168000000/8/1000000;	//计数初值，延时1us
		SysTick->VAL = 0;					//清空当前值
		SysTick->CTRL |= 0x1;				//开始计数
		do
		{
			tmp = SysTick->CTRL;			//获取CTRL状态
		}while((tmp&0x1) && !(0x1<<16));
 
		SysTick->VAL = 0;					//清空当前值
		SysTick->CTRL &= 0;					//关闭计数
	}
 
}

