
#ifndef _PATH_LIB_H_
#define _PATH_LIB_H_

#include <sleep.h>
#include <motor.h>
#include <analog.h>
//--------------------------------- For black line -------------------------------------------//

/*#define TRACK_OK ((left>ref)&&(mid<ref)&&(right>ref))
#define CROSS_ALL ((left<ref)&&(mid<ref)&&(right<ref))

#define OVER_LEFT (((left>ref)&&(mid>ref)&&(right<ref))||((left>ref)&&(mid<ref)&&(right<ref)))
#define OVER_RIGHT (((left<ref)&&(mid>ref)&&(right>ref))||((left<ref)&&(mid<ref)&&(right>ref)))
#define CROSS_LEFT ((left<ref)&&(mid<ref)&&(right>ref))
#define CROSS_RIGHT ((left>ref)&&(mid<ref)&&(right<ref))
*/
//--------------------------------- For white line -------------------------------------------//

#define TRACK_OK ((left<ref)&&(mid>ref)&&(right<ref))
#define CROSS_ALL ((left>ref)&&(mid>ref)&&(right>ref))

#define OVER_LEFT (((left<ref)&&(mid<ref)&&(right>ref))||((left<ref)&&(mid>ref)&&(right>ref)))
#define OVER_RIGHT (((left>ref)&&(mid<ref)&&(right<ref))||((left>ref)&&(mid>ref)&&(right<ref)))
#define CROSS_LEFT ((left>ref)&&(mid>ref)&&(right<ref))
#define CROSS_RIGHT ((left<ref)&&(mid>ref)&&(right>ref))
//---------------------------------------------------------------------------------------------//

// Marcro define direction control robot when detect cross line 
#define LEFT  1
#define RIGHT 2
#define PASS  3
#define STOP  4
#define BLACK 5
#define WHITE 6
 
// Variable reference detect Line or Floor 
unsigned int ref = 400;  
// Variable configuration power of motor 
unsigned char pow = 80;
// Variable for keep sensor value (reflect sensor)
unsigned int left=0,right=0,mid=0;     
// Variable define analog port used for reflect sensor 
unsigned char sensor_left_channel = 0;
unsigned char sensor_mid_channel = 1;
unsigned char sensor_right_channel = 2;
// Variable define channel of motor //
unsigned char motor_left_channel = 2;
unsigned char motor_right_channel = 1;



void turn_left(unsigned int spin_time)
{
    motor(motor_right_channel,-pow);
    motor(motor_left_channel,-pow);                   
    sleep(spin_time);                
}
void turn_right(unsigned int spin_time)
{
    motor(motor_right_channel,pow);                   
    motor(motor_left_channel,pow);
    sleep(spin_time);               
}
void run_fd(unsigned int spin_time)
{
    motor(motor_right_channel,-pow);                     
    motor(motor_left_channel,pow);                     
    sleep(spin_time);
}
void run_bk(unsigned int spin_time)
{
    motor(motor_right_channel,pow);                    
    motor(motor_left_channel,-pow);                     
    sleep(spin_time);
}


void set_sensor(int l,int m,int r)
{
    sensor_left_channel = l;
    sensor_mid_channel = m;
    sensor_right_channel = r;
}
void set_motor(int l,int r)
{
    motor_left_channel = l;
    motor_right_channel = r;
}
void set_power(int value)
{
    pow = value;
}
void set_ref(int value)
{
    ref = value;
}
void read_sensor()
{
    left = analog(sensor_left_channel);    // Read value left sensor
    mid = analog(sensor_mid_channel);      // Read value middle sensor
    right = analog(sensor_right_channel);  // Read value right sensor
}
void wait_turnleft_ok()
{
    int temp_pow;
    temp_pow = pow;
    set_power(80);
    while(1)
      {
        read_sensor();
        
    }
}
void spin_find_line()
{
    int spin=0;
    while(spin!=1)
      {
        read_sensor();
        if(OVER_RIGHT)
          turn_left(10);
        else if(OVER_LEFT)
          turn_right(10);
        else if(TRACK_OK)
          spin = 1;
    } 
}
void cross_all(int dir_control)
{
    int result=0;
    while(result!=1)
      {
        read_sensor();
        if(CROSS_ALL)
          {
            if(dir_control==STOP)
              {
                //ao();
                motor_stop(ALL);
				result = 1;
                //beep();
				sleep(100);
            }
            else
              {  
                run_fd(10);
                //beep();
                
                if(dir_control==LEFT)
                  { 
                    run_fd(200);
                    turn_left(600);     // Old 0.8
                } 
                else if(dir_control==RIGHT)
                  {
                    run_fd(200);
                    turn_right(600);   // Old 0.8
                } 
                else if(dir_control==PASS)
                  {   
                    run_fd(200);
                }
                spin_find_line();  
                result = 1;
            } 
        }
        else if(OVER_RIGHT)
          turn_left(10);
        else if(OVER_LEFT)
          turn_right(10);
        else
          {
            run_fd(10);
        }
    }
}
void cross_right(int dir_control)
{
    int result=0;
    while(result!=1)
      {
        read_sensor();
        if(CROSS_RIGHT)
          {
            if(dir_control==STOP)
              {
                //ao();
				motor_stop(ALL);
                result = 1;
                //beep();
            }
            else
              {  
                run_fd(10);
                //beep();
                
                if(dir_control==LEFT)
                  { 
                    run_fd(200);
                    turn_left(500);    // Old 0.8
                } 
                else if(dir_control==RIGHT)
                  {
                    run_fd(200);
                    turn_right(500); // Old 0.8
                } 
                else if(dir_control==PASS)
                  {   
                    run_fd(200);
                }
                spin_find_line();  
                result = 1;
            } 
        }
        else if(OVER_RIGHT)
          turn_left(10);
        else if(OVER_LEFT)
          turn_right(10);
        else
          {
            run_fd(10);
        }
    }
}
void cross_left(int dir_control)
{
    int result=0;
    while(result!=1)
      {
        read_sensor();
        if(CROSS_LEFT)
          {
            if(dir_control==STOP)
              {
                //ao();
                motor_stop(ALL);
				result = 1;
                //beep();
            }
            else
              {  
                run_fd(10);
                //beep();
                
                if(dir_control==LEFT)
                  { 
                    run_fd(200);
                    turn_left(500); // Old 0.8
                } 
                else if(dir_control==RIGHT)
                  {
                    run_fd(200);
                    turn_right(500); // Old 0.8
                } 
                else if(dir_control==PASS)
                  {   
                    run_fd(200);
                }
                spin_find_line();  
                result = 1;
            } 
        }
        else if(OVER_RIGHT)
          turn_left(10);
        else if(OVER_LEFT)
          turn_right(10);
        else
          {
            run_fd(10);
        }
    }
}



#endif
