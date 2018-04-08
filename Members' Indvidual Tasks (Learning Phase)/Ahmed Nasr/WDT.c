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
 

 #include "WDT.h"

 void WDT_on(void)
 {
	 /*
	  Watchdog Timer enables with timeout period 2.1 second.
	  if it's not turned off after 2.1 it will reset the chip
	  */

	 WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
 }


void WDT_off(void)
{
	/*	Turning off The Time out of Watchdog Timer by:
			Set logical ones to WDTOE & WDE Register
			Wait 4 clock cycles to reset WDE

	*/
	WDTCR = (1<<WDTOE) | (1<<WDE);
	//wait 4 cycles before clear the WDE bit
	_delay_us(4);
	WDTCR = 0x00;
};  