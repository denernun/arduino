#include "Arduino.h"
#include <NewPing.h>
#include <UIPEthernet.h>
#include "utility/logging.h"

// SONAR
#define TRIGGER_PIN 6
#define ECHO_PIN 5
#define MAX_DISTANCE 300
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
unsigned int pingValue = 0;
unsigned long pingTimer = millis();
unsigned int pingSpeed = 50;
bool sensorStateOn = false;

// RELE
#define PIN_RELE 12
#define ON_RELE LOW
#define OFF_RELE HIGH

void setup() {

  // SERIAL
  Serial.begin(9600);

  // ETHERNET
  // Schemas: https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-modulo-ethernet-enc28j60-web-server
  // start the Ethernet connection:
  // Serial.println("Initialize Ethernet with DHCP");
  // byte mac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  // if (Ethernet.begin(mac) == 0) {
  //   Serial.println("Failed to configure Ethernet using DHCP");
  //   if (Ethernet.hardwareStatus() == EthernetNoHardware) {
  //     Serial.println("Ethernet shield was not found");
  //     Serial.println("Sorry, can't run without hardware");
  //     while (true) {
  //       delay(1);
  //     }
  //   }
  //   if (Ethernet.linkStatus() == LinkOFF) {
  //     Serial.println("Ethernet cable is not connected.");
  //   }
  // } else {
  //   Serial.print("localIP: ");
  //   Serial.println(Ethernet.localIP());
  //   Serial.print("subnetMask: ");
  //   Serial.println(Ethernet.subnetMask());
  //   Serial.print("gatewayIP: ");
  //   Serial.println(Ethernet.gatewayIP());
  //   Serial.print("dnsServerIP: ");
  //   Serial.println(Ethernet.dnsServerIP());
  // }

  // RELE
  pinMode(PIN_RELE, OUTPUT);

}

void pingCheck() {
  if (sonar.check_timer()) {
    pingValue = sonar.ping_result / US_ROUNDTRIP_CM;
    if (pingValue >= 50 && !sensorStateOn) {
      sensorStateOn = true;
      Serial.print(pingValue);
      Serial.println(" cm - BOMBA LIGADA");
      digitalWrite(PIN_RELE, ON_RELE);
    } else if (pingValue <= 10 && sensorStateOn) {
      sensorStateOn = false;
      Serial.print(pingValue);
      Serial.println(" cm - BOMBA DESLIGADA");
      digitalWrite(PIN_RELE, OFF_RELE);
    }
  }
}

void loop() {
  if (millis() >= pingTimer) {
    pingTimer += pingSpeed;
    sonar.ping_timer(pingCheck);
  }
}
