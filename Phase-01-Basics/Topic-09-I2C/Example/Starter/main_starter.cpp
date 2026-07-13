// Topic 09 — I2C
// Starter: scan the I2C bus, then read temp/humidity on a loop.
// Copy this file into your PlatformIO project's src/ folder as main.cpp.

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

const uint32_t READ_INTERVAL_MS = 2000;

Adafruit_AHTX0 aht;
uint32_t lastRead = 0;

void scanI2CBus() {
  // TODO: loop addresses 1-126, use Wire.beginTransmission(addr) +
  // Wire.endTransmission() == 0 to check if a device responded.
  // Print any addresses found, in hex (e.g. "Found device at 0x38").
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Scanning I2C bus...");
  scanI2CBus();

  // TODO: initialize the sensor with aht.begin(), print "Sensor ready."
  // if it succeeds (or an error message if it doesn't).
}

void loop() {
  // TODO: every READ_INTERVAL_MS, read temp + humidity with aht.getEvent()
  // and print them, e.g.:
  //   "Temp: 24.3C  Humidity: 51.2%"
}
