#ifndef LINEFOLOW_H
#define LINEFOLOW_H
#include <Arduino.h>
#include "LineSensors.h"
#include "MotorDrive.h"
//#include "boll.h"
#include <Servo.h>
#include "pid.h"

class lineFolow{
private:
  MotorDrive _motors;
  LineSensors _line;
  pid _pid;
  int _left = 0;
  int _right = 0;
  int _speed = 0;
  int _minSpeed = 70;
  int _forWardSpeed = 0;
  int _coectionSpeed = 8;
  int _sMultip = 10;
  int _decA = 18;
  int _leftMotor = 0;
  int _rightMotor = 0;
public:
  void folowLine();
  void folowLinePid();
  String toString();
  String motorsToStr();
  void start();
  bool onLine();
  void easyFolow();
  void readLine();
  void UpdateSpeed();
  void pidErrorBacic();
  void setSpeed(int left, int right);


};



#endif
