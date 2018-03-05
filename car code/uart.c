/*
 * uart.c
 *
 * Created: 2018-02-25 7:44:54 PM
 *  Author: anssk
 */ 

#include "UART.h"




void UART_Init()
{
	UBRRL = (uint8_t) BaudeRate;
	UBRRH = (uint8_t) (BaudeRate >> 8);
	
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);
	
}

void UART_Send(uint8_t data ){
	while(! ((UCSRA) & (1<<UDRE) ));
	UDR = data;
}

char UART_recieve(void){
	while(!((UCSRA) & (1<<RXC)));
	return UDR;
}
