// TODO:
//
//    0.x*speedVal when steering?
//
//    If there are problems, add a value to turnDelay

// Include libraries:
#include <Adafruit_MotorShield.h>
#include <lenlib.h>
#include <Wire.h>
#include <Servo.h>

// Delay value called after motors been running:
int delVal = 0;

// Initialize variables for storing the sensor values
int leftSensor = 0;
int middleSensor = 0;
int rightSensor = 0;

//int turnSpeed = 60;
int turnDelay = 0;
// int containing last action: 0 starting value, 1 fwd, 2 steerLeft, 3 steerRight
int lastAction = 0;

// // Variable that works as a factor regulating the turn speed. i.e 1.8*spedVal = turnspeed
// float turnMulti = 1.8;
// float turnDivi = 0.2;
// This is the speed value, (0-255)
int speedVal = 90; // 100 seem to be a good value

// // Variable that works as a factor regulating the turn speed. i.e 1.8*spedVal = turnspeed
// float turnMulti = 1.8;
// // This is the speed value, (0-255)
// int speedVal = 100; // 100 seem to be a good value

int loopDelay = 0;

myMotors Motors;   // Create Motors object
mySensors Sensors; // Create Sensors object

void setup() {
  Serial.begin(9600); // set up Serial connection at 9600 bps

  Motors.beginMotors();   // Start motors
  Sensors.beginSensors(); // Start sensors

  delay(2000);
}

void loop() {

  readSensors();

  // if the right sensor is the only sensor that have the value 1, the bot need to compensate by turning right
  if((leftSensor == 0 && middleSensor == 0 && rightSensor == 1) || (leftSensor == 0 && middleSensor == 1 && rightSensor == 1))
  {
    steerRight();
    Serial.print("SteerLeft");
    lastAction = 2;
  }
  // if the left sensor is the only sensor that have the value 1, the bot need to compensate by turning left
  else if((leftSensor == 1 && middleSensor == 0 && rightSensor == 0) || (leftSensor == 1 && middleSensor == 1 && rightSensor == 0))
  {
    steerLeft();
    Serial.print("SteerRight");
    lastAction = 3;
  }
  // if sensor value = 1, then the sensor is on track
  if((leftSensor == 0 && middleSensor == 1 && rightSensor == 0) || (leftSensor == 1 && middleSensor == 1 && rightSensor == 1))
  {
    fwd();
    Serial.print("Forward");
    lastAction = 1;
  }
  else
  {
    // if(lastAction == 1){fwd();Serial.print("Forward**");}
    // else if(lastAction == 2){steerLeft();Serial.print("SteerLeft**");}
    // else if(lastAction == 3){steerRight();Serial.print("SteerRight**");}
    // else {stop();Serial.println("Stop");}
  }
  delay(loopDelay);
  Serial.println();
}

void readSensors(){
  // Read the sensor values:
  leftSensor = Sensors.readReflect0();
  delay(20);
  middleSensor = Sensors.readReflect1();
  delay(20);
  rightSensor = Sensors.readReflect2();
  delay(20);
  // Print status of sensors:
  Serial.print("Reflect 0: ");Serial.print(leftSensor);
  Serial.print("\tReflect 1: ");Serial.print(middleSensor);
  Serial.print("\tReflect 2: ");Serial.print(rightSensor);
  Serial.print("\tMotor speed: ");Serial.print(speedVal);
  Serial.print("\tAction: ");
}

//
// Motor functions
//
void fwd(){
  Motors.runMotor(1,FORWARD,speedVal);
  Motors.runMotor(2,FORWARD,speedVal);
  delay(delVal);
}
void rev(){
  Motors.runMotor(1,BACKWARD,speedVal);
  Motors.runMotor(2,BACKWARD,speedVal);
  delay(delVal);
}
void stop(){
  Motors.runMotor(1,FORWARD,0);
  Motors.runMotor(2,FORWARD,0);
  delay(delVal);
}
// void steerRight(){
//   Motors.runMotor(1,FORWARD,speedVal*turnMulti);
//   Motors.runMotor(2,FORWARD,speedVal*turnDivi);
//   delay(delVal);
// }
// void steerLeft(){
//   Motors.runMotor(1,FORWARD,speedVal*turnDivi);
//   Motors.runMotor(2,FORWARD,speedVal*turnMulti);
//   delay(delVal);
// }
void steerRight(){
  Motors.runMotor(1,FORWARD,speedVal);
  Motors.runMotor(2,FORWARD,0);
  delay(delVal);
}
void steerLeft(){
  Motors.runMotor(1,FORWARD,0);
  Motors.runMotor(2,FORWARD,speedVal);
  delay(delVal);
}

void turnLeft(){  // Turn 90 degree LEFT
  Motors.runMotor(1,BACKWARD,speedVal);
  Motors.runMotor(2,FORWARD,speedVal);
  delay(turnDelay);
  Motors.runMotor(1,FORWARD,0);
  Motors.runMotor(2,FORWARD,0);
}
void turnRight(){   // Turn 90 degrees RIGHT
  Motors.runMotor(1,FORWARD,speedVal);
  Motors.runMotor(2,BACKWARD,speedVal);
  delay(turnDelay);
  Motors.runMotor(1,FORWARD,0);
  Motors.runMotor(2,FORWARD,0);
}
