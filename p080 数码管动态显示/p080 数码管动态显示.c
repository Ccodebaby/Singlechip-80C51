#include <reg51.h>
#include "kid-51.c"

void main() {
	while( true ) {
		P3 = b1;
		P2 = _ledL;
		delay( 1 );
		P3 = b0;
		P2 = _led2;
		delay( 1 );
	}
}