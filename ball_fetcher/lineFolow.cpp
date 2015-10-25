#include "lineFolow.h"

#include <Arduino.h>


void lineFolow::folowLine(){
  _line.readSens();
  // [0.3] av tapen
  // [3. 10] på tapen

  //int leftDir = _line.direction();
  //int rightDir = _line.direction() ;
  //_left = (leftDir + _coectionSpeed ) * _line.speed() * (-1) + _minSpeed;
  //_right = (rightDir + _coectionSpeed ) * _line.speed() * (-1)  + _minSpeed;
  if (onLine()){
    //_forWardSpeed = (( _line.speed()) * _sMultip);
    //_left = _forWardSpeed + (_decA - _line.left()) * _coectionSpeed;
    //_right = _forWardSpeed + (_decA - _line.right())  * _coectionSpeed;
    //_left = _left;
    //_right = _right  * 3 + 10;
    //Serial.print("r= ");
    //Serial.print(left);
    //Serial.print(" l= ");
    //Serial.println(right);


  } else {
    //_right = -50;
    //_left = -50;
    //Serial.println(" else");
  }
  Serial.println(toString());
  //Serial.println(_line.rawArray());
  _motors.setSpeed(_left, _right);
  //Serial.println(_motors.toString());
  //Serial.println(toString());
}

void lineFolow::readLine(){
  _line.readSens();
  _left = _line.left();
  _right = _line.right();
  _speed = _line.speed();
}

void lineFolow::UpdateSpeed(){
  _motors.setSpeed(_leftMotor, _rightMotor);
}

void lineFolow::easyFolow(){
  readLine();
  int trip = 5;
  int tot = _left + _speed + _right ;
  if (true){
    if (_left < 2 && _speed < 2 && _right < 2){
      _leftMotor = -70;
      _rightMotor = -70;
      UpdateSpeed();
      while (tot < trip){
        readLine();
        tot = _left + _speed + _right ;
      }
      if (_left > trip && _speed > trip && _right < trip){
          //Serial.println("if case 2");
          _leftMotor = -150;
          _rightMotor = 150;
      } else   if (_left < trip && _speed > trip && _right > trip){
         //Serial.println("if case 3");
         _leftMotor = 150;
         _rightMotor = -150;
      }
      UpdateSpeed();


    } else if (_left < trip && _speed > trip && _right < trip){
      //Serial.println("if case 1");
      _leftMotor = 150;
      _rightMotor = 150;
    } else   if (_left > trip && _speed > trip && _right < trip){
        //Serial.println("if case 2");
        _leftMotor = 150;
        _rightMotor = -150;
    } else   if (_left < trip && _speed > trip && _right > trip){
       //Serial.println("if case 3");
       _leftMotor = -150;
       _rightMotor = 150;
    } else   if (_left < trip && _speed < trip && _right < trip){
      //Serial.println("if case 4");
      _leftMotor = 70;
      _rightMotor = 80;
    }
  }
  UpdateSpeed();
  Serial.println(toString());
  //Serial.println(_line.rawArray());
}

void lineFolow::start(){
  _motors.start();
  Serial.println("Start lineFolow");
}

bool lineFolow::onLine(){
  //int tot = _line.left() + _line.right() + _line.speed();
  //int medium = tot / 3;
  if (_line.left() > 3 || _line.speed() > 3 || _line.right() > 3 ){
    return true;
  } else {
    return false;
  }
}

String lineFolow::toString(){
  String temp = "";
  temp = "lineFolow _forWardSpeed=";
  temp += _forWardSpeed;
  temp += " _left=";
  temp += _left;
  temp += " _right=";
  temp += _right;
  return temp;
}
