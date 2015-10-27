#ifndef FECHBAL_H
#define FECHBAL_H

#include <Arduino.h>
#include "LineSensors.h"
#include "MotorDrive.h"
#include "boll.h"
#include "lineFolow.h"
#include "adArray.h"
#include <Servo.h>
#include "fetchbal.h"
#include "distSens.h"

class fetcBal{
private:
  Boll _Boll[3];                       // tre bollar
  Servo _fork;                         // Gaffel
  lineFolow _lineFolow;
  intArray _stopper;
  distSens _distance;
  int _laniSpeed = 180;
  bool _stop;
  int _stopperPin = 13;
  int _maxDist = 400;                  // distance to ball can onyl be max ...
  int _picDist = 60;
  int _operationalPos;                 // vart vi borde vara i programmet
  int _forkPin = 9;
  int _angle;                          // Vinkel på Gaffel.
  int _minFork = 95;
  float _reedBall = 197.0;
  float _blueBall = 160.0;
  float _slected = _reedBall;
public:
  void start();
  void findMinOnBall();
  void setforkAngle(int angle);
  void riseFork();
  void lowerFork();
  void run();
  String toString();
  bool readStopper();
  void folowLine();
  void takeBal();
  void gotoLain(int lane);
  void onLain();

};


#endif
