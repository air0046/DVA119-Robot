#include "LineSensors.h"
#include <Arduino.h>
// This is the functionality off the class difined in the .h file.
const float pi = 3.1415;  // yes Have some..

LineSensors::LineSensors(int LeftPin, int MiddPin, int RightPin){
  // Class construktor for LineSensors.
  // The variables in the declaration is the pin number to the diffrent sensors.
  _LeftPin = LeftPin;
  _MiddPin = MiddPin;
  _RightPin = RightPin;
}

void LineSensors::start(){
  // Self explaining.
  pinMode(_LeftPin, INPUT );
  pinMode(_MiddPin, INPUT );
  pinMode(_RightPin, INPUT );
}

void LineSensors::readSens(){
  // This is a part of LineSensors class that reead the line sensors to variable.

  // Read the sensor values:
  _LeftValue = digitalRead(_LeftPin);
  delay(20);
  _MiddValue= digitalRead(_MiddPin);
  delay(20);
  _RightValue= digitalRead(_RightPin);
}

float LineSensors::direction(){
  // this method whill atemt to return the direction that the line is in.
  // The method returns a value from -pi to +pi if and only if nott all sensors
  // have the same value in case 1 1 1 and 0 0 0 it returns a value out side the range.
  // where
  //        0 is strait a head
  //        pi/2   is left
  //        -pi/2  is Right
  //        pi     is basck ward.
  float ret = 0;

  // Forward 0 1 0
  if ((_LeftValue == 0) && (_MiddValue = 1) && (_RightValue = 0) ) { ret = 0;}
  // Left and Forward 1 1 0
  else if ((_LeftValue == 1) && (_MiddValue = 1) && (_RightValue = 0) ) { ret = pi/4;}
  // Only Left 1 0 0
  else if ((_LeftValue == 1) && (_MiddValue = 1) && (_RightValue = 0) ) {  ret = pi/2;}
  // Right and Forward. 0 1 1
  else if ((_LeftValue == 0) && (_MiddValue = 1) && (_RightValue = 1) ) { ret = (-1)*(pi/4); }
  // Only Right 0 0 1
  else if ((_LeftValue == 1) && (_MiddValue = 0) && (_RightValue = 1) ) { ret = (-1)*(pi/2); }
  // Al sensors 1 1 1 equals a value above pi
  else if ((_LeftValue == 1) && (_MiddValue = 1) && (_RightValue = 1) ) { ret = 10.0;}
  // Mandotory else sequense
  else { ret = -10.0; }



}

String LineSensors::toString(){
  // This functinon returns an string with all parameters of the object
  String temp = "";
  temp = "LineSens [ Left: ";
  temp += _LeftValue;
  temp += " Midel; ";
  temp += _MiddValue;
  temp += "Right: ";
  temp += _RightValue;
  temp += " ] ";

  return temp;
}
