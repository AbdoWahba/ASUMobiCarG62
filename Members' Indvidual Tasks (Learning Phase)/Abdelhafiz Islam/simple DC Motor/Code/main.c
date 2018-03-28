/*
 * DC motor.c
 *this code rotates a DC motor using an H-Bridge 
 * Created: 3/28/2018 7:14:43 PM
 * Author : Ab Hafiz
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL 
#include <util/delay.h>


int main(void)

{ DDRA =0xff;
	
   
    while (1) 
    {
		PORTA = 0b00000001; // makes the motor rotates in one direction
		_delay_ms(2000);	// w8 for two seconds
		PORTA = 0b00000010; // makes the motor roatates in the opposite direction
		_delay_ms(2000);	// w8 for two seconds 	
		PORTA = 0b00000000;	// turn off the motor 
		_delay_ms(2000);
    }
}

