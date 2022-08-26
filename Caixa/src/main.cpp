#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
}

void loop(){
  // if (Serial.available()) {
  //   // wait a bit for the entire message to arrive
  //   delay(100);
  //   // clear the screen
  //   lcd.clear();
  //   // read all the available characters
  //   while (Serial.available() > 0) {
  //     // display each character to the LCD
  //     lcd.write(Serial.read());
  //   }
  // }
}
