#include <avr/io.h>
//Biblioteca para utilizar as rotinas de interrupção
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

//Rotina da interrupção INT0
ISR(INT0_vect) {
	//Desabilita interrupções
	SREG &= ~(0x80) ;		
	//Muda o estado da porta D6
	PORTD ^= (1 << PD6) ;
	//Debouncing
	_delay_ms(300) ;
	//Habilita novamente as interrupções
	SREG |= 0x80 ;
}


int main() {
	//Configura a porta D2 como entrada
	DDRD &= ~(1 << PD2) ;

	//Configura a porta D6 como saída
	DDRD |= (1 << PD6) ;

	//Habilita interrupções
	SREG |= 0x80 ;
	//Configura INT0 paraa borda de subida do sinal
	EICRA |= 0x03 ;
	//Habilita a interrupção INT0
	EIMSK = 0x01 ; 


	while (1) {
	}
	return 0 ;
}
