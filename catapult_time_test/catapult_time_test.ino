#include <phys253.h>
#include <LiquidCrystal.h>

// Sensor Ports
#define LEFT_MOTOR 1
#define RIGHT_MOTOR 0
 
int count = 0;
int buttonSwitchCount = 1;
int timeStart;
int interval;
 
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
        
        while(!startbutton()){
          interval = analogRead(6);
          LCD.clear(); LCD.print(interval);
          delay(50);
        }
        while(startbutton()){};
        timeStart = millis();
        motor.speed(LEFT_MOTOR,255);
        motor.speed(RIGHT_MOTOR,255);
        
        while( millis() - timeStart < interval ){};
        motor.speed(LEFT_MOTOR,0);
        motor.speed(RIGHT_MOTOR,0);        
        
}
