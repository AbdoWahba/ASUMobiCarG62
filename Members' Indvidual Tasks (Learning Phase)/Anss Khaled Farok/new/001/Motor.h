/*
 * Motor.h
 *
 * Created: 2018-04-02 10:17:28 PM
 *  Author: anssk
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include "MACROS.h"
#include "PWM.h"

#define SetMotor(REG,PIN_IN1,PIN_IN2) ((REG)|=(1<<(PIN_IN1))|(1<<(PIN_IN2)))

void Motor_Forward(uint8_t PIN_PORT , uint8_t PIN_IN1 , uint8_t PIN_IN2);
void Motor_Backward(uint8_t PIN_PORT , uint8_t PIN_IN1 , uint8_t PIN_IN2);
void Motor_Speed(uint8_t Enable_PIN , uint8_t speed);



#endif /* MOTOR_H_ */