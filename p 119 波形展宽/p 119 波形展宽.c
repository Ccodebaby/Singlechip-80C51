#include <reg51.h>
#include "kid-51.c"

sbit P3_0 = P3^0;

main() 
{
    TMOD = 0x06;
    TL0 = 0xff;
    TR0 = true;

    while(1) 
    {
        while( !TF0 );

        TF0 = false;
        TMOD = 0x02;
        TL0 = 0x06;
        P3_0 = 0;

        while( !TF0 );
        
        TF0 = false;
        TMOD = 0x06;
        TL0 = 0xff;
        P3_0 = 1;
    }
}