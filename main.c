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
#include "uart.h"
#include "irsensor.h"
#include "motion.h"


void Normal(char motionState);
void Line();

volatile uint8_t data;

int main(void)
{
    UART_init();

	Motor_Init(PC0,PC1,PC2,PC3);
	Motor_setSpeed(120,120);
	
	sei();
	
	char carState	= 'W'; /* W -> Normal */ /* U -> Line */
    while (1) 
    {

			
			/* Mode select */
			if( data == 'W'){
					carState = 'W';
			}
			else if ( data == 'w'){
				 carState = 'w' ;
			}
	
			
			
			/* Speed select */
			if( (data >= '0' && data <= '9') || data == 'q'){
				if(data == 'q') {
					Motor_setSpeed(255,255);
				}
				else {
					uint8_t x = 25.5 * data;
					Motor_setSpeed(x,x);
				}
			}
				
			
			
			
			if(carState == 'w'){
				Line();
			}
			else{
				
				if( !(PINC&(1<<PC4)) || !(PINC&(1<<PC5)) ){
					Motor_Backward();
					//_delay_ms(250);
				}
				else{
					Motor_Stop();
					Normal(data);
				}
			}
			
			/* ULTRASONIC && SERVO */
		
    }
}



void Normal(char motionState){
	if( motionState == 'F' ){
		Motor_Forward();
	}
	else if(motionState == 'B' ){
		Motor_Stop();
		
		Motor_Backward();
	}
	else if(motionState == 'R' ){
		Motor_Right();
	}
	else if(motionState == 'L' ){
		Motor_Left();
	}
	else if(motionState == 'S' ){
		Motor_Stop();
	}

/*
// 
// 	if( !(PINA&(1<<PC4)) ){
// 		
// 		Motor_Left();
// 		_delay_ms(250);
// 		
// 	}
// 	
// 	if( !(PINA&(1<<PC6)) ){
// 		
// 		Motor_Right();
// 		_delay_ms(250);
// 		
// 	}
*/


}

void Line(){
	
	if(IR_Read(PC4,PC5,PC6) == 2){
		Motor_setSpeed(150,150);
		Motor_Left();
	}
	else if(IR_Read(PC4,PC5,PC6) == 1){
		Motor_setSpeed(150,150);
		Motor_Right();
	}
	else{
		Motor_setSpeed(200,200);
		Motor_Forward();
	}
}



/* ********************** Interrupts ************************ */ 

/* UART */
ISR(USART_RXC_vect)
{
	data = UDR;
}