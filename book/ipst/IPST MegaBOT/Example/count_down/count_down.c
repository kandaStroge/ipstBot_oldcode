#include <in_out.h>
#include <sleep.h>
#include <lcd.h>
void main()
{
	int i;
	for(i=10;i>0;i--)
	{
		lcd("Count: %d  ",i);
		sleep(1000);
	}
	lcd("Count: %d  ",i);
}

