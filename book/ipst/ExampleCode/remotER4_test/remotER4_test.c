#include <lcd.h>
#include <sleep.h>
#include <serial.h>

void main()
{
	char command; 
	uart_set_baud(1200);
	while(1)
	{
		command = uart_getkey();
		lcd("Key Value: %c  ",command);
	}
}
