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

// Variable that works as a factor regulating the turn speed. i.e 1.8*spedVal = turnspeed
float turnMulti = 1.8;

myMotors Motors;   // Create Motors object
mySensors Sensors; // Create Sensors object

void setup() {
  Serial.begin(9600); // set up Serial connection at 9600 bps
    
  Motors.beginMotors();   // Start motors
  Sensors.beginSensors(); // Start sensors

  delay(2000);
}

void loop() {

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
  //Serial.print("\tTurn speed: ");Serial.print(turnSpeed);
  Serial.print("\n");

  // if the right sensor is the only sensor that have the value 1, the bot need to compensate by turning right
  if((leftSensor == 0 && middleSensor == 0 && rightSensor == 1) || (leftSensor == 0 && middleSensor == 1 && rightSensor == 1)) 
  {
      Motors.runMotor(1,FORWARD,(turnMulti*speedVal));
      Motors.runMotor(2,BACKWARD,0);
      //remove delay
      delay(delVal);      
      //if((leftSensor == 0 && middleSensor == 0 && rightSensor == 0) || (leftSensor == 1 && middleSensor == 1 && rightSensor == 1))
//      {
//          Motors.runMotor(1,FORWARD,(turnMulti*speedVal));
//          Motors.runMotor(2,BACKWARD,0);;
//      }
//      else{}
  }
  // if the left sensor is the only sensor that have the value 1, the bot need to compensate by turning left
  else if((leftSensor == 1 && middleSensor == 0 && rightSensor == 0) || (leftSensor == 1 && middleSensor == 1 && rightSensor == 0)) 
  {
      Motors.runMotor(1,BACKWARD,0);
      Motors.runMotor(2,FORWARD,(turnMulti*speedVal));
      //remove delay
      delay(delVal);
      //if((leftSensor == 0 && middleSensor == 0 && rightSensor == 0) || (leftSensor == 1 && middleSensor == 1 && rightSensor == 1))
//      {
//          Motors.runMotor(2,BACKWARD,0);;
//          Motors.runMotor(2,FORWARD,(turnMulti*speedVal));
//      }
//      else{}
  }
  // if sensor value = 1, then the sensor is on track
  else if((leftSensor == 0 && middleSensor == 1 && rightSensor == 0) || (leftSensor == 1 && middleSensor == 1 && rightSensor == 1))
  {
      if(middleSensor == 0)
      {
        Motors.runMotor(1,BACKWARD,speedVal);
        Motors.runMotor(2,BACKWARD,speedVal);
        delay(100);
      }
      else
      {
        Motors.runMotor(1,FORWARD,speedVal);
        Motors.runMotor(2,FORWARD,speedVal);    
      }
      //remove delay
      delay(delVal);
  }

  // if none of the sensors have a value 1, the robot probably went too fast and missed the turn. Backup and hope we find the tape again.
  else if(leftSensor == 0 && middleSensor == 0 && rightSensor == 0)
  {
    Motors.runMotor(1,BACKWARD,speedVal);
    Motors.runMotor(2,BACKWARD,speedVal);
    delay(80);
  }
  else
  {
      Motors.runMotor(1,FORWARD,0);
      Motors.runMotor(2,FORWARD,0);
  }
  // test if motors work
  //Motors.runMotor(1,FORWARD,speedValue);
  //Motors.runMotor(2,FORWARD,speedValue);
}
