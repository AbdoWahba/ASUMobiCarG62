/*
 * GccApplication4.c
 *
 * Created: 19/02/2018 02:25:30 م
 * Author : Fathy
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRA = 0b00000111;
	while (1)
	{
		
			PORTA|=(1<<PINA0);
			_delay_ms(500);
			PORTA&=~(1<<PINA0);
	        PORTA|=(1<<PINA1);
	        _delay_ms(500);
			PORTA&=~(1<<PINA1);
		    PORTA|=(1<<PINA2);
		    _delay_ms(500);
			PORTA&=~(1<<PINA2);
	}
	return 0;
}
