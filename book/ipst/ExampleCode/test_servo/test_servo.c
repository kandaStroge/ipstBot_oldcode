#include <lcd.h>
#include <sleep.h>
#include <servo.h>
#include <in_out.h>
void main()
{
	unsigned char pos=20;
	while(1)
	{
		lcd("Position: %d   ",pos);
		servo(0,pos);
		if(sw1()==0)
		{
			pos++;
			sleep(100);
		}
		if(sw2()==0)
		{
			pos--;
			sleep(100);
		}
	}
}
