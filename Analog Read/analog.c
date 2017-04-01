/*
	analog.c
	Autor: Guilherme Prearo
	Função: Lê o valor de tensão da porta C0 convertido em um valor digital e então seta o PWM de modoque a intensidade do LED em D6 seja proporcional à tensão
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main() {
	//Configura a porta D6 como saída 
	DDRD |= _BV(PD6) ;
	
	//Configura o duty cycle inicial para 0%
	OCR0A = 0x00 ;
	//Configura o modo do PWM
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00) ;
	//Seleciona o divisor de frequência para o timer
	TCCR0B = (1 << CS01) ;

	//Vref = AVcc; Bits ajustados a esquerda; Canal 0
	ADMUX = (1 << REFS0) | (1 << ADLAR) ;
	//Habilita a conversão AD
	ADCSRA  = (1 << ADEN) ;

	while (1) {
		//Inicia a conversão AD
		ADCSRA |= (1 << ADSC) ;
		//Espera a conversão terminar
		while (!(ADCSRA & (1 << ADIF))) ;
		//Configura o duty cycle conforme a entrada analógica
		OCR0A = ADCH ;
		//Espera um pouco antes da próxima conversão
		_delay_ms(10) ;
	}
	return 0 ;
}
