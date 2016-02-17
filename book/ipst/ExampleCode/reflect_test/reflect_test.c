#include <sleep.h>	
#include <analog.h>	
#include <lcd.h>	
void main()
{
	while(1)
	{
		lcd("L %d  M %d    #nR %d    ",analog(0),analog(1),analog(2));
		sleep(10);
	}
}
