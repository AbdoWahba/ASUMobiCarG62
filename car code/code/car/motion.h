/*
 * motion.h
 *
 * Created: 2018-02-25 7:45:38 PM
 *  Author: anssk
 */ 


#ifndef MOTION_H_
#define MOTION_H_

#define DDR_MOTOR	DDRC
#define PORT_MOTOR	PORTC

#define Enable_MOTOR_1  PD5
#define Enable_MOTOR_2  PD4

#include <avr/io.h>
#include "PWM.h"

void Motor_Init(uint8_t MotorA1 , uint8_t MotorA2 , uint8_t MotorB1 , uint8_t MotorB2);

void Motor_Stop();

void Motor_Forward();

void Motor_Backward();

void Motor_Left();

void Motor_Right();

void Motor_setSpeed(uint8_t Motor1 , uint8_t Motor2);


#endif /* MOTION_H_ */