#include <lcd.h>
#include <analog.h>
#include <sleep.h>

void main()
{
	
	while(1)
	{
		lcd("L %d  M %d  R %d      ",analog(0),analog(1),analog(2));
		sleep(100);
	}
}
