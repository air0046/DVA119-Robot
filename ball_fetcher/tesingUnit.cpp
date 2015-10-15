#ifndef TESTUNIT
#define TESTUNIT
#include "tesingUnit.h"
#include "MotorDrive.h"

void motorTest_back_and_forward(){
  MotorDrive motors;
  motors.start(); 
  motors.setSpeed(120, 120);            // Forward
  Serial.print("Forward");
  Serial.println(motors.toString());
  delay(2000);
  motors.stopAl();
  Serial.print("Stopp");
  Serial.println(motors.toString());
  delay(2000);
  motors.setSpeed(-120, 120);
  Serial.print("Left");
  Serial.println(motors.toString());
  delay(2000);
  motors.stopAl();
  Serial.print("Stop");
  Serial.println(motors.toString());
  delay(2000);
  motors.setSpeed(120, -120);
  Serial.print("Right");
  Serial.println(motors.toString());
  delay(2000);
  motors.stopAl();
  Serial.print("Stop");
  Serial.println(motors.toString());
  delay(2000);
  motors.setSpeed(-120, -120);
  Serial.print("Backward");
  Serial.println(motors.toString());
  delay(2000);
  motors.stopAl();
  Serial.print("Stop");
  Serial.println(motors.toString());
  delay(2000);
}

void motorTest_forward_for_sec(int speed, int sec) {
  /* code */
  MotorDrive motors;                    //MtorOBJ
  motors.start();
  motors.setSpeed(speed, speed);        // Go forward
  Serial.println(motors.toString());
  delay(sec);                           // for sec
  motors.setSpeed(0,0);                 // Stop
}

void motorTest_turn_for_sec(int speed, int sec) {
  /* code */
  MotorDrive motors;
  motors.start();
  motors.setSpeed(speed, (-1) * speed); // Turn arud
  Serial.println(motors.toString());
  delay(sec);                           // for sec
  motors.setSpeed(0,0);                 // Stop
}

#endif
