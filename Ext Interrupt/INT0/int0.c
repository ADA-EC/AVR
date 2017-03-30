#include <avr/io.h>
//Bibliote para utilizar as rotinas de interrupção
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

//Rotina da interrupção INT0
ISR(INT0_vect) {
	//Acende o LED em D6
	PORTD |= (1 << PD6) ;
}


int main() {
	//Configura a porta D2 como entrada
	DDRD &= ~(1 << PD2) ;

	//Configura a porta D6 como saída
	DDRD |= (1 << PD6) ;

	//Habilita interrupções
	SREG |= 0x80 ;
	//Configura INT0 paraa borda de subida do sinal
	EICRA = 0x03 ;
	//Habilita a interrupção INT0
	EIMSK = 0x01 ; 


	while (1) {
		//Apaga a porta D6 a cada 1s
		PORTD &= ~(1 << PD6) ;
		_delay_ms(1000) ;
	}
	return 0 ;
}
