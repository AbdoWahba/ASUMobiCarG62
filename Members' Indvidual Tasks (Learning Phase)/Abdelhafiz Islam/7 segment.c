
#define F_CPU 1000000UL	
#include <avr/delay.h>
#include <avr/io.h>


int main(void)
{
    DDRA =0b11111111;
	
    while (1) 
    {
		PORTA = 0b00111111; // number 0	
		_delay_ms(1000);
		PORTA = 0b01100000;// number 1
		_delay_ms(1000);
		PORTA = 0b01011011; // number 2
		_delay_ms(1000);
		PORTA =	0b01001111; //number 3 
		_delay_ms(1000);
		PORTA = 0b01100110; // number 4
		_delay_ms(1000);
		PORTA = 0b01101101; // number 5
		_delay_ms(1000);
		PORTA = 0b01111101;// number 6
		_delay_ms(1000);
		PORTA = 0b00000111; //number 7
		_delay_ms(1000);
		PORTA = 0b01111111; // number 8
		_delay_ms(1000);
		PORTA = 0b01101111;
		_delay_ms(1000);
    }
}

