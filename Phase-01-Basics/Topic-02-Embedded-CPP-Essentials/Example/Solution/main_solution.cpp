// Topic 02 — Embedded C++ Essentials
// Solution. No hardware needed — compiles with plain g++.
//
//   g++ -std=c++17 -o led_demo main_solution.cpp
//   ./led_demo

#include <cstdint>
#include <iostream>

class Led {
  public:
    Led(uint8_t pin) : pin_(pin), isOn_(false) {}

    void turnOn() {
      isOn_ = true;
    }

    void turnOff() {
      isOn_ = false;
    }

    bool isOn() const {
      return isOn_;
    }

  private:
    uint8_t pin_;
    bool isOn_;
};

class Button {
  public:
    Button(uint8_t pin) : pin_(pin), isPressed_(false) {}

    void press() {
      isPressed_ = true;
    }

    void release() {
      isPressed_ = false;
    }

    bool isPressed() const {
      return isPressed_;
    }

  private:
    uint8_t pin_;
    bool isPressed_;
};

// Takes both by reference: no copies, and changes to `led` here
// affect the real object the caller has.
void updateLedFromButton(Led& led, const Button& button) {
  if (button.isPressed()) {
    led.turnOn();
  } else {
    led.turnOff();
  }
}

int main() {
  Led led(2);        // pretend pin 2
  Button button(4);   // pretend pin 4

  button.press();
  updateLedFromButton(led, button);
  std::cout << "Button pressed -> LED is " << (led.isOn() ? "ON" : "OFF") << "\n";

  button.release();
  updateLedFromButton(led, button);
  std::cout << "Button released -> LED is " << (led.isOn() ? "ON" : "OFF") << "\n";

  return 0;
}
