#ifndef LineSensors_H
#define LineSensors_H
// LineSensors
// This is a class to store the line sensors values instead of using the lenlib.
//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change
#include <Arduino.h>
#include "adArray.h"


class LineSensors {
  private:
    // Values from sensors
    intArray _leftArray;
    intArray _midArray;
    intArray _rightArray;
    // Conected pnins.  (7, 6, 5);
    int _LeftPin = 7;
    int _RightPin = 6;
    int _MiddPin = 5;

  public:
    //LineSensors(int LeftPin, int MiddPin, int RightPin);
    void start();
    void readSens();
    int direction();
    String toString();
};
#endif
