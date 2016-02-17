#include <in_out.h>
#include <sleep.h>
void main()
{
	while(1)
	{
		if(in_b(4)==0)
		{
			toggle_d(7);
			sleep(200);
		}
	}
}
