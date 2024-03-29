#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <NewPing.h>

// Pinos
#define PIN_LED 13
#define PIN_LED_POT 11
#define PIN_RELE 12
#define PIN_PIR 10
#define PIN_DISTANCIA 9
#define PIN_BUTTON 8
#define PIN_POT A0

// SONAR
#define TRIGGER_PIN 6
#define ECHO_PIN 5
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
unsigned int pingCm = 0;
unsigned long pingTimer = millis();
unsigned int pingSpeed = 50;
bool sensorStateOn = false;

// DHT
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
unsigned long lastTimeDhtChanged = millis();
unsigned int debounceDhtDuration = 5000;

// LCD
#define LCD_ROWS 2
#define LCD_COLS 16
LiquidCrystal_I2C lcd(0x27,LCD_ROWS,LCD_COLS);

// RELE
#define RELE_LIGADO LOW
#define RELE_DESLIGADO HIGH

// POT
unsigned int valuePot = 0;
char valuePotStr[7];

// BUTTON
byte lastButtonState;
unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;

// PIR
bool sensorState = false;
bool lastSensorState = false;

void setup() {

  // SERIAL
  Serial.begin(9600);

  // DHT
  dht.begin();

  // LCD
  lcd.init();
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("* NJ AUTOMACAO *");

  // LED
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LED_POT, OUTPUT);

  // PIR
  pinMode(PIN_PIR, INPUT);

  // BUTTON
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  // RELE
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, RELE_DESLIGADO);

}

void echoCheck() {
  if (sonar.check_timer()) {
    pingCm = sonar.ping_result / US_ROUNDTRIP_CM;
    if (pingCm >= 50 && !sensorStateOn) {
      sensorStateOn = true;
      Serial.print(pingCm);
      Serial.println(" cm - BOMBA LIGADA");
      digitalWrite(PIN_RELE, RELE_LIGADO);
    } else if (pingCm <= 10 && sensorStateOn) {
      sensorStateOn = false;
      Serial.print(pingCm);
      Serial.println(" cm - BOMBA DESLIGADA");
      digitalWrite(PIN_RELE, RELE_DESLIGADO);
    }
  }
}

void loop() {

  // SONAR
  if (millis() >= pingTimer) {
    pingTimer += pingSpeed;
    sonar.ping_timer(echoCheck);
  }

  // DHT
  if (millis() - lastTimeDhtChanged >= debounceDhtDuration) {
    lastTimeDhtChanged = millis();
    float t = dht.readTemperature();
    if (isnan(t)) {
      lcd.setCursor(9,1);
      lcd.print("DHTFAIL");
    } else {
      lcd.setCursor(9,1);
      lcd.print(t);
      lcd.setCursor(15,1);
      lcd.print("C");
    }
  }

  // BUTTON
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
    byte buttonState = digitalRead(PIN_BUTTON);
    if (buttonState == LOW) {
      digitalWrite(PIN_LED, HIGH);
      digitalWrite(PIN_RELE, RELE_LIGADO);
    }
  }

  // POT
  valuePot = analogRead(PIN_POT);
  dtostrf(valuePot,6,1,valuePotStr);
  lcd.setCursor(0,1);
  lcd.print(valuePotStr);
  analogWrite(PIN_LED_POT, byte (valuePot / 4));
  digitalWrite(PIN_LED_POT, byte (valuePot / 4));

  // Liga o LED
  if (valuePot >= 500) {
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }

  // Liga o RELE
  // if (!lastSensorState) {
  //   if (valuePot >= 700) {
  //     digitalWrite(PIN_RELE, RELE_LIGADO);
  //   } else {
  //     digitalWrite(PIN_RELE, RELE_DESLIGADO);
  //   }
  // }

  // PIR
  // sensorState = digitalRead(PIN_PIR);
  // if (sensorState) {
  //   if (!lastSensorState) {
  //     lastSensorState = true;
  //     digitalWrite(PIN_RELE, RELE_LIGADO);
  //   }
  // } else {
  //   lastSensorState = false;
  //   if (valuePot < 700) {
  //     digitalWrite(PIN_RELE, RELE_DESLIGADO);
  //   }
  // }

}
