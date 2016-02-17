#include <sleep.h>	
#include <in_out.h>	
#include <lcd.h>	

void main()
{
	while(1)
	{
		lcd("Switch1: %d  #nSwitch2: %d ",in_a(0),in_a(1));
		sleep(10);
	}

}
