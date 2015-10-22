#include "distSens.h"
#include <math.h>

void distSens::readDistance(){
  const int it = 4;
  int dist = 0;

  for (int i = 0; i < it; i++){
    //Serial.println("readDistance");
    delay(20);
    //dist = map(analogRead(_pin), 1, 133, 100 , 1);
    // inget Framför dist = 1
    // Precis framför dist = 1300
    dist = analogRead(_pin);
  }

  dist=(dist)/it;
  _distance = 629.779+(-126.442)*log(dist);

}
bool distSens::inRange(float min, float max){

}

float distSens::getDistance(){
  return _distance;
}

String distSens::toString(){
  String st = "";
  st = "DistSens d=";
  st += _distance;
  st += " mm";
  return st;

}
