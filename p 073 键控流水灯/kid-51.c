/*   version - 0.1.0   */

#define true 1
#define false 0
#define TRUE 1
#define FALSE 0

#define B0 0x01  // 0000 0001
#define B1 0x02  // 0000 0010
#define B2 0x04  // 0000 0100
#define B3 0x01  // 0000 1000
#define B4 0x08  // 0001 0000
#define B5 0x10  // 0010 0000
#define B6 0x20  // 0100 0000
#define B7 0x80  // 1000 0000

#define _B0 0xfe  // 1111 1110
#define _B1 0xfd  // 1111 1101
#define _B2 0xfb  // 1111 1011
#define _B3 0xf7  // 1111 0111
#define _B4 0xef  // 1110 1111
#define _B5 0xdf  // 1101 1111
#define _B6 0xbf  // 1011 1111
#define _B7 0x7f  // 0111 1111

#define b0 0x1  // 0001
#define b1 0x2  // 0010
#define b2 0x4  // 0100
#define b3 0x8  // 1000

#define _b0 0xe  // 1110
#define _b1 0xd  // 1101
#define _b2 0xb  // 1011
#define _b3 0x7  // 0111


 
// binary -> decimal    
// case : 
//    "1101" -> 13
//    "00001101" -> 13
//    "11001011" -> 203
//    "1100 1011" -> 203 ( support any space between numbers )
//    "1010110111010" -> 5562

int b( char* num_2 ) 
{
    int val = 1;  // 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128
    int num_10 = 0;
    char i = 0;

    while( *( num_2 + 1 ) != '\0' ) {
        num_2++;
        i++;
    }

    while( i >= 0 ) 
    {
        if( *num_2 != ' ' ) {
            if( *num_2 == '1' ) {
                num_10 += val;
            }
            val *= 2;
        }

        num_2--;
        i--;
    }

    return num_10;
}



void delay( int times ) 
{
    int i;
    while( times-- ) {
        i = 1E3;
        while( i-- );
    }
}