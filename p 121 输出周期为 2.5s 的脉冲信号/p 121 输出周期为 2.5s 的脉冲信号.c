#include <reg51.h>
#include "kid-51.c"

unsigned char count = 0;

main()
{
    TMOD = b("0000 0001");
    TH0 = 0xd1, TL0 = 0x20;
    EA = ET0 = 1;
    TR0 = true;
    while( true );
}

t0() interrupt 1 
{
    TH0 = 0xd1, TL0 = 0x20;

    count++;
    if( count == 50 ) {
        P2 = 0; 
    } else if ( count == 250 ) {
        P2 = 1;
        count = 0;
    }
}