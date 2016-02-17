#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_
#include <in_out.h>
#define CLK(x)	out_d(2,x)
#define CS(x)	out_d(3,x)
#define DOUT(x)	out_d(4,x)
#define DIN()	in_d(5)


#define JOY_SQUARE	0x8000
#define JOY_X	0x4000
#define JOY_O	0x2000
#define JOY_TRIANGLE	0x1000
#define JOY_R1	0x0800
#define JOY_L1	0x0400
#define JOY_R2	0x0200
#define JOY_L2	0x0100
#define JOY_LEFT	0x0080
#define JOY_DOWN	0x0040
#define JOY_RIGHT	0x0020
#define JOY_UP	0x0010
#define JOY_START	0x0008
#define JOY_SELECT	0x0001

unsigned char joystick_ini=0;
void joystick_init()
{
	if(joystick_ini==0)
	{
		joystick_ini=1;
		CLK(0);
		CS(1);
		DOUT(0);
	}
}
unsigned char readJoy(unsigned char BYTE_OUT)
{
	unsigned char BYTE_IN=0;
	unsigned char i,j=0x01;
	joystick_init();
	for (i=0;i<8;i++)
	{ // Loop 8 Time for Send and Recieve Byte
		if((BYTE_OUT&j)==j ) // Test Bit 0 or 1
		{ DOUT(1);} // Set Dout
		else
		{ DOUT(0);}
		CLK(1); // Clock Pulse High
			BYTE_IN=(BYTE_IN>>1); // Receive Byte LSB First
			if (DIN()==1)
		{BYTE_IN=(BYTE_IN | 0x80);}
		CLK(0); // Clock Pulse Low
		j=j<<1;
	}
	return BYTE_IN;
}
unsigned int getJoy()
{
	unsigned char PSX_IN;
	unsigned char PSX_ID;
	unsigned char PSX_STATUS;
	unsigned char PSX_LEFT;
	unsigned char PSX_RIGHT;
	CS(0);
		PSX_IN=readJoy(0x01); // Send Start Command
		PSX_ID=readJoy(0x42); // Send Command Read Switch and Read ID
		PSX_STATUS=readJoy(0x00); // Read STATUS (0x5A)
		PSX_LEFT=readJoy(0x00); // Read Byte 0
		PSX_RIGHT=readJoy(0x00); // Read Byte 1
	CS(1);
	return((PSX_RIGHT<<8)|PSX_LEFT);
}
unsigned char testJoy(unsigned int key)
{
	unsigned int joy_val;
	joy_val = getJoy();
	if((joy_val & key)==key)
		return(0);
	else
		return(1);
}
#endif
