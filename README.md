# Traffic Light

A non-blocking traffic light simulation using millis() 
and state machine pattern on Arduino Uno.

## Components
- Arduino Uno
- 3x LED (Red, Yellow, Green)
- 3x 220Ω Resistor

## Light Meanings
- 🔴 Red    = STOP
- 🟡 Orange = READY
- 🟢 Green  = PASS

## Concepts Covered
- millis() non-blocking timing
- State machine using enum and switch/case
- Reusable functions
- Serial Monitor debugging

## How It Works
STOP (Red) stays on for 3 seconds, switches to READY (Orange) 
for 1 seconds, then PASS (Green) for 3 second, 
then back to STOP — all without delay().

## Simulation
[Run on Wokwi](https://wokwi.com/projects/466190861128474625)
