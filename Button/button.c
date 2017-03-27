#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define TIME 250 

int main() {
	DDRB |= _BV(DDB5) ;
	DDRC &= ~_BV(DDC5) ;
	unsigned char flag = 0 ;
	unsigned char pc = 0;
	unsigned char prev_pc = 1 ;

	while (1) {
		prev_pc = pc;
		pc = PINC ;
		if (pc > 0 && prev_pc != pc) {
			flag = ~flag & 1 ;
		}
		PORTB = (flag << PB5) ;
		_delay_ms(50) ;
	}
	return 0 ;
}
