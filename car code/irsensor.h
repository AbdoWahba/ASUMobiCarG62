/*
 * IncFile1.h
 *
 * Created: 3/1/2018 7:05:04 PM
 *  Author: Tasnem bebars
 */ 


#ifndef irsensor_H_
#define irsensor_H_

#define PORTLEFT  PINC
#define PORTMID   PINC
#define PORTRIGHT PINC

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



/* prototypes*/
uint8_t IR_read ( uint8_t irPinLeft , uint8_t irPinMid , uint8_t irPinRight ) ;



#endif /* irsensor_H_ */