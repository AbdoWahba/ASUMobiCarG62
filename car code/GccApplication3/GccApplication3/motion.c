/*
 * motion.c
 *
 * Created: 2018-02-25 7:45:26 PM
 *  Author: anssk
 */ 

#include "motion.h"

/* Each motor has 2 pin */
volatile uint8_t  motorA1 
				, motorA2 
				, motorB1 
				, motorB2;

void Motor_Init(uint8_t MotorA1 , uint8_t MotorA2 , uint8_t MotorB1 , uint8_t MotorB2){
	motorA1 = MotorA1 ; motorA2 = MotorA2;
	motorB1 = MotorB1 ; motorB2 = MotorB2;
	

	DDR_MOTOR |= ( (1<<motorA1) | (1<<motorA2) | (1<<motorB1) | (1<<motorB2) );


/*
// 	DDRA |= ((1<< Motor1) | (1<<Motor2));
// 	PORTA &= ~((1<<Motor1) | (1<<Motor2));
*/
}

void Motor_Stop(){
	PORT_MOTOR &= ~(1<<motorA1);
	PORT_MOTOR &= ~(1<<motorA2);
	
	PORT_MOTOR &= ~(1<<motorB2);
	PORT_MOTOR &= ~(1<<motorB2);
}

void Motor_Forward(){
	PORT_MOTOR |= (1<<motorA1);
	PORT_MOTOR &= ~(1<<motorA2);
	
	PORT_MOTOR |= (1<<motorB1);
	PORT_MOTOR &= ~(1<<motorB2);
}

void Motor_Backward(){
	PORT_MOTOR |= (1<<motorA2);
	PORT_MOTOR &= ~(1<<motorA1);
	
	PORT_MOTOR |= (1<<motorB2);
	PORT_MOTOR &= ~(1<<motorB1);

}

void Motor_Right(){
	PORT_MOTOR |= (1<<motorA2);
	PORT_MOTOR &= ~(1<<motorA1);
	
	PORT_MOTOR &= ~(1<<motorB2);
	PORT_MOTOR &= ~(1<<motorB1);

}

void Motor_Left(){
	PORT_MOTOR &= ~(1<<motorA1);
	PORT_MOTOR &= ~(1<<motorA2);
	
	PORT_MOTOR |= (1<<motorB1);
	PORT_MOTOR &= ~(1<<motorB2);

}

void Motor_setSpeed(uint8_t Motor1 , uint8_t Motor2){
	analogWrite( 1, Motor1);
	analogWrite( 2, Motor2);
}
