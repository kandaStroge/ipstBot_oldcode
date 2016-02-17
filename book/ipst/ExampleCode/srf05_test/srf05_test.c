#include <sleep.h>
#include <lcd.h>
#include <srf05_lib.h>

void main()
{
	unsigned int dist;
	while(1)
	{
		dist = srf05_dist(ECHO_PB0,PULSE_PB1);
		lcd("Distance: %d cm   ",dist);
		sleep(10);
	}

}
