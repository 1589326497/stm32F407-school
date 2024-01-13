#include "SEG_8.h"
#include "delay.h"
#define SEG_time  1000
uint8_t table1[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e
};//定义位选数组
void SEG_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能GPIOF时钟	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//普通输出模式
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//上拉
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//推挽输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//100MHz
	GPIO_Init(GPIOE,&GPIO_InitStructure);//初始化
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}

void SEG_display(int nu)	
{	
	GPIO_SetBits(GPIOE,GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);//位选第一个数码管
	t=seg_8[num];
	SEG_Data_Write(t);
}

