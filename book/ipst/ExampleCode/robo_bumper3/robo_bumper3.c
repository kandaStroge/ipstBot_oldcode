#include <motor.h>	
#include <sleep.h>	
#include <in_out.h>	
#include <lcd.h>	
#include <sound.h>
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
void main()
{
	char left,right;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		left = in_a(0);
		right = in_a(1);
		if(left==0 || right==0)
		{
			beep_b(4);
			backward(1000);
			if(rand()%2==1)
			{
				turn_left(800);
			}
			else
			{
				turn_right(800);
			}
		}
		else
		{
			forward(10);
		
		}
	}
}
