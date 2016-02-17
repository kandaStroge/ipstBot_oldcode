#include <lcd.h>
#include <sleep.h>
#include <serial.h>

void main()
{
	char key;
	uart("Hello I am Robot\r\n"); 
	lcd("Bluetooth wait");
	while(1)
	{
		key = uart_getkey();
		if(key!=0)
		{
			lcd("Key Value: %c  ",key);
			uart("You press key: %c \r\n",key);
		}
	}
}

