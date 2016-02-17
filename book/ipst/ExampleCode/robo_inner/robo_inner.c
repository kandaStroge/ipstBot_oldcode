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
	unsigned int left,right;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		left = analog(0);
		right = analog(2);
		if(left>REF && right>REF)
		{
			forward(10);
		}
		else if(left<REF && right>REF)
		{
			backward(1000);
			turn_right(1500);
		}
		else if(left>REF && right<REF)
		{
			backward(1000);
			turn_left(1500);
		}
		else if(left<REF && right<REF)
		{
			backward(1000);
			turn_left(1500);
		}
	}
}
