/*
 * pir sensor.c
 *
 * Created: 2/26/2018 5:58:28 PM
 * Author : Dell
 */ 
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int main()
{
	DDRA=0x00;
	PORTA=0x00;
	DDRB=0x01; 
	PORTB=0x00; 
	while(1)
	{
		if((PINA&(1<<0)))           
		{
			PORTB = 0b00000111;           
			_delay_ms(5000);
			PORTB=0x00;
		}
		else
		PORTB=0x00;  // buzzer/LED off
	}
	return 0;
}


