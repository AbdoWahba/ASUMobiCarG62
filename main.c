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
#define CARWIDTH	14
#define PI			3.14

#define angleFactor 1.5


/* ******************* PROTOTYPES	******************* */
void normalMode(char motionState);
void lineFollowerMode();
void Circle_CCkWise();
void Circle_CkWise();
void angle_CW(uint8_t theta);
void angle_CCW(uint8_t theta);
void rec();
void inf();




/* ******************* GLOBAL VAR	******************* */
volatile uint8_t UART_RECEVED_DATA;
volatile short pulse_Counter = 0;
volatile short measuredDistance = 0;
volatile int requiredDistance = 0;
volatile uint8_t s[4];
volatile uint8_t arrCounter = 0;
volatile uint8_t recFlag = 0;
volatile uint8_t carMode = 'w';
		/*
		*	w		-> Normal mode // Bluetooth mode // Phase 1
		*	W 'Capital W ' -> Line Follower mode // Phase 2
		*	U 'Capital U ' -> Distance // Phase 3
		*	C ''	-> Circle clockwise
		*	c		-> Circle Counter clockwise
		*	A		-> angle CW
		*	a		-> angle CCW
		*/


int main(void)
{
    UART_init();
	
	int0_Init ();

	motorPinInit();

	PWM_init();
	
	sei();
	

	
	
	
	motorSpeedSet(255,255); 
	
	motorStop();
	
    while (1) 
    {
	
			
			/* *** Mode Select *** */
			if( UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'A' || UART_RECEVED_DATA == 'a' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I' ){
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
			
			else if(carMode == 'E'){
				rec();
				UART_RECEVED_DATA = 'w';
				motorStop();
			}
			
			else if(carMode == 'I'){
				inf();
			}
			
			else if(carMode == 'C'){
				Circle_CkWise();
				UART_RECEVED_DATA = 'w';
			}
			
			else if(carMode == 'c'){
				Circle_CCkWise();
				UART_RECEVED_DATA = 'w';
			}
			
			else if(carMode == 'A'){
				while(1){
						while( UART_RECEVED_DATA != ';' ){
					
							if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'a' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I'){
								break;
							}
					
						}
				
						if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'a' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I'){
							carMode =(UART_RECEVED_DATA);
							break;
						}
				
						angle_CW(atoi(s));
				
						UART_RECEVED_DATA = 'A';
				}
			}
			
			else if(carMode == 'a'){
				while(1){
						while( UART_RECEVED_DATA != ';' ){
					
							if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'A' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I'){
								carMode = UART_RECEVED_DATA;
								break;
							}
					
						}
				
						if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' ||  UART_RECEVED_DATA == 'U' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'A' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I'){
							carMode =(UART_RECEVED_DATA);
							break;
						}
				
						angle_CCW(atoi(s));
				
						UART_RECEVED_DATA = 'a';
				}
			}
			
			else if (carMode == 'U'){

				int0_Enable;
				
				while(1){
					
					while( UART_RECEVED_DATA != ';' ){
					
						if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'A' || UART_RECEVED_DATA == 'a' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I'){
					
							carMode =(UART_RECEVED_DATA);
							break;
						}
						
					}

					if(UART_RECEVED_DATA == 'W' || UART_RECEVED_DATA == 'w' || UART_RECEVED_DATA == 'C' || UART_RECEVED_DATA == 'c' || UART_RECEVED_DATA == 'A' || UART_RECEVED_DATA == 'a' || UART_RECEVED_DATA == 'E' || UART_RECEVED_DATA == 'I'){
					
						carMode =(UART_RECEVED_DATA);
						break;
					}

					requiredDistance = atoi(s);
					
					if (measuredDistance < requiredDistance){
						motorForward();
					}
					else {
						
					motorStop();
					
					pulse_Counter = 0;
					measuredDistance = 0;
					
					UART_RECEVED_DATA = 'U';
					
			
					}
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
	
	if(IS_BIT_SET(PINA,2)&&IS_BIT_CLEAR(PINA,0))
	{
		motorLeft();
		while(IS_BIT_CLEAR(PINA,1)&&IS_BIT_CLEAR(PINA,0))
		{
			motorLeft();
		}
		motorForward();
	}
	else if (IS_BIT_CLEAR(PINA,2)&&IS_BIT_SET(PINA,0))
	{
		motorRight();
		while(IS_BIT_CLEAR(PINA,2)&&IS_BIT_CLEAR(PINA,1))
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
void Circle_CCkWise(){
	int0_Enable;
	

	motorSpeedSet( 180 , 255 );
	while(measuredDistance <= 628){
		motorForward();
	}
	
	motorStop();
	
	pulse_Counter = 0;
	measuredDistance = 0;
	int0_Disable;
}

void Circle_CkWise(){
	int0_Enable;
	
	
	motorSpeedSet( 220 , 150 );
	while(measuredDistance <= 628){
		motorForward();
	}
	
	motorStop();
	
	pulse_Counter = 0;
	measuredDistance = 0;
	int0_Disable;
}

void inf(){
	Circle_CCkWise();
	Circle_CkWise();
}

/* ********************** ANGLE ************************ */ 
void angle_CW(uint8_t theta){
	
	
	short ratio = (((0.5 * CARWIDTH) * theta * (PI / 180)) * angleFactor);
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	int0_Enable;
	
	while(measuredDistance <= ratio){
		motorRight();
	}
	
	motorStop();
	
	int0_Disable;
	pulse_Counter = 0;
	measuredDistance = 0;
}

void angle_CCW(uint8_t theta){
	
	short ratio = (((0.5 * CARWIDTH) * theta * (PI / 180)) * angleFactor);
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	int0_Enable;
	
	while(measuredDistance <= ratio){
		motorLeft();
	}
	
	motorStop();
	
	int0_Disable;
	pulse_Counter = 0;
	measuredDistance = 0;
	
}

void rec(){
	int0_Enable;
	
	while(measuredDistance <= 100){
		motorForward();
	}
	motorStop();
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	_delay_ms(1000);
	angle_CW(75);
	_delay_ms(1000);
	
	pulse_Counter = 0;
	measuredDistance = 0;

	int0_Disable;
	int0_Enable;

	while(measuredDistance <= 100){
		motorForward();
	}
	motorStop();
		
	pulse_Counter = 0;
	measuredDistance = 0;
		
	_delay_ms(1000);
	angle_CW(75);
	_delay_ms(1000);
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	int0_Disable;
	int0_Enable;
	
	while(measuredDistance <= 100){
		motorForward();
	}
	motorStop();
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	_delay_ms(1000);
	angle_CW(75);
	_delay_ms(1000);
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	int0_Disable;
	int0_Enable;
	
	while(measuredDistance <= 100){
		motorForward();
	}
	motorStop();
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	_delay_ms(1000);
	angle_CW(75);
	_delay_ms(1000);
	
	pulse_Counter = 0;
	measuredDistance = 0;
	
	int0_Disable;
}



/* ********************** Interrupts ************************ */ 

/* ******************* UART INTERRUPT	******************* */
ISR(USART_RXC_vect)
{
	UART_RECEVED_DATA = UDR;


	if((carMode == 'U' || carMode == 'a' || carMode == 'A') && ((UART_RECEVED_DATA <= '9' && UART_RECEVED_DATA >= '0') || UART_RECEVED_DATA == ';')){
		s[arrCounter++] = UART_RECEVED_DATA;
		if(s[(arrCounter-1)] == ';'){
			s[(arrCounter-1)] = '\0';
			arrCounter = 0;
		}
	}
}

ISR (INT0_vect)
{
		pulse_Counter++;
		measuredDistance = (pulse_Counter * 5 / (14.0));
}

