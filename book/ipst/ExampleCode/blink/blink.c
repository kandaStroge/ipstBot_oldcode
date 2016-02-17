#include <in_out.h>
#include <sleep.h>
void main()
{
	while(1)
	{
		set_a(5);
		sleep(300);
		clear_a(5);
		sleep(300);
	}
}
