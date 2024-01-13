#include "stm32f4xx.h"
#include "systick.h"

void delay_nms(u32 t)//最大定时 798ms
{		
	u32 temp;	   
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); 	
	SysTick->LOAD=t*21000; 				//时间加载	  		 
	SysTick->VAL=0x00;        				//清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //开始倒数 	 
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; //关闭计数器
	SysTick->VAL =0X00;       				//清空计数器 
}

void delay_ms(u16 nms)//最大定时 65535ms  因为nms设置的是u16类型
{	 	 
	u8 repeat=nms/540;										
	u16 remain=nms%540;
	while(repeat)
	{
		delay_nms(540);
		repeat--;
	}
	if(remain)delay_nms(remain);
} 

