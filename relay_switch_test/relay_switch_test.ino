#include <phys253.h>
#include <LiquidCrystal.h>
  
#define OUT1 9
#define OUT2 14

void setup()
{
  #include <phys253setup.txt>
  pinMode(OUT1, OUTPUT);      // sets the digital pin as output
  pinMode(OUT2, OUTPUT);      // sets the digital pin as output
}

void loop()
{
  
  while(stopbutton()&&startbutton()){
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, HIGH);
  }
  
  while(stopbutton()&&!(startbutton())){
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, HIGH);
  }
  
  while(!(stopbutton())&&startbutton()){
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
  }
  
  while(!(stopbutton())&&!(startbutton())){
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, LOW);
  }
  
  delay(100);
}
