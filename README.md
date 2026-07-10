# ESP32-S3-Smart-Dashboard-in-60-days

Learn embedded C++ from scratch by building a real product: a **networked smart dashboard** on the ESP32-S3 — sensors, live data from the web, a real display, and production-grade firmware practices, in 60 days.

This repo is a structured, hands-on path. Each phase builds directly on the last, and every phase ends with a working checkpoint project — not just disconnected exercises.

## Why this repo

Most "learn embedded C++" resources either stay stuck in blink-an-LED territory or jump straight into production firmware with no ramp. This repo is built around one real target: a small dashboard device that reads sensors, pulls data from an API, and displays it — the kind of thing you'd actually want on your desk. Along the way you pick up the C++, the RTOS, the networking, and the practices that make firmware maintainable.

## Prerequisites

- Basic programming experience in *any* language (loops, functions, variables). No embedded or C++ experience required.
- A computer with USB, and the patience to debug wiring before code (embedded work is like that).

## Core hardware

| Component | Role |
|---|---|
| Seeed Xiao ESP32S3 | Primary dev board |
| Breadboard + jumper wires + resistors | Prototyping |
| LEDs, pushbuttons, buzzer | Phase 1 I/O |
| Temp/humidity sensor (I²C) | Phase 1–2 sensing |
| 2.8" TFT (SPI) + E-ink display | Phase 2–3 output |
| SD card module | Data logging |
| 3.3V/5V buck converters | Power lessons |
| Digital multimeter | Debugging |

Full hardware list, including optional additions, lives in [`hardware/README.md`](hardware/README.md).

## The 3 phases

### Phase 1 — Foundations
Embedded C++, ESP32-S3 architecture, PlatformIO, Git basics, and the core peripherals (GPIO, UART, SPI, I²C). Ends with a sensor-to-feedback checkpoint project.

### Phase 2 — Connectivity & Architecture
Displays and graphics, Wi-Fi, HTTP/HTTPS, REST APIs, JSON, FreeRTOS, software architecture, state machines, and driver development. Ends with a checkpoint: live API data parsed and rendered on-screen, run through a state machine.

### Phase 3 — Smart Dashboard (Final Project)
Everything integrated: sensors + network data + display, task-managed with FreeRTOS, OTA updates, and production firmware practices (error handling, logging, watchdogs, recovery).

See [`ROADMAP.md`](ROADMAP.md) for the full lesson-by-lesson breakdown and progress tracking.

## Repo structure

```
├── README.md
├── ROADMAP.md
├── LICENSE
├── phase1-foundations/
│   ├── README.md
│   └── examples/
├── phase2-connectivity-architecture/
│   ├── README.md
│   └── examples/
├── phase3-smart-dashboard/
│   ├── README.md
│   └── src/
├── hardware/
│   └── README.md
└── resources/
```

## How to use this repo

1. Work through phases in order — each assumes the last is done.
2. Every lesson folder has a short README (concept + what to build) and example code.
3. Build the checkpoint project at the end of each phase before moving on.
4. Commit as you go — this repo also doubles as your Git practice.

## License

See [LICENSE](LICENSE).
