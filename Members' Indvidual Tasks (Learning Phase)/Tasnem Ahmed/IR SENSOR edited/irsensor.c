/*
 * GccApplication2.c
 *
 * Created: 3/1/2018 7:01:18 PM
 * Author : Tasnem bebars
 */ 

#include <avr/io.h>
#include "IR SENSOR/irsensor.h"
/* definitions */ 

char IR_read(uint8_t pil /*left*/ , uint8_t pim /*mid*/ , uint8_t pir /*right*/){
	/* the function read value from 3 irs  by take pins num then return values tends to them */
	if ( !((PINA&(1<<pil))  && (PINA&(1<<pim))  && !(PINA&(1<<pir)) ) || (!(PINA&(1<<pil))  && !(PINA&(1<<pim)) && !(PINA&(1<<pir)) ) || ((PINA&(1<<pil)) && (PINA&(1<<pim))  && (PINA&(1<<pir)) ) || ((PINA&(1<<pil))  && !(PINA&(1<<pim)) && (PINA&(1<<pir))   ) )
	{
		return 0 ;
	}
	if ((!(PINA&(1<<pil))  && !(PINA&(1<<pim))  &&(PINA&(1<<pir)) ) || (!(PINA&(1<<pil))  && (PINA&(1<<pim))  && (PINA&(1<<pir)) )  )
	{
		return 1 ;
	}
	 else if (((PINA&(1<<pil))  && !(PINA&(1<<pim)) && !(PINA&(1<<pir)) ) || ((PINA&(1<<pil))  &&(PINA&(1<<pim)) && !(PINA&(1<<pir)) )  )
	{
		return -1 ;
	}
	else if ( (!(PINA&(1<<pil))  && !(PINA&(1<<pim))  && !(PINA&(1<<pir)) )  )
	{
		return 2 ;
	}
	/* if 0 go forward 
	if 1 turn right 
	if -1 turn left 
	if 2 go forward 5 sec
	*/
	
}



int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

