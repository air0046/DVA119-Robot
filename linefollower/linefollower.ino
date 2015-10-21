// TODO:
//
//    If there are problems, add a value to turnDelay

// Include libraries:
#include <Adafruit_MotorShield.h>
#include <lenlib.h>
#include <Wire.h>
#include <Servo.h>

// Delay value called after motors been running:
int delVal = 100;

// Initialize variables for storing the sensor values
int leftSensor = 0;
int middleSensor = 0;
int rightSensor = 0;

// This is the speed value, (0-255)
int speedVal = 70; // 60 seem to be a good value
//int turnSpeed = 60;
int turnDelay = 0;
// int containing last action: 0 starting value, 1 fwd, 2 steerLeft, 3 steerRight
int lastAction = 0;

// Variable that works as a factor regulating the turn speed. i.e 1.8*spedVal = turnspeed
float turnMulti = 1.7;

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

  // if sensor value = 1, then the sensor is on track
  if((leftSensor == 0 && middleSensor == 1 && rightSensor == 0))
  {
    fwd();
    Serial.println("Forward");
    lastAction = 1;
  }
  // if the right sensor is the only sensor that have the value 1, the bot need to compensate by turning right
  else if((leftSensor == 0 && middleSensor == 0 && rightSensor == 1))
  {
    steerLeft();
    Serial.println("SteerLeft");
    lastAction = 2;
  }
  // if the left sensor is the only sensor that have the value 1, the bot need to compensate by turning left
  else if((leftSensor == 1 && middleSensor == 0 && rightSensor == 0))
  {
    steerRight();
    Serial.println("SteerRight");
    lastAction = 3;
  }
  else
  {
    if(lastAction == 1){fwd();Serial.println("Forward**");}
    else if(lastAction == 2){steerLeft();Serial.println("SteerLeft**");}
    else if(lastAction == 3){steerRight();Serial.println("SteerRight**");}
    else {stop();Serial.println("Stop");}
  }
  delay(loopDelay);
}

void readSensors(){
  // Read the sensor values:
  leftSensor = Sensors.readReflect0();
  delay(20);
  middleSensor = Sensors.readReflect1();
  delay(20);
  rightSensor = Sensors.readReflect2();

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
}
void rev(){
  Motors.runMotor(1,BACKWARD,speedVal);
  Motors.runMotor(2,BACKWARD,speedVal);
}
void stop(){
  Motors.runMotor(1,FORWARD,0);
  Motors.runMotor(2,FORWARD,0);
}
void steerRight(){
  Motors.runMotor(1,FORWARD,speedVal*turnMulti);
  Motors.runMotor(2,FORWARD,speedVal);
}
void steerLeft(){
  Motors.runMotor(1,FORWARD,speedVal);
  Motors.runMotor(2,FORWARD,speedVal*turnMulti);
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
