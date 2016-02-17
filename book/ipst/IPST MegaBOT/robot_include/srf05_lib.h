// For IPST Robot
#ifndef _ROBOT_SRF05_LIB_H_
#define _ROBOT_SRF05_LIB_H_
#include <systick_timer.h>
#include <in_out.h>
#include <sleep.h>

#define ECHO_PA0 0
#define ECHO_PA1 1
#define ECHO_PA2 2
#define ECHO_PA3 3
#define ECHO_PA4 4
#define ECHO_PA5 5
#define ECHO_PA6 6

#define ECHO_PB0 10
#define ECHO_PB1 11
#define ECHO_PB2 12
#define ECHO_PB3 13
#define ECHO_PB4 14

#define ECHO_PC0 20
#define ECHO_PC1 21

#define ECHO_PD0 30
#define ECHO_PD1 31
#define ECHO_PD2 32
#define ECHO_PD3 33
#define ECHO_PD4 34
#define ECHO_PD5 35
#define ECHO_PD6 36
#define ECHO_PD7 37

#define PULSE_PA0 0
#define PULSE_PA1 1
#define PULSE_PA2 2
#define PULSE_PA3 3
#define PULSE_PA4 4
#define PULSE_PA5 5
#define PULSE_PA6 6

#define PULSE_PB0 10
#define PULSE_PB1 11
#define PULSE_PB2 12
#define PULSE_PB3 13
#define PULSE_PB4 14

#define PULSE_PC0 20
#define PULSE_PC1 21

#define PULSE_PD0 30
#define PULSE_PD1 31
#define PULSE_PD2 32
#define PULSE_PD3 33
#define PULSE_PD4 34
#define PULSE_PD5 35
#define PULSE_PD6 36
#define PULSE_PD7 37

void activePulsePin(unsigned int _pulsePin,char dat)
{
	if(_pulsePin>=PULSE_PA0 && _pulsePin<=PULSE_PA6)
		out_a(_pulsePin-PULSE_PA0,dat);
	else if(_pulsePin>=PULSE_PB0 && _pulsePin<=PULSE_PB4)
		out_b(_pulsePin-PULSE_PB0,dat);
	else if(_pulsePin>=PULSE_PC0 && _pulsePin<=PULSE_PC1)
		out_c(_pulsePin-PULSE_PC0,dat);
	else if(_pulsePin>=PULSE_PD0 && _pulsePin<=PULSE_PD7)
		out_d(_pulsePin-PULSE_PD0,dat);

}
void waitEchoUntil(unsigned int _echoPin,char dat)
{
	if(_echoPin>=ECHO_PA0 && _echoPin<=ECHO_PA6)
	{	
		if(dat){while(in_a(_echoPin-ECHO_PA0)==0);}else{while(in_a(_echoPin-ECHO_PA0));} 
	}
	else if(_echoPin>=ECHO_PB0 && _echoPin<=ECHO_PB4)
	{	
		if(dat){while(in_b(_echoPin-ECHO_PB0)==0);}else{while(in_b(_echoPin-ECHO_PB0));} 
	}
	else if(_echoPin>=ECHO_PC0 && _echoPin<=ECHO_PC1)
	{	
		if(dat){while(in_c(_echoPin-ECHO_PC0)==0);}else{while(in_c(_echoPin-ECHO_PC0));} 
	}
	else if(_echoPin>=ECHO_PD0 && _echoPin<=ECHO_PD7)
	{	
		if(dat){while(in_d(_echoPin-ECHO_PD0)==0);}else{while(in_d(_echoPin-ECHO_PD0));} 
	}
}
unsigned int srf05_dist(unsigned int echoPin,unsigned int pulsePin)
{
   	unsigned long mc;	// Variable for internal this function 
	// Generate pulse trigger srf05
	activePulsePin(pulsePin,1);
	activePulsePin(pulsePin,0);
	
	waitEchoUntil(echoPin,0);	// Ensure logic 0
	waitEchoUntil(echoPin,1);	// Detect rising pulse
	systick_start();		// Start counting pulse width
	waitEchoUntil(echoPin,0);	// Detect falling pulse
	mc = usec();		// Load cycle time count
	sleep(10);		
	return(mc/58);	// Return distance cm scale
}
#endif
