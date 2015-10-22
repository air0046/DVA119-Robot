
#include "fetchbal.h"
// This is the program to fecth the ball att the 3 track
//#include <WProgram.h> //  It is very important to remember this! note that
//                          if you are using Arduino 1.0 IDE, change
#include <Arduino.h>


void fetcBal::setforkAngle(int angle){
  _angle = angle;
  _fork.write(map(angle, 0, 255, 0, 180));
}

/*fetcBal::fetcBal(){
  _fork.attach(9);
}*/

void fetcBal::run(){

}

String fetcBal::toString(){
  String temp = "";
  temp = "FechBal _operationalPos= ";
  temp += _operationalPos;
  for(int i = 0; i < 3; i++){
    temp += " BollCollor ";
    temp += i;
    temp += "=";
    temp += _Boll[1].color();
    temp += " ";
  }
  temp += " forkAngle= ";
  temp += _angle;
}
