#include "boll.h"
#include <Arduino.h>
#include <Servo.h>




void Boll::readColor(){
  setColor(readSens());
}

float Boll::readSens(){
  const int it = 4;
  float color = 0;

  for (int i = 0; i < it; i++){
    //Serial.println("readColor");
    delay(20);
    color = analogRead(_pin);
  }
  color = (color)/it;
  //Serial.println(color);
  return color;
}


bool Boll::isThisBoll(){

    // (collor * minDiv) < readSens < (collor * maxDiv)
  if (((_color * _minDiv) < readSens()) && (readSens() < (_color * _maxDiv))){
    return true;
  } else {
    return false;
  }
}


float Boll::color(){
  return _color;
}

void Boll::setMinMaxDiv(float minDiv, float maxDiv){
  _minDiv = minDiv;
  _maxDiv = maxDiv;
}

void Boll::setColor(float color){
  _color = color;
  //Serial.println("collor");
}

String Boll::toString(){
  String temp = "";
  temp += " Boll color=";
  temp += color();
  return temp;

}
