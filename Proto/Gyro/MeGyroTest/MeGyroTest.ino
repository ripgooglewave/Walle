/**
 * @version V1.0.0
 * @date    2016/09/18
 * @brief   Modified Gyro example to work with Auriga
 *
 */

#include "MeAuriga.h"
#include <Wire.h>

MeGyro gyro(1,0x69);

void setup()
{
  Serial.begin(115200);
  gyro.begin();
}

void loop()
{
  gyro.update();
  Serial.read();
  Serial.print("X:");
  Serial.print(gyro.getAngleX() );
  Serial.print(" Y:");
  Serial.print(gyro.getAngleY() );
  Serial.print(" Z:");
  Serial.println(gyro.getAngleZ() );
  delay(10);
}

