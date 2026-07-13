# Topic 08 — SPI Concepts

No wiring yet, no code — SPI gets used for real in Phase 2 when you drive the TFT display. This topic is just the mental model, so when you get there it's "oh, this is that thing" instead of new syntax and new concepts at the same time.

## What SPI is for

SPI (Serial Peripheral Interface) is a fast bus used when a device needs to move a lot of data quickly — a screen full of pixels, a stream of data to/from an SD card. It trades a couple of extra wires for speed, compared to I²C (Topic 09), which is slower but simpler and uses fewer pins.

## The four wires

| Signal | Meaning |
|---|---|
| **MOSI** | Master Out, Slave In — data from the ESP32-S3 to the peripheral |
| **MISO** | Master In, Slave Out — data from the peripheral back to the ESP32-S3 |
| **SCK** | Serial Clock — the ESP32-S3 generates this; keeps both sides in sync |
| **CS** (Chip Select) | Tells one specific device "the next data is for you" |

The ESP32-S3 is almost always the **master** — the one driving the clock and initiating communication. Your display or SD card is the **slave**, responding to what the master sends.

## Why CS matters: one bus, many devices

MOSI, MISO, and SCK can be **shared** across multiple SPI devices — that's the efficient part of the design. But if two devices both tried to respond at once, you'd get garbled data. **CS solves this**: each device gets its own dedicated CS pin, and only the device whose CS line is pulled LOW is "listening" at that moment.

This is why, later, you'll see code like:

```cpp
digitalWrite(TFT_CS, LOW);   // "talking to the display now"
// ... transfer data ...
digitalWrite(TFT_CS, HIGH);  // "done, display can ignore the bus"
```

If you eventually wire up both the TFT *and* the SD card module (Phase 2), they can share MOSI/MISO/SCK — but each needs its own CS pin so only one is "active" during any given transfer.

## SPI vs I²C, at a glance

| | SPI | I²C |
|---|---|---|
| Wires needed | 4+ (plus one CS per device) | 2 (shared by all devices) |
| Speed | Fast | Slower |
| Typical use here | Displays, SD card | Sensors (temp/humidity, IMU) |

Neither is "better" — they're suited to different jobs. Fewer wires and simplicity for sensors (I²C), raw speed for anything pushing lots of data (SPI).

## What's next

Topic 09 puts the *other* bus, I²C, into actual practice — wiring and reading a real sensor. SPI comes back for real in Phase 2, driving the TFT display, using exactly the mental model above.
