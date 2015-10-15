#include <Adafruit_MotorShield.h>
#include <lenlib.h> 
#include <Servo.h> 
#include <Wire.h> 

mySensors Sensors; // create sensors object
myMotors Motors; // Create motors object

int LMotorSpeed = 100;
int RMotorSpeed = 100;

int accelScalle = 3;
float scaledX, scaledY, scaledZ = 0;      // Anväsns för att lagra axelvariablerna
const int accPinX = 5;                  // Pinnar för kopplingen.
const int accPinY = 6;
const int accPinZ = 7;

void readAccel(){
    boolean debug = true;
    int rawX, rawY, rawZ = 0;
    // Läs in varje axel.
    rawX = analogRead(accPinX);
    rawY = analogRead(accPinY);
    rawZ = analogRead(accPinZ);

    // Skala om de annaloga signalerna.
    scaledX = map(rawX, 0, 675, -accelScalle, accelScalle);
    scaledY = map(rawY, 0, 675, -accelScalle, accelScalle);
    scaledZ = map(rawZ, 0, 675, -accelScalle, accelScalle);
    // för deugging printa till serialla.
    if (debug){
        Serial.print("Acc X= raw(");
        Serial.print(rawX);
        Serial.print(")  Scaled(");
        Serial.print(scaledX);
        Serial.print(")   ");
        Serial.print("Y= raw(");
        Serial.print(rawY);
        Serial.print(")  Scaled(");
        Serial.print(scaledY);
        Serial.print(")   ");
        Serial.print("Z = raw(");
        Serial.print(rawZ);
        Serial.print(")  Scaled(");
        Serial.print(scaledZ);
        Serial.println(")");
    }
}

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println(" Starting Tibetan goat");
}

void loop() {
  // put your main code here, to run repeatedly:
    readAccel();
    delay(2000);

}
