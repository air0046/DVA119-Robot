#ifndef DISTSENS_H
#define DISTSENS_H

#include <Arduino.h>
//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change

class distSens {
private:
  float _distance = 0;
  int _pin = 0;
public:
  void readDistance();
  bool inRange(float min, float max);
  float getDistance();
  float distMap(float x, float in_min, float in_max, float out_min, float out_max);
  String toString();
};

#endif
