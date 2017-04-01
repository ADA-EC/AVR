/*
	button.c
	Autor: Guilherme Prearo
	Função: Lê o estado de um botão na porta C5 e na borda de subida deste sinal inverte o estado do LED na porta D6
*/


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


int main() {
	//Configura a porta D6 como saída
	DDRD |= _BV(DDD6) ;

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
		entrada = (PINC & (1 << PINC5)) ;

		//Se a entrada entá em '1' e édiferente da anterior:
		//	bordade subida! Então pisca o LED
		if (entrada > 0 && entrada_ant != entrada) {
			PORTD ^= (1 << PD6) ;
		}

		//Esperaum tempinho antes de efetuar a próxima leitura
		_delay_ms(10) ;
	}
	return 0 ;
}
