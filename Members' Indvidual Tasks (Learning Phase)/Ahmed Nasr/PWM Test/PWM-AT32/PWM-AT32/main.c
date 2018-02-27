/*
 * PWM-AT32.c
 *
 * Created: 2/27/2018 12:27:31 PM
 * Author : Ahmed Nasr 
 * Driver Test Code
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"


int main(void)
{
    while (1) 
    {
	
	analogWrite(1, 127);
	analogWrite(2,127);

	 
}
}

