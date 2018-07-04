/*
 * photointerrupt.c
 *
 * Created: 7/1/2018 12:46:05 PM
 *  Author: AyaMosaad.
 */ 

#include "photointerrupt.h"
 void int0_Init ()
{
	/* This function enables all external interrupts
	*/
	// Enabling interrupt 0
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	
}




 float Mesture_displacement (uint16_t pulse_count)
{
  return (((pulse_count) / 20.0) * (21.5)) ;  //n is no of pulses in one turn of wheel
}

