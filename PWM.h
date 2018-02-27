/*
 * PWM.h
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


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <util/delay.h>

void analogWrite(uint8_t pin, uint8_t duty_cycle);


#endif /* PWM_H_ */