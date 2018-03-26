/*
 * main.c
 *
 * Created: 2018-03-05 8:33:44 PM
 * Author : anssk
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include "irsensor.h"


void Normal(char motionState);
void Line();


int main(void)
{
    UART_Init();
	Motor_Init(PC0,PC1,PC2,PC3);
	Motor_setSpeed(250,250);
	
	
	
	char motionState	= 'S';
	char carState		= 'W'; /* W -> Normal */ /* U -> Line */
    while (1) 
    {

			
			if( UART_recieve() == 'W' || UART_recieve() == 'U')
				{ carState = UART_recieve(); }
			else { motionState = UART_recieve(); }
			
			
			
			if(carState == 'U'){
				Line();
			}
			else if(carState == 'w' || carState == 'u') {
				Motor_Stop();
			}
			else{
				Normal(motionState);
			}
			
			
		
    }
}



void Normal(char motionState){
	if( motionState == 'F' ){
		Motor_Forward();
	}
	else if(motionState == 'B' ){
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


	if( !(PINA&(1<<PC4)) ){
		
		Motor_Left();
		_delay_ms(250);
		
	}
	
	if( !(PINA&(1<<PC6)) ){
		
		Motor_Right();
		_delay_ms(250);
		
	}

/*
// 	if( IR_Read(PC4,PC5,PC6) == -1 ) {
// 		Motor_Right();
// 		_delay_ms(250);
// 	}
// 	if(IR_Read(PC4,PC5,PC6) == 1){
// 		Motor_Left();
// 		_delay_ms(250);
// 	}
*/
}

void Line(){
	if(IR_Read(PC4,PC5,PC6) == 0){
		Motor_setSpeed(200,200);
		Motor_Forward();
	}
	else if(IR_Read(PC4,PC5,PC6) == -1){
		Motor_setSpeed(100,100);
		Motor_Left();
	}
	else if(IR_Read(PC4,PC5,PC6) == 1){
		Motor_setSpeed(100,100);
		Motor_Right();
	}
}
