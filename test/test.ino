#include <phys253.h>
#include <LiquidCrystal.h>
 
int ledPin = 36;                 // LED connected to digital pin 15

void setup()
{
  #include <phys253setup.txt>
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  digitalWrite(ledPin, HIGH);   // sets the LED on
  LCD.clear(); LCD.print("High");
  delay(1000);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  LCD.clear(); LCD.print("Low");
  delay(1000);                  // waits for a second
}
