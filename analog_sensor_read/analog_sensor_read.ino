#include <avr/EEPROM.h>
#include <avr/interrupt.h>
#include <phys253.h>
#include <LiquidCrystal.h>

// Sensor Ports
#define IR_A 0
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
  value = analogRead(IR_A);
  LCD.clear();
  LCD.print(value);
  delay(100);
}
