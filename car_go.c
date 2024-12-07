#include <REGX52.H>
#include "motor.h"

//定义小车的各种行驶状态

void car_go()       //小车向前直行
{
    speed = 20;
    LF_motor_go();
    RF_motor_go();
    LR_motor_go();
    RR_motor_go();
}

void car_back()       //小车向后直行
{
    speed = 18;
    LF_motor_back();
    RF_motor_back();
    LR_motor_back();
    RR_motor_back();
}

void car_leftgo()       //小车前左拐弯
{
    speed = 18;
    LF_motor_stop();
    LR_motor_stop();
    RF_motor_go();
    RR_motor_go();
}

void car_rightgo()       //小车前右拐弯
{
    speed = 18;
    RF_motor_stop();
    RR_motor_stop();
    LF_motor_go();
    LR_motor_go();
}

void car_leftback()       //小车后左拐弯
{
    speed = 18;
    LF_motor_stop();
    LR_motor_stop();
    RF_motor_back();
    RR_motor_back();
}

void car_rightback()       //小车后右拐弯
{
    speed = 18;
    RF_motor_stop();
    RR_motor_stop();
    LF_motor_back();
    LR_motor_back();
}

void car_leftstop()        //小车原地左拐
{
    speed = 20;
    RF_motor_go();
    RR_motor_go();
    LF_motor_back();
    LR_motor_back();
}

void car_rightstop()        //小车原地右拐
{
    speed = 20;
    RF_motor_back();
    RR_motor_back();
    LF_motor_go();
    LR_motor_go();
}

void car_stop()             //小车停止
{
    LF_motor_stop();
    LR_motor_stop();
    RF_motor_stop();
    RR_motor_stop();
}