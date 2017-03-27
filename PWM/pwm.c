#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define TIME 250 

int main() {
	DDRD |= _BV(PD6) ;

	OCR0A = 0x00 ;
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00) ;
	TCCR0B = (1 << CS01) ;


	while (1) {
		OCR0A += 5 ;
		_delay_ms(20) ;

	}
	return 0 ;
}
