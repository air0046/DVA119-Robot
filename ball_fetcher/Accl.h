#ifndef ACCLREAD_H
#define ACCLREAD_H

#include <Arduino.h>

class Accl {
  private:
    int _x = 0;
    int _y = 0;
    int _z = 0;

    int _pinX = 0;
    int _pinY = 0;
    int _pinZ = 0;
    int _accelScalle = 3;
  public:
    Accl(int pinX, int pinY, int pinZ);
    void reed();
    String toString();
    void Start();
};

#endif
