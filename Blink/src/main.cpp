#include "Arduino.h"

#define LED_BUILTIN 13

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(PIN2, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(PIN2, HIGH);

  // wait for a second
  delay(2000);

  // turn the LED off by making the voltage LOW
  digitalWrite(PIN2, LOW);

  // wait for a second
  delay(2000);
}
