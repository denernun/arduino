#include <Arduino.h>
#include <WiFiManager.h>

void setup()
{
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("connected...yeey :)");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
