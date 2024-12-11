#include <REGX52.H>

//定时器和中断控制使能，实现pwm调速

unsigned char l,r,Lspeed,Rspeed;        //定义周期计数和小车速度

sbit ENA = P1^0;       //左轮使能
sbit ENB = P1^5;       //右轮使能

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
    
	l++;
	r++;
	
	if(l <= Lspeed)	//控制左轮使能开关
	{
		ENA = 1;
	}else
	{
		ENA = 0;
	}
	if(r <= Rspeed)	//控制右轮使能开关
	{
		ENB = 1;
	}else
	{
		ENB = 0;
	}
	
	if(l >=100)       //一个l周期
	{
		l = 0;		
	}
	if(r >=100)       //一个r周期
	{
		r = 0;		
	}

}

