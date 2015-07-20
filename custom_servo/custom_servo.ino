#include <phys253.h>
#include <LiquidCrystal.h>

enum { POT = 2,
       MOTOR = 3
     };

int error;
int pot;
int gain;
int angle;

void setup()
{
#include <phys253setup.txt>
	//Serial.begin(9600);
	LCD.clear();	LCD.home();
	LCD.print("Press Start.");
	while (!startbutton()) {};
	angle = 700;
}

void loop()
{
	LCD.clear(); LCD.home();
	//angle = map(knob(6), 0, 1023, 0, 180);
	//pot = map(analogRead(POT), 0, 1023, 0, 180);

	// MAX VALUES:
	// retracted pot (up) = 930
	// extended pot (down) = 500

	int val = map(knob(6), 0 ,1023, 500, 930);
	if (startbutton()) {
		angle = val;
	}
	gain = map(knob(7), 0 , 1023, 0, 30);
	pot = analogRead(POT);
	error = gain * (pot - angle);
	LCD.print("A:"); LCD.print(val); LCD.print(" G:"); LCD.print(gain);
	/*if (error < 0) {
		error = map(error, 0, -180, -40, -255);
	} else if (error > 0) {
		error = map(error, 0, 180, 40, 255);
	} else {
		error = 0;
	}*/
	error = constrain(error, -255, 255);
	motor.speed(MOTOR, error);
	LCD.setCursor(0, 1);LCD.print("P:") LCD.print(pot); LCD.print(" "); LCD.print(error);
	delay(100);
}