#include "distSens.h"
#include <math.h>

void distSens::readDistance(){
  const int it = 4;
  int dist = 0;

  for (int i = 0; i < it; i++){
    delay(20);
    dist = analogRead(_pin);
  }

  dist=(dist)/it;
  _distance = 629.779+(-126.442)*log(dist);

}
bool distSens::inRange(float min, float max){

}

float distSens::getDistance(){
  readDistance();
  return _distance;
}

String distSens::toString(){
  String st = "";
  st = "DistSens d=";
  st += _distance;
  st += " mm";
  return st;

}
