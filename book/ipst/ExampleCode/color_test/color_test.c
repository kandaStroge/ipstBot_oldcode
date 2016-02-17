#include <lcd.h>
#include <analog.h>
void main()
{
	while(1)
	{
		lcd("Color: %d   ",analog(5));
		sleep(10);
	}
}
