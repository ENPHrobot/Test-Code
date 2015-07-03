#include <phys253.h>
#include <LiquidCrystal.h>

// Sensor Ports
//#define LEFT_MOTOR 1
#//define RIGHT_MOTOR 0
 
//int count = 0;
//int buttonSwitchCount = 1;
//int timeStart;
int interval;
int catapult_pin = 36;
 
void setup()
{
	#include <phys253setup.txt>
	LCD.clear();
	LCD.home();

for (int i = 8; i < 16; i++) 
        pinMode(i, OUTPUT);
      	LCD.print("Press Start.");
        while(!startbutton()){};
        LCD.clear();
}

void loop()
{       
        
        while(digitalRead(0) == LOW){
          interval = analogRead(6);
          LCD.clear(); LCD.print(interval);
          delay(50);
        }
        while(digitalRead(0) == HIGH){};
        //motor.speed(RIGHT_MOTOR,255);
        digitalWrite(catapult_pin,HIGH);
        
        delay(interval);
        //motor.speed(RIGHT_MOTOR,0);
        digitalWrite(catapult_pin,LOW);
}
