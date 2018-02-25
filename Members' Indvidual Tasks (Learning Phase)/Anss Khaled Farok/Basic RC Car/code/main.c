/*
 * RCCAR.c
 *
 * Created: 2018-02-25 7:44:20 PM
 * Author : anssk
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "uart.h"
#include "motion.h"


int main(void)
{
	UART_Init();
    MInit();
    volatile uint8_t status;
    while (1)
    {
	    status = UART_recieve();
	    
	    if((char)status == 'f'){
		    MForward();
	    }
	    else if ((char)status == 'b'){
		    MBackward();
	    }
	    else if((char)status == 'l'){
		    MLeft();
	    }
	    else if((char)status == 'r'){
			MRight();
	    }
	    else if((char)status == 's'){
			MStop();
	    }
	    
    }
}

