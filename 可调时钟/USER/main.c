/*

KEY0:����ʱ��У׼ģʽ
KEY1:�����������ֵ
KEY2:�������ݲ��˳�
KEY_UP:λѡ�����

���°���KEY0������ʱ��У׼ģʽ�����������ʾ�ĸ��㣬
���°���KEY1(����ʱ��У׼ģʽʱĬ��λѡ���ұ������),
���ұ��������ֵ��һ������KEY_UP����λѡ�ұߵڶ�λ��
��ܣ�����KEY2����������ֵ���沢�˳���

*/

#include "SEG_8.h"
#include "sys.h"
#include "delay.h"
#include "timer.h"
#include "rtc.h"
#include "key.h"


int main(void)
{
	
	delay_init(168);
	SEG_Init();
	KEY_Init();
	TIM3_init(20-1,8400-1);//��ʱ2����  ���ж���ˢ�������
	My_RTC_Init();		 		//��ʼ��RTC
	
	while(1)
	{		
		if(KEY_SCAN() == 1)
			KeyDeal();	  //ʱ��У׼����
		delay_ms(5);
	}
	
}
