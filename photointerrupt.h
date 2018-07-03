/*
 * photointerrupt.h
 *
 * Created: 7/1/2018 12:47:00 PM
 *  Author:AyaMosaad.
 */ 

#ifndef photointerrupt_H_
#define photointerrupt_H_  

#include <avr/io.h>
#include <avr/interrupt.h>
#include "MACROS.h"


#define int0_Enable		((GICR)|=(1<<(INT0)))
#define int0_Disable	((GICR)&=(uint8_t)(~(1<<(INT0))))


void int0_Init ();      

float Mesture_displacement (uint16_t pulse_count);


#endif /*photointerrupt_H_*/