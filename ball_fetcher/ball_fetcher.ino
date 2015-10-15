#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <Servo.h>
#include "LineSensors.h"
#include "MotorDrive.h"



const float pi = 3.1415;

LineSensors SensLine(7,6,5);        // Create an object of SensLine with the pinns 7 6 5
MotorDrive motors;                  // Create a object of MotorDrive

void setup() {

  Serial.begin(9600);
  motors.start();                   // Start motors.
  SensLine.start();                 // Start LineSensors.
}

void loop() {
  SensLine.readSens();
  delay(1500);
}










void motorTest(){
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
