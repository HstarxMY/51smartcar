#include <REGX52.H>
#include "pwm.h"
#include "car_go.h"

void main()
{

	Timer0_Init();

	while (1)
	{
		car_go(20,25);
	}

}