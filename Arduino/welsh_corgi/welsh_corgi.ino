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

int x;
int y;
int yaw;

void setup()
{
  pinMode(13, OUTPUT);
  futaba.begin();
}
void loop()
{
  if (futaba.readCal(channels, &failSafe, &lostFrame)) {
    //x = channels[1] - 1025;
    //y = channels[0] - 1025;
    //yaw = channels[3] - 1025;
    x = channels[1] * 1024;
    y = channels[0] * 1024;
    yaw = channels[3] * 1024;
    Serial.println(x);
    Serial.println(y);
    Serial.println(yaw);
    wheel_FL.rotate(-x + y + yaw);
    wheel_RL.rotate(-x - y + yaw);
    wheel_FR.rotate(-x - y + yaw);
    wheel_RR.rotate(-x + y + yaw);
    delay(5);
  }
}
