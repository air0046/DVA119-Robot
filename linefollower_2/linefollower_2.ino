// Include libraries:
#include <Adafruit_MotorShield.h>
#include <lenlib.h>
#include <Wire.h>
#include <Servo.h>
#include "utility/Adafruit_PWMServoDriver.h"
//42,1,150 @ 110
//30,1.05,0 @ 60
//float Kp=17,Ki=3.8,Kd=0.0;
int loopDelay = 0;
float Kp=16,Ki=0,Kd=15;//15
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0, previous_I=0;
int sensor[3]={0, 0, 0};
int initial_motor_speed=50;
int lessThan = 20;
void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);

//myMotors Motors;   // Create Motors object
mySensors Sensors; // Create Sensors object
myMotors Motors;
//Adafruit_MotorShield AFMS = Adafruit_MotorShield();
//Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
//Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);


// Create the motor shield object with the default I2C address
// Adafruit_MotorShield AFMS = Adafruit_MotorShield();
//
// Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
// Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);

void setup()
{
 Serial.begin(9600); //Enable Serial Communications

 Motors.beginMotors();   // Start motors
 //AFMS.begin();
 Sensors.beginSensors(); // Start sensors

 delay(1000);
}

void loop()
{
    read_sensor_values();
    calculate_pid();
    motor_control();
    //
    // Serial.print("Sensor0: ");
    // Serial.print(sensor[0]);
    // Serial.print("\tSensor1: ");
    // Serial.print(sensor[1]);
    // Serial.print("\tSensor2: ");
    // Serial.println(sensor[2]);

    delay(loopDelay);
}

void read_sensor_values()
{
  sensor[0]=Sensors.readReflect0();
  sensor[1]=Sensors.readReflect1();
  sensor[2]=Sensors.readReflect2();

  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1))//&&(sensor[4]==0)&&(sensor[4]==1))
  error=2;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1))
  error=1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0))//&&(sensor[4]==1)&&(sensor[4]==0))
  error=0;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0))//&&(sensor[4]==1)&&(sensor[4]==0))
  error=-1;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0))//&&(sensor[4]==0)&&(sensor[4]==0))
  error=-2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0))//&&(sensor[4]==0)&&(sensor[4]==0))
    if(error==-2) error=-2;
    else error=2;
}

void calculate_pid()
{
    P = error;
    I = I + previous_I;
    D = error-previous_error;

    PID_value = (Kp*P) + (Ki*I) + (Kd*D);

    previous_I=I;
    previous_error=error;
}

void motor_control()
{
    // Calculating the effective motor speed:
    int left_motor_speed = initial_motor_speed-PID_value;
    int right_motor_speed = initial_motor_speed+PID_value;

    // The motor speed should not exceed the max PWM value
    constrain(left_motor_speed,0,255);
    constrain(right_motor_speed,0,255);

    // Serial.print("Left Motor Speed: ");
    // Serial.print(left_motor_speed);
    // Serial.print("\tRight Motor Speed: ");
    // Serial.println(right_motor_speed);
    if(left_motor_speed < lessThan){
        Motors.runMotor(2,BACKWARD,initial_motor_speed*2.2); // Left motor Speed
        Motors.runMotor(1,FORWARD,right_motor_speed); //Right motor Speed
    }
    else if(right_motor_speed < lessThan){
      Motors.runMotor(1,BACKWARD,initial_motor_speed*2.2); // Left motor Speed
      Motors.runMotor(2,FORWARD,right_motor_speed); //Right motor Speed
    }
    else{
    Motors.runMotor(2,FORWARD,left_motor_speed); // Left motor Speed
    Motors.runMotor(1,FORWARD,right_motor_speed); //Right motor Speed
  }
    //analogWrite(9,initial_motor_speed-PID_value);   //Left Motor Speed
    //analogWrite(10,initial_motor_speed+PID_value);  //Right Motor Speed
    //myMotor1->setSpeed(initial_motor_speed-PID_value);
    //myMotor2->setSpeed(initial_motor_speed+PID_value);

    //following lines of code are to make the bot move forward
    /*The pin numbers and high, low values might be different
    depending on your connections */
    // digitalWrite(4,HIGH);
    // digitalWrite(5,LOW);
    // digitalWrite(6,LOW);
    // digitalWrite(7,HIGH);
    //myMotor1->run(FORWARD);
    //myMotor2->run(FORWARD);

}
