#include "Wheel.h"
#include "Arduino.h"

Wheel::Wheel(int pin_en1, int pin_en2, int pin_pwm)
    : _pin_en1(pin_en1), _pin_en2(pin_en2), _pin_pwm(pin_pwm)
{
    pinMode(_pin_en1, OUTPUT);
    pinMode(_pin_en2, OUTPUT);
    pinMode(_pin_pwm, OUTPUT);
    digitalWrite(_pin_en1, HIGH);
    digitalWrite(_pin_en2, LOW);
}

void Wheel::rotate(int pwm) {
    if (pwm > 0) {
        digitalWrite(_pin_en1, HIGH);
        digitalWrite(_pin_en2, LOW);
        analogWrite(_pin_pwm, pwm);
    }
    else {                       // FOLDING
        digitalWrite(_pin_en1, LOW);
        digitalWrite(_pin_en2, HIGH);
        analogWrite(_pin_pwm, -pwm);
    }
}
