void Delay_us(void)	//@12.000MHz  20us
{
	unsigned char data i;

	_nop_();
	i = 7;
	while (--i);
}
