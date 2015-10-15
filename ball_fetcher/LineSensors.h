#ifndef LineSensors_H
#define LineSensors_H
// LineSensors
// This is a class to store the line sensors values instead of using the lenlib.
//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change
#include <Arduino.h>


class LineSensors {
  private:
    // Values from sensors
    int _LeftValue;
    int _MiddValue;
    int _RightValue;
    // Conected pnins.
    int _LeftPin;
    int _RightPin;
    int _MiddPin;
  public:
    LineSensors(int LeftPin, int MiddPin, int RightPin);
    void start();
    void readSens();
    float direction();
    String toString();
};
#endif
