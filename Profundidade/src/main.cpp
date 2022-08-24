#include "Arduino.h"

// ENTRADA SENSOR
const int pinoSensor = A0;

// ON
const int pinoLED11 = 11;

// SENSOR
const int pinoLED12 = 12;

// Valor de Leitura do Sensor
int valSensor = 0;

void setup(){

  // INICIALIZAÇÃO DA SERIAL
  Serial.begin(9600);

  // INPUTS
  pinMode(pinoSensor, INPUT);

  // OUTPUTS
  pinMode(pinoLED11, OUTPUT);
  pinMode(pinoLED12, OUTPUT);

}

void loop(){

  digitalWrite(pinoLED11, HIGH);

  valSensor = analogRead(pinoSensor);

  Serial.println(valSensor);

  if(valSensor > 500) {

    digitalWrite(pinoLED12, HIGH);

  } else {

    digitalWrite(pinoLED12, LOW);

  }

}
