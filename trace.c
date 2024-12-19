#include <REGX52.H>
#include "car_go.h"
#include "Delay_ms.h"

sbit LEFT1  = P3^3;     //10000
sbit LEFT2  = P3^4;     //01000
sbit MID3   = P3^5;     //00100
sbit RIGHT4 = P3^6;     //00010
sbit RIGHT5 = P3^7;     //00001

// tracekey = ;		//循迹按键

unsigned char xjxs = 0 ;     //循迹行驶

void traceline()
{
	if ((LEFT1==1)&&(LEFT2==1)&&(MID3==0)&&(RIGHT4==1)&&(RIGHT5==1))        //11011
    {
        xjxs = 1;
    }else if ((LEFT1==1)&&(LEFT2==0)&&(MID3==1)&&(RIGHT4==1)&&(RIGHT5==1))  //10111
    {
        xjxs = 2;
    }else if ((LEFT1==1)&&(LEFT2==1)&&(MID3==1)&&(RIGHT4==0)&&(RIGHT5==1))  //11101
    {
        xjxs = 3;
    }else if ((LEFT1==0)&&(LEFT2==1)&&(MID3==1)&&(RIGHT4==1)&&(RIGHT5==1))  //01111
    {
        xjxs = 4;
    }else if ((LEFT1==1)&&(LEFT2==1)&&(MID3==1)&&(RIGHT4==1)&&(RIGHT5==0))  //11110
    {
        xjxs = 5;
    }else if ((LEFT1==0)&&(LEFT2==0)&&(RIGHT5==1))      //00xx1
    {
        xjxs = 6;
    }else if ((LEFT1==1)&&(RIGHT4==0)&&(RIGHT5==0))     //1xx00
    {
        xjxs = 7;
    }else if ((LEFT1==0)&&(LEFT2==0)&&(MID3==0)&&(RIGHT4==0)&&(RIGHT5==1))  //00001
    {
        xjxs = 8;
    }else if ((LEFT1==1)&&(LEFT2==0)&&(MID3==0)&&(RIGHT4==0)&&(RIGHT5==1))  //00001
    {
        xjxs = 8;
    }else if ((LEFT1==0)&&(LEFT2==0)&&(MID3==0)&&(RIGHT4==0)&&(RIGHT5==0))  //00000
    {
        xjxs = 8;
    }else if ((LEFT1==1)&&(LEFT2==1)&&(MID3==1)&&(RIGHT4==1)&&(RIGHT5==1))  //11111
    {
        xjxs = 9;
    }
    
    
    
    
    
  

    switch(xjxs)
    {
        case 1 : car_go(20,25);break;
        case 2 : car_go(20,35);break;
        case 3 : car_go(35,25);break;
        case 4 : car_go(20,60);while (1)
        {
            if (MID3==1)break;
        }
        break;
        case 5 : car_go(60,25);while (1)
        {
            if (MID3==1)break;
        }
        break;
        case 6 : car_go(0,100);while (1)
        {
            if (MID3==1)break;
        }
        break;
        case 7 : car_go(100,0);while (1)
        {
            if (MID3==1)break;
        }
        break;
        case 8 : car_stop();Delay_ms(1);car_go(0,0);Delay_ms(1000);car_stop();Delay_ms(1000);car_turn_L(0,0);while(1)
        {
            if (MID3==1)break;
        }break;
        case 9 : car_go(0,0);break;
    }
}