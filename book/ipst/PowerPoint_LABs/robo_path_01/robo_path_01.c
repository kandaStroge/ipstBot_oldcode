#include <motor.h>	
#include <sleep.h>	
#include <in_out.h>	
#include <analog.h>	
#include <lcd.h>	
#define POW 70
#define REF 500
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
void cross_turn_right()
{
	unsigned int left,right;
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
			turn_left(10);
		}
		else if(left>REF && right<REF)
		{
			turn_right(10);
		}
		else if(left<REF && right<REF)
		{
			forward(300);
			turn_right(800);
			break;
		}
	}
}
void main()
{
	lcd("Press SW1");
	sw1_press();
	cross_turn_right();
	pause();
}
