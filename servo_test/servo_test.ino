#include <avr/EEPROM.h>
#include <phys253.h>
//#include <Interrupts.h>
#include <LiquidCrystal.h>

int prevAngle;
int angle;
int angleArray[3000];

void setup()
{
#include <phys253setup.txt>
	Serial.begin(9600);
	LCD.clear();
	LCD.home();
	LCD.print("Press Start.");
	while (!startbutton()) {};
	prevAngle = map(knob(6), 0, 1023, 0, 180);
}

void loop()
{
	LCD.clear(); LCD.home();
	angle = map(knob(6), 0, 1023, 0, 180);
	LCD.print(angle);
	if (startbutton()) {
		/*if ( angle > prevAngle) {
			int d = angle - prevAngle;
			int t = 3000 / d;
			Serial.println(t);
			for (int i = prevAngle; i < angle; i++) {
				for (int j = 1; j <= t ; j++) {
					
				}
			}
			for ( int i = prevAngle; i < angle; i++) {
				LCD.clear();
				LCD.print(i);
				RCServo0.write(i);
			}
		} else if ( angle < prevAngle) {
			RCServo0.write(angle);
		}
		prevAngle = angle;*/
		RCServo0.write(angle);
		delay(200);
	}
	delay(150);
}
