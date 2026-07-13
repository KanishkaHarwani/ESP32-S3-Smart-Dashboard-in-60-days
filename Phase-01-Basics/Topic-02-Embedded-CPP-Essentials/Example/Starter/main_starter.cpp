// Topic 02 — Embedded C++ Essentials
// Starter: fill in the TODOs. No hardware needed — compiles with plain g++.
//
//   g++ -std=c++17 -o led_demo main_starter.cpp
//   ./led_demo

#include <cstdint>
#include <iostream>

class Led {
  public:
    Led(uint8_t pin) : pin_(pin), isOn_(false) {}

    void turnOn() {
      // TODO: set isOn_ to true
    }

    void turnOff() {
      // TODO: set isOn_ to false
    }

    bool isOn() const {
      // TODO: return the current state
      return false;
    }

  private:
    uint8_t pin_;
    bool isOn_;
};

class Button {
  public:
    Button(uint8_t pin) : pin_(pin), isPressed_(false) {}

    void press() {
      // TODO: set isPressed_ to true
    }

    void release() {
      // TODO: set isPressed_ to false
    }

    bool isPressed() const {
      // TODO: return the current state
      return false;
    }

  private:
    uint8_t pin_;
    bool isPressed_;
};

// TODO: implement this function.
// It should take the Led and Button BY REFERENCE (not by copy),
// and set the LED on/off to match the button's pressed state.
void updateLedFromButton(Led& led, const Button& button) {
  // TODO
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
