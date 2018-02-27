/*
 * UART.h
 *
 * Created: 2/19/2018 12:27:16 AM
 *  Author: Ahmed
 */ 
/*
UART Driver written for ATMEGA32 Microcontroller
Author: Ahmed Nasr

*/

#ifndef UART_H_
#define UART_H_


#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 1000000UL
#endif


#define BAUD_RATE 115200




/******************** Prototypes **************************/

void UART_init();
void UART_sendByte(const uint8_t data);
uint8_t UART_receiveByte();
void UART_sendString(const uint8_t *str);
void UART_receiveString(uint8_t *str);






#endif /* UART_H_ */