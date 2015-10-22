#ifndef Boll_H
#define Boll_H

#include <Arduino.h>
//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change


// Boll klassen för 



class Boll {
private:
  int _pin = 1;
  float _color = 0.0;
  float _maxDiv = 1.05;
  float _minDiv = 0.95;
public:
  void readColor();
  float readSens();
  bool isThisBoll();
  String toString();
  float color();
  void setMinMaxDiv(float minDiv, float maxDiv);
  void setColor(float color);
};

#endif
