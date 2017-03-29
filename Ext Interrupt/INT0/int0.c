#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#define TIME 250 


ISR(INT0_vect) {
	PORTD |= (1 << PD6) ;
}


int main() {
	DDRD &= ~(1 << PD2) ;
	PORTD |= (1 <<PD2) ;
	DDRD |= (1 << PD6) ;

	SREG |= 0x80 ;
	EICRA = 0x03 ;
	EIMSK = 0x01 ; 


	while (1) {
		PORTD &= ~(1 << PD6) ;
		_delay_ms(500) ;
	}
	return 0 ;
}
