#ifndef ACCLREAD
#include "Accl.h"
#include <stdarg.h>
#include <Arduino.h>

Accl::Accl(int pinX, int pinY, int pinZ){
  _pinX = pinX;
  _pinY = pinY;
  _pinZ = pinZ;
}

void Accl::Start(){
  pinMode(_x, INPUT);
  pinMode(_y, INPUT);
  pinMode(_z, INPUT);

}

void Accl::reed(){
    int rawX, rawY, rawZ = 0;
    // Läs in varje axel.
    rawX = analogRead(_pinX);
    rawY = analogRead(_pinY);
    rawZ = analogRead(_pinZ);

    // Skala om de annaloga signalerna.
    _x = map(rawX, 0, 675, (-1) * _accelScalle, _accelScalle);
    _y = map(rawY, 0, 675, (-1) * _accelScalle, _accelScalle);
    _z = map(rawZ, 0, 675, (-1) * _accelScalle, _accelScalle);
  }

String Accl::toString(){
    // This functinon returns an string with all parameters of the object
    String temp = "";
    temp = "Accel [ x= ";
    temp += _x;
    temp += " Y= ";
    temp += _y;
    temp += " Z= ";
    temp += _z;
    temp += " ]";
    return temp;
}

  #undef ACCLREAD
  #endif
