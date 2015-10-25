#include "adArray.h"
#include <Arduino.h>

void intArray::push(int value){
  for (int i = 0; i < _arraySize ; i++){
      _array[i] = _array[i + 1];
  }
  _array[_arraySize-1] = value;
}

int intArray::sum(){
  int tot = 0;
  for (int i = 0; i < _arraySize; i++){
    tot += _array[i];
  }
  return tot;
}
int intArray::avrage(){
  return ((sum())/_arraySize);
}

String intArray::toString(){
  String temp = "";
  temp = "intArray [";
  for (int i = 0; i < _arraySize; i++){
    temp += _array[i];
    temp += " ";
  }
  temp += "] Sum=";
  temp += sum();
  return temp;
}

String intArray::raw(){
  String temp = "";
  temp = "intArray [";
  for (int i = 0; i < _arraySize; i++){
    temp += _array[i];
    temp += ",";
  }
  return temp;
}
