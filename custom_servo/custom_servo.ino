#include <phys253.h>
#include <LiquidCrystal.h>

enum { POT = 2,
       MOTOR = 3
     };

int error;
int pot;
int gain;
int int_error = 0;
int d_error;
int last_error = 0;
int angle;
int derpy_int_gain = 1;
int last_angle;

void setup()
{
#include <phys253setup.txt>
	//Serial.begin(9600);
	LCD.clear();	LCD.home();
	LCD.print("Press Start.");
	while (!startbutton()) {};
	angle = 700;
        last_angle = angle;
}

void loop()
{
	LCD.clear(); LCD.home();
	//angle = map(knob(6), 0, 1023, 0, 180);
	//pot = map(analogRead(POT), 0, 1023, 0, 180);

        // Max Values for upper motor
        // lower = 380
        // upper 740
        
       	// MAX VALUES FOR LOWER MOTOR
	// extended pot (down) = 200
        // retracted pot (up) = 550


	int val = map(knob(6), 0 ,1023, 200, 550  );
	if (startbutton()) {
		angle = val;
	}
	gain = map(knob(7), 0 , 1023, 0, 30);
	pot = analogRead(POT);
//        if (pot-angle >10 || pot-angle < -10) {
  	  error = gain * (pot - angle);
//          int_error += error >> 3;
//          int_error = constrain(int_error,-255,255);
//          d_error = (error - last_error) >> 1;
//          error = int_error + error + d_error;
//        } else {
//          error = 0;
//        }

        // Begin Derpy Integral gain
        if ((last_angle == angle) && !(pot-angle >10 || pot-angle < -10)) {
          error += derpy_int_gain;
          derpy_int_gain +=1 ;
        } else {
          derpy_int_gain = 0;
        }

	LCD.print("A:"); LCD.print(val); LCD.print(" G:"); LCD.print(gain);
	error = constrain(error, -255, 255);
        last_error = error;
        last_angle = angle;
	motor.speed(MOTOR, error);
	LCD.setCursor(0, 1);LCD.print("P:"); LCD.print(pot); LCD.print(" "); LCD.print(error);
	delay(100);
}
