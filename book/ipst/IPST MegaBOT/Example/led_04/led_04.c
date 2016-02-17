#include <in_out.h>
#include <sleep.h>
void main()
{
	while(1)
	{
		out_d(7,1);
		sleep(500);
		out_d(7,0);
		sleep(500);
	}
}
