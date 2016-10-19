#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define TIME 1000 

int main() {
	DDRB |= _BV(DDB5) ;

	while (1) {
		PORTB |= _BV(PORTB5) ;
		_delay_ms(TIME) ;

		PORTB &= ~_BV(PORTB5);
		_delay_ms(TIME) ;
	}
	return 0 ;
}
