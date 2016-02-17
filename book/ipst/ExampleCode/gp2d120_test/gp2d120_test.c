#include <sleep.h>	
#include <lcd.h>	
#include <gp2d120_lib.h>
void main()
{
	unsigned int dist;
	while(1)
	{
		dist = getdist(4);
		if(dist>=4 && dist<=32)
		{
			lcd("Distance: %d cm  ",dist);
		}
		else
		{
			lcd("Out of Range!    ");
		}
		sleep(200);
	}
}
