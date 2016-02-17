#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>

#ifndef _SERVO_H_
#define _SERVO_H_

char servo_ini = 0;
unsigned char activeServo[5]={0,0,0,0,0,0};
unsigned char timeBaseServo[5]={0,0,0,0,0};
unsigned long timerTick=0;

SIGNAL(SIG_OVERFLOW0) // Interval 50 us
{
	//TCNT0 = 156;	// Reload Interval 50 us  
	TCNT0 = 206;	// Reload Interval 25 us  
	timerTick++;
	if(timerTick>=1000)
	{
		timerTick = 0;
	}
	if(activeServo[0]==1)
	{
		if(timerTick<=timeBaseServo[0])
			PORTB |= 0x01;
		else
			PORTB &= 0xFE;
	}
	if(activeServo[1]==1)
	{
		if(timerTick<=timeBaseServo[1])
			PORTB |= 0x02;
		else
			PORTB &= 0xFD;
	}
	if(activeServo[2]==1)
	{
		if(timerTick<=timeBaseServo[2])
			PORTB |= 0x04;
		else
			PORTB &= 0xFB;
	}
	if(activeServo[3]==1)
	{
		if(timerTick<=timeBaseServo[3])
			PORTB |= 0x08;
		else
			PORTB &= 0xF7;
	}
	if(activeServo[4]==1)
	{
		if(timerTick<=timeBaseServo[4])
			PORTB |= 0x10;
		else
			PORTB &= 0xEF;
	}
}
void servo_start(void) // Config. and Start up timer 0 
{
   
	TCCR0 = (1<<CS01); 	// Prescaler 8,16 MHz,1 MC = 8/16M = 0.5 us/count 
	TIFR |= 1<<TOV0; 	//Clear TOV0 / clear
	TIMSK |= 1<<TOIE0; 	//Enable Timer0 Overflow Interrupt
	//TCNT0 = 156;	// Interval 50 us  	
    TCNT0 = 206;	// Interval 50 us  	
    
	sei();	// Enable all interrupt
	timerTick = 0;
	servo_ini = 1;
}
void servo_stop()
{
	TCCR0 = 0;		// Stop timer and 
	TCNT0 = 0;
	TIMSK &= ~_BV(TOIE0);	
	timerTick = 0;
	servo_ini = 0;
}
void servo(unsigned char _ch,unsigned int _pos)
{
	if(servo_ini==0)
	{
		servo_start();
		servo_ini=1;
	}
	if(_ch>=0 && _ch<=4)
	{
		DDRB |= 1<<(_ch);
		timeBaseServo[_ch] = _pos;
		activeServo[_ch]=1;
	}
}
void servo_pause(char _ch)
{
	if(_ch>=0 && _ch<=4)
	{
		activeServo[_ch]=0;
	}
}
void servo_resume(char _ch)
{
	if(_ch>=0 && _ch<=4)
	{
		activeServo[_ch]=1;
	}
}
unsigned char servo_get_status(char _ch)
{
	return(activeServo[_ch]);
}

#endif
