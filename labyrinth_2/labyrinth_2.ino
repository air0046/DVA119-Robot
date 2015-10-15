// Include libraries:
#include <Adafruit_MotorShield.h>
#include <lenlib.h>
#include <Wire.h>
#include <Servo.h>

// Create Motors object
myMotors Motors;

// Define pins for left Ultrasonic distance sensor
#define echoPinL 3
#define trigPinL 4
// Define pins for right Ultrasonic distance sensor
#define echoPinR 11
#define trigPinR 12
// Define pins for front IR sensor
#define irSensorPin A0

// Minimum distance to left or right obstacle variable
int dangerSideDist = 10;
// Upper threshold, safe distance side value
int safeSideDist = 20;

// Minimum distance to obstacles ahead of the robot
int dangerFrontDist = 250;
// Variables used to tell if there are any obstacles nearby.
boolean sensorHitL = false;
boolean sensorHitR = false;
boolean sensorHitF = false;
// Variables used to store the distance values.
long distanceL, distanceF, distanceR = 0;

// This is the motor speed value, (0-255)
int speedVal = 80; // 60 seem to be a good value
// Variable that works as a factor regulating the turn speed. i.e 1.8*speedVal = turnspeed
float turnMulti = 1.3;
// Delay value called after motors been running:
int delVal = 0;
// Delay value used when turning 90 degrees
int turnDelay = 680;
// Delay value used when rev:ing
int revDelay = 1000;

// General loop delay
int loopDelay = 150;

void setup() {
  Serial.begin(9600); // set up Serial connection at 9600 bps

  Motors.beginMotors();   // Start motors

  // Set pin modes for Ultrasonic distance sensor
  pinMode(echoPinL, INPUT);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinR, INPUT);
  pinMode(trigPinR, OUTPUT);

  delay(2000);
}

void loop() {
  // Read sensors and check for obstacles
  parseInputs();
  // Run motors based on data from parseInputs
  runMotors();

  delay(loopDelay);

  // turnLeft();
  // delay(4000);
  // turnRight();
  // delay(4000);

}

void runMotors(){

  if(sensorHitL && !sensorHitF && !sensorHitR) steerRight();
  else if (sensorHitR && !sensorHitF && !sensorHitL) steerLeft();
  else if (!sensorHitF && !sensorHitL && !sensorHitR) fwd();
  else if (sensorHitL && sensorHitR && !sensorHitF) fwd();
  else if (sensorHitF && !sensorHitL && !sensorHitR) parryObstacle();
  else stop();

  sensorHitL = false;
  sensorHitF = false;
  sensorHitR = false;
}

// Function that
void parryObstacle() {
  // If there is an obstacle to the left, but not to the right, turn 90 degrees right.
  if(sensorHitL && !sensorHitR){
    Serial.println("sensorHitL true, sensorHitR false");
    turnRight();
    }

  // If there is an obstacle to the right, but not to the right, turn 90 degrees left.
  else if(!sensorHitL && sensorHitR){

    Serial.println("sensorHitL false, sensorHitR true");
    turnLeft();
  }
  else if(sensorHitL && sensorHitR && !sensorHitF){
    fwd();
  }
  else if(sensorHitL && sensorHitR && sensorHitF){
    rev();
    // delay(revDelay);
    // stop();
  }
  else{
    stop();
  }
}

// Function that parse the values from the sensors and return true/false if there
//  are any obstacles nearby.
void parseInputs(){

  distanceF = frontSensorRead();
  distanceL = leftSensorRead();
  distanceR = rightSensorRead();

  if (distanceF > dangerFrontDist) sensorHitF = true;
  else sensorHitF = false;

  if (distanceL < dangerSideDist && distanceL < distanceR) sensorHitL = true;
  else sensorHitL = false;

  if (distanceR < dangerSideDist && distanceR < distanceL) sensorHitR = true;
  else sensorHitR = false;

  Serial.print("Left: ");
  Serial.print(sensorHitL);
  Serial.print(" ");
  Serial.print(distanceL);
  Serial.print("\tFront: ");
  Serial.print(sensorHitF);
  Serial.print(" ");
  Serial.print(distanceF);
  Serial.print("\tRight: ");
  Serial.print(sensorHitR);
  Serial.print(" ");
  Serial.println(distanceR);

}

// Function for measuring the distance using the LEFT Ultrasonic sensor
long leftSensorRead(){
  // Variables for duration and distance.
  long duration, distance = 0;

  // Left distance sensor, trigPin/echoPin cycle:
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL,LOW);
  duration = pulseIn(echoPinL, HIGH);

  // Calculate distance in cm. This is based on the speed of sound.
  distance = (duration/2) / 29.1;
  if(distance >= 200){
    distance = 199;
    return distance;
  }
  else{
  return distance;  // Return distance value
  }
}

// Function for measuring the distance using the RIGHT Ultrasonic sensor
long rightSensorRead(){
  // Variables for duration and distance.
  long duration, distance = 0;

  // Left distance sensor, trigPin/echoPin cycle:
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR,LOW);
  duration = pulseIn(echoPinR, HIGH);

  // Calculate distance in cm. This is based on the speed of sound.
  distance = (duration/2) / 29.1;
  if(distance >= 200){
    distance = 199;
    return distance;
  }
  else{
  return distance;  // Return distance value
  }
}

// Function for reading the distance to the obstacle in front of the robot.
long frontSensorRead(){
  long distance = 0;

  distance = analogRead(irSensorPin);

  return distance;
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
