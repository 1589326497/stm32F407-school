/*
8λ����� ��λѡ�͵�ƽ��Ч
					��ѡ�͵�ƽ��Ч �ߵ�ƽϨ��
*/
#include "CHECK.h"
#include "SEG_8.h"
#include "delay.h"
u8 seg_8[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
u8 t;
int num;
void SEG_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//ʹ��GPIOFʱ��
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;//��ͨ���ģʽ
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;//����
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;//100MHz
	GPIO_Init(GPIOE,&GPIO_InitStructure);//��ʼ��
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	
}

void SEG_display(u8 num,u8 n) //num��ѡ nλѡ
{	
	if(n==1)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_0);//λѡ��1�������
		
		
	}
	else if(n==2)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_1);//λѡ��1�������
	}
	else
	{
		
	}
	t=seg_8[num];
	SEG_Data_Write(t);
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	
//	num++;
//	delay_ms(500);
//	if(num==16) num=0;
}

