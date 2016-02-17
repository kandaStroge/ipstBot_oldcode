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
	char mid;
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		mid = in_a(0);
		if(mid==0)
		{
			beep_b(4);
			backward(500);
			turn_left(400);
		}
		else
		{
			forward(10);
		}
	}

}
