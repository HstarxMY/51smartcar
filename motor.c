#include <REGX52.H>

//定义每个轮子的状态

//定义轮子
sbit IN11 = ;       //左前
sbit IN12 = ;
sbit IN13 = ;       //右前
sbit IN14 = ;
sbit IN21 = ;       //左后
sbit IN22 = ;
sbit IN23 = ;       //右后
sbit IN24 = ;

//控制轮子状态
void LF_motor_go ()       //左前电机正转
{IN11 = ;IN12 = ;}
void LF_motor_back ()     //左前电机反转
{IN11 = ;IN12 = ;}
void LF_motor_stop ()     //左前电机停止
{IN11 = 0;IN12 = 0;}

void RF_motor_go ()       //右前电机正转
{IN13 = ;IN14 = ;}
void RF_motor_back ()     //右前电机反转
{IN13 = ;IN14 = ;}
void RF_motor_stop ()     //右前电机停止
{IN13 = 0;IN14 = 0;}


void LR_motor_go ()       //左后电机正转
{IN21 = ;IN22 = ;}
void LR_motor_back ()     //左后电机反转
{IN21 = ;IN22 = ;}
void LR_motor_stop ()     //左后电机停止
{IN21 = 0;IN22 = 0;}

void RR_motor_go ()       //右后电机正转
{IN23 = ;IN24 = ;}
void RR_motor_back ()     //右后电机反转
{IN23 = ;IN24 = ;}
void RR_motor_stop ()     //右后电机停止
{IN23 = 0;IN24 = 0;}