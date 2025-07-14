#include "SSD.h"

const uint8_t digitSegments[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

SSD::SSD(const int segmentPins[7]) {
  for (int i = 0; i < 7; ++i) {
    _segmentPins[i] = segmentPins[i];
  }
}

void SSD::begin() {
  for (int i = 0; i < 7; ++i) {
    pinMode(_segmentPins[i], OUTPUT);
  }
}

void SSD::setSegments(const uint8_t segments[7]) {
  for (int i = 0; i < 7; ++i) {
    digitalWrite(_segmentPins[i], segments[i]);
  }
}

void SSD::displayDigit(uint8_t digit) {
  if (digit > 9) return;
  setSegments(digitSegments[digit]);
}

void SSD::clear() {
  uint8_t blank[7] = {0, 0, 0, 0, 0, 0, 0};
  setSegments(blank);
}