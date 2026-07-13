# Phase 1 — Foundations

Get comfortable with embedded C++, the ESP32-S3, and the core peripherals every later phase depends on. By the end, you'll be reading a sensor and driving output based on it — the smallest possible version of "device senses something, device reacts."

**Board:** Xiao ESP32S3
**Also needed:** breadboard, jumper wires, resistors, LEDs, pushbuttons, buzzer, temp/humidity sensor, multimeter

## How this phase is organized

Each topic below is its own folder. Topics with hands-on code have an `Example/` folder inside, split into `Starter/` (a skeleton with gaps to fill in) and `Solution/` (the completed reference version) — try the Starter first before looking at the Solution.

## Topics

| # | Topic | Has Example |
|---|---|---|
| 01 | [Embedded Systems Intro](Topic-01-Embedded-Systems-Intro/README.md) | No |
| 02 | [Embedded C++ Essentials](Topic-02-Embedded-CPP-Essentials/README.md) | Yes |
| 03 | [ESP32-S3 Architecture](Topic-03-ESP32S3-Architecture/README.md) | No |
| 04 | [PlatformIO Toolchain](Topic-04-PlatformIO-Toolchain/README.md) | Yes |
| 05 | [Git & GitHub Basics](Topic-05-Git-GitHub-Basics/README.md) | No |
| 06 | [GPIO](Topic-06-GPIO/README.md) | Yes |
| 07 | [UART](Topic-07-UART/README.md) | Yes |
| 08 | [SPI Concepts](Topic-08-SPI-Concepts/README.md) | No |
| 09 | [I²C](Topic-09-I2C/README.md) | Yes |
| 10 | [Debugging Basics](Topic-10-Debugging-Basics/README.md) | No |
| 11 | [Checkpoint Project](Topic-11-Checkpoint-Project/README.md) | Yes |

## Checkpoint project

Topic 11 ties the phase together: read the temp/humidity sensor over I²C, and react on the LEDs/buzzer based on a threshold. Small in scope, but it touches GPIO, I²C, and basic control flow — everything this phase covered.

Once it works and you understand every line of it, move to `phase2-connectivity-architecture/`.
