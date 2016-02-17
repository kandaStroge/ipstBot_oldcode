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
		sleep(100);
	}
}
