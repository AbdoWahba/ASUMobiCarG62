/*
 * uart.h
 *
 * Created: 2018-02-25 7:45:06 PM
 *  Author: anssk
 */ 


#ifndef UART_H_
#define UART_H_

#define  F_CPU 16000000UL
#define Baude 9600
#define BaudeRate ((F_CPU)/(Baude*16UL)-1)

#include <stdint.h>

void UART_Init();

void UART_Send(uint8_t data );

uint8_t UART_recieve(void);


#endif /* UART_H_ */