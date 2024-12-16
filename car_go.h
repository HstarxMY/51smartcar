#ifndef  __CAR_GO_H_
#define  __CAR_GO_H_

void car_go(int Lspeed,int Rspeed);  //小车向前直行
void car_back(int LS,int RS);       //小车向后，左轮速度，右轮速度
void car_stop();             //小车停止
void car_turn(int LS,int RS);        //小车转弯，向左转

#endif