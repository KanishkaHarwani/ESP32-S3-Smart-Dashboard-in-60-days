# Example — I²C Bus Scan + Live Sensor Readings

Confirm your sensor is wired correctly by scanning the bus, then read real temperature and humidity values on a loop.

## Wiring

Standard I²C 4-pin breakout wiring:

- **VCC** → 3.3V
- **GND** → GND
- **SDA** → Xiao ESP32S3 SDA pin
- **SCL** → Xiao ESP32S3 SCL pin

## Library

This example uses the Adafruit AHTX0 library (covers AHT10/AHT20-style sensors). Add to `platformio.ini`:

```ini
lib_deps =
    adafruit/Adafruit AHTX0
```

If your specific module uses a different chip, swap the library per its datasheet — the bus-scan step and overall structure stay the same regardless.

## The exercise

`main_starter.cpp` has the structure in place, with `// TODO` markers for:

1. Scanning the I²C bus once at startup and printing found addresses
2. Initializing the sensor
3. Reading temperature + humidity every 2 seconds and printing them

`main_solution.cpp` is the completed reference — try the starter first.

## Build, upload, monitor

```bash
pio run
pio run --target upload
pio device monitor
```

## Expected result

On startup:
```
Scanning I2C bus...
Found device at 0x38
Sensor ready.
```

Then, every 2 seconds:
```
Temp: 24.3C  Humidity: 51.2%
```

If the scan finds nothing, double-check SDA/SCL aren't swapped before assuming it's a code problem.

## Stretch (optional)

Feed these readings into Topic 06's LED: turn an LED on when temperature crosses a threshold you pick. This is effectively a preview of Topic 11's checkpoint project.
