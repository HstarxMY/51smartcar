#include <REGX52.H>
#include "car_go.h"

unsigned char U_data;     //接受数据存放
unsigned char flag = 0;		//切换循迹模式 0为关闭 1为开启

void receive(unsigned char m)
{
	switch(m)
    {
        
        case  '2':      //前进
            car_go(40,45);
        break;
        
        case  '4':
            car_turn_L(40,45);    // 左转
        break;
        
        case  '6':
            car_turn_L(40,45);    // 右转
        break;
        
        case '8':
            car_back(40,45);   //  后退
        break;
        
        case '5':      // 停止
             car_stop();
        break;
		
		case '7':
			flag = 1;		//循迹模式开启
		break;
		
		case '9':		//循迹模式关闭
			flag = 0;
		break;
        
    }

}

void Timer1_Isr(void) interrupt 4
{
	car_stop();
    RI = 0;                  //清除接受中断标志位
    U_data = SBUF;                    //接受数据
    receive(U_data);
}

void Timer1_Init()		 //9600bps@11.0592MHz
{
	PCON = 0x00;		//关倍频
	SCON = 0x50;		//八位数据，可变波特率	
	TMOD = 0x20;		//设置定时器模式
	TL1 = 0xFd;			//设置定时器初始值
	TH1 = 0xFd;			//设置定时器初始值
	ET1 = 0;			//禁止定时器1中断
	TR1 = 1;			//定时器1开始计时
	EA = 1;				//总中断
	ES = 1;				//打开串口中断
}
