/*
 * motion.c
 *
 * Created: 2018-02-25 7:45:26 PM
 *  Author: anssk
 */ 

#include "motion.h"
#include <avr/io.h>

void MInit(){
	DDRA |= ((1<< PA0) | (1<<PA1));
	PORTA &= ~((1<<PA0) | (1<<PA1));
}

void MStop(){
	PORTA &= ~(1<<PA2);
}

void MForward(){
	PORTA |= ((1<<PA0) | (1<<PA1));
	PORTA |= (1<<PA2);
}

void MBackward(){
	PORTA &= ~((1<<PA0) | (1<<PA1));
	PORTA |= (1<<PA2);
}

void MRight(){
	PORTA |= (1<<PA1);
	PORTA &= ~(1<<PA0);
	PORTA |= (1<<PA2);
}

void MLeft(){
	PORTA |= (1<<PA0);
	PORTA &= ~(1<<PA1);
	PORTA |= (1<<PA2);
}
