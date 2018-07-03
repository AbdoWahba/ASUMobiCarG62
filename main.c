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
#include "photointerrupt.h"


/* ******************* PROTOTYPES	******************* */
void normalMode(char motionState);
void lineFollowerMode();


/* ******************* GLOBAL VAR	******************* */
volatile uint8_t UART_RECEVED_DATA;
volatile float pulse_Counter = 0;
volatile uint8_t intFlag = 0;
volatile uint16_t measuredDistance = 0;

int main(void)
{
    UART_init();
	
	int0_Init ();

	motorPinInit();

	motorSpeedSet(255,255); 
	
	sei();
	
	uint8_t carMode = 'U';
		/*
		*	w -> Normal mode // Bluetooth mode // Phase 1
		*	W 'Capital W ' -> Line Follower mode // Phase 2
		*	U 'Capital U ' -> Distance // Phase 3
		*/
	float requiredDistance = 0;
	
		
    while (1) 
    {

			
			/* *** Mode Select *** */
			if( UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' ){
				carMode = UART_RECEVED_DATA;
			}
	
			
			
			/* Speed select */
/*
// 			else if(UART_RECEVED_DATA == 'q'){
// 				motorSpeedSet(255,255);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '9'){
// 				motorSpeedSet(225,225);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '8'){
// 				motorSpeedSet(200,200);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '7'){
// 				motorSpeedSet(175,175);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '6'){
// 				motorSpeedSet(150,150);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '5'){
// 				motorSpeedSet(125,125);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '4'){
// 				motorSpeedSet(100,100);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '3'){
// 				motorSpeedSet(75,75);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '2'){
// 				motorSpeedSet(50,50);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '1'){
// 				motorSpeedSet(25,25);
// 			}
// 			
// 			else if(UART_RECEVED_DATA == '0'){
// 				motorSpeedSet(0,0);
// 			}	
// 			
*/
			else{}
			
			
			/* ************ *********** */
			
			if(carMode == 'W'){
				
				lineFollowerMode();
				
			}
			else if (carMode == 'U'){
				


					int0_Enable;
		
					while(1){
		
						//while( UART_RECEVED_DATA == 'U' );
		
		
						if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' || UART_RECEVED_DATA == 'u'){
							carMode = UART_RECEVED_DATA;
							break;
						}
		
		
						//requiredDistance = ((short)UART_RECEVED_DATA) ;
						requiredDistance = 10 ;
		
						while( pulse_Counter <= requiredDistance && pulse_Counter != 0){
							
							motorForward();
							
							

		
						}
		
						motorStop();
		
						pulse_Counter = 0;
						measuredDistance = 0;
		
					//	UART_RECEVED_DATA = 'U';
					}
		
					int0_Disable;
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
	
	if(IS_BIT_SET(PINC,4)&&IS_BIT_CLEAR(PINC,6))
	{
		motorLeft();
		while(IS_BIT_CLEAR(PINC,5)&&IS_BIT_CLEAR(PINC,6))
		{
			motorLeft();
		}
		motorForward();
	}
	else if (IS_BIT_CLEAR(PINC,4)&&IS_BIT_SET(PINC,6))
	{
		motorRight();
		while(IS_BIT_CLEAR(PINC,4)&&IS_BIT_CLEAR(PINC,5))
		{
			motorRight();
		}
		motorForward();
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

ISR (INT0_vect)
{

	if( intFlag == 0){
		_delay_ms(50);
		pulse_Counter++;	
		intFlag = 1;
	}
	else if(intFlag == 1){
		_delay_ms(50);
		intFlag = 0;
	}

	//measuredDistance = (((pulse_Counter) / 14.0) * (21.5));
	UART_sendByte((char)(pulse_Counter));

	
	
}









































