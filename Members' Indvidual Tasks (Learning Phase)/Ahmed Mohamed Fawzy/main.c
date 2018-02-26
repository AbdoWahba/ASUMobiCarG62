/*
 * blinking2_leds.c
 *
 * Created: 2/26/2018 10:49:44 AM
 * Author : Dell
 */ 

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	
	while(1)
	{
		PORTC = 0xFF;
		_delay_ms(1000);
		PORTC = 0x00;
		_delay_ms(1000);
	}
}

