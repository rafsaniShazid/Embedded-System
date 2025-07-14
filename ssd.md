# SSD Arduino Library

Simple library to control a **single-digit 7-segment display** (common cathode) with Arduino.

---

## Features

- Display digits 0 to 9
- Clear the display
- Easy pin configuration

---

## Hardware Setup

- Use a **common cathode 7-segment display**.
- Connect each segment pin (a to g) to Arduino digital pins via a 220–470Ω resistor.
- Connect the common cathode pin(s) to **GND**.
- Make sure to note which Arduino pin corresponds to which segment.

---

## Installation

1. Download the `SSD` file.
2. Open `Documents\Arduino\libraries`.
3. Paste the folder
4. The library is installed and ready to use.

---

## Usage

### Wiring Example

| Segment | Arduino Pin (example) |
|---------|-----------------------|
| a       | 2                     |
| b       | 3                     |
| c       | 4                     |
| d       | 5                     |
| e       | 6                     |
| f       | 7                     |
| g       | 8                     |

### Code Example

```cpp
#include <SSD.h>

// Define Arduino pins connected to segments a to g
int segments[7] = {2, 3, 4, 5, 6, 7, 8};

// Create SSD object
SSD ssd(segments);

void setup() {
  ssd.begin(); // Initialize pins as outputs
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    ssd.displayDigit(i); // Display digits 0 to 9
    delay(1000);
  }
  ssd.clear(); // Turn off all segments
  delay(1000);
}
