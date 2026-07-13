# Phase 3 — Smart Dashboard (Final Project)

Everything from Phase 1 and 2 comes together here: sensors, network data, and a display, run as proper FreeRTOS-managed firmware — with the practices that make it something you'd actually trust to run unattended.

**Board:** Xiao ESP32S3
**Also needed:** everything from Phase 1 & 2, plus optionally: SD card (logging), BNO085 IMU, LED strip (status indicator), Raspberry Pi (optional network host)

## What you're building

A dashboard device that:
- Reads at least one local sensor (temp/humidity, and optionally IMU)
- Pulls at least one data source from the network (API call from Phase 2, or your own small backend)
- Displays both on the TFT and/or E-ink screen, laid out clearly
- Runs as separate FreeRTOS tasks (sensing, networking, display) coordinated through a state machine
- Recovers gracefully from Wi-Fi drops, API failures, or a disconnected sensor — instead of hanging or crashing
- Can be updated with new firmware over the air, without a USB cable

The exact data you display is up to you — weather + local sensor readings, a stock ticker, GitHub stats, whatever's interesting enough that you'd actually leave it running on your desk.

## Lessons

1. **Project architecture**
   Decide your data sources, display layout, and update cadence before writing code. Sketch the block diagram: what task owns what data, what triggers a redraw.

2. **Integration**
   Bring Phase 1+2 pieces together under FreeRTOS: a sensing task, a networking task, a display task, communicating via queues — not global variables everywhere.

3. **OTA updates**
   Implement firmware-over-the-air updates, basic versioning, and a rollback strategy so a bad update doesn't brick the device.

4. **Production firmware practices**
   Structured error handling, a config management approach (Wi-Fi credentials, API keys — not hardcoded in `main.cpp`), a real logging strategy, watchdog timers, and recovering cleanly from power loss.

5. **Optional: local logging**
   Log sensor/API data to the SD card as a history/backup — useful if the network drops or you want a record over time.

6. **Debugging & polish**
   Deliberately stress-test: kill the Wi-Fi mid-run, feed it a malformed API response, disconnect the sensor. Confirm the device degrades gracefully instead of hanging.

7. **Documentation**
   Write up the final build: architecture diagram, wiring, what you'd do differently. This becomes the closing entry in the repo.

## Optional extensions

- Raspberry Pi as a network host — running a small backend, MQTT broker, or dashboard aggregator that your ESP32-S3 pulls from
- BNO085 IMU as an additional data source (orientation/motion)
- Addressable LED strip as a status indicator (e.g. red = error state, green = healthy)

## Done when

- It runs continuously without manual intervention
- A dropped Wi-Fi connection or bad API response doesn't hang the device
- You can push an OTA update and it applies successfully
- The `src/` folder and this README reflect the final, working build

## Source

Final project code lives in `src/`, organized by the architecture you defined in lesson 1 (e.g. `drivers/`, `tasks/`, `net/`, `ui/`) rather than one flat file.
