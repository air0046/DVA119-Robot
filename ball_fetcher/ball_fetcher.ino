#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include <Servo.h>
#include "LineSensors.h"
#include "MotorDrive.h"
#include "tesingUnit.h"



const float pi = 3.1415;

LineSensors SensLine(7,6,5);        // Create an object of SensLine with the pinns 7 6 5
//MotorDrive motors;                  // Create a object of MotorDrive

void setup() {

  Serial.begin(9600);
//  motors.start();                   // Start motors.
  SensLine.start();                 // Start LineSensors.
}

void loop() {
  SensLine.readSens();
  for(int i = 1; i > 4; i++){
    Serial.println("Starting motorTest_forward_for_sec in 5sec");
    delay(5000);
    motorTest_forward_for_sec(50*i, 10);
    Serial.println("Stopped motorTest_forward_for_sec in 5sec");
    delay(1000);
  }
  for(int i=1; i > 4; i++){
    Serial.println("Starting motorTest_turn_for_sec in 5sec with turn time set to 2sec");
    delay(5000);
    motorTest_forward_for_sec(50*i, 2);
    Serial.println("Stopped motorTest_forward_for_sec");
    delay(1000);
  }

}
