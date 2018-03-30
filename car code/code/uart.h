/*
 * UART.h
 *
 * Created: 3/12/2018 11:22:18 PM
 *  Author: Ahmed
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>


/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/************************** Functions Prototypes ***********************/
void UART_init(void);

void UART_sendByte(const uint8_t data);

uint8_t UART_recieveByte(void);

void UART_sendString(const uint8_t *Str);

void UART_receiveString(uint8_t *Str); // Receive until #



#endif /* UART_H_ */