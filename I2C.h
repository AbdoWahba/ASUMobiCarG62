C/*
 * I2C.h
 *
 * Created: 6/27/2018 9:48:55 PM
 *  Author: Ahmed Nasr
 *  Master Mode I2C Driver 
 */ 


#ifndef I2C_H_
#define I2C_H_


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


/* I2C Status Bits in the TWSR Register */
#define START         0x08 // start has been sent
#define REP_START     0x10 // repeated start
#define MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave



/******************* Functions Prototypes ***********************************/ 


volatile uint8_t  I2C_receivedData;
volatile uint8_t  I2C_sendingData;

/*
* Functions Definitions
*/

void I2C_init();
void I2C_start();
void I2C_write(uint8_t data);
void I2C_write_to(uint8_t address);
void I2C_read_from(uint8_t address);
void I2C_stop();
ISR(TWI_vect);




#endif /* I2C_H_ */