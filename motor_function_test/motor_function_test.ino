#include <avr/EEPROM.h>
#include <phys253.h>
#include <LiquidCrystal.h>

// Sensor Ports
#define LEFT_MOTOR 1
#define RIGHT_MOTOR 0
#define MOTOR 0
#define pauseMTR() (motor.speed(LEFT_MOTOR,0))

int value = 0;
 
void setup()
{
	#include <phys253setup.txt>
	LCD.clear();
	LCD.home();
        
      	LCD.print("Press Start.");
        while(!startbutton()){};
        LCD.clear();
}

void loop()
{       
        if ( startbutton()) {
            pauseMTR();
        }
        value = analogRead(6)/2 - 256; // Read from knob
        motor.speed(MOTOR, value);
        LCD.clear();
        LCD.print(value);
        delay(100);
}
