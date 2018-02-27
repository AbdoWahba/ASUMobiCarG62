/*
 * WDT.c
 *
 * Created: 2/27/2018 2:10:58 PM
 *  Author: Ahmed Nasr
 * Watchdog timer driver developed and tested on ATmega 32 microcontroller
 * Watchdog Timer is an important and useful method to reset the microcontroller if it's stuck or hung up 
 * anywhere in the code, especially for the areas we may it may cause any problems.

 * It works as follows:
 *		1. we turn on the Watchdog Timer and it starts to countdown for 2.1 s 
		2. if it is not turned of before the 2.1 seconds, it resets the Microcontroller
 */ 


#ifndef WDT_H_
#define WDT_H_

#include <avr/io.h>
#include <util/delay.h>

void WDT_on(); 
void WDT_off();



#endif /* WDT_H_ */