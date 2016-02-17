#include <motor.h>	
#include <sleep.h>
#include <in_out.h>
#include <lcd.h>
#include <srf05_lib.h>	
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
		dist = srf05_dist(ECHO_PB0,PULSE_PB1);
		if(dist>=3 && dist<=12)
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
