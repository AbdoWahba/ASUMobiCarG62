/*
 * dc motors.c
 *
 * Created: 4/1/2018 2:33:30 PM
 * Author : Dell
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL 
#include <util/delay.h>


void delay()
{
	uint8_t i;
	for(i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}

}

int main()
{
	//Configure TIMER1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); 

	ICR1=4999;  

	DDRD|=(1<<PD4)|(1<<PD5);   

	while(1)
	{

		OCR1A=97;   //0 
		delay();

		OCR1A=316;  //90 
		delay();

		OCR1A=425;  //135 

		delay();

		OCR1A=535;  //180 
		delay();
	}
}

