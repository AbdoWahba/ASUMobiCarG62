/*
 * traffic.c
 *
 * Created: 2/18/2018 11:48:08 PM
 * Author : Tasnem bebars
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{
	DDRA = 0b00001111;
	while(1)
	{
		PORTA = 0b00000001;
		_delay_ms(1500);
		PORTA = 0b00000010;
		_delay_ms(1500);
			PORTA = 0b00000100;
			_delay_ms(1500);
				
	}
	return 0;
}

