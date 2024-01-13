


#include "sys.h"
#include "CHECK.h"
#include "led.h"
#include "delay.h"
#include "SEG_8.h"
#include "key.h"

//保存按键值
static u8 m_check;	
static u8 m_key;
int main(void)
{
	CHECK_Init();
	delay_init(168);
	LED_Init();
	SEG_Init();
	while(1)
	{

		m_check=CHECK_Scan();
		m_key=KEY_SCAN();
		
		//显示矩阵键盘数值
		
		if(m_check)
		{
			SEG_display(m_check/(u8)10,(u8)1);
			SEG_display(m_check%(u8)10,(u8)2);
		}
		
//		if(m_check/10==0)	//m_check的值为个位数
//		{
//			SEG_display(m_check,1);
//			
//		}
//		else	//m_check的值为俩位数
//		{
//			SEG_display(1,1);
//			SEG_display(m_check%10,2);
//			
//		}
		
		//显示按键数值
//		switch(m_key)
//		{
//			case 1:
//				SEG_display(1,1);
//				SEG_display(6,2);
//			break;
//			case 2:
//				SEG_display(1,1);
//				SEG_display(7,2);
//			break;
//			case 3:
//				SEG_display(1,1);
//				SEG_display(8,2);
//			break;
//		}
		
		
		
	}
}
