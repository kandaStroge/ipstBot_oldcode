#include <in_out.h>
#include <lcd.h>
#include <sleep.h>
void main()
{
	int i=0;
	lcd("Press SW1#nfor Counter");
	sw1_press();
	lcd("#c");
	while(1)
	{
		lcd("Count: %d ",i++);
		sleep(1000);
	}
}
