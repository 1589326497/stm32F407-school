/*

KEY0:进入时间校准模式
KEY1:增加数码管数值
KEY2:保存数据并退出
KEY_UP:位选数码管

按下按键KEY0，进入时间校准模式，数码管上显示四个零，
按下按键KEY1(进入时间校准模式时默认位选最右边数码管),
最右边数码管数值加一，按下KEY_UP键，位选右边第二位数
码管，按下KEY2按键，将数值保存并退出。

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
	TIM3_init(20-1,8400-1);//定时2毫秒  在中断中刷新数码管
	My_RTC_Init();		 		//初始化RTC
	
	while(1)
	{		
		if(KEY_SCAN() == 1)
			KeyDeal();	  //时间校准函数
		delay_ms(5);
	}
	
}
