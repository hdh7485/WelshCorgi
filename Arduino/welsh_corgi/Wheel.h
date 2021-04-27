#ifndef Wheel_h
#define Wheel_h
#include "Arduino.h"
#include <Encoder.h>

class Wheel {
  private:
    const uint8_t _pin_en1;
    const uint8_t _pin_en2;
    const uint8_t _pin_pwm;
    const uint8_t _pin_enc_a;
    const uint8_t _pin_enc_b;
    Encoder _encoder;
  public:
    Wheel(uint8_t pin_en1 = 9, uint8_t pin_en2 = 10, uint8_t pin_pwm = 11, uint8_t pin_enc_a=2, uint8_t pin_enc_b=3);

    void rotate(int pwm = 0);

    float getRadianPsec();

    void setPIDVelocity(float targetRadianPsec);
};
#endif
