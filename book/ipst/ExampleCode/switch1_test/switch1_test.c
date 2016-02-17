#include <sleep.h>	
#include <in_out.h>	
#include <lcd.h>	

void main()
{
	while(1)
	{
		lcd("Switch: %d ",in_a(0));
		sleep(10);
	}

}
