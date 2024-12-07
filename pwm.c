#include <REGX52.H>

//定时器和中断控制使能，实现pwm调速

unsigned char counter,speed;        //定义周期计数和小车速度

sbit EN1A = ;       //左前轮使能
sbit EN1B = ;       //右前轮使能
sbit EN2A = ;       //左后轮使能
sbit EN2B = ;       //右后轮使能

void Timer0_Init()		//100微秒@11.0592MHz
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

void Timer0_Isr() interrupt 1	//中断函数
{
	TL0 = 0xA4;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
    
	counter++;
	if(counter >=100)       //一个周期
	{
		counter = 0;		
	}
	if(counter <= speed)	//控制使能开关
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

