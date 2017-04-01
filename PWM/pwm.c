/*
	pwm.c
	Autor: Guilherme Prearo
	Função: Controla a intensidade de um LED na porta D6 por meio do PWM. Aumenta a intensidade até que a variável estoure, então volta do 0.
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


int main() {
	//Configura a porta D6 como saída
	DDRD |= _BV(PD6) ;

	//Seta o duty cycle para 0%
	OCR0A = 0x00 ;
	//Configura o modo do PWM
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00) ;
	//Configura a frequência do timer
	TCCR0B = (1 << CS01) ;


	while (1) {
		//Aumenta o duty cycle a cada 20ms
		OCR0A += 1 ;
		_delay_ms(20) ;

	}
	return 0 ;
}
