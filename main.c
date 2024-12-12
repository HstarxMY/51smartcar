#include <REGX52.H>
#include "pwm.h"
#include "car_go.h"
#include "Delay_ms.h"
#include "trace.h"

bit flag1=0;		//循迹控制🚩
bit flag2=0;		//蓝牙控制🚩

void main()
{
	Timer0_Init();		//初始化时钟0，控制pwm调速

	while(1)
	{	
		//自动避障行驶--逻辑
		car_go(20,25);		//笔直前行
		
		//蓝牙控制开启循迹
		if(tracekey = 0)
		{
			Delay_ms(10);
			flag1 = 1;
			car_stop();
			Delay_ms(1000);
		}
		//蓝牙控制行驶状态
		
		
		//黑线循迹逻辑
		if(flag1 = 1)
		{
			traceline();
		}
		
		//蓝牙控制逻辑
		
		
	}

}