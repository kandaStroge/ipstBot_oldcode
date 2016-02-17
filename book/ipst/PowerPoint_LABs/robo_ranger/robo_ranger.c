#include <motor.h>	
#include <sleep.h>
#include <in_out.h>
#include <lcd.h>
#include <gp2d120_lib.h>	
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
	unsigned int dist;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		dist = getdist(4);
		if(dist>=4 && dist<15)
		{
			backward(1000);
			turn_left(1500);
		}
		else
		{
			forward(10);
		}
		
	}

}
