#include <motor.h>	
#include <sleep.h>	
#include <in_out.h>	
#include <analog.h>	
#include <lcd.h>
#include <sound.h>	
#define POW 70
#define REF 600
#define GREEN		273


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
	unsigned int left,mid,right;
	unsigned int color;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		left = analog(0);
		mid = analog(1);
		right = analog(2);
		if(left>REF && mid<REF && right>REF)
		{
			forward(10);
		}
		else if(left<REF && mid>REF && right>REF)
		{
			turn_left(10);
		}
		else if(left>REF && mid>REF && right<REF)
		{
			turn_right(10);
		}
		else if(left<REF && mid<REF && right<REF)
		{
			pause();
			while(2)
			{
				color = analog(5);
				if(color>=GREEN-2 && color <= GREEN+2)
				{
					break;
				}
			}
			beep_b(4);
			forward(200);			
		}
	}
}
