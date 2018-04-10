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
#include "Motor.h"
#include "MACROS.h"


/* **************** FUN PROTOTYPES **************** */

/* NORMAL MOTION */
void Stop();
void Forward();
void Backward();
void Right();
void Left();
void setSpeed(uint8_t A, uint8_t B);

/* LINE FOLLOWER */
void Line(); 



volatile uint8_t data; /* RECIEVED DATA FROM UART */



int main(void)
{
	/* **************** INITIALIZATIONS **************** */
	sei();
	
    UART_init();

	/* SET MOTORS PINS TO BE OUTPUT */
	SetMotor(DDRC,PC0,PC1);		/* MOTOR A */ 
	SetMotor(DDRC,PC2,PC3);		/* MOTOR B */	
	setSpeed(0,0);				/* initialize speed by 0 */
	
	
	/* SET IR PINS TO BE INPUT */
	SET_IR_PINS(DDRC,PC4);		/* LEFT IR */
	SET_IR_PINS(DDRC,PC5);		/* MID IR */
	SET_IR_PINS(DDRC,PC6);		/* RIGHT IR */
	
	
	/* **************** USED VARIABLES **************** */ 
	
	char carState	= 'W';		/* W -> NORMAL STATE ----- w -> LINE FOLLOWER STATE */
	
	
    while(1)
	{

			
			/* **************** CAR STATE SELECT **************** */
			
			if( data == 'W')
			{
				carState = 'W';
			}
			else if(data == 'w')
			{
				carState = 'w' ;
			}
	
			
			
			/* **************** CAR SPEED SELECT **************** */
			
			if( (data >= '0' && data <= '9') || data == 'q')
			{
				if(data == 'q')
				{
					setSpeed(255,255);
				}
				else
				{
					uint8_t x = 28 * data;
					setSpeed(x,x);
				}
			}
				
			
			
			/* **************** MOTION BASED ON CAR STATE **************** */
			
			if(carState == 'w')
			{
				Line();
			}
			
			else
			{
				
				/* **************** AVOID OBSTACLES **************** */
				if( IS_BIT_CLEAR(PINC,PC4) || IS_BIT_CLEAR(PINC,PC5) )
				{
					Backward();
				}
				
				/* **************** NORMAL MOTION **************** */
				else
				{
					
					
					if(data == 'F')
					{
						Forward();
					}
					else if(data == 'B')
					{
						Backward();
					}
					else if(data == 'R')
					{
						Right();
					}
					else if(data == 'L')
					{
						Left();
					}
					else if(data == 'S')
					{
						Stop();
					}
					
				}
				
			}
			
			/* **************** ULTRASONIC & SERVO CODE HERE **************** */
			

		
    } /* while */
} /* main */



/* MOTION STATES */
void Stop(){
	Motor_Stop(PORTC,PC0,PC1);
	Motor_Stop(PORTC,PC2,PC3);
}

void Forward(){
	Motor_Forward(PORTC,PC0,PC1);
	Motor_Forward(PORTC,PC2,PC3);
}

void Backward(){
	Motor_Backward(PORTC,PC0,PC1);
	Motor_Backward(PORTC,PC2,PC3);
}

void Left(){
	Motor_Forward(PORTC,PC0,PC1);
	Motor_Backward(PORTC,PC2,PC3);
}

void Right(){
	Motor_Backward(PORTC,PC0,PC1);
	Motor_Forward(PORTC,PC2,PC3);
}

void setSpeed(uint8_t A, uint8_t B){
	analogWrite(1,A);
	analogWrite(2,B);
}


/* LINE FOLLOWER STATE */
void Line(){
	
	if(IR_Read(PC4,PC5,PC6) == 2){
		setSpeed(150,150);
		Left();
	}
	else if(IR_Read(PC4,PC5,PC6) == 1){
		setSpeed(150,150);
		Right();
	}
	else{
		setSpeed(200,200);
		Forward();
	}
}



/* **************** INTERRUPTS **************** */

/* UART */
ISR(USART_RXC_vect)
{
	data = UDR;
}