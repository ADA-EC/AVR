#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#define F_CPU 8000000L
ISR(TIMER1_OVF_vect) {
	PORTD ^= (1 << PD6) ;
}

int main() {
	DDRD |= _BV(PD6) ;

	OCR1A = 0x00 ;
	TCCR1A = 0x00 ;
	TCCR1B = (1 << CS11) | (1 << CS10) ;

	SREG |= 0x80 ;
	TIMSK1 |= 0x01 ;



	while (1) {

	}
	return 0 ;
}
