//延迟20微秒级函数
//直接给函数赋值本来的数字处于二十即可使用
#include <intrins.h>

void Delay_us(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i;

	while (xms)
	{
		_nop_();
		i = 6;
		while (--i);
	}
	
	xms--;
}