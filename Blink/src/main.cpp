#include "Arduino.h"

#define LED_BUILTIN 13

void setup()
{
  Serial.begin(9600);
  delay(2000);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);

  // DHT.read11(A2); //LÊ AS INFORMAÇÕES DO SENSOR
  // Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
  // Serial.print(DHT.humidity); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
  // Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
  // Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  // Serial.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
  // Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  // delay(2000);
}
