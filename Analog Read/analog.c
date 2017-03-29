#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define TIME 250 

int main() {
	DDRD |= _BV(PD6) ;

	OCR0A = 0x00 ;
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00) ;
	TCCR0B = (1 << CS01) ;

	//Vref = AVcc; Bits ajustados a esquerda; Canal 0
	ADMUX = (1 << REFS0) | (1 << ADLAR) ;
	ADCSRA  = (1 << ADEN) ;

	while (1) {
		ADCSRA |= (1 << ADSC) ;
		while (!(ADCSRA & (1 << ADIF))) ;
		OCR0A = ADCH ;
		_delay_ms(10) ;
	}
	return 0 ;
}
