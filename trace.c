#include <REGX52.H>
#include "car_go.h"
#include "Delay_ms.h"

sbit left1  = ;     //10000
sbit left2  = ;     //01000
sbit mid3   = ;     //00100
sbit right4 = ;     //00010
sbit right5 = ;     //00001

sbit tracekey = ;		//循迹按键

unsigned char xjxs = 0 ;     //循迹行驶

void traceline()
{
	if ((left1==0)&&(left2==0)&&(mid3==1)&&(right4==0)&&(right5==0))        //00100
    {
        xjxs = 1;
    }else if ((left1==0)&&(left2==1)&&(mid3==0)&&(right4==0)&&(right5==0))  //01000
    {
        xjxs = 2;
    }else if ((left1==0)&&(left2==0)&&(mid3==0)&&(right4==1)&&(right5==0))  //00010
    {
        xjxs = 3;
    }else if ((left1==1)&&(left2==0)&&(mid3==0)&&(right4==0)&&(right5==0))  //10000
    {
        xjxs = 4;
    }else if ((left1==0)&&(left2==0)&&(mid3==0)&&(right4==0)&&(right5==1))  //00001
    {
        xjxs = 5;
    }else if ((left1==1)&&(left2==1)&&(right5==0))      //11xx0
    {
        xjxs = 6;
    }else if ((left1==0)&&(right4==1)&&(right5==1))     //0xx11
    {
        xjxs = 7;
    }else if ((left1==1)&&(left2==1)&&(mid3==1)&&(right4==1)&&(right5==0))  //11110
    {
        xjxs = 8;
    }else if ((left1==0)&&(left2==1)&&(mid3==1)&&(right4==1)&&(right5==1))  //01111
    {
        xjxs = 8;
    }else if ((left1==1)&&(left2==1)&&(mid3==1)&&(right4==1)&&(right5==1))  //11111
    {
        xjxs = 8;
    }else if ((left1==0)&&(left2==0)&&(mid3==0)&&(right4==0)&&(right5==0))  //00000
    {
        xjxs = 9;
    }
    
    
    
    
    
  

    switch(xjxs)
    {
        case 1 : car_go();break;
        case 2 : car_go();break;
        case 3 : car_go();break;
        case 4 : car_go();while (1)
        {
            if (mid3==1)break;
        }
        break;
        case 5 : car_go();while (1)
        {
            if (mid3==1)break;
        }
        break;
        case 6 : car_go();while (1)
        {
            if (mid3==1)break;
        }
        break;
        case 7 : car_go();while (1)
        {
            if (mid3==1)break;
        }
        break;
        case 8 : car_stop();Delay_ms(1);car_go();Delay_ms(1000);car_stop();Delay_ms(1000);car_turn();while(1)
        {
            if (mid3==1)break;
        }break;
        case 9 : car_go();break;
    }
}