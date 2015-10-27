#ifndef TESTUNIT_H
#define TESTUNIT_H

#include <Arduino.h>

void motorTest_back_and_forward();
void motorTest_turn_for_sec(int speed, int sec);
void motorTest_forward_for_sec(int speed, int sec);
void motorTest_Turning_Robot();
void ballTest_readColor();
void ballTest_isThis(float testValue);
void distSens_test_dist();
void adArray_intArray();
void LineSensors_test();
void LineSensors_test_dir();
void LineSensors_test_raw();
void Test_servo();
void test_extra_sensor();
bool buttonA();

#endif
