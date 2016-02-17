#include <lcd.h>		
#include <sleep.h>	
#include <servo.h>	
#include <in_out.h>	
void main()
{
	lcd("Press SW1");	
	sw1_press();
	lcd("Servo Run");	
	servo(0,60);	
	sleep(5000);
	servo_pause(0);
	lcd("Servo Stop");	

}
