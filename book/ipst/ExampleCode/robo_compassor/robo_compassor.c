#include <motor.h>	
#include <sleep.h>
#include <in_out.h>
#include <lcd.h>
#include <cmps03_lib.h>	
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
	unsigned int angle;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		pause();
		angle = cmps03_angle();
		lcd("Angle: %d  ",angle);
		if(angle>=40 && angle<=60)
		{
			forward(100);
		}
		else if(angle>60 && angle<=230)
		{
			turn_left(100);
		}
		else 
		{
			turn_right(100);
		}
		
	}

}
