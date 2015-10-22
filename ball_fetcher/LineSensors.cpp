#include "LineSensors.h"
#include <Arduino.h>
// This is the functionality off the class difined in the .h file.
const float pi = 3.1415;  // yes Have some..

void LineSensors::start(){
  // Self explaining.
  pinMode(_LeftPin, INPUT );
  pinMode(_MiddPin, INPUT );
  pinMode(_RightPin, INPUT );
}

void LineSensors::readSens(){
  // This is a part of LineSensors class that reead the line sensors to variable.

  // Read the sensor values:
  _leftArray.push(digitalRead(_LeftPin));
  delay(20);
  _midArray.push(digitalRead(_MiddPin));
  delay(20);
  _rightArray.push(digitalRead(_RightPin));
}

int LineSensors::direction(){
  // this method whill atemt to return the direction that the line is in.
  // The method returns a value from -pi to +pi if and only if nott all sensors
  // have the same value in case 1 1 1 and 0 0 0 it returns a value out side the range.
  // where


}

String LineSensors::toString(){
  // This functinon returns an string with all parameters of the object
  String temp = "";
  temp = "LineSens [ Left: ";
  temp += _leftArray.sum();
  temp += " Midel; ";
  temp += _midArray.sum();
  temp += "Right: ";
  temp += _rightArray.sum();
  temp += " ] direction= ";

  return temp;
}
