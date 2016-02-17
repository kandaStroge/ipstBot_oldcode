#include <sleep.h>
#include <lcd.h>
#include <cmps03_lib.h>
void main()
{
	unsigned int angle;
	while(1)
	{
		angle = cmps03_angle();
		lcd("Angle: %d  ",angle);
		sleep(10);
	}

}
