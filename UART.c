/*
 * UART.c
 *
 * Created: 2/19/2018 12:26:56 AM
 *  Author: Ahmed
 */ 
 #include "UART.h"

 
 /************************ Functions Definitions *******************************/


 void UART_init(){
	 /* The function initializes the UART module 
	 * Enable Transimiting and Receiving
	 * No Parity check - 8 bit data in the frame
	 * only one stop bit
	 * set BAUD Rate
	 */
	 UCSRB = (1 << TXEN) | (1 << RXEN);
	 UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	 UBRRL = UBRR_VALUE;
	 UBRRH = UBRR_VALUE >> 8;
 }



 void UART_sendByte(uint8_t data) {
	 /* waiting till UDR register is empty
	 * send data
	 * waiting till TXC flag is set
	 * clear flag
	 */
	 while (!(UCSRA & (1 << UDRE)));
	 UDR = data;
	 while (!(UCSRA & (1 << TXC)));
	 UCSRA |= (1 << TXC);
 }

 uint8_t UART_receiveByte() {
	 /* waiting till RXC flag is set
	 * clear the flag 
	 * return data
	 *
	 */
	 while  (!(UCSRA & (1 << RXC)));
	 UCSRA |= (1 << RXC);
	 return UDR;

 }

 void UART_sendString(const uint8_t *str) {
	/*


	*/
	 while (*str != '\0') {
		 UART_sendByte(*str);
		 str++;
	 }

 }


 void UART_receiveString(uint8_t *str) {

	 uint8_t i = 0;
	 str[i] = UART_receiveByte();

	 while(i != '#') {
		 str[i++] = UART_receiveByte();

	 }
	 str[i] = '\0';

 }







