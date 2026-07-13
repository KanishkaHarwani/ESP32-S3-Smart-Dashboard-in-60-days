# Roadmap

Full lesson-by-lesson breakdown for all 3 phases. Check items off as you complete them — this file doubles as your progress tracker (no separate PROGRESS.md/CHANGELOG.md needed).

---

## Phase 1 — Foundations

Board: Xiao ESP32S3 · breadboard, LEDs, buttons, buzzer, temp/humidity sensor, multimeter

- [ ] What is embedded systems programming — constraints, real-time, memory
- [ ] Embedded C++: variables, types, structs/classes, pointers & references
- [ ] ESP32-S3 architecture: dual-core, memory map, peripherals overview
- [ ] Toolchain: PlatformIO setup, project structure, build/upload/monitor
- [ ] Git & GitHub: repo structure, commits, branches, `.gitignore` for firmware
- [ ] GPIO: digital in/out, pushbutton + debounce, PWM/LED fade
- [ ] UART: serial communication, `Serial` monitor as a debug tool
- [ ] SPI: concept + wiring (prep for Phase 2 displays)
- [ ] I²C: concept + wiring, device scanning, reading the temp/humidity sensor
- [ ] Debugging basics: serial prints, wiring/power mistakes, using the multimeter
- [ ] **Checkpoint project:** sensor reading → LED/buzzer feedback loop

---

## Phase 2 — Connectivity & Architecture

Board: Xiao ESP32S3 · + TFT, E-ink display, SD card, buck converters

- [ ] Displays and graphics: driving the TFT (SPI) — framebuffers, primitives, fonts
- [ ] E-ink display: partial refresh, low-power display concepts
- [ ] Wi-Fi networking: station mode, connecting, reconnect handling
- [ ] HTTP/HTTPS: making requests, TLS basics on embedded, certificates
- [ ] REST APIs: calling a public API, structuring a simple endpoint
- [ ] JSON: parsing/serializing (ArduinoJson), mapping API data to structs
- [ ] FreeRTOS: tasks, scheduling, `vTaskDelay`, queues, why RTOS over one big loop
- [ ] Software architecture: layering drivers vs. logic vs. UI
- [ ] State machines: modeling app states (connecting → fetching → displaying → error)
- [ ] Driver development: writing a thin driver for a sensor/peripheral
- [ ] Debugging (intermediate): log levels, crash/backtrace basics, watchdog timers
- [ ] Power: buck converters, powering display + MCU cleanly, brownout awareness
- [ ] **Checkpoint project:** pull API data over WiFi, parse JSON, render on display, driven by a state machine

---

## Phase 3 — Smart Dashboard (Final Project)

- [ ] Project architecture: data sources, display layout, update cadence
- [ ] Integrate Phase 1+2 pieces: sensors + network data + display, task-managed via FreeRTOS
- [ ] OTA updates: implementing firmware-over-the-air, versioning, rollback safety
- [ ] Production firmware practices: error handling, config management, logging, watchdogs, power-loss recovery
- [ ] Optional: local data logging to SD card as backup/history
- [ ] Debugging & polish: stress-testing, WiFi drop, API failure, sensor disconnect
- [ ] Documentation: final README/build log for the repo

---

## Progress

| Phase | Status |
|---|---|
| Phase 1 — Foundations | Not started |
| Phase 2 — Connectivity & Architecture | Not started |
| Phase 3 — Smart Dashboard | Not started |

Update the table above as you complete each phase.
