#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

//Rotina das interrupções PCINT1
ISR(PCINT1_vect) {
	//Acende o LED na porta D6
	PORTD |= (1 << PD6) ;
}


int main() {
	//Configura PC1 como entrada (geradora da interrupção)
	DDRC &= ~(1 << PC1) ;

	//Configura D6 como saída
	DDRD |= (1 << PD6) ;

	//Habilita interrupções
	SREG |= 0x80 ;
	//Habilita a interrupção PCINT1
	PCICR = (1 << PCIE1) ;
	//Habilita interrupção PCINT9
	PCMSK1 = (1 << PCINT9) ; 

	while (1) {
		//Apaga o LED em D6 cada 1s
		PORTD &= ~(1 << PD6) ;
		_delay_ms(1000) ;
	}
	return 0 ;
}
