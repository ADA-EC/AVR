/*
	timer.c
	Autor: Guilherme Prearo
	Função: Pisca o LED em D6 com um período de aproximadamente 1s
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

//Rotina de interrupção de overflow do Timer 1
ISR(TIMER1_OVF_vect) {
	//Pisca um LED em D6
	PORTD ^= (1 << PD6) ;
}

int main() {
	//Configura D6 como saída
	DDRD |= _BV(PD6) ;

	//Configra o modo
	TCCR1A = 0x00 ;
	//Configura o divisor de frequência
	TCCR1B = (1 << CS11) | (1 << CS10) ;

	//Habilita interrupções
	SREG |= 0x80 ;
	//Habilita interrupção Timer 1 Overflow
	TIMSK1 |= 0x01 ;


	while (1) {

	}
	return 0 ;
}
