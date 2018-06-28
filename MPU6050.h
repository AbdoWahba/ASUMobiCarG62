/*
 * MPU6050.h
 *
 * Created: 6/27/2018 11:07:49 PM
 *  Author: Ahmed Nasr
 * The driver built on the top of the I2C Driver
 * It's built to interface MPU 6050 Accelerometer & Gyroscope module with ATmega32 Microcontroller
 */ 


#ifndef MPU6050_H_
#define MPU6050_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#include "I2C.h"

#define MPU_Address 0x68


/*********** Functions Protoypes ******************/

void MPU_init(uint8_t Address); // init I2C & all MPU configurations
void MPU_clacError();           // calc Error, this function should be called at the configurations
void MPU_readBytes(uint8_t bytes); // request to read certain numbers of bytes from the MPU
void MPU_writeTo_reg(uint8_t regAddr, uint8_t bytes);
void MPU_readFrom_reg(uint8_t regAddr, uint8_t bytes);




#endif /* MPU6050_H_ */