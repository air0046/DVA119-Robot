#include "MotorDrive.h"
#include "Arduino.h"
#include <Adafruit_MotorShield.h>

// LineSensors
// This is the functionality off the class difined in the .h file.
#include "ardprintf.h"
const float pi = 3.1415;

void MotorDrive::start(){
  // functinon to start the motor sheald and sett initial parameters to 0.
  AFMS.begin();
  _LeftMotorSpeed = 0;
  _LeftMotorDirection = 0;
  _RightMotorSpeed = 0;
  _RightMotorDirection = 0;
  UpdateSpeed();        // Private functinon to setTeSpeed.
}

void MotorDrive::stopAl(/* arguments */) {
  // This one is probably not nezzesery but its practical.
  _LeftMotorSpeed = 0;
  _RightMotorSpeed = 0;
  UpdateSpeed();
}

void MotorDrive::setSpeed(int left, int right){
  // as the name sugiest this is my implimintation of lenlibs runnmotor.
  // The functinon takes positeve an negative numbers and based on that it runns the motors ether forward or Backward.
  if (left < 0){
    _LeftMotorDirection = 2;        // Backward
  } else {
    _LeftMotorDirection = 1;        // Forward
  }
  if (right < 0){
    _RightMotorDirection = 2;       // Backward
  } else {
    _RightMotorDirection = 1;       // Forward
  }
  _LeftMotorSpeed=abs(left);        // absulute value in to speed vaiabels.
  _RightMotorSpeed=abs(right);
  UpdateSpeed();
}

void MotorDrive::UpdateSpeed(/* arguments */) {
  // Magic...
  LeftMotor->run(_LeftMotorDirection);
  LeftMotor->setSpeed(_LeftMotorSpeed);
  RightMotor->run(_RightMotorDirection);
  RightMotor->setSpeed(_RightMotorSpeed);
}

void MotorDrive::TurnRobot(float angle, int speed){
// Gradualy going to start writing code here the folowing weaks.
// This whill be a wrapper of setSpeed functinon.
}

String MotorDrive::toString(){
  String MyVal = "";
  MyVal = "[ LMS: ";
  MyVal += _LeftMotorSpeed;
  MyVal += " LMD: ";
  MyVal += _LeftMotorDirection;
  MyVal += " ] [ RMS: ";
  MyVal += _RightMotorSpeed;
  MyVal += " RMD: ";
  MyVal += _RightMotorDirection;
  MyVal += " ] \n";
  return MyVal;
}
