#include "pid.h"

#include <Arduino.h>





void pid::calculate_pid()
{
    _P = _error;
    _I = _I + _previous_I;
    _D = _error - _previous_error;

    _PID_value = (_Kp*_P) + (_Ki*_I) + (_Kd*_D);

    _previous_I = _I;
    _previous_error = _error;
}

void pid::motor_control()
{
    // Calculating the effective motor speed:
    int left_motor_speed = _initial_motor_speed - _PID_value;
    int right_motor_speed = _initial_motor_speed + _PID_value;

    // The motor speed should not exceed the max PWM value
    constrain(left_motor_speed,0,255);
    constrain(right_motor_speed,0,255);

    if(left_motor_speed < _lessThan){
        //Motors.runMotor(2,BACKWARD,initial_motor_speed*2.2); // Left motor Speed
        //Motors.runMotor(1,FORWARD,right_motor_speed); //Right motor Speed
        _leftMotor = left_motor_speed;
        _rightMotor = _initial_motor_speed * _motoMult;
    } else if(right_motor_speed < _lessThan){
      //Motors.runMotor(1,BACKWARD,initial_motor_speed*2.2); // Left motor Speed
      //Motors.runMotor(2,FORWARD,right_motor_speed); //Right motor Speed
      _leftMotor = _initial_motor_speed * _motoMult;
      _rightMotor = right_motor_speed;
    } else {
    //Motors.runMotor(2,FORWARD,left_motor_speed); // Left motor Speed
    //Motors.runMotor(1,FORWARD,right_motor_speed); //Right motor Speed
    _leftMotor = left_motor_speed;
    _rightMotor =  right_motor_speed;
  }
}
void pid::run(){

  //read_sensor_values();
  calculate_pid();
  motor_control();

  delay(_loopDelay);
  Serial.println(toString());

}

String pid::toString(){
    String text = "";
    text = "LinePid _leftMotor=";
    text += _leftMotor;
    text += " _rightMotor=";
    text += _rightMotor;
    text += " _error=";
    text += _error;
    text += " ";
    //text += _line.toString();

    return text;
}
void pid::setError(int error){ _error = error;}
int pid::getleftMotor(){ return _leftMotor;}
int pid::getrightMotor(){ return _rightMotor; }
