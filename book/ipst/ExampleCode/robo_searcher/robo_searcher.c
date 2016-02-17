#include <motor.h>	
#include <sleep.h>
#include <in_out.h>
#include <lcd.h>
#include <servo.h>
#include <gp2d120_lib.h>
	
#define POW 70
#define GET_MID 55
#define GET_LEFT 86
#define GET_RIGHT 18
#define DIST_MIN 25
	
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
	unsigned int dist,dist_l,dist_r;
	servo(0,GET_MID);
	lcd("Press SW1");
	sw1_press();
	
	while(1)
	{
		servo(0,GET_MID);
		dist = getdist(4);
		if(dist>=4 && dist<=12)
		{
			pause();
			
			servo(0,GET_LEFT);
			sleep(1000);
			dist_l = getdist(4);
			
			servo(0,GET_RIGHT);
			sleep(1000);
			dist_r = getdist(4);
			servo(0,GET_MID);
			sleep(1000);
			if(dist_l>=dist_r && dist_l>DIST_MIN)
			{
				turn_left(300);	
			}
			else if(dist_r>dist_l && dist_r>DIST_MIN)
			{
				turn_right(300);	
			}
			else
			{
				backward(1000);
				turn_right(500);
			}
			
		}
		else
		{
			forward(10);
		}
		
	}

}
