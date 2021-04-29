#include "Wheel.h"
#include "Arduino.h"

Wheel::Wheel(uint8_t pin_en1, uint8_t pin_en2, uint8_t pin_pwm, uint8_t pin_enc_a, uint8_t pin_enc_b)
    : _pin_en1(pin_en1), _pin_en2(pin_en2), _pin_pwm(pin_pwm), _pin_enc_a(pin_enc_a), _pin_enc_b(pin_enc_b), _encoder(_pin_enc_a, _pin_enc_b)
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

float Wheel::getRadianPsec() {
    return _encoder.read();
}

void Wheel::setPIDVelocity(float targetRadianPsec){
//    float Pgain = 1.0;    
//    float Igain = 0.0;    
//    float Dgain = 0.0;    
//    float error = targetRadianPsec - getRadianPsec();
////    float error_sum += error;
//    float error_sum = 0;
//    float PID_value = error*Pgain + error_sum*Igain + (last_error - error)*Dgain;
//    float last_error = error;
//    return PID_value;
}
