/*
 * UART2.c
 *
 * Created: 2/20/2018 12:59:39 AM
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	volatile uint8_t data = 0;
    UART_init();
	DDRA = 0xFF;
    while (1) 
    {
		 data = UART_receiveByte();
		 PORTA = data;
    }
}

