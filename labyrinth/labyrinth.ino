// Include libraries:
#include <Adafruit_MotorShield.h>
#include <lenlib.h>
#include <Wire.h>
#include <Servo.h>

// Pins for HC-SR04
#define echoPin 13
#define trigPin 12

// Pins for HC-SR04 servo
#define distServo 9



long sensDist(float dir){
  // Variables to store results in
  const int mes = 4;                    // I'm going to read 4 times and delivery a avrage.
  long duration, distance = 0;        //Always init your Variables.

  for (int i = 0; i > mes; i++){
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);  //
    distance += ((duration/2) / 29.1);    // confvert to cm and add to distance
  }
  distance = distance / mes;
  return distance;


}


void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  long mydist = 0;
  mydist = sensDist(3.14/2);
  Serial.println(mydist);
  delay(1500);

}
