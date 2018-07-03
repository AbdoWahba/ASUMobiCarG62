/*
 * photointerrupt.c
 *
 * Created: 7/1/2018 12:46:05 PM
 *  Author: AyaMosaad.
 */ 

#include "photointerrupt.h"
 void int0_Init ()
{
	SETBIT( MCUCR , ISC00); 
	CLEARBIT( MCUCR , ISC01);

	sei();
	CLEARBIT (DDRD,PD2);
}




 float Mesture_displacement (uint16_t pulse_count)
{
  return (((pulse_count) / 20.0) * (21.5)) ;  //n is no of pulses in one turn of wheel
}

