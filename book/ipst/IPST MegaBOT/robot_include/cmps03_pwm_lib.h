#ifndef _CMPS03_PWM_LIB_H_
#define _CMPS03_PWM_LIB_H_
#include <in_out.h>
#include <systick_timer.h>

#define PWM_PA0 0
#define PWM_PA1 1
#define PWM_PA2 2
#define PWM_PA3 3
#define PWM_PA4 4
#define PWM_PA5 5
#define PWM_PA6 6

#define PWM_PB0 10
#define PWM_PB1 11
#define PWM_PB2 12
#define PWM_PB3 13
#define PWM_PB4 14

#define PWM_PC0 20
#define PWM_PC1 21

#define PWM_PD0 30
#define PWM_PD1 31
#define PWM_PD2 32
#define PWM_PD3 33
#define PWM_PD4 34
#define PWM_PD5 35
#define PWM_PD6 36
#define PWM_PD7 37

void waitPWMUntil(unsigned int _pwmPin,char dat)
{
	if(_pwmPin>=PWM_PA0 && _pwmPin<=PWM_PA6)
	{	
		if(dat){while(in_a(_pwmPin-PWM_PA0)==0);}else{while(in_a(_pwmPin-PWM_PA0));} 
	}
	else if(_pwmPin>=PWM_PB0 && _pwmPin<=PWM_PB4)
	{	
		if(dat){while(in_b(_pwmPin-PWM_PB0)==0);}else{while(in_b(_pwmPin-PWM_PB0));} 
	}
	else if(_pwmPin>=PWM_PC0 && _pwmPin<=PWM_PC1)
	{	
		if(dat){while(in_c(_pwmPin-PWM_PC0)==0);}else{while(in_c(_pwmPin-PWM_PC0));} 
	}
	else if(_pwmPin>=PWM_PD0 && _pwmPin<=PWM_PD7)
	{	
		if(dat){while(in_d(_pwmPin-PWM_PD0)==0);}else{while(in_d(_pwmPin-PWM_PD0));} 
	}
}
unsigned int cmps03_pwm_angle(unsigned int pwmPin)
{
	unsigned int pwms;
	waitPWMUntil(pwmPin,0);
	waitPWMUntil(pwmPin,1);
	systick_start();
	waitPWMUntil(pwmPin,0);
	pwms  = usec()/1000;
	return((pwms-1)*10);
}

#endif
