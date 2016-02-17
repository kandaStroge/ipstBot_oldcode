#ifndef _CMPS03_LIB_H_
#define _CMPS03_LIB_H_

#include <avr/io.h>	// Header file for AVR MCU 
#include <i2c.h>	// Include Library for i2c bus(module TWI)	

#define CMPS03_ID 0xC0	// Constant for CMPS03 ID 

unsigned int cmps03_angle()
{
	unsigned int angle_val;	// Keep data from read
	TWBR = 60;	// Ensure decrease bit rate i2c bus
	i2c_start();		// Start condition
	i2c_write(CMPS03_ID);	// Send CMPS03 ID 
	i2c_write(2);		// Send command get data 2 byte(return data range 0-3599)
	
	i2c_start();	// Restart condition
	i2c_write(CMPS03_ID+1);	// Send CMPS03 ID for Read mode	
	angle_val = i2c_read(ACK);	// Read high byte from CMPS03(wait acknowledge)
	angle_val <<=8;				// Shift bit for high byte
	angle_val |= i2c_read(NACK); // Read low byte from CMPS03(none acknowledge)
	i2c_stop();					// Stop condition
	return(angle_val/10);		// Return value div 10
}

#endif
