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
void pause()
{
	motor_stop(1);
	motor_stop(2);
}
void main()
{
	char key;
	lcd("Wait for PC");
	while(1)
	{
		key = uart_getkey();
		if(key=='w' || key=='W')
		{
			beep_b(4);
			forward(1);
		}
		if(key=='a' || key=='A')
		{
			beep_b(4);
			turn_left(1);
		}
		if(key=='d' || key=='D')
		{
			beep_b(4);
			turn_right(1);
		}
		if(key=='s' || key=='S')
		{
			beep_b(4);
			backward(1);
		}
		if(key=='p' || key=='P')
		{
			beep_b(4);
			pause();
		}
	
	}

}
