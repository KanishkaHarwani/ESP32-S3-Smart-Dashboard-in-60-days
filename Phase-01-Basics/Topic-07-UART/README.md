# Topic 07 — UART

UART (Universal Asynchronous Receiver/Transmitter) is the simplest way two devices exchange data over wires — and on your dev board, it's also your window into what the chip is actually doing. From here on, `Serial` is how you debug everything in this repo.

## Baud rate: both sides need to agree

UART has no clock wire — both devices just agree in advance on how fast bits are being sent, in bits per second (**baud rate**). If they don't match, you get garbage characters instead of readable text.

```cpp
Serial.begin(115200);  // must match monitor_speed in platformio.ini
```

That's why `platformio.ini` (Topic 04) has `monitor_speed = 115200` — it has to match what you call `Serial.begin()` with in code, or the serial monitor shows nonsense.

## Printing — your primary debugging tool

```cpp
Serial.println("Hello from the ESP32-S3");   // text + newline
Serial.print("Reading: ");
Serial.println(42);                           // numbers work directly
Serial.printf("Temp: %.1fC\n", 23.5);          // formatted, like C's printf
```

Before you have a display, before you have Wi-Fi — `Serial.println` is how you find out if your code is even reaching a given line. Sprinkling print statements through code you're not sure about is a completely normal, professional debugging technique, not a shortcut.

## Reading input — the board can listen too

Serial isn't just output. You can type into the serial monitor and have your program react:

```cpp
if (Serial.available() > 0) {
  String command = Serial.readStringUntil('\n');
  command.trim();  // remove trailing whitespace/newline characters

  if (command == "on") {
    // ...
  }
}
```

`Serial.available()` tells you if there's unread incoming data waiting — always check this before trying to read, or you'll block waiting for input that isn't there yet.

## Non-blocking timing recap

You'll want to print status periodically without freezing everything else with `delay()`. This is the same `millis()` pattern from Topic 06's debounce:

```cpp
uint32_t lastPrint = 0;
if (millis() - lastPrint > 2000) {
  lastPrint = millis();
  Serial.println("still alive");
}
```

## What's next

The example combines both directions: the board prints a periodic status message, and accepts simple text commands to control an LED. Topic 08 covers SPI conceptually, then Topic 09 gets you reading a real I²C sensor and printing its values over exactly this UART connection.
