#include <in_out.h>
#include <lcd.h>
#include <sleep.h>
void main()
{
	int i=0;
	while(1)
	{
		if(sw1()==0)
		{
			i++;
			sleep(200);
		}
		if(sw2()==0)
		{
			i--;
			sleep(200);
		}
		lcd("Count: %d ",i);
	}
}
