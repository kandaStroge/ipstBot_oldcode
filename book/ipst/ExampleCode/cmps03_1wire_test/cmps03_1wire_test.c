#include <sleep.h>
#include <lcd.h>
#include <cmps03_pwm_lib.h>
void main()
{
	unsigned int angle;
	while(1)
	{
		angle = cmps03_pwm_angle(PWM_PB4);
		lcd("Angle: %d  ",angle);
		sleep(10);
		
	}

}
