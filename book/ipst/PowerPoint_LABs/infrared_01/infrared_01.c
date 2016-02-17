#include <analog.h>
#include <lcd.h>
#include <sleep.h>
void main()
{
	int infrared=0;
	while(1)
	{
		infrared = analog(3);
		lcd("Infrared: %d ",infrared);
		sleep(100);
	}
}
