#include <lcd.h>
#include <i2c.h>
#include <sleep.h>
#define TPA81_ID 0xD0	// Constant for CMPS03 ID 

#define PIXEL1 2
#define PIXEL2 3
#define PIXEL3 4
#define PIXEL4 5
#define PIXEL5 6
#define PIXEL6 7
#define PIXEL7 8
#define PIXEL8 9



unsigned char tpa81_temp(char pixel)
{
	unsigned char dat;	// Keep data from read
	TWBR = 60;	// Ensure decrease bit rate i2c bus
	i2c_start();		// Start condition
	i2c_write(TPA81_ID);	// Send CMPS03 ID 
	i2c_write(pixel);		// Send command get data 2 byte(return data range 0-3599)
	
	i2c_start();	// Restart condition
	i2c_write(TPA81_ID+1);	// Send CMPS03 ID for Read mode	
	dat = i2c_read(NACK);	// Read high byte from CMPS03(wait acknowledge)
	i2c_stop();					// Stop condition
	return(dat);		// Return value div 10
}

void main()
{
	while(1)
	{
		lcd("%d,%d,%d,%d    #n%d,%d,%d,%d    ",tpa81_temp(PIXEL1),tpa81_temp(PIXEL2),tpa81_temp(PIXEL3),tpa81_temp(PIXEL4),tpa81_temp(PIXEL5),tpa81_temp(PIXEL6),tpa81_temp(PIXEL7),tpa81_temp(PIXEL8));
		//lcd("%d %d  ",tpa81_temp(PIXEL1),tpa81_temp(PIXEL2));
		sleep(10);
	}
}
