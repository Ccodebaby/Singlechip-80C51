#include <reg51.h>
#include "kid-51.c"

const char led[] = { _led0, _led1, _led2, _led3, _led4, _led5, _led6, _led7, _led8, _led9 };
char count = 0;

main() 
{
	P0 = P2 = _led0;
	TMOD = b("0000 0110");
	TH0 = TL0 = 0xff;
	EA = ET0 = 1;
	TR0 = 1;
	
	while( true );
}

t0() interrupt 1
{
	count++;
	if( count == 100 ) {
		count = 0;
	}

	P0 = led[ count / 10 ];
	P2 = led[ count % 10 ];
}