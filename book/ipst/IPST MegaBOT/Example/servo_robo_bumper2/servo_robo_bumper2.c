#include <servo.h>
#include <sleep.h>
#include <in_out.h>
#include <lcd.h>
#include <sound.h>
#define SERVO_MID 55
#define SERVO_SPEED 5

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
	char left,right;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		left = in_a(0);
		right = in_a(1);
		if(left==1 && right==1)
		{
			forward(10);
		}
		else if(left==0 && right==1)
		{
			beep_b(4);
			backward(500);
			turn_right(400);
		}
		else if(left==1 && right==0)
		{
			beep_b(4);
			backward(500);
			turn_left(400);
		}
		else if(left==0 && right==0)
		{
			beep_b(4);
			backward(500);
			turn_left(800);
		}
	}

}

