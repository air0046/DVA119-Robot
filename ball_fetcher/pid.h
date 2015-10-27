//#ifndef LINEFOLOWPID_H
#define LINEFOLOWPID_H
#include <Arduino.h>
#include "LineSensors.h"
#include "MotorDrive.h"
//#include "boll.h"
#include <Servo.h>

class pid{
private:

  float _motoMult = 2.2;
  int _leftMotor = 0;
  int _rightMotor = 0;
  // Part of pid do not mess.
  int _loopDelay = 0;
  float _Kp=16,_Ki=0,_Kd=15;//15
  float _error=0, _P=0, _I=0, _D=0, _PID_value=0;
  float _previous_error=0, _previous_I=0;
  //int sensor[3]={0, 0, 0};
  int _initial_motor_speed=150; //50
  int _lessThan = 20;
  void read_sensor_values(void);
  void calculate_pid(void);
  void motor_control(void);
  void reeadLine();
public:
  void run();
  void runLoop();
  String toString();
  void start();
  void setError(int error);
  int getleftMotor();
  int getrightMotor();
};
