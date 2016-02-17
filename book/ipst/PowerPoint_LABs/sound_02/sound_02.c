#include <sound.h>
#include <sleep.h>
void main()
{
	while(1)
	{
		sound_a(5,800,100);
		sleep(1000);
	}
}
