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

/* ******************* DEFINES	******************* */
#define CARRADIUS	14


/* ******************* PROTOTYPES	******************* */
void normalMode(char motionState);
void lineFollowerMode();
void Circle_CCkWise(short R);
void Circle_CkWise(short R);
void get_receivedString(uint8_t c);


/* ******************* GLOBAL VAR	******************* */
volatile uint8_t UART_RECEVED_DATA;
volatile short pulse_Counter = 0;
volatile short measuredDistance = 0;
volatile int requiredDistance = 0;
volatile uint8_t s[3];
uint8_t arrCounter = 0;


int main(void)
{
    UART_init();
	
	int0_Init ();

	motorPinInit();

	PWM_init();
	
	sei();
	
	uint8_t carMode = 'w';
		/*
		*	w -> Normal mode // Bluetooth mode // Phase 1
		*	W 'Capital W ' -> Line Follower mode // Phase 2
		*	U 'Capital U ' -> Distance // Phase 3
		*/
	
	
	
	motorSpeedSet(255,255); 
	
	motorStop();
	
    while (1) 
    {
	
			
			/* *** Mode Select *** */
			if( UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'O'){
				carMode = UART_RECEVED_DATA;
			}
					
			else if(UART_RECEVED_DATA == 'S'){
				motorStop();
			}


				/* Speed select */
			
				else if(UART_RECEVED_DATA == 'q'){
			 		motorSpeedSet(255,255);
			 	}
			
			 	else if(UART_RECEVED_DATA == '9'){
			 		motorSpeedSet(225,225);
			 	}
			
			 	else if(UART_RECEVED_DATA == '8'){
			 		motorSpeedSet(200,200);
				}
			
			 	else if(UART_RECEVED_DATA == '7'){
			 		motorSpeedSet(175,175);
			 	}
			
			 	else if(UART_RECEVED_DATA == '6'){
			 		motorSpeedSet(150,150);
			 	}
			
			 	else if(UART_RECEVED_DATA == '5'){
			 		motorSpeedSet(125,125);
			 	}
			
			 	else if(UART_RECEVED_DATA == '4'){
			 		motorSpeedSet(100,100);
			 	}
			
			 	else if(UART_RECEVED_DATA == '3'){
			 		motorSpeedSet(75,75);
			 	}
			
			 	else if(UART_RECEVED_DATA == '2'){
			 		motorSpeedSet(50,50);
			 	}
			
			 	else if(UART_RECEVED_DATA == '1'){
			 		motorSpeedSet(25,25);
			 	}
			
				else if(UART_RECEVED_DATA == '0'){
			 		motorSpeedSet(0,0);
			 	}

				else{}
			
			
			/* ************ *********** */
			
			if(carMode == 'W'){
				
				lineFollowerMode();
				
			}
			
			else if(carMode == 'C'){
				while( UART_RECEVED_DATA == 'C' );
				Circle_CkWise(UART_RECEVED_DATA);
			}
			
			else if(carMode == 'O'){
				while( UART_RECEVED_DATA == 'O' );
				Circle_CCkWise(UART_RECEVED_DATA);
			}
			
			else if (carMode == 'U'){

				int0_Enable;
				
				while(1){
					
					while( UART_RECEVED_DATA == 'U' ){
						if(arrCounter >= 3){
							break;
						}
					}
					
					if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' || UART_RECEVED_DATA == 'u'){
						carMode =(UART_RECEVED_DATA - 48);
						break;
					}
					
/*
// 					while (arrCounter < 3) {
// 						get_receivedString(UART_RECEVED_DATA);
// 						requiredDistance = atoi(s);
// 					}
*/
					requiredDistance = atoi(s);
					//UART_sendByte(requiredDistance);
					
					if (measuredDistance < requiredDistance){
						motorForward();
						//UART_sendByte((char)(pulse_Counter)/255);
					}
					else {
					motorStop();
					
					pulse_Counter = 0;
					measuredDistance = 0;
					
					UART_RECEVED_DATA = 'U';
					int0_Disable;
					}
				}
				
				
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

/* ********************** CIRCLE ************************ */ 
void Circle_CCkWise(short R){
	float R1 = R -(0.5*CARRADIUS);
	float ratio = ((CARRADIUS+R1)/R1);
	
	motorSpeedSet( (255/ratio) , 255 );
	motorForward();
}

void Circle_CkWise(short R){
	float R1 = R-(0.5*CARRADIUS);
	float ratio = ((CARRADIUS+R1)/R1);
	
	motorSpeedSet( 255 , (255/ratio) );
	motorForward();
}

/* ********************** Interrupts ************************ */ 

/* ******************* UART INTERRUPT	******************* */
ISR(USART_RXC_vect)
{
	UART_RECEVED_DATA = UDR;
	
	if(UART_RECEVED_DATA <= 57 && UART_RECEVED_DATA >= 48){
		s[arrCounter] = UART_RECEVED_DATA;
		if(arrCounter == 2){
			s[arrCounter] = '\0';
		}else {
			arrCounter++;
		}
	}
}

ISR (INT0_vect)
{


		pulse_Counter++;
		measuredDistance = (pulse_Counter * 5 / (14.0));
		

}

/*
// void get_receivedString(uint8_t c) {
// 		if (c != '0') {
// 			s[arrCounter] = c;
// 			arrCounter++;
// 		}
// 		else {
// 			s[arrCounter] = '\0';
// 
// 		} 
// 		if (arrCounter == 3) arrCounter = 0;
// 		
// }
*/
		
		








































