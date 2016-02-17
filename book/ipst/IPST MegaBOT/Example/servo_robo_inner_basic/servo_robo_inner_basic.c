#include <servo.h>
#include <sleep.h>
#include <in_out.h>
#include <analog.h>
#include <lcd.h>
#define SERVO_MID 55
#define SERVO_SPEED 5
#define REF 500

void forward(unsigned int delay)
{
	servo(0,SERVO_MID+SERVO_SPEED);
	servo(1,SERVO_MID-SERVO_SPEED);
	sleep(delay);
}
void backward(unsigned int delay)
{
	servo(0,SERVO_MID-SERVO_SPEED);
	servo(1,SERVO_MID+SERVO_SPEED);
	sleep(delay);
}
void turn_left(unsigned int delay)
{
	servo(0,SERVO_MID-SERVO_SPEED);
	servo(1,SERVO_MID-SERVO_SPEED);
	sleep(delay);
}
void turn_right(unsigned int delay)
{
	servo(0,SERVO_MID+SERVO_SPEED);
	servo(1,SERVO_MID+SERVO_SPEED);
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
