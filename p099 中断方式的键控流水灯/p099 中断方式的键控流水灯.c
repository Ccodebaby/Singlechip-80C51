#include <reg51.h>
#include "kid-51.c"


char led[] = { _B0, _B1, _B2, _B3 };
bit run = false;
// 0 - down
// 1 - up
bit dir;


main() 
{
	char i;

	IT0 = 1, EX0 = 1, EA = 1;

	while( true ) 
	{
		if( run ) 
		{
			if( dir ) {
				for( i = 3; i >= 0; i-- ) {
					P2 = led[i];
					delay( 20 );
				}
			} else {
				for( i = 0; i < 4; i++ ) {
					P2 = led[i];
					delay( 20 );
				}
			}

		} else {
			P2 = 0;
		}
	}
}


onkey() interrupt 0 
{
	switch( P0 & 0x0f ) {
		case _b0: run = 1, dir = 1; break;
		case _b1: run = 0; break;
		case _b2: dir = 0; break;
		case _b3: dir = 1; break; 
	}
}