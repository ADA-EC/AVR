/*
	blink.c
	Autor: Guilherme Prearo
	Função: Pisca um LED na porta D6 com um período de 1s
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() {
	//Configura a porta D6 como output
	//O macro _BV(DDD6) equivale a (1 << DDD6)
	DDRD |= _BV(DDD6) ;

	while (1) {
		//Define a saída da porta D6 como nível lógico alto
		PORTD |= _BV(PORTD6) ;

		//Espera por 500ms
		_delay_ms(500) ;

		//Define a saída da porta D6 como nível lógico baixo
		PORTD &= ~_BV(PORTD6);

		//Espera mais 500ms
		_delay_ms(500) ;

		/*
		//Código alternativo (toggle usando XOR)

		//Realiza um XOR entre 1 e o valor da porta (toggle)
		PORTD ^= (1 << PORTD6) ;
		//Espera por 500ms 
		_delay_ms(500) ;
		*/
		
		/*
		//Código alternativo 2 (toggle usando reg. PIND)
		PIND |= (1 << PIND6) ;
		_delay_ms(500) ;
		*/
	}
	return 0 ;
}
