#ifndef FECHBAL_H
#define FECHBAL_H

#include <Arduino.h>
#include "LineSensors.h"
#include "MotorDrive.h"
#include "boll.h"
#include <Servo.h>

class fetcBal{
private:
  LineSensors _SensLine; //(7, 6, 5);        // Create an object of SensLine with the pinns 7 6 5
  MotorDrive _motors;                  // Motorer
  Boll _Boll[3];                       // tre bollar
  Servo _fork;                         // Gaffel
  int _operationalPos;                 // vart vi borde vara i programmet
  int _angle;                          // Vinkel på Gaffel.
  float _reedBall = 197.0;
  float _blueBall = 160.0;
public:
  fetcBal();
  void setforkAngle(int angle);
  void run();
  String toString();
};


#endif
