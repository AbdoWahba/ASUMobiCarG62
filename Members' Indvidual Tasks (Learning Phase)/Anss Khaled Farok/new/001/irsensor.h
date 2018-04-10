/*
 * IRCode.h
 *
 * Created: 3/9/2018 2:36:58 PM
 *  Author: Akram
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#define MyPort PINC
#include <avr/io.h>

#define SET_IR_PINS(REG,IR_PIN) ((REG)&=~(1<<(IR_PIN)))
int8_t IR_Read (uint8_t L /*left sensor*/ , uint8_t M /*mid sensor*/ , uint8_t R /*right sensor*/);


#endif /* INCFILE1_H_ */