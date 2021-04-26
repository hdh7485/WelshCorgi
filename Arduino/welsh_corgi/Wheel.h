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
//    {
//      pinMode(_pin_en1, OUTPUT);
//      pinMode(_pin_en2, OUTPUT);
//      pinMode(_pin_pwm, OUTPUT);
//      digitalWrite(_pin_en1, HIGH);
//      digitalWrite(_pin_en2, LOW);
//    }
    void rotate(int pwm = 0);
//{
//      if (pwm > 0) {
//        digitalWrite(_pin_en1, HIGH);
//        digitalWrite(_pin_en2, LOW);
//        analogWrite(_pin_pwm, pwm);
//      }
//      else {                       // FOLDING
//        digitalWrite(_pin_en1, LOW);
//        digitalWrite(_pin_en2, HIGH);
//        analogWrite(_pin_pwm, -pwm);
//      }
//    }
};
#endif
