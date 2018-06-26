/*
 * main.c
 *
 * Created: 2018-03-05 8:33:44 PM
 * Author : anssk
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MACROS.h"
#include "uart.h"
#include "irsensor.h"
#include "motion.h"
#include "PWM.h"

/* ******************* PROTOTYPES	******************* */
void normalMode(char motionState);
void lineFollowerMode();


/* ******************* GLOBAL VAR	******************* */
volatile uint8_t UART_RECEVED_DATA;



int main(void)
{
    UART_init();

	motorPinInit();

	motorSpeedSet(150, 150); 
	
	sei();
	
	uint8_t carMode = 'W';
		/*
		*	w -> Normal mode // Bluetooth mode // Phase 1
		*	W 'Capital W ' -> Line Follower mode // Phase 2
		*/
		
		
    while (1) 
    {

			
			/* *** Mode Select *** */
			if( UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ){
				carMode = UART_RECEVED_DATA;
			}
	
			
			
			/* Speed select */
			else if( (UART_RECEVED_DATA >= '0' && UART_RECEVED_DATA <= '9') || UART_RECEVED_DATA == 'q'){
				if(UART_RECEVED_DATA == 'q') {
					motorSpeedSet(255,255);
				}
				else {
					uint8_t x = 25 * UART_RECEVED_DATA;
					motorSpeedSet(x,x);
				}
			}
				
			
			
			
			if(carMode == 'W'){
				
				lineFollowerMode();
				
			}
			else{
				
				normalMode(UART_RECEVED_DATA);
				
			}
			
		
    }
}


/* ******************* NORMAL MODE // BLUETOOTH MODE	******************* */
void normalMode(char motionState){
	if( motionState == 'F' ){
		motorForward();
	}
	else if(motionState == 'B' ){
		motorBackword();
	}
	else if(motionState == 'R' ){
		motorRight();
	}
	else if(motionState == 'L' ){
		motorLeft();
	}
	else if(motionState == 'S' ){
		motorStop();
	}

}


/* ******************* LINE FOLLOWER MODE	******************* */
void lineFollowerMode(){
	
	if(IR_Read(PC4,PC5,PC6) == 2){
		motorLeft();
	}
	else if(IR_Read(PC4,PC5,PC6) == 1){
		motorRight();
	}
	else{
		motorForward();
	}
}



/* ********************** Interrupts ************************ */ 

/* ******************* UART INTERRUPT	******************* */
ISR(USART_RXC_vect)
{
	UART_RECEVED_DATA = UDR;
}