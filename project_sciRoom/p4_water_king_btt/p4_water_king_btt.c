#include <ipst.h>
#include <math.h> 

/* configuration */

#define DELAYPORT 0				//Relay output port	Num
#define SOUNDPORT 6				//Sound output port Num

#define ANALOG_VOL_PORT 0		//Movement Registance port	Num
#define ANALOG_REG_PORT 1		//Registance input port	Num

#define FLOAT_K_DEFAULT 850.00
#define TIME_LOOP_CHK_MIN 30


//Port Define 
#define PSB in_b(0)		//Prosive Bottom port
#define NTB in_b(1)		//Netive Bottom port
#define ACB in_b(2)		//Active Bottom port

#define ANALOG_VOL analog(ANALOG_VOL_PORT)  //Buzzer port
#define ANALOG_REG analog(ANALOG_REG_PORT)	//Registance Port Input
#define DELAYFUNC out_d		//Relay output port
#define SOUNDFUNC sound_d	//Sound output port (Buzzer)

//Main command
#define SIL SOUNDFUNC(SOUNDPORT,2000,100);
#define WARS SOUNDFUNC(SOUNDPORT,5000,700);
#define DANS SOUNDFUNC(SOUNDPORT,5000,1200);



/* Main Programming */
void main(){
while(1){toggle_d(0);sleep(1000);}
/*
	int watertime ;
	float ksoil;

	//Reset All Setting
	resetblock();

	//Welcome screen
	welcome();
	
	//Help Function
	recomended();

	//Cheack Stick in soil
	select_menu();
	
	//Select mode

	//first Cheack

	//Wait to water in frist CHK

	//Finish loop*/

}



/*------- Calculator Function --------*/

// Time Calculate
long covHourtoMin(unsigned int hour){
	long a=0;
	a = hour*60*1000;
	return a;
}

void sleepMin(unsigned int mina)  //Sleep Def
{
	unsigned int i,j;
	for(i=0;i<mina;i++){
	for(j=0;j<60;j++){
	sleep(1000);}}
}

//Calculate
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

float cal_chk_insoil(unsigned int port, unsigned int number, unsigned int delay) //Chack vol scolling
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
	

if((float)lista[0]==arga||(float)lista[0]>=arga-10&&(float)lista[0]<=arga+10){return 1;} //Not scolling
else{return 0;} //Scolling
}


float persen(float numa, float maxa,float pera) //return float
{
	float ap;
	ap = (numa/maxa)*pera;
	return ap;
}


/*------- User Interface ------*/


void select_menu(){
	int ps,nt,ac,tt,is;
	while(is<=3){
		if(PSB==0||NTB==0||ACB==0){
			if(PSB==0){tt+=2;}
			else if(NTB==0){tt-=1;}
			else if(ACB==0){tt+=3;}
			is++;
		}
		else if(tt==8){
			lcd("%l             ",(unsigned long)timer_set_manul());
		}
	}
}

int timer_set_manul(){
	unsigned long hr,mn,sc;
	hr=0;mn=0;sc=0;
	while(ACB!=0){
		lcd("Set Hours#n:::%d      ",hr);
		sleep(100);
		if(PSB==0){ hr++;}
		else if(NTB==0){hr--;}
		else if(hr<0){hr=0;}
		else if(hr>59){hr=59;}
	}
	while(ACB!=0){
		lcd("Set Minute#n:::%d      ",mn);
		sleep(100);
		if(PSB==0){ mn++;}
		else if(NTB==0){mn--;}
		else if(mn<0){mn=0;}
		else if(mn>59){mn=59;}			
	}
	while(ACB!=0){
		lcd("Set Secound#n:::%d      ",sc);
		sleep(100);
		if(PSB==0){ sc++;}
		else if(NTB==0){sc--;}
		else if(sc<0){sc=0;}
		else if(sc>59){sc=59;}			
	}
	while(ACB!=0){
		lcd("___Sumery___#nH:%d    ;M:%d  ;S:%d  ",hr,mn,sc);
		sleep(200);
	}
	if(hr==0){return (long)(mn*60)+(sc);}
	else if(hr>168&&hr<540){return (unsigned long)hr*3600;}
	else if(hr>=540){return -1;}
		
}

/*------- Step function ----------*/
void welcome(){
	lcd(" l__l l__l   #n l  l l  l5CH00l ");
	sleep(2000);
	lcd("   Welcome to #n      MCT       ");
	sleep("1000");
	SIL;
	lcd("#c");
}//complated

void recomended(){
	SIL;
	lcd("#cHelp! Plz Red Buttom Now");
	sleep(3000);
	int i=0;
	while(i<3){	
		if(ACB==0){
			lcd("+ is Posive Buttom");sleep(3000);
			lcd("- is Netive Buttom");sleep(3000);
			lcd("Y is Active Buttom");sleep(3000);
			break;
		}
		for(i=0;i<3;i++){
			sleep(1000);
			i++;
		}
	}
}//completed

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

void chkstickinsoil(){ //For Check Stick in Soil Only
	unsigned int k,a;
	a = ANALOG_REG;
	lcd("--Install BiStick to soil--");
	SOUNDFUNC(SOUNDPORT,3500,50);
	sleep(5000);
	
	lcd("#c");
	/////////////NOOTTT
	while(1){
		int brk = cal_chk_insoil(ANALOG_REG_PORT,5,200);
		sleep(500);

		if(brk == 0){
			lcd("Still Scolling!!");  //Chack agin for sure
			sleep(2000);
			int brka = cal_chk_insoil(ANALOG_VOL_PORT,5,200);
			if(brka == 0){
				lcd("#cOk!!#nStick In Soil");sleep(5000);lcd("#c"); break; }
		}
	}

}//UnComplete


