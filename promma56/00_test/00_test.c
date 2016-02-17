#include <motor.h>
#include <sleep.h>
#include <analog.h>
#include <in_out.h>
#include <lcd.h>
#include <servo.h>
#include <sound.h>
#include <gp2d120_lib.h>

#define POW 50
#define LPOW 50
#define REF 1
#define GRP 30	//degree
#define SIL	beep_d(1)
#define SIC	beep_d(1);
#define L1  in_a(1)
#define L2	in_a(0)
#define CT	in_b(2)
#define R1	in_b(3)
#define R2	in_b(4)
#define CC	in_a(5)	//Check can

#define BL in_a(2)
#define BR in_a(3)
#define BC in_a(6)

#define SERVO_GRP 0	//25max-85min
#define SERVO_GRP_MIN 25
#define SERVO_GRP_MAX 70
#define SERVO_ARM 1
#define SERVO_ARM_MIN 20
#define SERVO_ARM_MAX 40
//min45-max80

#define COLOR in_a(5)

#define INFARED getdist(4);

#define DENT_CAN 7 //cm

#define WBW	(L1>=REF&&CT< REF&&R1>=REF)
#define	BWW (L1< REF&&CT>=REF&&R1>=REF)
#define WWB (L1>=REF&&CT>=REF&&R1< REF)
#define	BBW (L1< REF&&CT< REF&&R1>=REF)
#define WBB (L1>=REF&&CT< REF&&R1< REF)
#define BBB	(L1< REF&&CT< REF&&R1< REF)
#define WWW	(L1>=REF&&CT>=REF&&R1>=REF)
#define W_W	(L1>=REF&&R1>=REF)
#define B_B	(L1< REF&&R1< REF)
#define W_B	(L1>=REF&&R1< REF)
#define B_W	(L1< REF&&R1>=REF)

#define BBBBB (L2< REF&&L1< REF&&CT< REF&&R1< REF&&R2< REF)




void main(){
while(1){
sleep(200);
lcd("Selec");
	if(sw1()==0){
	lcd("Forward");
		while(1){
			forward(10);
		}
	}
	else if(sw2()==0){
		lcd("Bump 1 2 3 4 to#n PA2 3 4 5");
		while(1){
		chk_line6();
		}
	}

	else if(sw3()==0){
	lcd("forward Backward# left right");
		sleep(1000);
		while(1){
			chk_movement();
		}
	}
}
			
}






/* Track line */
void trackto(){
	if(W_W){forward(100);}
	else if(W_B){turn_right(10);}
	else if(B_W){turn_left(10);}
}
void trackline(){
		if(WBW){forward(100);}
		else if(WWB){turn_right(10);}
		else if(BWW){turn_left(10);}
}


/* Basic function */
void startup(){
	lcd("Press SW1");
	servo_close();
	servo_stop();
	sw1_press();
}

void chk_line6(){	lcd("L1:%d L2:%d CT:%d #nR1:%d R2:%d",L1,L2,CT,R1,R2);}
void chk_line9(){	lcd("BL1:%d L2:%d CT:%d #nR1:%d R2:%d",L1,L2,CT,R1,R2);}




void chk_servo_pos(){
	int na,nb,ea,eb,ec,ed;
	na=25;
	nb=25;

	while(1){
		ea = in_a(2);
		eb = in_a(3);
		ec = in_a(4);
		ed = in_a(5);

		servo(0,na);
		servo(1,nb);
		if(ea==0){na+=5;}
		else if(eb==0){na-=5;}
		else if(ec==0){nb+=5;}
		else if(ed==0){nb-=5;}
		lcd("K:%d   #nA:%d   ",na,nb);
	}
}

void chk_movement(){

	while(1){
	 forward(1000);SIL;
	 backward(1000);SIL;
	 turn_left(1000);SIL;
	 turn_right(1000);
	 SIL;
	}

}

void chk_gripper(){
	while(1){
		if(in_a(2)==0){servo_open();lcd("open      ");}
		else if(in_a(3)==0){servo_close();lcd("Close      ");}
		else if(in_a(4)==0){servo_put();lcd("Put     ");}
	}
}

void chk_infa(){
	int dist;
	while(1){
		dist = getdist(6);
		lcd("%d        ",dist);
		sleep(500);
	}
}


/* Basic controll */
void forward(unsigned int delay){
	motor(1,POW);
	motor(2,POW);
	sleep(delay);
}

void backward(unsigned int delay){
	motor(1,-POW);
	motor(2,-POW);
	sleep(delay);
}

void turn_left(unsigned int delay){
	motor(1,-POW);
	motor(2,POW);
	sleep(delay);
}

void turn_right(unsigned int delay){
	motor(1,POW);
	motor(2,-POW);
	sleep(delay);
}

void pause(delay){   
	motor_stop(ALL);
	sleep(delay);
}




/* Movement function */  
void L90(){
	forward(20);
	while(L1>=REF){
		turn_left(20);
	}
	while(L1<REF){
		turn_left(20);
	}
	pause(400);
			
}

void R90(){
	forward(20);
	while(R1>=REF){
		turn_right(20);
	}
	while(R1<REF){
		turn_right(20);
	}
	pause(400);
	
		
}

/* Gripper */
void servo_open(){
	servo(SERVO_GRP,SERVO_GRP_MAX);sleep(200);
	servo(SERVO_ARM,SERVO_ARM_MIN);sleep(200);
	servo(SERVO_ARM,SERVO_ARM_MIN);sleep(200);
	servo_stop();
}

void servo_close(){
	servo(SERVO_GRP,SERVO_GRP_MIN);sleep(200);
	servo(SERVO_ARM,SERVO_ARM_MAX);sleep(200);
	servo(SERVO_ARM,SERVO_ARM_MAX);sleep(200);
	servo_stop();
}

void servo_put(){
	servo(SERVO_ARM,SERVO_ARM_MIN);sleep(200);
	servo(SERVO_GRP,SERVO_GRP_MAX);sleep(200);
	servo(SERVO_GRP,SERVO_GRP_MAX);sleep(200);
	servo_stop();
}



/* NOTE
Set motor :: Right to "m1" and Left "m2"
Set servo :: Gripper to "servo_B0"
Set senso :: Leftest to PA0 , PA1 , PA.. or Digi to PB0...
Set CKbox :: Checkbox sensor "PD0"
Set Degre :: Degree of servo shoud set "0" to Leftest
Set Infar :: Infared Front set to PA5 

*/

/*
Alogorithm


*/

