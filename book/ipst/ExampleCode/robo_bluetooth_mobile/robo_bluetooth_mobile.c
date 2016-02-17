#include <motor.h>	
#include <sleep.h>	
#include <lcd.h>	
#include <sound.h>
#include <serial.h>
#define POW 70	
void forward(unsigned int delay)
{
	motor(1,POW);
	motor(2,POW);
	sleep(delay);
}
void backward(unsigned int delay)
{
	motor(1,-POW);
	motor(2,-POW);
	sleep(delay);
}

void turn_left(unsigned int delay)
{
	motor(1,-POW);
	motor(2,POW);
	sleep(delay);
}
void turn_right(unsigned int delay)
{
	motor(1,POW);
	motor(2,-POW);
	sleep(delay);
}
void pause()
{
	motor_stop(1);
	motor_stop(2);
}
void main()
{
	char command;
	lcd("wait for Mobile");
	while(1)
	{
		command = uart_getkey();
		if(command=='A')
		{
			beep_b(4);
			forward(1);
		}
		if(command=='B')
		{
			beep_b(4);
			backward(1);
		}
		if(command=='C')
		{
			beep_b(4);
			turn_left(1);
		}
		if(command=='D')
		{
			beep_b(4);
			turn_right(1);
		}
		if(command=='S')
		{
			beep_b(4);
			pause();
		}
	}

}
