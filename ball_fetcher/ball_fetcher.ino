#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <Servo.h>
#include "LineSensors.h"
#include "MotorDrive.h"
#include "tesingUnit.h"
#include "lineFolow.h"

//MotorDrive motors;
lineFolow theLine;

void setup() {

  //motors.stopAl();
  Serial.begin(9600);
  delay(1000);
  Serial.println("Welcome!");
  // Unit tests.
  //motorTest_back_and_forward();
  //motorTest_Turning_Robot();       //  OK
  //ballTest_readColor();               //  OK
  // ballTest_isThis(160.2);           // OK
  //distSens_test_dist();
  //adArray_intArray();
  //LineSensors_test();
  // LineSensors_test_dir();            // 0k
  //LineSensors_test_raw();
  theLine.start();
}

void loop() {
  //Serial.println("Starting Proggram");
  //theLine.folowLine();
  theLine.easyFolow();


}
