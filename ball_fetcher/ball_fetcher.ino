#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <Servo.h>
#include "LineSensors.h"
#include "MotorDrive.h"
#include "tesingUnit.h"

void setup() {

  Serial.begin(9600);
  delay(400);
  // Unit tests.
  // motorTest_Turning_Robot();       //  OK
  //ballTest_readColor();               //  OK
   ballTest_isThis(160.2);           // OK
  //distSens_test_dist();
}

void loop() {
  Serial.println("Starting Proggram");


}
