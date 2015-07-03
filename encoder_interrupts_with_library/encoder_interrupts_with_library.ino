#include <avr/EEPROM.h>
#include <phys253.h>
#include <LiquidCrystal.h>
#include <Interrupts.h>

// Sensor Ports
#define ENCODER_A 0
 
void (*func_ptr) (void) = incre;
Interrupts interrupt;
volatile unsigned int encount = 0;

// ISR function
ISR(INT0_vect) {callfn();};

void setup()
{
  #include <phys253setup.txt>
  LCD.clear();
  LCD.home();
  
  interrupt.enableExternalInterrupt(INT0, RISING);
  
  LCD.print("Press Start.");
  while(!startbutton()){};
  LCD.clear();
}

void loop()
{
  while (startbutton()) {
    if (encount > 100) func_ptr = incre2;
    encount = 0;
  }
  LCD.clear();
  LCD.print(encount);
  delay(100);
}

void incre() {
  encount++;
}

void incre2() {
  encount += 20;
}

void callfn(){
  func_ptr();
}
