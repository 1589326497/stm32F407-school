#include "SEG_8.h"
#define SEG_time  1000
uint8_t hash_table_8[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xAB,0xA3 
	};//��ѡ�����ŵ��������� 0-9 A-F o:0xA3 n:0xAB
u8 t;
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
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}

void SEG_display(u8 num,u8 n) //num��ѡ nλѡ
{	
	if(n==1)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_0);//λѡ��1�������
		
	}
	else if(n==2)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_1);//λѡ��2�������
		
	}
	else if(n==3)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_2);//λѡ��3�������
	}
	else if(n==4)
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_3);//λѡ��4�������
	}
	
	if(17>=num>=0)	//�ж�num��Χ�Ƿ���Ϊ��ϣ���±�
	{
		t=hash_table_8[num];
		SEG_Data_Write(t);
	}
	//��ն�ѡ��λѡ����λ
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	
}
//��������
void SEG_Clear(void)
{
	//��ն�ѡ��λѡ����λ
	GPIO_SetBits(GPIOE,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_SetBits(GPIOE,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 |  GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	
}

