#ifndef SSD_H
#define SSD_H

#include <Arduino.h>

class SSD {
  public:
    SSD(const int segmentPins[7]);
    void begin();
    void displayDigit(uint8_t digit);
    void clear();

  private:
    int _segmentPins[7];
    void setSegments(const uint8_t segments[7]);
};

#endif