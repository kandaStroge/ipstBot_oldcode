#include <servo.h>
#include <sleep.h>
#include <in_out.h>
#include <lcd.h>

#define SERVO_MID 55
#define SERVO_SPEED 5

void forward(unsigned int delay)
{
	servo(0,SERVO_MID+SERVO_SPEED);
	servo(1,SERVO_MID-SERVO_SPEED);
	sleep(delay);
}
void turn_left(unsigned int delay)
{
	servo(0,SERVO_MID-SERVO_SPEED);
	servo(1,SERVO_MID-SERVO_SPEED);
	sleep(delay);
}
void main()
{
	lcd("Press SW1");
	sw1_press();	
	while(1)
	{
		forward(2000);
		turn_left(500);
	}

}
