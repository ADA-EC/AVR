#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>


ISR(PCINT1_vect) {
	PORTD |= (1 << PD6) ;
}


int main() {
	DDRC &= ~(1 << PC1) ;
	PORTC |= (1 <<PC1) ;
	DDRD |= (1 << PD6) ;

	SREG |= 0x80 ;
	PCICR = (1 << PCIE1) ;
	PCMSK1 = (1 << PCINT9) ; 

	while (1) {
		PORTD &= ~(1 << PD6) ;
		_delay_ms(500) ;
	}
	return 0 ;
}
