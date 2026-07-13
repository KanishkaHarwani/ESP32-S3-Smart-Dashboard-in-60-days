# Example — Model an LED and a Button in C++

No hardware, no PlatformIO yet — this compiles and runs directly on your computer. The goal is purely the C++: fixed-width types, a class with private state, and a function that takes a reference.

## The exercise

You're modeling two components as classes:

- **`Led`** — has a pin number and an on/off state. Needs `turnOn()`, `turnOff()`, and `isOn()`.
- **`Button`** — has a pin number and a pressed state. Needs `press()`, `release()`, and `isPressed()`.

Then write one plain function, `updateLedFromButton(Led& led, const Button& button)`, that turns the LED on when the button is pressed and off when it isn't — taking both by reference, no copies.

`main_starter.cpp` has the class shells and `// TODO` markers where you fill things in. `main_solution.cpp` is the completed reference — try the starter first.

## Build & run

You need a C++ compiler (`g++` or `clang++`) — no board, no PlatformIO required for this one.

```bash
g++ -std=c++17 -o led_demo main_starter.cpp
./led_demo
```

(swap in `main_solution.cpp` once you want to check your work, or compare)

## Expected output

```
Button pressed -> LED is ON
Button released -> LED is OFF
```

## Stretch (optional)

Add a `Buzzer` class following the same pattern, and make `updateLedFromButton` also sound the buzzer on press. This is good practice before Topic 06, where you'll wire this exact logic to real GPIO pins.
