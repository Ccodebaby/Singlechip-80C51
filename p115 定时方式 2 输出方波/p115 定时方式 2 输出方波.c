#include <reg51.h>
#include "kid-51.c"


sbit P2_0 = P2^0;


main() 
{
	TMOD = b("0000 0010");
	TH0 = TL0 = 0x06;
	EA = ET0 = 1;
	TR0 = 1;

	while( true );
}


t0() interrupt 1
{
	P2_0 = !P2_0;
}