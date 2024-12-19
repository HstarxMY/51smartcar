#include <REGX52.H>
#include "pwm.h"
#include "car_go.h"
#include "Delay_ms.h"
#include "trace.h"
#include "bluetooth.h"

void main()
{
	Timer0_Init();		//初始化时钟0，控制pwm调速
	Timer1_Init();		//初始化时钟1，控制蓝牙接收
	while(1)
	{	
		
		control();
		
//		car_go(40,45);
		
//		if(flag == 1)
//		{
//			traceline();
//		}
		
	}	
}