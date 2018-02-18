/*
 * UART Enable.c
 *
 * Created: 2018-02-16 3:48:13 PM
 * Author : anssk
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define Baude 9600
#define BaudeRate ((F_CPU)/(Baude*16UL)-1)

void UART_Init()
{
	UBRRL = (uint8_t) BaudeRate;
	UBRRH = (uint8_t) (BaudeRate >> 8);
	
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);
	
}

void UART_Send(unsigned char data ){
	while(! ((UCSRA) & (1<<UDRE) ));
	UDR = data;
}

unsigned char UART_recieve(void){
	while(!((UCSRA) & (1<<RXC)));
	return UDR;
}

int main(void)
{
	UART_Init();
		
    /* Replace with your application code */
    while (1) 
    {
		
		UART_Send( UART_recieve() );
		_delay_ms(1000);		
    }
	
	return 0;
}

