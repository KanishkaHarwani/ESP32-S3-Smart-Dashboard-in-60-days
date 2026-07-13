// Topic 09 — I2C
// Solution: scan the I2C bus, then read temp/humidity on a loop.
// Copy this file into your PlatformIO project's src/ folder as main.cpp.

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

const uint32_t READ_INTERVAL_MS = 2000;

Adafruit_AHTX0 aht;
uint32_t lastRead = 0;

void scanI2CBus() {
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.printf("Found device at 0x%02X\n", addr);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Scanning I2C bus...");
  scanI2CBus();

  if (aht.begin()) {
    Serial.println("Sensor ready.");
  } else {
    Serial.println("Could not find AHT sensor - check wiring.");
  }
}

void loop() {
  if (millis() - lastRead > READ_INTERVAL_MS) {
    lastRead = millis();

    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);

    Serial.printf("Temp: %.1fC  Humidity: %.1f%%\n",
                  temp.temperature, humidity.relative_humidity);
  }
}
