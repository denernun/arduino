#include "Arduino.h"

// LED
#define PIN_LED 13

// BOTAO
#define PIN_BUTTON 8
byte lastButtonState;
unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;

void setup(){

  // SERIAL
  Serial.begin(9600);

  // LED
  pinMode(PIN_LED, OUTPUT);

  // BOTAO
  pinMode(PIN_BUTTON, INPUT);
  lastButtonState = digitalRead(PIN_BUTTON);

}

void loop(){

  // Botao
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
    byte buttonState = digitalRead(PIN_BUTTON);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      Serial.println(buttonState);
    }
  }

}
