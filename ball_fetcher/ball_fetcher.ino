#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <Servo.h>
//#include "LineSensors.h"
//#include "MotorDrive.h"
#include "tesingUnit.h"
//#include "pid.h"
#include "lineFolow.h"
#include "fetchbal.h"

//MotorDrive motors;

//lineFolow theLine;
fetcBal bollen;

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
  distSens_test_dist();
  //adArray_intArray();
  //LineSensors_test();
  // LineSensors_test_dir();            // 0k
  //LineSensors_test_raw();
  //Test_servo();                     // ok
  //test_extra_sensor();              // ok   1 på teipen och i luften
  bollen.start();
  //bollen.run();
  bollen.findMinOnBall();
  Serial.end();

}

void loop() {
  //Serial.println("Starting Proggram");
  //theLine.folowLine();
  //theLine.easyFolow();
  /*while (digitalRead(2) == 0){
    theLine.folowLinePid();
  }*/




}
