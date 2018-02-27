/*
 * PWM.c
 *
 * Created: 2/27/2018 12:28:28 PM
 *  Author: Ahmed Nasr 
 *  A PWM driver developed and tested for ATMEGA32.
 * The Driver will be serving the car motors Driver
 * Currently works on a 1 MHZ Clock Speed
 * Future Improvements: 
 * 	- Making it portable and independent on the clock speed
 *
 */ 

#include "PWM.h"

void analogWrite(uint8_t pin, uint8_t duty_cycle) {
	/* Initialization:
					Set desired pin to be output pin.
					8 Bit Mode.
					Non Inverting Mode.
					8 bit Prescaler 
		Reset Timer 1
		set Duty Cycle value to OCR Reg.
	*/
	TCNT1 = 0;
	if (pin == 1) {
		DDRD |= (1 << PIND5);
		TCCR1A |= (1 << COM1A1) | (1 << WGM10);
		TCCR1B |= (1 << WGM12) | (1 << CS11);
		OCR1A = duty_cycle;
	}
	else if (pin == 2) {
		DDRD |= (1 << PIND4);
		TCCR1A |= (1 << COM1B1) | (1 << WGM10);
		TCCR1B |= (1 << WGM12) | (1 << CS11);
		OCR1B = duty_cycle;
	}


}