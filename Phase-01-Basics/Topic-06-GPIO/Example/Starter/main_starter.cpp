// Topic 06 — GPIO
// Starter: debounced button press toggles an LED.
// Copy this file into your PlatformIO project's src/ folder as main.cpp.

#include <Arduino.h>

const uint8_t LED_PIN = D1;
const uint8_t BUTTON_PIN = D2;
const uint32_t DEBOUNCE_MS = 50;

bool ledOn = false;

// Tracking raw reading vs. an accepted "stable" state is what makes this a
// real debounce, not just a delay: it ignores bounce AND avoids re-toggling
// while the button is held down past the debounce window.
bool lastReading = HIGH;   // HIGH = not pressed (INPUT_PULLUP)
bool stableState = HIGH;
uint32_t lastChangeTime = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // TODO: read the current raw value of BUTTON_PIN into `reading`

  // TODO: if `reading` differs from `lastReading`, the signal just changed —
  // reset lastChangeTime to millis() (this restarts the debounce window)

  // TODO: if enough time has passed since lastChangeTime (> DEBOUNCE_MS),
  // the signal has settled. If it also differs from `stableState`:
  //   - update stableState to `reading`
  //   - if stableState == LOW (a real press), flip ledOn and write it to LED_PIN

  // TODO: set lastReading = reading, ready for the next loop iteration
}
