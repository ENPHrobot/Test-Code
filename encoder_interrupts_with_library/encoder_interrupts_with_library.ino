#include <avr/EEPROM.h>
#include <phys253.h>
#include <LiquidCrystal.h>
#include <Interrupts.h>

// Sensor Ports
#define ENCODER_A 0

volatile unsigned int encount = 0;

void setup()
{
#include <phys253setup.txt>
    LCD.clear(); LCD.home();

    enableExternalInterrupt(INT0, RISING);
    attachISR(INT0, incre);

    LCD.print("Press Start.");
    while (!startbutton()) {};
    LCD.clear();
}

void loop()
{
    while (startbutton()) {
        delay(250);
        if (encount > 100) attachISR(INT0, decre);
        else attachISR(INT0, incre);
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
