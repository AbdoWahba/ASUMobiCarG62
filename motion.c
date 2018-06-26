/*
 * motion.c
 *
 * Created: 2018-02-25 7:45:26 PM
 *  Author: anssk
 */ 

#include "motion.h"

/*
//  MOTOR1_A	
//  MOTOR1_B	
//  EN_MOTOR1	
// 
//  MOTOR2_A	
//  MOTOR2_B	
//  EN_MOTOR2	
*/

void motorPinInit(){
	SETBIT( MOTOR_DDR , MOTOR1_A );
	SETBIT( MOTOR_DDR , MOTOR1_B );
	
	SETBIT( MOTOR_DDR , MOTOR2_A );
	SETBIT( MOTOR_DDR , MOTOR2_B );
}

void motorStop(){
	CLEARBIT( MOTOR_PORT , MOTOR1_A );
	CLEARBIT( MOTOR_PORT , MOTOR1_B );
	
	CLEARBIT( MOTOR_PORT , MOTOR2_A );
	CLEARBIT( MOTOR_PORT , MOTOR2_B );
}

void motorBackword(){
	CLEARBIT( MOTOR_PORT , MOTOR1_A );
	SETBIT( MOTOR_PORT , MOTOR1_B );
	
	CLEARBIT( MOTOR_PORT , MOTOR2_A );
	SETBIT( MOTOR_PORT , MOTOR2_B );
}

void motorForward(){
	SETBIT( MOTOR_PORT , MOTOR1_A );
	CLEARBIT( MOTOR_PORT , MOTOR1_B );
	
	SETBIT( MOTOR_PORT , MOTOR2_A );
	CLEARBIT( MOTOR_PORT , MOTOR2_B );

}

void motorLeft(){
	CLEARBIT( MOTOR_PORT , MOTOR1_A );
	SETBIT( MOTOR_PORT , MOTOR1_B );
	
	SETBIT( MOTOR_PORT , MOTOR2_A );
	CLEARBIT( MOTOR_PORT , MOTOR2_B );

}

void motorRight(){
	SETBIT( MOTOR_PORT , MOTOR1_A );
	CLEARBIT( MOTOR_PORT , MOTOR1_B );
	
	CLEARBIT( MOTOR_PORT , MOTOR2_A );
	SETBIT( MOTOR_PORT , MOTOR2_B );

}

void motorSpeedSet(uint8_t leftMotor , uint8_t rightMotor){
	analogWrite(EN_MOTOR1 , leftMotor);
	analogWrite(EN_MOTOR2 , rightMotor);
}
