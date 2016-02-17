#include <lcd.h>
#include <sleep.h>
void main()
{
	int i=0;
	while(1)
	{
		lcd("Count: %d ",i);
		sleep(1000);
		i++;
	}
}
