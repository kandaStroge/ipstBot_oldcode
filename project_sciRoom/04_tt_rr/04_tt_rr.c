#include <ipst.h>
#include <math.h> 

#define DELAYFUNC out_d
#define DELAYPORT 0
#define SOUNDFUNC sound_d
#define SOUNDPORT 6

#define ANALOG_VOL analog(ANALOG_VOL_PORT)
#define ANALOG_VOL_PORT 0
#define ANALOG_REG analog(ANALOG_REG_PORT)
#define ANALOG_REG_PORT 1

#define FLOAT_K_DEFAULT 850.00
#define TIME_LOOP_CHK_MIN 30

//Build 1.5.560726
void main(){
	int watertime ;
	float ksoil;


//Reset All Setting
resetblock();

//Welcome screen
welcome();

//Chack Stick in Soil And User Confirm
lcd("Step[1/3]#nInstall in soil");
sleep(1000);
chkstickinsoil();

//Set time
lcd("Step[2/3]#n::Set Time");
sleep(1000);
watertime = chktime();

//Fisrt Chack KSoil ; out of loop
lcd("Step[3/3]#n::Find Ksoil");
sleep(1000);
ksoil = firstchksoil();

lcd("#cStep Succ#nEnjoy!!");
sleep(2000);
SOUNDFUNC(SOUNDPORT,3500,500);
DELAYFUNC(DELAYPORT,0);

//chack wet for delay time
chkwetfordelay(watertime,ksoil);

//Finish Loop
while(1){
	chkwetfordelay(watertime,ksoil);

}



/*
sleep(5000);
lcd("%d",ANALOG_REG);
sleep(5000);

//chkVol(0,5,50);
while(1){lcd("%d     #n%d     ",ANALOG_VOL,ANALOG_REG);}
//Press input Reg &chack

//Frist Chack in soil  &by K default
//Set time
//if wet == water & Find Ksoil & delay [time] ; else == next  
//while(1)
//chack soil by Ksoil

//


/*
while(1){

int regg = analog(1);
	lcd("%f     #n%f        ",(float)regg,persen((float)regg,1023,100));
	sleep(200);
}

//lcd("#c%f     ",chkVol());
//sleep(5000);





	//[chack mios of soil] 
	//[]
	
	while(1){
		int regoftime = analog(0), regofsoil = analog(1);
		int a =persen((float)regoftime,1023,60);
		lcd("%d    #%d   #nP %d    ",regoftime,regofsoil,a);
		sleep(100);
		if(a>0){out_d(7,1);}
		else{out_d(7,0);}
	}
*/


}



///////////////// Calculator Func //////////////////////
int Round(float myfloat) //covert float  to integer
{ 
  double integral; 
  float fraction = (float)modf(myfloat, &integral); 
  
  if (fraction >= 0.5) 
    integral += 1; 
  if (fraction <= -0.5) 
    integral -= 1; 
  
  return (int)integral; 
  //Input : 3.1415  ==> Out : 3
}


long covHourtoMin(unsigned int hour)
{
	long a=0;
	a = hour*60*1000;
	return a;
}

float ar(unsigned int port, unsigned int number,unsigned int delay){ //Find Average
	int i,list[number];
	float sum, arg;
	
		//lcd("Plz Wait while #nSysChk Mois ");
		//sleep(1000);
		//lcd("#c");
	

		for(i=0;i<number;i++){ 
			list[i]= analog(port);
			sleep(delay);
			lcd("#c%d     ",analog(port));

			//ar
			sum = sum + list[i];
		}
		arg = sum / number;	
	return arg;
	//Use lcd("#cA%f      ",ar(1,15,200));

}

void sleepMin(unsigned int mina)  //Sleep Def
{
	unsigned int i,j;
	for(i=0;i<mina;i++){
	for(j=0;j<60;j++){
	sleep(1000);}}
}  

float persen(float numa, float maxa,float pera) //return float
{
	float ap;
	ap = (numa/maxa)*pera;
	return ap;
}

float chkVola(unsigned int port, unsigned int number, unsigned int delay) //Chack vol scolling
{
	int ia,lista[number];
	float suma, arga;
	
			for(ia=0;ia<number;ia++){ 
			lista[ia]= analog(port);
			sleep(delay);
			//lcd("#c%d     ",analog(port));

			//ar
			suma = suma + (float)lista[ia];
		}
		arga = suma / number;	
	

if((float)lista[0]==arga){return 1;} //Not scolling
else{return 0;} //Scolling

//Used to  int a = chkVola(0,5,10);
//lcd("%d     ",a);	


}

///////////////// END Calculator func //////////////////////


void welcome(){
	lcd(" l__l l__l   #n l  l l  l5CH00l ");
	sleep(2000);
	lcd("   Welcome to #n      MCT       ");
	sleep("1000");
	SOUNDFUNC(SOUNDPORT,2000,200);
	lcd("#c");
}//complated

void resetblock()
{
	lcd("#cReset All#nPlaese Wait!");
	DELAYFUNC(DELAYPORT,0);  //Port PD0 set Delay
	sleep(1000);
	SOUNDFUNC(SOUNDPORT,3000,1000);
	lcd("#cReset : #nComplated");
	sleep(1000);
	lcd("#c");
}//completed

void chkstickinsoil(){ //For Chack Stick in Soil Only
	unsigned int k,a;
	a = ANALOG_REG;
	lcd("Install biStick to soil");
	SOUNDFUNC(SOUNDPORT,3500,50);
	sleep(5000);
	lcd("#cAnd Scoll Vol for Confirm");
	sleep(3000);
	while(1){
		int brk = chkVola(ANALOG_VOL_PORT,5,200);
		sleep(500);

		if(brk == 0){
			lcd("Still Scolling!!");  //Chack agin for sure
			sleep(2000);
			int brka = chkVola(ANALOG_VOL_PORT,5,200);
			if(brka == 0){
				lcd("#cOk!!#nStick In Soil");sleep(5000);lcd("#c"); break; }
			}
		}

}//Complete

int chktime(){
	unsigned int time_min;
	int ax;
	lcd("#cScolling for Selec time water (min)");
	SOUNDFUNC(SOUNDPORT,3500,500);
	sleep(3000);

	while(1){
		ax = persen((float)ANALOG_VOL,1023,60);
		lcd("#cWater Time : %d    ",ax);
		sleep(10);

		int brktime = chkVola(ANALOG_VOL_PORT,5,100),j=0;		
		if(brktime == 1){
			lcd("#cSure [No/Yes]");  //Chack agin for sure
			sleep(3000);
			
			while(1){
				int axtime =  persen((float)ANALOG_VOL,1023,60) ;
				

				if(axtime <= 1){
					lcd("#cOk!!#nWater time = %d",ax);
					sleep(5000);
					lcd("#c");
					return ax; 
				}

				else if(axtime > 50){
					
					lcd("No! I'm not sure#nScolling Agin");
					sleep(2000);
					j++;
				}
				else if(j>0){break;}				
				
			}
			
		}
	}
	
//use to (int)a = chktime();
} //Complete

float firstchksoil(){
	unsigned int i=0;
	float ksoil;
	lcd("#cSoil First Chack #n");
	sleep(1000);
	DELAYFUNC(DELAYPORT,0);
	float kki = ar(ANALOG_REG_PORT,5,500);
		float kdefault = FLOAT_K_DEFAULT;
	while(1){
		

		lcd("#cKnow: %f      #nKdef: %f     ",kki,kdefault);
		sleep(5000);

		if((float)kki < (float)kdefault){
			ksoil = ar(ANALOG_REG_PORT,10,500);
			lcd("Wet with water");
			sleep(2000);
			return ksoil;
		}

		else if (i==1) //Spacial because It's Waiting for water this first
		{	
			float kkia = 0 , j = 1.0;


			while(1){
				//Chack agin
				kkia = ar(ANALOG_REG_PORT,5,500);
					
				lcd("#cPlz Wait!?#nsoil absorb water");				
				sleep(1000);
				lcd("#cKnow: %f      #nKdef: %f     ",kkia/j,kdefault);

				if(((float)kkia/j) < (float)kdefault){

					ksoil = ar(ANALOG_REG_PORT,10,500);
					lcd("#cSoil is wet?");
					sleep(3000);
					DELAYFUNC(DELAYPORT,0);
					return ksoil;					
				}
			j++;									
				
			}
			

		}

		else{
			SOUNDFUNC(SOUNDPORT,3500,2000);
			lcd("#cWetar for Soil conditioning");
			DELAYFUNC(DELAYPORT,1);
			sleep(5000);  //First water
			i=1;
		}
	}


	//Use to (float)k = firstchksoil();  ; out of loop
}//Complete

void water(){
	SOUNDFUNC(SOUNDPORT,3500,200);
	DELAYFUNC(DELAYPORT,1);
	sleepMin(persen(ANALOG_VOL,1023,100));
	SOUNDFUNC(SOUNDPORT,2000,1000);

}

void chkwetfordelay(unsigned int watertime,unsigned int ksoil){
	if(ksoil < FLOAT_K_DEFAULT){
		DELAYFUNC(DELAYPORT,0);
		lcd("See You In %d",TIME_LOOP_CHK_MIN);
		sleep(3000);
		lcd("#c                            ");
		sleep(10);
		SOUNDFUNC(SOUNDPORT,3500,200);		
		sleepMin(TIME_LOOP_CHK_MIN);
	}
	else if(ksoil >= FLOAT_K_DEFAULT){
		SOUNDFUNC(SOUNDPORT,3500,3000);
		DELAYFUNC(DELAYPORT,1);
		sleepMin(watertime);
		DELAYFUNC(DELAYPORT,0);
		
	}
	//New at 26/7/56
	else if (ksoil < 1){
		SOUNDFUNC(SOUNDPORT,3500,2000);
		DELAYFUNC(DELAYPORT,1);
		sleepMin(1);
		DELAYFUNC(DELAYPORT,0);
	}

}
 







