#ifndef TESTUNIT
#define TESTUNIT
#include "tesingUnit.h"
#include "MotorDrive.h"
#include "boll.h"
#include "distSens.h"
#include "adArray.h"
#include "LineSensors.h"
#include <Servo.h>

void motorTest_back_and_forward(){
  while (buttonA()){
    MotorDrive motors;
    motors.start();
    motors.setSpeed(20 , -40);            // Forward
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
}

void motorTest_forward_for_sec(int speed, int sec) {
  /* code */
  while (buttonA()){
    MotorDrive motors;
    motors.start();
    motors.setSpeed(speed, speed);            // Forward
    Serial.println(motors.toString());
    delay(sec * 1000);                           // for sec
    motors.setSpeed(0,0);                 // Stop
  }
}

void motorTest_turn_for_sec(int speed, int sec) {
  while (buttonA()){
    MotorDrive motors;
    motors.start();
    motors.setSpeed(speed, (-1) * speed); // Turn arud
    Serial.println(motors.toString());
    delay(sec * 1000);                           // for sec
    motors.setSpeed(0,0);                 // Stop
  }
}

void motorTest_Turning_Robot(){
  MotorDrive motors;

  motors.start();
  while (buttonA()){

    delay(8000);
    Serial.println("Turn 90");
    motors.TurnRobot(90.0);
    Serial.println(motors.toString());
    delay(4000);
    Serial.println("Turn -90");
    motors.TurnRobot(-90.0);
    Serial.println(motors.toString());
    delay(4000);
    Serial.println("Turn 180");
    motors.TurnRobot(180.0);
    Serial.println(motors.toString());
    delay(4000);
    motors.TurnRobot(-180.0);
    Serial.println(motors.toString());
    Serial.println("End");
    delay(4000);
    Serial.println("Turn -360");
    motors.TurnRobot(-360.0);
    Serial.println(motors.toString());
    motors.stopAl();
  }
}

void ballTest_readColor(){
  Boll boll1;
  while (buttonA()){
    Serial.println("ballTest_readColor Starting");
    boll1.readColor();
    Serial.println(boll1.toString());
    delay(2000);
  }
}

void ballTest_isThis(float testValue){
  Boll boll1;
  Serial.println("Starting ballTest_isThis");
  //boll1.setColor(145.0);     // Blå
  while (true) {
    //Serial.println("While");
    boll1.setColor(160.0);     // Blå
    if(boll1.isThisBoll()){
      Serial.println("Blå");
    }
    boll1.setColor(197.0);     // röd
    if(boll1.isThisBoll()){
      Serial.println("Röd");
    }
    delay(200);
  }

}
void distSens_test_dist(){
  distSens sens;
  while (buttonA) {
    sens.readDistance();
    Serial.println(sens.toString());
  }
}

void ballTest_tellBall(){
  while (buttonA) {
    /* code */

  }
}

void adArray_intArray(){
  intArray testInt;
  delay(1000);
  Serial.println(testInt.toString());
  int i = 1;
  while (buttonA) {
    /* code */

    testInt.push(10 * ( i ) );
    Serial.println(testInt.toString());
    i ++;
    delay(2000);
  }
}

void LineSensors_test_raw(){
  LineSensors line;
  while (buttonA) {
    /* code */
    line.readSens();
    Serial.println(line.rawArray());
    delay(500);
  }
}

void LineSensors_test(){
  LineSensors line;
  while (buttonA) {
    /* code */
    line.readSens();
    Serial.println(line.toString());
    delay(50);
  }
}

void LineSensors_test_dir(){
  LineSensors line;
  while (buttonA) {
    /* code */
    line.readSens();
    Serial.print("dir=");
    Serial.print(line.direction());
    Serial.print(" speed");
    Serial.println(line.speed());
    delay(500);
  }
}

bool buttonA (){
  return true;
}

void Test_servo(){
  Servo serv;
  int angle = 0;
  serv.attach(9);
  while(true){
    angle = random(0, 255);
    Serial.println(angle);
    serv.write(angle);
    delay(4000);

  }
}

void test_extra_sensor(){
  while ( true ) {
    /* code */
    Serial.println(digitalRead(13));
  }

}

#endif
