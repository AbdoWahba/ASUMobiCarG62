/*
 * motion.h
 *
 * Created: 2018-02-25 7:45:38 PM
 *  Author: anssk
 */ 


#ifndef MOTION_H_
#define MOTION_H_

#include <avr/io.h>
#include "PWM.h"
#include "MACROS.h"

#define MOTOR_DDR		DDRC
#define MOTOR_PORT		PORTC

#define MOTOR1_A		PC0
#define MOTOR1_B		PC1

#define MOTOR2_A		PC2
#define MOTOR2_B		PC3

#define EN_MOTOR1		PB3
#define EN_MOTOR2		PD7

void motorPinInit();

void motorStop();

void motorForward();

void motorBackword();

void motorLeft();

void motorRight();

void motorSpeedSet(uint8_t leftMotor , uint8_t rightMotor);


#endif /* MOTION_H_ */