/*
 * MACROS.h
 *
 * Created: 2018-04-07 4:34:57 AM
 *  Author: anssk
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#include <avr/io.h>

#define SETBIT(REG,BIT)		((REG)|=(1<<(BIT)))
#define CLEARBIT(REG,BIT)	((REG)&=(uint8_t)(~(1<<(BIT))))
#define TOGGLEBIT(REG,BIT)	((REG)^=(1<<(BIT)))

#define IS_BIT_SET(REG,BIT)	((REG)&(1<<(BIT)))
#define IS_BIT_CLEAR(REG,BIT)	(!((REG)&(1<<(BIT))))






#endif /* MACROS_H_ */