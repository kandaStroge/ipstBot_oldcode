#include <lcd.h>		
#include <sleep.h>	
#include <servo.h>	
#include <in_out.h>	
void main()
{
	lcd("Press SW1");	
	sw1_press();
	while(1)		
	{
		servo(0,20);	
		sleep(2000);
		servo(0,60);	
		sleep(2000);

	}
}
