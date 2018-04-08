
/*
 * PWM.c
 *
 * Created: 2/27/2018 12:28:14 PM
 *  Author: Ahmed Nasr 
 */ 

#include "PWM.h"



void analogWrite(uint8_t pin, uint8_t duty_cycle) {
	/* - Initialization:
					- Set desired pin to be output pin.
					- 8 Bit Mode.
					- Non Inverting Mode.
					- 8 bit Prescaler 
		- Reset Timer 1
		- set Duty Cycle value to OCR Reg.
	*/
	
	if (pin == 1) {
		DDRD |= (1 << PIND5);
		TCCR1A |= (1 << COM1A1) | (1 << WGM10);
		TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);
		OCR1A = duty_cycle;
	}
	else if (pin == 2) {

		DDRD |= (1 << PIND4);
		TCCR1A |= (1 << COM1B1) | (1 << WGM10);
		TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);
		OCR1B = duty_cycle;
	}


}