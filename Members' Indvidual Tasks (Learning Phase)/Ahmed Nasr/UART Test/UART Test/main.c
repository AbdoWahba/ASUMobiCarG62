/*
 * UART Test.c
 *
 * Created: 2/20/2018 12:28:56 AM
 * Author : Ahmed Nasr
 * The Project is created to test the UART Driver 
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	volatile uint8_t data = 0;
	volatile uint8_t msg = 0;
	DDRA = 0xFF;
	UART_init();
	
    while (1) 
    {
	msg = UART_receiveByte();
	UART_sendByte(data);
	PORTA = msg;
	
	
	data++;
	_delay_ms(1000);
}

}

