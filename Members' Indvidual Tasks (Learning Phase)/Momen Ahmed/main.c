/*
 * GccApplication4.c
 *
 * Created: 19/02/2018 02:25:30 م
 * Author : Fathy
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
int main(void)
{
	DDRA = 0b00000111;
	
	while (1)
	{
		PORTA=0B00000001;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
		PORTA=0B00000010;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
		PORTA=0B00000100;
		_delay_ms(500);
		PORTA=0b00000000;
		_delay_ms(500);
	}
	return 0;
}
