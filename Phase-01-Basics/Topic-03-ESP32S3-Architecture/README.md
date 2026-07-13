# Topic 03 — ESP32-S3 Architecture

A quick tour of the chip you're actually programming. No code here — just enough of a mental map so later topics ("this runs on Core 1", "that lives in flash") make sense instead of feeling like magic.

## Two cores, not one

The ESP32-S3 has **two CPU cores** (Xtensa LX7, up to 240MHz each). Most simple Arduino-style sketches only ever use one core without you noticing — but this matters a lot later:

- **Phase 2 (FreeRTOS)** — you'll deliberately run different tasks (sensor reading, networking, display) so they can genuinely run in parallel instead of competing for time on a single core.
- Wi-Fi and Bluetooth radios lean on this dual-core setup internally, which is part of why the ESP32 family became the default choice for connected projects.

## Memory: three things to know

You don't need deep memory-management skills for this repo, but recognizing these terms will save you a lot of confused debugging later:

| Type | What it is | Rough size (Xiao ESP32S3) |
|---|---|---|
| **Flash** | Where your compiled program lives — persists after power-off | 8MB |
| **RAM (SRAM)** | Working memory — variables, the stack, anything "live" while running | ~512KB |
| **PSRAM** | Extra RAM some boards add for memory-hungry tasks (e.g. camera buffers, big display framebuffers) | 8MB (Xiao ESP32S3 Sense variant; check your specific board) |

The key takeaway: **RAM is small and fixed.** Unlike your laptop, there's no swap space to fall back on — this is why Topic 02's fixed-width types (`uint8_t` instead of assuming `int`) actually matters here, not just as a style preference.

## Peripherals you'll actually use in this repo

The chip exposes dedicated hardware for talking to the outside world — these aren't "features," they're the whole reason embedded chips look different from a general-purpose CPU:

- **GPIO** — general-purpose pins, digital in/out (Topic 06)
- **UART** — serial communication, your main debugging tool (Topic 07)
- **SPI** — fast peripheral bus, used for the TFT and E-ink displays (Phase 2)
- **I²C** — simpler two-wire bus, used for sensors like your temp/humidity module (Topic 09)
- **Wi-Fi / Bluetooth radios** — built into the chip, this is what makes the "Smart Dashboard" networked at all (Phase 2)

## Why ESP32-**S3** specifically

The S3 variant adds a few things over the original ESP32 that matter for this repo:

- **USB OTG support** — the Xiao ESP32S3 can appear as a USB device directly (no separate USB-to-serial chip needed on some boards), which simplifies flashing and debugging.
- **More capable AI/vector instructions** — not something this repo uses directly, but it's why S3 boards are popular for camera/ML side-projects if you explore beyond the dashboard.
- It's simply the current, well-supported chip in the family — better long-term library and tooling support than older ESP32 variants.

## What's next

Topic 04 gets PlatformIO installed and configured so you can actually compile and flash code onto this chip — turning everything above from theory into something you can watch happen on real hardware.
