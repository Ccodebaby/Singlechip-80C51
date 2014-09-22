#include <reg51.h>
#include "kid-51.c"

void main() 
{
    bit run = false;

    // 0 = down
    // 1 = up
    bit dir = 1;

    unsigned char LED[4] = { _B0, _B1, _B2, _B3 };
    int i;

    while( true ) 
    {
        int k = P0 & 0x0f;

        switch( k ) {
            case _b0:
                run = true; break;
            case _b1:
                run = false; break;
            case _b2:
                dir = 0; break;
            case _b3:
                dir = 1; break;
        }

        if( run ) {

            if( dir ) {
                for( i = 3; i >= 0; i-- ) {
                    P2 = LED[i];
                    delay( 30 );
                }
            } else {
                for( i = 0; i <= 3; i++ ) {
                    P2 = LED[i];
                    delay( 30 );
                }
            }
            
        } else {
            P2 = 0xff;
        }
    }
}