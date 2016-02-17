#include <analog.h>
#include <lcd.h>
#include <sleep.h>
#include <sound.h>
void main()
{
	int infrared=0;
	while(1)
	{
		infrared = analog(3);
		lcd("Infrared: %d ",infrared);
		if(infrared<500)
		{
			beep_b(4);
		}
		sleep(100);
	}
}
