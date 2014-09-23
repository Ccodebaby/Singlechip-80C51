#include <reg51.h>
#include "kid-51.c"

void main() 
{
	// negative pole
	char led[10] = { _led0, _led1, _led2, _led3, _led4, _led5, _led6, _led7, _led8, _led9 }; 

	char i;
	while( true ) 
	{
		for( i = 0; i < 10; i++ ) {
			P0 = led[i];
			delay( 20 );
		}
	}
}