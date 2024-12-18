#include <REGX52.H>
#include "pwm.h"
#include "motor.h"

//定义小车的各种行驶状态

void car_go(int LS,int RS)       //小车向前，左轮速度，右轮速度
{
	Lspeed = LS;
	Rspeed = RS;
	L_motor_go ();
	R_motor_go ();
}

void car_back(int LS,int RS)       //小车向后，左轮速度，右轮速度
{
	Lspeed = LS;
	Rspeed = RS;
	L_motor_back ();
	R_motor_back ();
}

void car_turn_L(int LS,int RS)		//小车转弯，向左转
{
	Lspeed = LS;
	Rspeed = RS;
	L_motor_back();
	R_motor_go();
}

void car_turn_R(int LS,int RS)		//小车转弯，向右转
{
	Lspeed = LS;
	Rspeed = RS;
	L_motor_go();
	R_motor_back();
}

void car_stop()             //小车停止
{
    L_motor_stop();
    R_motor_stop();
}