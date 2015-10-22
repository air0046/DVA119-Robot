#ifndef ADARRAY_H
#define ADARRAY_H

#include <Arduino.h>

class intArray {
private:
  int _arraySize = 10;
  int _array[10];

public:
  void push(int value);
  int sum();
  int avrage();
};

#endif
