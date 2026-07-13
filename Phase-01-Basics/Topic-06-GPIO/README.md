# Topic 06 — GPIO

GPIO (General Purpose Input/Output) pins are the most basic thing an embedded chip does: read a voltage, or set one. Everything else in this repo — sensors, displays, comms — is built on top of this same idea, just with more structure around it.

## Digital output

Setting a pin `HIGH` or `LOW` is the whole idea:

```cpp
pinMode(LED_PIN, OUTPUT);
digitalWrite(LED_PIN, HIGH);  // ~3.3V out
digitalWrite(LED_PIN, LOW);   // 0V out
```

You did exactly this in Topic 04's blink example.

## Digital input

Reading a pin tells you whether it's currently high or low — this is how you read a pushbutton:

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
bool pressed = (digitalRead(BUTTON_PIN) == LOW);  // LOW because of the pullup wiring below
```

**Why `INPUT_PULLUP` and not just `INPUT`?** An unconnected digital pin "floats" — it can read random noise as HIGH or LOW. `INPUT_PULLUP` uses the chip's internal resistor to hold the pin HIGH by default, so wiring a button between the pin and ground gives you a clean, predictable LOW when pressed. It's why the logic above is inverted (`== LOW` means pressed) — this trips people up the first time, so it's worth remembering now.

## Debounce: the annoying-but-necessary part

A mechanical button doesn't cleanly go from "not pressed" to "pressed" — the contacts physically bounce for a few milliseconds, and your chip is fast enough to see that bounce as several rapid presses instead of one. Debouncing means ignoring changes that happen too soon after the last one:

```cpp
if (digitalRead(BUTTON_PIN) == LOW && (millis() - lastPressTime > 50)) {
  // treat this as a real, single press
  lastPressTime = millis();
}
```

`millis()` returns milliseconds since the board booted — you'll use it constantly for timing without blocking (`delay()` freezes everything; `millis()` doesn't).

## PWM: fake analog output

Digital pins are only HIGH or LOW — no in-between. PWM (Pulse Width Modulation) fakes an in-between value by switching HIGH/LOW very fast, at a controllable ratio (duty cycle). An LED fading isn't actually at "half brightness" electrically — it's flickering faster than your eye can see, spending roughly half its time on:

```cpp
analogWrite(LED_PIN, 128);  // roughly 50% duty cycle, out of 0-255
```

## What's next

The example combines all three: debounced button input toggling an LED, with a PWM fade as a stretch goal. Topic 07 then covers UART — your main tool for actually seeing what your program is doing while it runs.
