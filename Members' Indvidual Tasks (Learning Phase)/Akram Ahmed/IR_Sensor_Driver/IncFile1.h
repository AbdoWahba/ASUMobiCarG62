/*
 * IncFile1.h
 *
 * Created: 3/7/2018 11:08:18 PM
 *  Author: Akram
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#define MyPin PINA

int8_t IR_READ (uint8_t L /*left sensor*/ , uint8_t M /*mid sensor*/ ,uint8_t R /*right sensoe*/)
{
	int8_t w;
	if ((MyPin&(1<<L)) && !(MyPin&(1<<R)))
	{
		w=1;
	}
	else if (!(MyPin&(1<<L)) && (MyPin&(1<<R)))
	{
		w=-1;
	}
	else 
	{
		w=0;
	}
	return w; /*if left sensor reads 1 then w =1 and car turns right
				if right sensor reads 1 then w=-1 and car turns left 
				if both of them reads 1 or 0 then w= 0 and car goes straight */
}




#endif /* INCFILE1_H_ */