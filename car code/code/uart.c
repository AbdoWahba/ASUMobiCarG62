/*
 * UART.c
 *
 * Created: 3/12/2018 11:22:03 PM
 *  Author: Ahmed
 */ 

#include "UART.h"

#define F_CPU 16000000

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)


void UART_init(void)
{
	/* U2X = 1 for double transmission speed */
	UCSRA = (1<<U2X);
 
	UCSRB = (1<<RXEN) | (1<<TXEN) | (1 << RXCIE); // Enable Transmission, Receive and Receive Interrupt
		
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1); 
	
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;

}
	
void UART_sendByte(const uint8_t data)
{
	while(!(UCSRA & (1 << UDRE))){}
 
	UDR = data;
}



void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}

}




/* Interrupt Function */ 
