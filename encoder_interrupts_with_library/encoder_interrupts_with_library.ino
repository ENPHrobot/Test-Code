#include <avr/EEPROM.h>
#include <phys253.h>
#include <LiquidCrystal.h>
#include <Interrupts.h>

// Sensor Ports
#define ENCODER_A 1

volatile unsigned int encount = 0;

void setup()
{
#include <phys253setup.txt>
    LCD.clear(); LCD.home();

    enableExternalInterrupt(INT1, RISING);
    attachISR(INT1, incre);
    attachTimerInterrupt(1, incre);

    LCD.print("Press Start.");
    while (!startbutton()) {};
    LCD.clear();
}

void loop()
{
    while (startbutton()) {
        delay(250);
        if (encount > 100)  {
            attachISR(INT0, decre);
            attachTimerInterrupt(1, decre);
        }
        else {
            attachISR(INT1, incre);
            attachTimerInterrupt(1, incre);
        }
    }
    while ( stopbutton()){
        delay(250);
        detachTimerInterrupt();
    }
    LCD.clear();
    LCD.print(encount);
    delay(100);
}

void incre() {
    encount++;
}

void decre() {
    encount--;
}
