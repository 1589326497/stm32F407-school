#include "CHECK.h"
#include "sys.h"
#include "delay.h"
#include "SEG_8.h"

u8 temp,key;
void CHECK_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��Ϊ���ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��Ϊ����ģʽ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

u8 CHECK_Scan(void)
{
	KEY_Data_Write(0xfe) //ɨ���һ��
  temp=KEY_Data_Read;
  temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay_ms(10);
		if(temp!=0xf0)
		{
			temp=KEY_Data_Read;
			switch(temp)
			{
				case 0xee: key=0;break;
				case 0xde: key=1;break; 
				case 0xbe: key=2;break;   
				case 0x7e: key=3;break;
			}
				while(temp != 0xf0)
				{
					temp=KEY_Data_Read;
					temp=temp&0xf0;
				}
					
	  }
	}
		KEY_Data_Write(0xfd) //ɨ��ڶ���
  temp=KEY_Data_Read;
  temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay_ms(10);
		if(temp!=0xf0)
		{
			temp=KEY_Data_Read;
			switch(temp)
			{
				case 0xed: key=4;break;
				case 0xdd: key=5;break; 
				case 0xbd: key=6;break;   
				case 0x7d: key=7;break;
			}
			while(temp != 0xf0)
				{
					temp=KEY_Data_Read;
					temp=temp&0xf0;
				}
					
	  }
	}
		KEY_Data_Write(0xfb) //ɨ�������
  temp=KEY_Data_Read;
  temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay_ms(10);
		if(temp!=0xf0)
		{
			temp=KEY_Data_Read;
			switch(temp)
			{
				case 0xeb: key=8;break;
				case 0xdb: key=9;break; 
				case 0xbb: key=10;break;   
				case 0x7b: key=11;break;
			}
			while(temp != 0xf0)
				{
					temp=KEY_Data_Read;
					temp=temp&0xf0;
				}
					
					
	  }
	}
	
		KEY_Data_Write(0xf7) //ɨ�������
  temp=KEY_Data_Read;
  temp=temp&0xf0;
	if(temp!=0xf0)
	{
		delay_ms(10);
		if(temp!=0xf0)
		{
			temp=KEY_Data_Read;
			switch(temp)
			{
				case 0xe7: key=12;break;
				case 0xd7: key=13;break; 
				case 0xb7: key=14;break;   
				case 0x77: key=15;break;
			}
			while(temp != 0xf0)
				{
					temp=KEY_Data_Read;
					temp=temp&0xf0;
				}
					
	  }
		
	}
	return key;
}

