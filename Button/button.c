#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


int main() {
	//Configura a porta B5 como saída
	DDRB |= _BV(DDB5) ;

	//Configura a porta C5 como entrada
	DDRC &= ~_BV(DDC5) ;

	//entrada armazenará o valor lido na porta C
	unsigned char entrada = 0;
	//entrada_ant armazenará o valor lido anteriormente na porta C
	unsigned char entrada_ant = 1 ;

	while (1) {
		//Atualiza a entrada_ant
		entrada_ant = entrada;
		//Lê o valor novo da entrada
		entrada = PINC ;

		//Se a entrada entá em '1' e édiferente da anterior:
		//	bordade subida! Então pisca o LED
		if (entrada > 0 && entrada_ant != entrada) {
			PORTB ^= (1 << PB5) ;
		}

		//Esperaum tempinho antes de efetuar a próxima leitura
		_delay_ms(50) ;
	}
	return 0 ;
}
