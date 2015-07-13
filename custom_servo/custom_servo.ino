#include <phys253.h>
#include <LiquidCrystal.h>

enum { POT = 0,
       MOTOR = 0
     };

int error;
int pot;
int angle;

void setup()
{
#include <phys253setup.txt>
	//Serial.begin(9600);
	LCD.clear();	LCD.home();
	LCD.print("Press Start.");
	while (!startbutton()) {};
}

void loop()
{
	LCD.clear(); LCD.home();
	//angle = map(knob(6), 0, 1023, 0, 180);
	//pot = map(analogRead(POT), 0, 1023, 0, 180);
	angle = knob(6);
	pot = analogRead(POT);
	error = pot - angle;
	LCD.print("A:"); LCD.print(angle); LCD.print(" E:"); LCD.print(error);
	/*if (error < 0) {
		error = map(error, 0, -180, -40, -255);
	} else if (error > 0) {
		error = map(error, 0, 180, 40, 255);
	} else {
		error = 0;
	}*/
	error = constrain(error, -100, 100);
	motor.speed(MOTOR, error);
	LCD.setCursor(0, 1); LCD.print(pot); LCD.print(" "); LCD.print(error);
	delay(100);
}