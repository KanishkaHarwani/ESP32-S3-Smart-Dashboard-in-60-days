# Topic 04 — PlatformIO Toolchain

This is where things stop being theory. By the end of this topic, you'll have real code running on your Xiao ESP32S3.

## Why PlatformIO instead of Arduino IDE

Arduino IDE is fine for tiny sketches, but it gets awkward fast: managing libraries by hand, no real project structure, weak editor support. **PlatformIO** is a proper build system — it handles your toolchain, libraries, and board configuration through one config file, and works inside VS Code with real autocomplete and debugging support. It's also what most production embedded teams actually use, so you're learning the real workflow, not a toy version of it.

## Install

1. Install [VS Code](https://code.visualstudio.com/)
2. Inside VS Code, install the **PlatformIO IDE** extension (Extensions panel → search "PlatformIO IDE")
3. Restart VS Code when prompted — PlatformIO installs its own toolchain (compiler, uploader) automatically on first run

## Anatomy of a PlatformIO project

```
my-project/
├── platformio.ini      # board config, framework, libraries — the heart of the project
├── src/
│   └── main.cpp        # your code goes here
├── include/             # optional headers
└── lib/                 # optional private libraries
```

`platformio.ini` is the important one. A minimal config for the Xiao ESP32S3 looks like this:

```ini
[env:seeed_xiao_esp32s3]
platform = espressif32
board = seeed_xiao_esp32s3
framework = arduino
monitor_speed = 115200
```

- **`platform`** — which chip family's toolchain to install (espressif32 covers the whole ESP32 line)
- **`board`** — the exact board definition (pin mappings, flash size, etc.)
- **`framework`** — we're using `arduino`, since the Arduino core gives you `setup()`/`loop()` and a huge library ecosystem, while still being real C++ underneath
- **`monitor_speed`** — baud rate for the serial monitor (Topic 07 covers what this means)

## The core workflow

Every PlatformIO project boils down to three actions, all available as buttons in the VS Code status bar or via CLI:

```bash
pio run              # build (compile)
pio run --target upload   # build + flash to the board
pio device monitor   # open the serial monitor to see Serial.print() output
```

You'll use this exact loop — build, upload, monitor — for the rest of the repo.

## What's next

Head into `Example/` to set up your first real PlatformIO project and blink an LED on actual hardware. From Topic 06 onward, every example in this repo follows this same project shape.
