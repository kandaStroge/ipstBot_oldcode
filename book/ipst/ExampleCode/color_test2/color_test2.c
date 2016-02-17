#include <lcd.h>
#include <analog.h>
#define BLACK		0	
#define BLUE		127	
#define GREEN		273
#define SKY_BLUE	466	
#define PURPLE		675
#define RED			853
#define ORANGE		965
#define YELLOW		997
#define WHITE		1020

void main()
{
	unsigned int color;
	while(1)
	{
		color = analog(5);
		lcd("#n%d     ",color);
		if(color>=BLACK && color <= BLACK+2)
		{
			lcd("BLACK       ");
		}
		else if(color>=BLUE-2 && color <= BLUE+2)
		{
			lcd("BLUE        ");
		}
		else if(color>=GREEN-2 && color <= GREEN+2)
		{
			lcd("GREEN       ");
		}
		else if(color>=SKY_BLUE-2 && color <= SKY_BLUE+2)
		{
			lcd("SKY-BLUE    ");
		}
		else if(color>=PURPLE-2 && color <= PURPLE+2)
		{
			lcd("PURPLE      ");
		}
		else if(color>=RED-2 && color <= RED+2)
		{
			lcd("RED         ");
		}
		else if(color>=ORANGE-2 && color <= ORANGE+2)
		{
			lcd("ORANGE      ");
		}
		else if(color>=YELLOW-2 && color <= YELLOW+2)
		{
			lcd("YELLOW      ");
		}
		else if(color>=WHITE-2 && color <= WHITE+2)
		{
			lcd("WHITE      ");
		}
		else
		{
			lcd("UNKNOWN    ");
		
		}
		sleep(100);
	}
}
