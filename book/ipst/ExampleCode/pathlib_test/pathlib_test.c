#include <lcd.h>
#include <path_lib.h>


void main()
{
	set_sensor(0,1,2);
	set_ref(400);
	set_power(70);
	set_motor(1,2);
	lcd("Press SW1 #nFor Run");
	sw1_press();
	//while(1)
	//{run_fd(1000);}
	
	cross_all(PASS);
	cross_all(PASS);
	cross_all(LEFT);
	cross_right(RIGHT);
	cross_all(STOP);
	sleep(3000);

	turn_left(1000);
	spin_find_line();
	cross_left(LEFT);
	cross_all(LEFT);
	cross_all(STOP);
	sleep(3000);

	turn_left(1000);
	spin_find_line();
	cross_all(LEFT);
	cross_left(LEFT);
	cross_all(STOP);
	sleep(3000);

	turn_left(1000);
	spin_find_line();
	cross_right(RIGHT);
	cross_all(LEFT);
	cross_all(PASS);
	cross_all(PASS);
	cross_all(STOP);



	
}







