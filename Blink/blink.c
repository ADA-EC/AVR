#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() {
	//Configura a porta B5 como output
	//A função _BV(DDB5) equivale a (1 << DDB5)
	DDRB |= _BV(DDB5) ;

	while (1) {
		//Define a saída da porta B5 como nível lógico alto
		PORTB |= _BV(PORTB5) ;

		//Espera por 500ms
		_delay_ms(500) ;

		//Define a saída da porta B5 como nível lógico baixo
		PORTB &= ~_BV(PORTB5);

		//Espera mais 500ms
		_delay_ms(500) ;

		/*
		//Código alternativo (toggle usando XOR)

		//Realiza um XOR entre 1 e o valor da porta (toggle)
		PORTB ^= (1 << PORTB5) ;
		//Espera por 500ms 
		_delay_ms(500) ;
		*/
		
		/*
		//Código alternativo 2 (toggle usando reg. PINB)
		PINB |= (1 << PINB5) ;
		_delay_ms(500) ;
		*/
	}
	return 0 ;
}
