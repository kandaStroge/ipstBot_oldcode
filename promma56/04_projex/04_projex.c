#include <motor.h>
#include <sleep.h>
#include <analog.h>
#include <in_out.h>
#include <lcd.h>
#include <servo.h>
#include <sound.h>
#include <gp2d120_lib.h>

#define POW 60
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

#define BBL	(L2< REF&&L1< REF)
#define WBL	(L2>=REF&&L1< REF)
#define BWL	(L2< REF&&L1>=REF)
#define WWL (L2>=REF&&L1>=REF)

#define BBR	(R1< REF&&R2< REF)
#define WBR	(R1>=REF&&R2< REF)
#define BWR	(R1< REF&&R2>=REF)
#define WWR (R1>=REF&&R2>=REF)

#define BBBBB (L2< REF&&L1< REF&&CT< REF&&R1< REF&&R2< REF)




void main(){


startup();
forward(500);

step01();
step02();

motor_stop(ALL);

}

/* STEP */
void step01(){
	while(1){
		if(W_W||WWL&&WWR){
			forward(10);
		}
		else if(B_W||BWL){
			turn_left(10);
		}
		else if(W_B||WBR){
			turn_right(10);
		}
		else if(WBW||BBR||BBB){
			forward(100);
			R90();
		}
		if(CC<REF){break;}
		
	}
}

void step02(){
int dist;

	SIL;
	forward(10);
	while(1){
		trackto();
dist = INFARED;
		 if(dist>6&&dist<8){
		if(BC<REF){
	backward(100);
			pause(100);
			servo_open();
			forward(10);
			pause(10);
			servo_close();
			break;
		}
		else{lcd("%d  ",dist);break;}
		}
	}

}

void step3(){
	forward(200);
	while(1){
		trackto();
	if(BBB){
		forward(50)	;
	}

}
}

/* Function */
void trackto(){
	if(W_W){ forward(10);}
	else if(B_W){turn_right(10);}
	else if(W_B){turn_right(10);}
}


/* Basic function */
void startup(){
	lcd("Press SW1");
	servo_close();
	servo_stop();
	sw1_press();
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
	while(L2>=REF){
		turn_left(20);
	}
	while(L2<REF){
		turn_left(20);
	}
	while(L1>=REF){
		turn_left(20);
	}
	while(CC<REF){
		forward(10);
	}
	//pause(400);
			
}

void R90(){
	forward(20);
	while(R2>=REF){
		turn_right(20);
	}
	while(R2<REF){
		turn_right(20);
	}
	while(R1>=REF){
		turn_left(20);
	}
	while(CC<REF){
		forward(10);
	}
	//pause(400);
	
		
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

