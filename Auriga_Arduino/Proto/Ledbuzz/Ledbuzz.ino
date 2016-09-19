/**
 * \par Copyright (C), 2016, Jakob Schyberg
 * @author  Jakob Schyberg
 * @version V1.0.0
 * @date    2016/09/18
 * @brief   Description: Prototype 1 for "Walle"
 *
 */

 #include <Arduino.h>
#include <avr/wdt.h>
#include <MeAuriga.h>

#define BUZZER_PORT                          45
#define RGBLED_PORT                          44

MeBuzzer buzzer;
MeRGBLed led;

void setup()
{
 delay(5);
  Serial.begin(115200);
  delay(5);
  led.setpin(RGBLED_PORT);
  buzzer.setpin(BUZZER_PORT);
  led.setColor(5,255,0,0);
  led.show();
  //buzzer.tone(1000,1000);
}

int i = 0;
int j = 0;
void loop()
{
  buzzer.setpin(BUZZER_PORT);
  delay(1000);
  led.setColor(i,j,0,0);
  led.show();
  j+=10;
  i++;
  buzzer.tone(1000,1000);
  /*
  Serial.read();
  Serial.print(" i:");
  Serial.println(i);*/

}
