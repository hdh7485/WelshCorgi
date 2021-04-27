#ifndef Wheel_h
#define Wheel_h
#include "Arduino.h"

class Wheel {
  private:
    int _pin_en1;
    int _pin_en2;
    int _pin_pwm;
  public:
    Wheel(int pin_en1 = 9, int pin_en2 = 10, int pin_pwm = 11);
    void rotate(int pwm = 0);
};
#endif
