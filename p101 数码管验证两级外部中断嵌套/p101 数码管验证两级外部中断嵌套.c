#include <reg51.h>
#include "kid-51.c"

show( unsigned char port );

char led[] = { _led0, _led1, _led2, _led3, _led4, _led5, _led6, _led7, _led8, _led9, _led_ };
sbit small_led = P3^0;


main() 
{
	small_led = 0;
	P0 = P1 = P2 = _led_;  // show '-'
	IT0 = IT1 = 1;  // 脉冲触发
	PX0 = 0; PX1 = 1;  // 优先级：int1 > int2
	EX0 = EX1 = EA = 1;  // 开中断
	while( true ) {
		show( 0 );
	}
}


int0() interrupt 0
{
	small_led = IE0;
	show( 2 );
}


int1() interrupt 2 
{
	small_led = IE0;
	show( 1 );
}


// show led '0' ~ '9', end with '-' 
// port - 'P1' | 'P2' | 'P3'
show( char port )
{
	char i;
	for( i = 0; i < 11; i++ ) {
		if( port == 0 ) P0 = led[i];
		else if( port == 1 ) P1 = led[i];
		else if( port == 2 ) P2 = led[i];
		delay( 50 );
	}
}