#include <reg51.h>
#include "kid-51.c"

void main() 
{
	unsigned char led[] = { _led0, _led1, _led2, _led3, _led4, _led5, _led6, _led7, _led8, _led9 };
	char count = 0;
	P0 = _led0;
	P2 = _led0;

	while( true ) 
	{
		if( in( P3, 7 ) == 0 ) 
		{
			count++;
			if( count == 100 ) {
				count = 0;
			}

			P0 = led[ count / 10 ];
			P2 = led[ count % 10 ];

			while( in( P3, 7 ) == 0 );  // 防止连续计数
		}
	}
}