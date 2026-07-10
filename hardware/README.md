# Hardware

Everything used across the three phases, what it's for, and what's still needed. If you're just starting Phase 1, skip to [Get now](#get-now--phase-1).

## Primary board

**Seeed Xiao ESP32S3** (x3) — this is the board the whole repo is built around. Other boards you own (ESP32 DevKit, WROOM, ESP8266, Teensy, Nano 33 BLE Sense, Raspberry Pi models) are not required for the core path, but are noted below where they're useful as optional side-exploration.

## Owned — core to this repo

| Item | Used in | Notes |
|---|---|---|
| Jumper wires | All phases | |
| Breadboard (large + small) | All phases | |
| Resistor set | Phase 1+ | |
| LED set (R, G, B, White) | Phase 1 | |
| Buzzer | Phase 1 | |
| Pushbutton set | Phase 1 | |
| Digital multimeter | Phase 1+ | Debugging habit, not optional |
| Temp & humidity sensor (I²C) | Phase 1–2 | First I²C peripheral |
| 2.8" TFT display, 240×320 (SPI) | Phase 2 | First display, framebuffer concepts |
| SD card module + 32GB cards (x2) | Phase 2–3 | Data logging |
| Addressable LED strip, 1m | Phase 2 (optional) | Status indicator on final dashboard |
| BNO085 IMU (Adafruit + generic) | Phase 2–3 (optional) | Motion data as a dashboard input |

## Owned — optional / other-repo material

Not used in the core path, but you already own these — fine to explore on the side or save for a future robotics-flavored repo:

ESP32 DevKit 32E (x2), ESP32 WROOM (x2), ESP8266, Teensy 3.5, Teensy 4.1, Arduino Nano 33 BLE Sense, Raspberry Pi 3B, Raspberry Pi 5, Raspberry Pi Zero W, Rpi Camera V2.1, Arducam Camera Module 3, Xiao ESP32S3 CAM + hat, Xiao camera sensors, Xiao antennas, Screwdriver set.

> Raspberry Pi 5 has a natural role in Phase 3 as an optional network host (dashboard backend, MQTT broker, or data sink) — see phase 3 README when you get there.

## Get now — Phase 1

You already have everything Phase 1 needs. Optional additions:

- 2x **10kΩ potentiometer** — analog input lesson
- A **data-capable USB cable** dedicated to the Xiao ESP32S3

## Get for Phase 2 & 3

**Power**
- 12V → 5V converter
- 3.3V buck converter module(s)

**Display**
- E-ink display (any SPI module, ~2–3")

**Xiao breadboard setup** (cheaper alternative to the official expansion board — also reusable across your other boards)
- 2x 7-pin female headers (solder to Xiao's castellated edges) — or a plain Xiao-to-breadboard carrier PCB
- DS3231 RTC module (with CR2032 battery) — timestamps for dashboard data
- A few small prototyping perfboards

**Sensors** (pick based on what you want your dashboard to show)
- LDR (light sensor)
- BME280 / BMP280 (pressure, temp, optionally humidity) — second I²C sensor
- Soil moisture sensor
- Rotary encoder with push switch — menu navigation on the display
- IR receiver + remote — protocol decoding lesson
- Capacitive touch sensor (TTP223)

**Output devices**
- Single WS2812 addressable RGB LED breakout — smaller-scale version of your LED strip
- TM1637 4-digit 7-segment display — different display-driving paradigm than TFT/E-ink

## Deliberately skipped for this repo

Motors, servos, steppers, H-bridge drivers, ultrasonic distance sensors, PIR motion sensors, gas/MQ sensors — none of these serve a connectivity-and-dashboard-focused repo. Good candidates for a future robotics/automation repo instead.
