// Topic 04 — PlatformIO Toolchain
// Solution: blink an LED on real hardware (Xiao ESP32S3).
// Copy this file into your PlatformIO project's src/ folder as main.cpp.

#include <Arduino.h>

const uint8_t LED_PIN = D0; // change to whichever pin your LED is wired to

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
