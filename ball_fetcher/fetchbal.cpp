
#include "fetchbal.h"
// This is the program to fecth the ball att the 3 track
//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change
#include <Arduino.h>


void fetcBal::setforkAngle(int angle){
  _angle = angle;
  _fork.write(angle);
}

void fetcBal::start(){

  _fork.attach(_forkPin);
  Serial.println("Start fetcBal");
  _lineFolow.start();
}

void fetcBal::run(){
  //gotoLain(0);
  Serial.println("getReady in 2sec");
  delay(2000);
  lowerFork();
  /*while ( readStopper() == false ){
    Serial.println(" FolowLine");
    folowLine();

  }*/
  _lineFolow.setSpeed(100,100);
  delay(1000);
  takeBal();
  delay(2000);
  _fork.detach();
}
void fetcBal::takeBal(){
  while (_distance.getDistance() < _maxDist) {
    Serial.println("to far away");
    delay(1000);
  }
  Serial.println("Lets go and get ball in 1sec");
  delay(1000);
  // Hitta bollen genom att rotera lite til höger och vänsetr.
  _lineFolow.setSpeed(_laniSpeed,_laniSpeed);
  while (_distance.getDistance() > _picDist){
    Serial.println(_distance.toString());
    //Serial.println(_lineFolow.motorsToStr());
  }
  _lineFolow.setSpeed(0,0);
  delay(500);
  riseFork();
  bool contin = true;
  while ( contin ) {
    /* code */
    _Boll[0].readColor();
    Serial.println(_Boll[0].toString());
    if (_Boll[0].color() < _slected ){
      Serial.println("That whas a good choise. Dropping in 2sec");
      delay(2000);
      setforkAngle(50);
      contin = false;
    }
  }
}

void fetcBal::findMinOnBall(){
  int dist = 0;
  int distOld = 0;
  int min = 100000;
  int rotDelay = 3000;
  bool findMin = true;
  _lineFolow.setSpeed(-100, 100);
  while (_distance.getDistance() < _maxDist){
    Serial.println(" Rotate loop ");
  }
  delay(100);
  _lineFolow.setSpeed(0,0);
  while (findMin){
    dist = _distance.getDistance();
    if (dist < distOld){
      distOld = dist;
    }else{
      findMin = false;
    }
    _lineFolow.setSpeed(100, +100);
    Serial.println(dist);
  }
  _lineFolow.setSpeed(0,0);
  Serial.println("End Dist");
}

void fetcBal::folowLine(){
  _lineFolow.folowLinePid();
}

void fetcBal::riseFork(){
  int target = 150;
  for (int i = _minFork; i < target ; i ++){
    setforkAngle(i);
    delay(10);
  }
  //setforkAngle(150);

}

void fetcBal::lowerFork(){
  setforkAngle(_minFork );
}

bool fetcBal::readStopper(){
  _stopper.push(digitalRead(_stopperPin));
  if (_stopper.sum() >= 2){
    _stop = true;
  } else {
    _stop = false;
  }
  Serial.print("fetcBal::readStopper() sum= ");
  Serial.println(_stopper.sum());
  return _stop;
}

String fetcBal::toString(){
  String temp = "";
  temp = "FechBal _stopper.sum =";
  temp += _stopper.sum();
  temp += "   ";
  temp += _operationalPos;
  /*for(int i = 0; i < 3; i++){
    temp += " BollCollor ";
    temp += i;
    temp += "=";
    temp += _Boll[1].color();
    temp += " ";
  }*/
  temp += " forkAngle= ";
  temp += _angle;
  return temp;
}
