#include <lcd.h>
#include <sleep.h>
#include <serial.h>
#include <sound.h>

void main()
{
	char key[17],i;
	for(i=0;i<16;i++)
	{
		key[i]='*';
	}
	key[17]=0;

	while(1)
	{
		
		//lcd(key);
		//lcd("#n%d  ",_sdat_in);
		lcd("#n%d  ",_key);
		if(sw1()==0)
		{
			beep_b(4);
			sleep(100);
			for(i=0;i<16;i++)
			{
				key[i]= uart_getkey();
			}
			key[17]=0;
			lcd(key);
		}
	}
}
/*void main()
{
	char key;
	uart("Hello I am Robot\r\n"); 
	lcd("Bluetooth wait");
	while(1)
	{
		key = uart_getkey();
		if(key==27)
		{
			//uart("Rcv 27 \r\n");
			sleep(25);
			key = uart_getkey();
			if(key==65)
				uart("You press key: Arrow UP \r\n");
			if(key==66)
				uart("You press key: Arrow DOWN \r\n");
			if(key==67)
				uart("You press key: Arrow RIGHT \r\n");
			if(key==68)
				uart("You press key: Arrow LEFT \r\n");
		}
		else
		{
			if(key=='A')
			{
				uart("You press key: A \r\n");
			}
			if(key=='B')
			{
				uart("You press key: B \r\n");
			}
			if(key=='C')
			{
				uart("You press key: C \r\n");
			}
			if(key=='D')
			{
				uart("You press key: D \r\n");
			}
		}
	}
}*/
