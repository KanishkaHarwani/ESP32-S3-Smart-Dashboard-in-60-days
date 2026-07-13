# Example — First Flash: Blink on Real Hardware

Your first program running on the actual Xiao ESP32S3. This is the last "no board" gap — from here on, everything runs on real hardware.

## Setup

1. Create a new PlatformIO project (VS Code → PlatformIO icon → **New Project**), board: **Seeed XIAO ESP32S3**, framework: **Arduino**
2. Copy `platformio.ini` from this folder into your new project's root (or use the one PlatformIO generates — they should match)
3. Copy `main_starter.cpp` into your project's `src/` folder, renamed to `main.cpp`
4. Connect the Xiao ESP32S3 via USB

## The exercise

An LED connected to pin `D0` (through a resistor, on your breadboard) should blink on and off, once per second. The starter has `// TODO` markers — fill in the pin setup and the on/off timing.

`main_solution.cpp` is the completed reference — try the starter first.

## Build, upload, monitor

```bash
pio run                     # compile
pio run --target upload     # flash to the board
pio device monitor          # watch Serial output (optional for this one)
```

If upload fails, double check the board is connected and no other program (like the Arduino IDE) has the serial port open.

## Expected result

The LED turns on for 1 second, off for 1 second, repeating — visible directly on your breadboard, no serial monitor needed.

## Stretch (optional)

Change the timing to an uneven pattern (e.g. on for 200ms, off for 800ms) and confirm you see it change on the hardware. Small changes like this are the fastest way to build real intuition for `delay()` timing before Topic 06 goes deeper into GPIO.
