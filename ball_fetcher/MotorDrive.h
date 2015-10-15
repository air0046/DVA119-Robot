#ifndef MotorDrive_H
#define MotorDrive_H

//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>


class MotorDrive{
  private:
    Adafruit_MotorShield AFMS = Adafruit_MotorShield();
  	Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
  	Adafruit_DCMotor *RightMotor = AFMS.getMotor(2);
    void UpdateSpeed();
    // Induvidual motor speed.
    int _LeftMotorSpeed;
    int _RightMotorSpeed;
    int _LeftMotorDirection;
    int _RightMotorDirection;

  public:
    void start();
    void setSpeed(int left, int right);
    void stopAl();
    void TurnRobot(float angle, int speed);          // This one is defined from -pi to pi
    String toString();
};

#endif
