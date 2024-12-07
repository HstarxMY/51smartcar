#include <REGX52.H>

//定时器和中断实现pwm调速

void Timer0_Isr(void) interrupt 1	//中断函数
{
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	compare = 20;			//调速开启使能时间比较变量
	counter++;
	if(counter >=100)       //一个周期
	{
		counter = 0;		
	}
	if(counter <= compare)	//控制使能开关
	{
		EN1A = 1;
		EN2A = 1;
		EN1B = 1;
		EN2B = 1;
	}else
	{
		EN1A = 0;
		EN2A = 0;
		EN1B = 0;
		EN2B = 0;
	}
}

void Timer0_Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
	EA = 1;					//定时器总开关
	PT0 = 0;				//定时器0中断优先级
}
