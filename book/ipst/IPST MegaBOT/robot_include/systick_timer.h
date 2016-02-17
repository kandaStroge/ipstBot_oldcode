// Resource:	base on Timer2(8 bit timer counter)


#ifndef _SYSTICK_TIMER_H_
#define _SYSTICK_TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>


unsigned long _tick=0;

SIGNAL(SIG_OVERFLOW2) // Interval 512 us
{
	_tick++;	
}
void systick_start(void) // Config. and Start up timer 0 
{
   
	TCCR2 = (1<<CS21)|(1<<CS20); 	// Prescaler 32,16 MHz,1 MC = 32/16M = 2us/count 
	TIFR |= 1<<TOV2; 	//Clear TOV0 / clear
	TIMSK |= 1<<TOIE2; 	//Enable Timer0 Overflow Interrupt
	TCNT2 = 0;	// Interval 512 us  	
    
	sei();	// Enable all interrupt
	_tick = 0;
}
void systick_stop()
{
	TCCR2 = 0;		// Stop timer and 
	TCNT2 = 0;
	TIMSK &= ~_BV(TOIE2);	// Clear bit TOIE0
	_tick = 0;		// Clear time
}
void systick_pause()
{
	TCCR2 = 0;		// Stop timer and not clear time
}
void systick_resume()
{
	TCCR2 = (1<<CS21)|(1<<CS20); 	// Prescaler 32,16 MHz,1 MC = 32/16M = 2us/count 
}
unsigned long usec()
{
	return((_tick*512)+(TCNT2*2));	
} 
#endif
