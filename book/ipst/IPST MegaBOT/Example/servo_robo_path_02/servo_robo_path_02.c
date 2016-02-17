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
void pause()
{
	servo_pause(0);	
	servo_pause(1);	
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
void cross_pass()
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
			forward(200);
			break;
		}
	}
}
void main()
{
	lcd("Press SW1");
	sw1_press();
	cross_turn_right();
	cross_pass();
	cross_pass();
	cross_pass();
	cross_pass();
	pause();
}



