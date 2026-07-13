# Example — Serial LED Control + Heartbeat

Control an LED by typing commands into the serial monitor, while the board also prints a periodic "heartbeat" message on its own — combining Serial output and input in one program.

## Wiring

Same LED setup as Topic 06: anode → resistor → `D1`, cathode → GND.

## The exercise

`main_starter.cpp` has the structure in place, with `// TODO` markers for:

1. Printing a "heartbeat" message every 2 seconds, without blocking (`millis()`, not `delay()`)
2. Reading a typed command from the serial monitor
3. Responding to `on`, `off`, and `status` commands

`main_solution.cpp` is the completed reference — try the starter first.

## Build, upload, monitor

```bash
pio run
pio run --target upload
pio device monitor
```

In the serial monitor, make sure line ending is set to **Newline** (PlatformIO's monitor defaults to this) so `readStringUntil('\n')` works correctly.

## Expected result

- Every 2 seconds, you see something like `[heartbeat] uptime: 4021ms` printed automatically
- Typing `on` + Enter turns the LED on and prints a confirmation
- Typing `off` + Enter turns it off
- Typing `status` + Enter prints whether the LED is currently on or off

## Stretch (optional)

Add a `blink` command that makes the LED blink for 5 seconds, then return to whatever state it was in before — without using `delay()` (this forces you to track blink state with `millis()` instead of freezing the loop, good practice for Phase 2's FreeRTOS tasks).
