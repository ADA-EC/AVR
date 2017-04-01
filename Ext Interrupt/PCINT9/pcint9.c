#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

//Rotina das interrupções PCINT1
ISR(PCINT1_vect) {
	//Desabilita interrupções
	SREG &= ~(0x80) ;

	//Testa se foi borda de subida de um sinal
	if (PINC & (1 << PINC1)) {
		//Muda o estado da porta D6
		PORTD ^= (1 << PD6) ;
		//Debouncing
		_delay_ms(300) ;
	}

	//Habilita novamente as interrupções
	SREG |= 0x80 ;
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
	}
	return 0 ;
}
