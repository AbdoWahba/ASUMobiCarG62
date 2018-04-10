/*
 * MACROS.h
 *
 * Created: 2018-04-08 3:24:12 AM
 *  Author: anssk
 */ 

#include <avr/io.h>

#ifndef MACROS_H_
#define MACROS_H_

#define SETBIT(REG,BIT) ((REG)|=(1<<(BIT)))
#define RESETBIT(REG,BIT) ((REG)&=(uint8_t)~(1<<(BIT)))
#define TOGGELBIT(REG,BIT) ((REG)^=(1<<(BIT)))

#define IS_BIT_SET(REG,BIT) ((REG)&(1<<(BIT)))
#define IS_BIT_CLEAR(REG,BIT)	(!((REG)&(1<<(BIT))))



#endif /* MACROS_H_ */