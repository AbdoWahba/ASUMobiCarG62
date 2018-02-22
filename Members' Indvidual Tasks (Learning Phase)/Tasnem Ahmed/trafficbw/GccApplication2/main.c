/*
 * GccApplication2.c
 *
 * Created: 2/22/2018 9:31:35 PM
 * Author : Tasnem bebars
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA =0b00000010;
	while(1)
	{
		if (PINA&(1<<PA0)) 
		{ PORTA |=(1<< PA1 ) ;  ;} 
	
			 if  (!(PINA&(1<<PA0))) 
			 { PORTA &= ~ (1<<PA1);}
			
		
	}
	return 0;
}

