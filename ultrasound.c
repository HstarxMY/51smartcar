#include <REGX52.H>
#include "intrins.h"
#include "car_go.h"
#include "Delay_ms.h"
#include "Delay_us.h"

sbit Trig = P2^1;  //超声波测距发射端位点
sbit Echo = P2^2;  //超声波测距接收端位点

unsigned int sum;	 // 
unsigned int mindistance = 20; 

void ultrasound ()  //超声波测距程序
{
	
//  T2MOD = 0;			//初始化模式寄存器	
//  T2CON = 0;      //初始化控制寄存器 
//  TL2 = 0;   			//设置定时初始值
//  TH2 = 0;				//设置定时初始值
//  RCAP2L = 0;			//设置定时重载值
//  RCAP2H = 0;     //设置定时重载值

		TMOD = 0x11;   //设置定时器模式
	  TL1 = 0;   			//设置定时初始值
		TH1 = 0;				//设置定时初始值
	
	  Trig = 1;      //发射一段脉冲 至少20us
		Delay_us();     //延时20us
		Trig = 0;       //关闭脉冲
	
		while(!Echo);   //等待超声波模块返回脉冲
		TR1 = 1;				//打开定时器
		while(Echo);		//等待超声波模块返回脉冲结束
		TR1 = 0; 				//停止定时器 计时结束
	
		sum = ((TH1*256+TL1)*0.034)/2+1;  //计算距离
	
	  if(mindistance > sum)
		{
			car_stop ();
			Delay_ms(1000);
		}
}