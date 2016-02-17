#include <motor.h>
#include <analog.h>
#include <sleep.h>
#define POW 100
#define REF 400

void run_fd(unsigned int delay)
{
	motor(1,-POW);
	motor(2,-POW);
	sleep(delay);
}
void run_bk(unsigned int delay)
{
	motor(1,POW);
	motor(2,POW);
	sleep(delay);
}
void turn_left(unsigned int delay)
{
	motor(1,-POW);
	motor(2,POW);
	sleep(delay);
}
void turn_right(unsigned int delay)
{
	motor(1,POW);
	motor(2,-POW);
	sleep(delay);
}

void main()
{
	int left,mid,right;
	while(1)
	{
		left = analog(0);
		mid = analog(1);
		right = analog(2);
		
		if(left<REF && mid>REF && right<REF)
		{
			run_fd(100);
		}
		else if(left>REF && mid>REF && right<REF)
		{
			turn_left(10);
		}
		else if(left>REF && mid<REF && right<REF)
		{
			turn_left(10);
		}
		else if(left<REF && mid>REF && right>REF)
		{
			turn_right(10);
		}
		else if(left<REF && mid<REF && right>REF)
		{
			turn_right(10);
		}
		else if(left>REF && mid>REF && right>REF)
		{
			run_fd(100);
		}
	
		
		
		
		
		
		
		
			
	}

}
