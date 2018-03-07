/*
 * CFile1.c
 *
 * Created: 3/8/2018 12:01:00 AM
 *  Author: Akram
 */ 
#define MyPin PINA
#include <avr/io.h>
#include <avr/delay.h>

int8_t IR_READ (uint8_t L /*left sensor*/ , uint8_t M /*mid sensor*/ ,uint8_t R /*right sensor*/)
{
	int8_t w;
	if ((MyPin&(1<<L)) && !(MyPin&(1<<R)))
	{
		return 1;
	}
	else if (!(MyPin&(1<<L)) && (MyPin&(1<<R)))
	{
		return -1;
	}
	else 
	{
		return 0;
	}		  /*if left sensor reads 1 then function returns 1 and car turns right
				if right sensor reads 1 then function returns -1 and car turns left 
				if both of them reads 1 or 0 then function returns 0 and car goes straight */
}

