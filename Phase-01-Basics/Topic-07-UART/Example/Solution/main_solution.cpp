// Topic 07 — UART
// Solution: control an LED via serial commands, plus a periodic heartbeat print.
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
  if (millis() - lastHeartbeat > HEARTBEAT_INTERVAL_MS) {
    lastHeartbeat = millis();
    Serial.printf("[heartbeat] uptime: %lums\n", millis());
  }

  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "on") {
      ledOn = true;
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED turned ON");
    } else if (command == "off") {
      ledOn = false;
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED turned OFF");
    } else if (command == "status") {
      Serial.printf("LED is currently %s\n", ledOn ? "ON" : "OFF");
    } else if (command.length() > 0) {
      Serial.printf("Unknown command: %s\n", command.c_str());
    }
  }
}
