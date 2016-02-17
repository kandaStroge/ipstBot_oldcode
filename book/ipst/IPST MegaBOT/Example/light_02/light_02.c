#include <analog.h>
#include <lcd.h>
#include <sleep.h>
void main()
{
	int light=0;
	while(1)
	{
		light = analog(1);
		lcd("Light: %d ",light);
		if(light<100)
		{
			out_d(7,1);
		}
		else
		{
			out_d(7,0);
		}
		sleep(100);
	}
}
