# Phase 2 — Connectivity & Architecture

Move from "reads a sensor" to "connected device with a real architecture." This phase adds displays, networking, and the structural concepts (RTOS, state machines, layering) that separate a toy sketch from real firmware.

**Board:** Xiao ESP32S3
**Also needed:** 2.8" TFT (SPI), E-ink display, SD card module, buck converters (3.3V/5V)

## Lessons

1. **Displays and graphics — TFT**
   Driving the 2.8" TFT over SPI: framebuffers, drawing primitives (lines, shapes, text), fonts.

2. **E-ink display**
   Partial refresh, why it's slower but far lower power than the TFT — contrast the two display types directly.

3. **Wi-Fi networking**
   Station mode, connecting to a network, handling disconnects/reconnects gracefully (not just happy-path code).

4. **HTTP/HTTPS**
   Making requests from the device, TLS basics on embedded hardware, working with certificates.

5. **REST APIs**
   Calling a public API for real data, understanding endpoints/methods/status codes, structuring a simple one of your own.

6. **JSON**
   Parsing and serializing with ArduinoJson, mapping API responses into C++ structs cleanly.

7. **FreeRTOS**
   Tasks and scheduling, `vTaskDelay` vs. blocking delay, queues for passing data between tasks, and *why* an RTOS beats a single `loop()` once you're juggling sensors + network + display.

8. **Software architecture**
   Layering: drivers vs. business logic vs. UI. Why mixing these makes firmware unmaintainable fast.

9. **State machines**
   Modeling your device's behavior explicitly: `CONNECTING → FETCHING → DISPLAYING → ERROR`, and why this beats a tangle of flags and booleans.

10. **Driver development**
    Write a thin driver wrapping a sensor/peripheral's I²C or SPI calls — a clean interface the rest of your code depends on, not the raw registers.

11. **Debugging (intermediate)**
    Log levels, reading a crash/backtrace, what a watchdog timer is and why it matters once things run unattended.

12. **Power**
    Using the buck converters to power the display and MCU cleanly, and what brownout behavior looks like when you get it wrong.

## Checkpoint project

**Live data display:** connect to Wi-Fi, call a public REST API, parse the JSON response, and render it on the TFT or E-ink display — all driven through an explicit state machine and running as FreeRTOS tasks (not one big `loop()`). This is effectively a smaller, single-source version of the Phase 3 dashboard.

Once this works reliably — including handling a dropped Wi-Fi connection or failed API call without hanging — move to `phase3-smart-dashboard/`.

## Examples

Code for each lesson lives in `examples/`, named by lesson number (e.g. `07-freertos-tasks/`).
