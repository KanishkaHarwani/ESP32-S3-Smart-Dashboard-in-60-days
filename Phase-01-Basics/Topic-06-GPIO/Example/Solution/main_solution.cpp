// Topic 06 — GPIO
// Solution: debounced button press toggles an LED.
// Copy this file into your PlatformIO project's src/ folder as main.cpp.

#include <Arduino.h>

const uint8_t LED_PIN = D1;
const uint8_t BUTTON_PIN = D2;
const uint32_t DEBOUNCE_MS = 50;

bool ledOn = false;

bool lastReading = HIGH;   // HIGH = not pressed (INPUT_PULLUP)
bool stableState = HIGH;
uint32_t lastChangeTime = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastReading) {
    lastChangeTime = millis();
  }

  if ((millis() - lastChangeTime) > DEBOUNCE_MS) {
    if (reading != stableState) {
      stableState = reading;

      if (stableState == LOW) {  // a real, settled press
        ledOn = !ledOn;
        digitalWrite(LED_PIN, ledOn ? HIGH : LOW);
      }
    }
  }

  lastReading = reading;
}
