/**
 * @author  Jakob Schyberg
 * @version V1.0.0
 * @date    2016/09/18
 * @brief   Description: Prototype for "Walle"
 *
 */
 
#include "MeAuriga.h"
#include <Wire.h>

typedef struct
{
  double P, I, D;
  float Setpoint;
  double Output, Integral, differential, lastAngle;
} PID;

PID  PID_angle;
MeGyro gyro(1,0x69);
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);

void setupPID() {
  PID_angle.Setpoint = -1;
  PID_angle.P = 15;          //17;
  PID_angle.I = 0.6;           //0;
  PID_angle.D = 0.02;        //-0.2  PID_speed.Setpoint = 0; 
  PID_angle.lastAngle = PID_angle.Setpoint;
}

void setupMotor() {
  attachInterrupt(Encoder_1.getIntNum(), isr_process_encoder1, RISING);
  attachInterrupt(Encoder_2.getIntNum(), isr_process_encoder2, RISING);
  Serial.begin(115200);
  
  //Set PWM 8KHz
  TCCR1A = _BV(WGM10);
  TCCR1B = _BV(CS11) | _BV(WGM12);

  TCCR2A = _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS21);
}

void setup()
{
  setupPID();
  setupMotor();
  Serial.begin(115200);
  gyro.begin();
}

void loop()
{
  gyro.update();
  if(Serial.available())
  {
    PID_angle.Setpoint = Serial.parseFloat();
    Serial.read();
    Serial.print("Relay: ");
    Serial.print(PID_angle.Setpoint);
  }
    
  PID_angle_compute();
}

void PID_angle_compute(void)   //PID
{
  double angleX = -gyro.getAngleX();
  double error = angleX - PID_angle.Setpoint;
  PID_angle.Integral += error;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
  if(abs(angleX - PID_angle.Setpoint) < 0.1)
  {
    PID_angle.Integral = 0;
  }

  PID_angle.differential = angleX-PID_angle.lastAngle;
  PID_angle.lastAngle = angleX;
  PID_angle.Output = PID_angle.P * error + PID_angle.I * PID_angle.Integral + PID_angle.D * PID_angle.differential;
  if(PID_angle.Output > 0)
  {
    PID_angle.Output = PID_angle.Output;
  }
  else
  {
    PID_angle.Output = PID_angle.Output;
  }

  double pwm_left = PID_angle.Output; // - PID_turn.Output;
  double pwm_right = -PID_angle.Output; //- PID_turn.Output;
  double balance_car_speed_offsets;
/*
  if(move_flag == true)
  { 
    balance_car_speed_offsets = 0;
  }
  else
  {*/
    balance_car_speed_offsets = 1.1 * (abs(Encoder_1.getCurrentSpeed()) - abs(Encoder_2.getCurrentSpeed()));
  //}

  if(balance_car_speed_offsets > 0)
  {
    if(pwm_left > 0)
    {
      pwm_right = pwm_right - abs(balance_car_speed_offsets);
    }
    else
    {
      pwm_right = pwm_right + abs(balance_car_speed_offsets);
    }
  }
  else if(balance_car_speed_offsets < 0)
  {
    if(pwm_right > 0)
    {
      pwm_left = pwm_left - abs(balance_car_speed_offsets);
    }
    else
    {
      pwm_left = pwm_left + abs(balance_car_speed_offsets);
    }
  }

#ifdef DEBUG_INFO
  Serial.print("Relay: ");
  Serial.print(PID_angle.Setpoint);
  Serial.print(" AngX: ");
  Serial.print(angleX);
  Serial.print(" Output: ");
  Serial.print(PID_angle.Output);
  Serial.print(" dif: ");
  Serial.println(PID_angle.differential);
#endif

  pwm_left = constrain(pwm_left, -255, 255);
  pwm_right = constrain(pwm_right, -255, 255);

  Encoder_1.setMotorPwm(pwm_left);
  Encoder_2.setMotorPwm(pwm_right);
  Encoder_1.updateSpeed();
  Encoder_2.updateSpeed();
}

void isr_process_encoder1(void)
{
  if(digitalRead(Encoder_1.getPortB()) == 0)
  {
    Encoder_1.pulsePosMinus();
  }
  else
  {
    Encoder_1.pulsePosPlus();;
  }
}

void isr_process_encoder2(void)
{
  if(digitalRead(Encoder_2.getPortB()) == 0)
  {
    Encoder_2.pulsePosMinus();
  }
  else
  {
    Encoder_2.pulsePosPlus();
  }
}





