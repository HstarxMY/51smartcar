#include <REGX52.H>
#include "car_go.h"
#include "trace.h"

unsigned char U_data;     //接受数据存放
unsigned char flag = 0;		//切换循迹模式 0为关闭 1为开启

void receive(unsigned char m)
{
	switch(m)
    {
        
        case  '1':      //前进
            car_go(40,45);
        break;
        
        case  'C':
            car_turn_L(40,45);    // 左转
        break;
        
        case  'D':
            car_turn_L(40,45);    // 右转
        break;
        
        case 'B':
            car_back(40,45);   //  后退
        break;
        
        case 'S':      // 停止
             car_stop();
        break;
		case 'T':
			flag = 1;		//循迹模式开启
		break;
		case 'F':		//循迹模式关闭
			flag = 0;
		break;
        
    }

}

void Timer1_Isr(void) interrupt 4
{
//	car_stop();
    RI = 0;                  //清除接受中断标志位
    U_data = SBUF;                    //接受数据
    receive(U_data);
}

void Timer1_Init(void)		 //9600bps@11.0592MHz
{
	PCON &= 0x7F;            //波特率不倍速
    SCON = 0x50;            //8位数据,可变波特率
//	AUXR &= 0xBF;            //定时器时钟12T模式
//	AUXR &= 0xFE;            //串口1选择定时器1为波特率发生器
    TMOD &= 0x0F;             //设置定时器模式
    TMOD |= 0x20;             //设置定时器模式
    TL1 = 0xFD;                //设置定时初始值
    TH1 = 0xFD;                //设置定时重载值
    ET1 = 0;                     //禁止定时器中断
    TR1 = 1;                  //定时器1开始计时
    EA  = 1;
    ES  = 1;

}
