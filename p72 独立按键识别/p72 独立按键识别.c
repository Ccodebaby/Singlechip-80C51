#include <reg51.h>

void main() 
{
    char key = 0;
    while(1) 
    {
        key = P0 & 0x0f;
        if( key != 0x0f ) {
            P2 = key;
        }
    }
}