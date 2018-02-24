/*
 * Bouncing LED.c
 *
 * Created: 2018-02-24 11:05:56 PM
 * Author : anssk
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	DDRA |= (1<<PA4) | (1<<PA5) | (1<<PA6) | (1<<PA7);
	
    while (1) 
    {
		uint8_t i = 0;
		while(i<4){
			PORTA &= ~(1<<(PA4 + i - 1));
			PORTA |= (1<<(PA4 + i));
			i++;
			_delay_ms(1000);
		}
		i = 0 ;
		 while(i<3){
			PORTA &= ~(1<<(PA7 - i));
			 PORTA |= (1<<(PA7 - i - 1));
			 i++;
			_delay_ms(1000);
		 }
		
    }
}

