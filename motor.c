#include <REGX52.H>

//定义每个轮子的状态

//定义轮子
sbit INA1 = P1^1;       //左
sbit INA2 = P1^2;
sbit INB1 = P1^3;       //右
sbit INB2 = P1^4;

//控制轮子状态
void L_motor_go ()       //左电机正转
{INA1 =0 ;INB2 =1 ;}
void L_motor_back ()     //左电机反转
{INA1 =1 ;INB2 =0 ;}
void L_motor_stop ()     //左电机停止
{INA1 = 0;INB2 = 0;}



void R_motor_go ()       //右电机正转
{INB1 =1 ;INB2 =0 ;}
void R_motor_back ()     //右电机反转
{INB1 =0 ;INB2 =1 ;}
void R_motor_stop ()     //右电机停止
{INB1 = 0;INB2 = 0;}
