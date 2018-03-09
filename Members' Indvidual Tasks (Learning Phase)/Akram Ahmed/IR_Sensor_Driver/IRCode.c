/*
 * IRCode.c
 *
 * Created: 3/9/2018 2:37:22 PM
 *  Author: Akram
 */

#include "IRCode.h"

int8_t IR_Read (uint8_t L /*left sensor*/ , uint8_t M /*mid sensor*/ , uint8_t R /*right sensor*/)
{
	if ((!(MyPort&(1<<L))&& !(MyPort&(1<<M)) && !(MyPort&(1<<R)) || (!(MyPort&(1<<L))&& MyPort&(1<<M) && !(MyPort&(1<<R))) || (MyPort&(1<<L)&& !(MyPort&(1<<M)) && MyPort&(1<<R) || (MyPort&(1<<L)&& MyPort&(1<<M) && MyPort&(1<<R)))))
	{
		return 0 ;
	}
	else if ((!(MyPort&(1<<L))&& !(MyPort&(1<<M)) && MyPort&(1<<R)) || (!(MyPort&(1<<L))&& MyPort&(1<<M) && MyPort&(1<<R)))
	{
		return -1 ;
	}
	else if ((MyPort&(1<<L)&& !(MyPort&(1<<M)) && !(MyPort&(1<<R))) || (MyPort&(1<<L)&& MyPort&(1<<M) && !(MyPort&(1<<R))))
	{
		return 1 ;
	}
	 /* if left sensor reads 0 then function returns 1 and car turns right
		if right sensor reads 0 then function returns -1 and car turns left 
		if both of them reads 1 or 0 then function returns 0 and car goes straight */
}