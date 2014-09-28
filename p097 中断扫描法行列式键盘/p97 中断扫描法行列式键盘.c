#include <reg51.h>
#include "kid-51.c"


char key[16];
char led[] = {
	_led0, _led1, _led2, _led3,
	_led4, _led5, _led6, _led7,
	_led8, _led9, _ledA, _ledB,
	_ledC, _ledD, _ledE, _ledF
};
char rows[] = { _B0, _B1, _B2, _B3 }; 


onkey() interrupt 0 
{
	char i, j;
	for( i = 0; i < 4; i++ ) {
		P2 = rows[i];
		for( j = 0; j < 16; j++ ) {
			if( P2 == key[j] ) {
				P0 = led[j];
				break;
	}}}
	P2 = 0x0f;
}


main() 
{
	key  [0] = b("1110 1110"), key  [1] = b("1101 1110"), key  [2] = b("1011 1110"), key  [3] = b("0111 1110"), 
	key  [4] = b("1110 1101"), key  [5] = b("1101 1101"), key  [6] = b("1011 1101"), key  [7] = b("0111 1101"), 
	key  [8] = b("1110 1011"), key  [9] = b("1101 1011"), key [10] = b("1011 1011"), key [11] = b("0111 1011"), 
	key [12] = b("1110 0111"), key [13] = b("1101 0111"), key [14] = b("1011 0111"), key [15] = b("0111 0111");

	P0 = 0x00;
	IT0 = 1;
	EX0 = 1;
	EA = 1;

	P2 = 0x0f;

	while( true );
}