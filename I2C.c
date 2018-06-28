/*
 * I2C.c
 *
 * Created: 6/27/2018 9:49:28 PM
 *  Author: Ahmed Nasr 
 *  Master Mode I2C Driver
 */ 

#include "I2C.h"


// Functions Definitions:

void I2C_init() {
/* 
	Enable TWCR bits
	reset  stop bits
*/

	TWCR = (1<<TWEN) | (1 << TWIE) | (1 << TWINT) | (1 << TWEA); // Enable I2C
	TWCR &= ~ (1 << TWSTO);
	TWCR &= ~ (1 << TWSTA);

}

void I2C_start() {

	TWCR |= (1 << TWSTA);

}

void I2C_write(uint8_t data) {

	I2C_sendingData = data;

}

uint8_t I2C_read() {
	return I2C_receivedData;

}

void I2C_write_to(uint8_t address) {
	uint8_t Add_W = (address <<  1); // 7 bit Address + Write bit is sent, Write bit = 0
	I2C_write(Add_W);
}

void I2C_read_from(uint8_t address) {

	uint8_t Add_R = (address <<  1) + 1; // 7 bit Address + Read bit is sent, Read bit = 1
	I2C_write(Add_R)
}



void I2C_stop(void) {

	TWCR &= ~( (1<<TWEA) | (1<<TWEN) ); // Reset Enable and Ack bits

	}





ISR(TWI_vect) {
	uint8_t status = TWSR & 0xF8; // Getting the most significant 5 bits in the register.

	switch(status)
	{
	/* Master Receiver Mode */

	case START: // Address + write has been received
				TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE);
				//I2C_receivedData = TWDR;
				break;	

	case REP_START:
				TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE);
				break;
	case MT_SLA_W_ACK:
				TWDR = I2C_sendingData;
				TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE);
				break;
	case MT_SLA_R_ACK:
				I2C_receivedData = TWDR;
				TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE);
				break;
	case MR_DATA_ACK:
				I2C_receivedData = TWDR;
				TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE);
				break;
	case MR_DATA_NACK:
				I2C_receivedData = TWDR;
				TWCR =  (1 << TWSTA) | (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE);
				break;

	}

	TWCR |= (1<<TWINT); // clear flag

	}




	/************* Another I2C_write() function implementation to be tested ************/ 
	/*
	void I2C_write(uint8_t data) {
		TWDR = data;
		I2C
		
		TWCR = (1 << TWINT) | (1 << TWEN);
		
	}

	*/