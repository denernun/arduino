#include "Arduino.h"

// ENTRADA SENSOR
const int pinoSensorA0 = A0;
const int pinoSensorA1 = A1;

// SENSOR
const int pinoLED12 = 12;
const int pinoLED13 = 13;

// Valor de Leitura do Sensor
int valSensorA0 = 0;
int valSensorA1 = 0;

void setup(){

  // INICIALIZAÇÃO DA SERIAL
  Serial.begin(9600);

  // INPUTS
  pinMode(pinoSensorA0, INPUT);
  pinMode(pinoSensorA1, INPUT);

  // OUTPUTS
  pinMode(pinoLED12, OUTPUT);
  pinMode(pinoLED13, OUTPUT);

}

void loop(){

  valSensorA0 = analogRead(pinoSensorA0);
  Serial.println(valSensorA0);
  if(valSensorA0 > 500) {
    digitalWrite(pinoLED13, HIGH);
  } else {
    digitalWrite(pinoLED13, LOW);
  }

  valSensorA1 = analogRead(pinoSensorA1);
  Serial.println(valSensorA1);
  if(valSensorA1 > 500) {
    digitalWrite(pinoLED12, HIGH);
  } else {
    digitalWrite(pinoLED12, LOW);
  }

}
