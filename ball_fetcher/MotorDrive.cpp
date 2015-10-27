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
  _inied = true;
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
  left = abs(left);                 // absulute value in to speed vaiabels.
  right = abs(right);
  /*if (left > _maxSpeed){
    left = _maxSpeed;
  } else if (left < _minSpeed && left > 4){
    left = _minSpeed;
  }
  if (right > _maxSpeed){
    right = _maxSpeed;
  } else if (right < _minSpeed && right > 4){
    right = _minSpeed;
  }*/
  _LeftMotorSpeed= left;
  _RightMotorSpeed= right * 0.75;
  //Serial.println("End setSpeed()");
  UpdateSpeed();
  //Serial.println("End UpdateSpeed()");
}

void MotorDrive::UpdateSpeed(/* arguments */) {
  // Magic...
  //Serial.println("UpdateSpeed");
  LeftMotor->run(_LeftMotorDirection);
  LeftMotor->setSpeed(_LeftMotorSpeed);
  RightMotor->run(_RightMotorDirection);
  RightMotor->setSpeed(_RightMotorSpeed);
  //Serial.println("End UpdateSpeed");
}

void MotorDrive::TurnRobot(float target_grad){
  // Gradualy going to start writing code here the folowing weaks.
  // This whill be a wrapper of setSpeed functinon.
  //Serial.println(target_grad);
  int speed = 100;
  int delaydeg = 12;
  if (target_grad > 1.0){
    Serial.println("Turn +");
    setSpeed(speed, (-1)*speed);
  } else if (target_grad < -1.0){
    Serial.println("Turn -");
    setSpeed((-1)*speed, speed);
  } else {
    setSpeed(0, 0);
    target_grad = 0,0;
  }
  delay((int)abs(target_grad) * delaydeg );  // 10ms per grad
  stopAl();
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
  MyVal += " ] inited=";
  if (_inied){ MyVal += " yes ";}else{ MyVal += " no ";}
  return MyVal;
}
