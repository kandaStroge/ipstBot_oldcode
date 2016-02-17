#include <in_out.h>
#include <sleep.h>
void main()
{
	while(1)
	{
		if(in_b(4)==0)
		{
			out_d(7,1);
		}
		else
		{
			out_d(7,0);
		}
	}
}
