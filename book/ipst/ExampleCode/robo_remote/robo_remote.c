#include <motor.h>	
#include <sleep.h>	
#include <lcd.h>	
#include <sound.h>
#include <serial.h>
#define POW 70	
void forward(unsigned int delay)
{
	motor(1,POW);
	motor(2,POW);
	sleep(delay);
}
void backward(unsigned int delay)
{
	motor(1,-POW);
	motor(2,-POW);
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
	char command;
	uart_set_baud(1200);
	lcd("Wait for remote");
	while(1)
	{
		command = uart_getkey();
		if(command=='a' || command=='A')
		{
			beep_b(4);
			backward(1);
		}
		if(command=='b' || command=='B')
		{
			beep_b(4);
			turn_right(1);
		}
		if(command=='c' || command=='C')
		{
			beep_b(4);
			turn_left(1);
		}
		if(command=='d' || command=='D')
		{
			beep_b(4);
			forward(1);
		}
	}

}
