#include <sleep.h>	
#include <lcd.h>
#include <sound.h>
#include <gp2d120_lib.h>
void main()
{
	unsigned int dist;
	while(1)
	{
		dist = getdist(4);
		lcd("Distance: %d cm  ",dist);
		if(dist>=4 && dist<=20)
		{
			beep_d(6);
		}
		sleep(200);
	}
}
