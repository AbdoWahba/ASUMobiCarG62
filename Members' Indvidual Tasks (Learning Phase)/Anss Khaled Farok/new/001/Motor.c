/*
 * Motor.c
 *
 * Created: 2018-04-02 10:17:02 PM
 *  Author: anssk
 */ 

#include "Motor.h"


void Motor_Forward(uint8_t PIN_PORT , uint8_t PIN_IN1 , uint8_t PIN_IN2){
	SETBIT(PIN_PORT,PIN_IN1);
	RESETBIT(PIN_PORT,PIN_IN2);
}

void Motor_Backward(uint8_t PIN_PORT , uint8_t PIN_IN1 , uint8_t PIN_IN2){
	SETBIT(PIN_PORT,PIN_IN2);
	RESETBIT(PIN_PORT,PIN_IN1);
}

void Motor_Stop(uint8_t PIN_PORT , uint8_t PIN_IN1 , uint8_t PIN_IN2){
	RESETBIT(PIN_PORT,PIN_IN2);
	RESETBIT(PIN_PORT,PIN_IN1);
}

void Motor_Speed(uint8_t Enable_PIN , uint8_t speed){
	analogWrite(Enable_PIN,speed);
}