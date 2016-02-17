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


void main(){
int c1,c2,c3,c4,c5,c6,c7,c8;
lcd("Press SW1");//
servo_close();
servo_stop();
sw1_press();

//#1 StartUp
forward(500);


while(1){
	if(WBB&&R2<REF){forward(50);R90();break;}
	trackto();
}
SIL;

///STEP  2
while(1){
int dist= INFARED
	if(dist>6&&dist<8){
			pause(50);
			//while(CT>REF){turn_right(10);}
			servo_open();
				//if(dist>6){forward(10);}
			servo_close();
			SIL;
			lcd("%d   ",dist);
			c2 = COLOR;
			break;
	}




	else if(W_B){turn_right(10);}
	else if(B_W){turn_left(10);}
	else if(W_W){forward(10);}



}

int cc2=1;
while(1){
	
	trackto();
	if(BBB){forward(100);cc2++;}
	else if(cc2==2){forward(10);
		while(1){
			if(c2==0){turn_right(50);}
			else{turn_left(50);}
		}
	}
	
	
}

while(1){
	while(1){
	trackline();
	}
}






	
motor_stop(ALL);





// R90
 












/*

	//#1 strage BBBBBB
	//{[ void::sp01(){
		forward(10);
		while(WWW){forward(100);}
		SIC;
		
	//]}

	//#2 trackline B_B
	//{[ void::sp02(){
		while(R2>=REF){
			f_trackline();
		}
		SIC;
	//]}

	//#3 if WBB[B] R90
	//{[ void::sp03(){
		while(L1<REF&&L2<REF){R90();}
		SIC;
		
	//#4 Infa=can  Getup
		


	//#5 func:; Cross1  uif cross2 st(litte) if:B TR(liitle)  ; BW cross1 infa=can 
	//#6 if can=W TR:while(B) ; ST:BBB ; ST(little) ; PUTCAN ; BW
	//#7 
	while(1){SIC;}
		trackline(1);
		if(WBB&&R2<REF){
			SIL;
			R90();
		}



*/

}//End main



/* Track line */
void trackto(){
	if(W_W){forward(100);}
	else if(W_B){turn_right(10);}
	else if(B_W){turn_left(10);}
}



/* Basic function */
void LCD_LTK_CHK(){	lcd("L1:%d L2:%d CT:%d #nR1:%d R2:%d",L1,L2,CT,R1,R2);}

void trackline(){
		if(WBW){forward(100);}
		else if(WWB){turn_right(10);}
		else if(BWW){turn_left(10);}
}

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

void lock_right(unsigned int delay){ // nouse
	motor_stop(2);
	motor(2,-POW);
	sleep(delay);
}

void lock_left(unsigned int delay){  // nouse
	motor(1,-POW);
	motor_stop(2);
	sleep(delay);
}

void pause(delay){   
	motor_stop(ALL);
	sleep(delay);
}





	

/* Basic Calculator */  // nouse
long map(long x, long in_min, long in_max, long out_min, long out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
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

