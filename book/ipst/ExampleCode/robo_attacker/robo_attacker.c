#include <motor.h>	
#include <sleep.h>	
#include <in_out.h>	
#include <lcd.h>	

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
		left = in_d(0);
		right = in_d(1);
		if(left==1 && right==1)
		{
			forward(10);
		}
		else if(left==0 && right==1)
		{
			backward(1000);
			turn_right(800);
		}
		else if(left==1 && right==0)
		{
			backward(1000);
			turn_left(800);
		}
		else if(left==0 && right==0)
		{
			backward(1000);
			turn_left(1500);
		}
	}

}
