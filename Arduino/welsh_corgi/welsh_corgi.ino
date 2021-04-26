#include "SBUS.h"
#include "Wheel.h"

SBUS futaba(Serial1);
uint16_t channels[16];
bool failSafe;
bool lostFrame;

int Motor_speed = 100;


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
