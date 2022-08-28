#include "Arduino.h"

// LED
int led = 13;
byte lastLedState = LOW;

// BUTTON
int pushButton = 2;
byte lastButtonState = LOW;
unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;

void setup(){

  // SERIAL
  Serial.begin(9600);

  // LED
  pinMode(led, OUTPUT);

  // BUTTON
  pinMode(pushButton, INPUT_PULLUP);

}

void loop(){

  // Botao
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
    lastTimeButtonStateChanged = millis();
    Serial.println(digitalRead(pushButton));
    if (digitalRead(pushButton) == LOW) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }

  // if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
  //   byte buttonState = digitalRead(pushButton);
  //   if (buttonState != lastButtonState) {
  //     lastTimeButtonStateChanged = millis();
  //     lastButtonState = buttonState;
  //     if (buttonState == HIGH) {
  //       digitalWrite(led, HIGH);
  //     } else {
  //       digitalWrite(led, LOW);
  //     }
  //   }
  // }

}
