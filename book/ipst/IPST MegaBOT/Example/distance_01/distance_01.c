#include <sleep.h>	
#include <lcd.h>	
#include <gp2d120_lib.h>
void main()
{
	unsigned int dist;
	while(1)
	{
		dist = getdist(4);
		lcd("Distance: %d cm  ",dist);
		sleep(200);
	}
}
