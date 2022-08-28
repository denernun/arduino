#include "Arduino.h"
#include <UIPEthernet.h>
#include "utility/logging.h"

#define ACTLOGLEVEL LOG_NONE

void setup() {

  // SERIAL
  Serial.begin(9600);

  // ETHERNET
  // Schemas: https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-modulo-ethernet-enc28j60-web-server
  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP");
  byte mac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found");
      Serial.println("Sorry, can't run without hardware");
      while (true) {
        delay(1);
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
  } else {
    Serial.print("localIP: ");
    Serial.println(Ethernet.localIP());
    Serial.print("subnetMask: ");
    Serial.println(Ethernet.subnetMask());
    Serial.print("gatewayIP: ");
    Serial.println(Ethernet.gatewayIP());
    Serial.print("dnsServerIP: ");
    Serial.println(Ethernet.dnsServerIP());
  }

}

void loop() {

}
