#ifndef Boll_H
#define Boll_H
#include <Arduino.h>
#include "LineSensors.h"
#include "MotorDrive.h"
//#include "boll.h"
#include <Servo.h>

class lineFolow{
private:
  MotorDrive _motors;
  LineSensors _line;
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
  String toString();
  void start();
  bool onLine();
  void easyFolow();
  void readLine();
  void UpdateSpeed();

};



#endif
