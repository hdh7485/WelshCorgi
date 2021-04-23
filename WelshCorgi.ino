#include "SBUS.h"
SBUS futaba(Serial1);
uint16_t channels[16];
bool failSafe;
bool lostFrame;

int Motor_speed = 100;

class Wheel {
  private:
    int _pin_en1;
    int _pin_en2;
    int _pin_pwm;
  public:
    Wheel(int pin_en1 = 9, int pin_en2 = 10, int pin_pwm = 11)
      : _pin_en1(pin_en1), _pin_en2(pin_en2), _pin_pwm(pin_pwm)
    {
      pinMode(_pin_en1, OUTPUT);
      pinMode(_pin_en2, OUTPUT);
      pinMode(_pin_pwm, OUTPUT);
      digitalWrite(_pin_en1, HIGH);
      digitalWrite(_pin_en2, LOW);
    }
    void rotate(int pwm = 0) {
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
};

Wheel wheel_FL(20, 19, 18);
Wheel wheel_FR(21, 22, 23);
Wheel wheel_RL(3, 4, 2);
Wheel wheel_RR(5, 6, 7);

void setup()
{
  pinMode(13, OUTPUT);
  futaba.begin();
}
void loop()
{
  if (futaba.read(channels, &failSafe, &lostFrame)) {
    int x = channels[1] - 1025;
    int y = channels[0] - 1025;
    Serial.println(x);
    Serial.println(y);
    wheel_FL.rotate(-x + y);
    wheel_RL.rotate(-x - y);
    wheel_FR.rotate(-x - y);
    wheel_RR.rotate(-x + y);
    delay(5);
  }
}
