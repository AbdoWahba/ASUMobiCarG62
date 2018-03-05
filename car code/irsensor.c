/*
 * GccApplication2.c
 *
 * Created: 3/1/2018 7:01:18 PM
 * Author : Tasnem bebars
 */ 


#include "irsensor.h"
/* definitions */ 


uint8_t IR_read(uint8_t irPinLeft , uint8_t irPinMid , uint8_t irPinRight){
	
	/* the function read value from 3 irs  by take pins num then return values tends to them */
	
	if( (PORTLEFT&(1<<irPinLeft)) ) {
		
		return 0;
	}
	else if ( !(PORTMID&(1<<irPinMid)) ){
		return 1;
	}
	else if  ( (PORTRIGHT&(1<<irPinRight)) ){
		return -1;
	}

	return 1;
	
	/*
	if ( !( ( PINA &(1<<irPinLeft))  && (PINA &(1<<irPinMid))  && !(PINA &(1<<irPinRight)) ) || ( !( PINA &(1<<irPinLeft) )  && !( PINA &(1<<irPinMid) ) && !( PINA &(1<<irPinRight) ) ) || ( ( PINA &(1<<irPinLeft)) && (PINA&(1<<irPinMid))  && (PINA&(1<<irPinRight)) ) || ((PINA&(1<<irPinLeft))  && !(PINA&(1<<irPinMid)) && (PINA&(1<<irPinRight))   ) )
	{
		return 0 ;
	}
	if ((!(PINA&(1<<irPinLeft))  && !(PINA&(1<<irPinMid))  &&(PINA&(1<<irPinRight)) ) || (!(PINA&(1<<irPinLeft))  && (PINA&(1<<irPinMid))  && (PINA&(1<<irPinRight)) )  )
	{
		return 1 ;
	}
	 else if (((PINA&(1<<irPinLeft))  && !(PINA&(1<<irPinMid)) && !(PINA&(1<<irPinRight)) ) || ((PINA&(1<<irPinLeft))  &&(PINA&(1<<irPinMid)) && !(PINA&(1<<irPinRight)) )  )
	{
		return -1 ;
	}
	else if ( (!(PINA&(1<<irPinLeft))  && !(PINA&(1<<irPinMid))  && !(PINA&(1<<irPinRight)) )  )
	{
		return 2 ;
	}
	*/
	/* if 0 go forward 
	if 1 turn right 
	if -1 turn left 
	if 2 go forward 5 sec
	*/
	
}



