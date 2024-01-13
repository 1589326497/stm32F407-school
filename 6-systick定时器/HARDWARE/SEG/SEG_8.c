#include "SEG_8.h"
#define SEG_time  1000
uint8_t hash_table_8[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xAB,0xA3 
	};//段选编码存放的数组容器 0-9 A-F o:0xA3 n:0xAB
u8 t;
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

void SEG_display(u8 num,u8 n) //num段选 n位选
{	
	if(n==1)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_0);//位选第1个数码管
		
	}
	else if(n==2)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_1);//位选第2个数码管
		
	}
	else if(n==3)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_2);//位选第3个数码管
	}
	else if(n==4)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_3);//位选第4个数码管
	}
	
	if(17>=num>=0)	//判断num范围是否在为哈希表下标
	{
		t=hash_table_8[num];
		SEG_Data_Write(t);
	}
	//清空段选，位选所有位
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	
}
//清空数码管
void SEG_Clear(void)
{
	//清空段选，位选所有位
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	
}

