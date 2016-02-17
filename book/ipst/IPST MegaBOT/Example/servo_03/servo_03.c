#include <lcd.h>		
#include <sleep.h>	
#include <servo.h>	
#include <in_out.h>	
#define SERVO_MID 55
void main()
{
	lcd("Press SW1");	
	sw1_press();
	servo(0,SERVO_MID+5);	
	sleep(2000);
	servo_pause(0);
}
