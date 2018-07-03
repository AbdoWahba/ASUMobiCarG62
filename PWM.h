/*
 * PWM.h
 *
 * Created: 2018-06-19 3:50:36 PM
 *  Author: anssk
 */ 


#ifndef PWM_H_
#define PWM_H_


#include <avr/io.h>
#include "MACROS.h"

#define		EN_TIMER0		1
#define		EN_TIMER1		0
#define		EN_TIMER2		1

void PWM_init();

void analogWrite(uint8_t PIN , uint8_t DC);

#endif /* PWM_H_ */