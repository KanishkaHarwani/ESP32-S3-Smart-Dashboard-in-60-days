// Topic 07 — UART
// Starter: control an LED via serial commands, plus a periodic heartbeat print.
// Copy this file into your PlatformIO project's src/ folder as main.cpp.

#include <Arduino.h>

const uint8_t LED_PIN = D1;
const uint32_t HEARTBEAT_INTERVAL_MS = 2000;

bool ledOn = false;
uint32_t lastHeartbeat = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Ready. Commands: on, off, status");
}

void loop() {
  // TODO: every HEARTBEAT_INTERVAL_MS, print something like:
  //   "[heartbeat] uptime: <millis()>ms"
  // without using delay() — track the last print time instead.

  // TODO: if Serial.available() > 0, read a line with
  //   Serial.readStringUntil('\n'), trim() it, and:
  //     - "on"     -> turn LED on, print confirmation
  //     - "off"    -> turn LED off, print confirmation
  //     - "status" -> print whether the LED is currently on or off
}
