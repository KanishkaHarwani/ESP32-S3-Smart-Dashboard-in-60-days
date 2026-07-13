# Example — Debounced Button Toggles an LED

Wire up a button and an LED, and make a clean, debounced press toggle the LED on/off — one press, one toggle, no double-triggers from switch bounce.

## Wiring

- **LED**: anode → resistor → any GPIO pin (e.g. `D1`), cathode → GND
- **Button**: one leg → GPIO pin (e.g. `D2`), other leg → GND (using `INPUT_PULLUP`, no external resistor needed)

## The exercise

`main_starter.cpp` has the pin setup and the `loop()` structure in place, with `// TODO` markers for:

1. Reading the button with debounce logic
2. Toggling the LED's state only on a clean, single press (not while held)

`main_solution.cpp` is the completed reference — try the starter first.

## Build, upload, monitor

Same PlatformIO workflow as Topic 04:

```bash
pio run
pio run --target upload
pio device monitor
```

## Expected result

Press the button once → LED flips state (off→on or on→off) exactly once, even if you hold it down. No flickering or double-toggles.

## Stretch (optional)

Instead of a hard on/off, replace `digitalWrite` with `analogWrite` and fade the LED up over 1 second when toggled on, and fade it down when toggled off — combining debounce with PWM in one program.
