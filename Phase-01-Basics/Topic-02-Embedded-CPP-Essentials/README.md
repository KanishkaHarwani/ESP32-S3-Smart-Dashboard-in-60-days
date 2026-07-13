# Topic 02 — Embedded C++ Essentials

This is the C++ you'll actually use in this repo — not the whole language, just the parts that matter once you're modeling hardware in code. No board needed yet; the example compiles and runs right on your computer. Topic 04 gets you flashing real hardware.

## Variables & fixed-width types

In regular C++ you might casually use `int`. In embedded work, size matters — you often want to know *exactly* how many bits/bytes something takes, because you're working with tiny amounts of memory and specific hardware registers. That's why embedded code leans on fixed-width types:

```cpp
uint8_t  brightness = 200;   // 0-255, one byte — perfect for PWM/LED values
uint16_t sensorRaw  = 1023;  // 0-65535, two bytes
int32_t  temperature = -540; // signed, four bytes
bool     isOn = true;
```

`uint8_t` means "unsigned integer, 8 bits." You'll see these constantly in datasheets and libraries — get comfortable reading them.

## Structs — grouping related data

A `struct` bundles related values into one thing, instead of tracking five loose variables that all belong together:

```cpp
struct SensorReading {
  float temperatureC;
  float humidityPct;
  uint32_t timestampMs;
};
```

## Classes — data + behavior together

A `class` is a struct that also owns *functions* that act on its own data. This is the shape you'll use to model real components (an LED, a sensor, a display) — the object tracks its own state and exposes clean methods instead of you manually managing raw variables everywhere.

```cpp
class Led {
  public:
    Led(uint8_t pin) : pin_(pin), isOn_(false) {}

    void turnOn()  { isOn_ = true; }
    void turnOff() { isOn_ = false; }
    bool isOn() const { return isOn_; }

  private:
    uint8_t pin_;
    bool isOn_;
};
```

Notice `private` — the LED's internal state (`pin_`, `isOn_`) can only be touched through the methods you provide. This is what "clean interface" means in practice, and it's the same idea Phase 2's driver-development lesson builds on.

## Pointers & references — the short version

You don't need deep pointer arithmetic for this repo, but you do need to recognize these two patterns:

```cpp
void turnOn(Led& led) {   // reference: "let me modify the real Led, not a copy"
  led.turnOn();
}

void turnOn(Led* led) {   // pointer: same idea, but can also be "nothing" (nullptr)
  if (led != nullptr) {
    led->turnOn();
  }
}
```

**Reference (`&`)** — a second name for an existing variable. Use it when something will always exist and you just want to avoid copying it.
**Pointer (`*`)** — an address that *can* be empty (`nullptr`). Use it when something might not exist yet, or when a library specifically asks for one (common with hardware driver libraries).

You'll see both constantly in Arduino/ESP32 libraries — recognizing them is the goal here, not mastering every edge case.

## What's next

Head into `Example/` and build a small class that models a hardware component using everything above. Topic 04 then gets PlatformIO set up so you can run code like this on the actual Xiao ESP32S3.
