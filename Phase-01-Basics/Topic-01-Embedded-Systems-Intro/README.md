# Topic 01 — What Is Embedded Systems Programming

No code in this one — just the mental model you need before anything else makes sense.

## The core idea

When you write a normal app, an operating system sits between your code and the hardware — it manages memory for you, schedules your program alongside a hundred others, and cleans up after you if you mess up.

Embedded programming removes that safety net. Your code often *is* the whole system. It talks directly to real circuits: it reads a voltage, it flips a physical pin, and if it locks up, nothing reboots it for you. That's what makes it different — and why it starts to feel more like "controlling a machine" than "writing software."

## Three things that make embedded different

**1. Resources are tiny and fixed.**
Your ESP32-S3 doesn't get more RAM if it runs low — there's no swap file, no cloud burst. A few hundred KB of RAM is what you get. This is why embedded C++ leans on being deliberate about memory instead of letting a garbage collector clean up later.

**2. Time is real.**
A sensor might need to be read within microseconds of an event, or a display refresh might need to happen on a strict schedule. In app development, "a bit slow" is usually just annoying. In embedded, "a bit slow" can mean a missed signal, a corrupted reading, or a burnt-out component.

**3. You're touching hardware directly.**
A line of code doesn't just change a variable — it can turn on an LED, spin a motor, or send data over a wire to another chip. That's the payoff of embedded work: your code has a physical effect you can see, hear, or measure.

## Why this repo uses C++ specifically

C++ gives you low-level control (you can talk directly to hardware registers when you need to) while also giving you structure — classes, templates, and abstractions — so your code doesn't turn into an unreadable pile of raw pin manipulations as your project grows. That balance is exactly what a project like the Smart Dashboard needs: simple sketches early on, real architecture by Phase 3.

## What's next

Topic 02 starts writing actual C++ — the subset of the language you'll lean on most for embedded work. Topic 03 then looks at the specific chip you'll be programming: the ESP32-S3.
