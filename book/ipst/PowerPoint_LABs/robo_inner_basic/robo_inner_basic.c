#include <motor.h>	
#include <sleep.h>	
#include <in_out.h>	
#include <analog.h>	
#include <lcd.h>	
#define POW 70
#define REF 600
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
void main()
{
	unsigned int sensor;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		sensor = analog(0);
		if(sensor>REF)
		{
			forward(10);
		}
		else 
		{
			backward(500);
			turn_right(800);
		}
	}
}
