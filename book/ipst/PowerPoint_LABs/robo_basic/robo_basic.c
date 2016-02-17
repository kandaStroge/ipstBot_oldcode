#include <motor.h>	
#include <sleep.h>	
#include <in_out.h>	
#include <lcd.h>	

#define POW 70	
void forward(unsigned int delay)
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
void main()
{
	lcd("Press SW1");
	sw1_press();
	while(1)
	{
		forward(2000);
		turn_left(500);
	}

}
