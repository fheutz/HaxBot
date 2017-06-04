#include <Arduino.h>
#include "StepperLib.h"

/**
 * @file StepperLib.cpp
 * @author Benjamin Boortz <benjamin.boortz@secure.mailbox.org>
 * @version 1.0
 */



Stepper::Stepper() {
	STEPPER1 = AccelStepper(HALFSTEP, defaultMotorPin1, defaultMotorPin3, defaultMotorPin2, defaultMotorPin4);
	STEPPER2 = AccelStepper(HALFSTEP, defaultMotorPin5, defaultMotorPin7, defaultMotorPin6, defaultMotorPin8);

	delay(1000);
				
	initializeStepper(&STEPPER1);
	initializeStepper(&STEPPER2); 
}

Stepper::Stepper(short motor1Pins[], short motor2Pins[]) {
	STEPPER1 = AccelStepper(HALFSTEP, motor1Pins[0], motor1Pins[2], motor1Pins[1], motor1Pins[3]);
	STEPPER2 = AccelStepper(HALFSTEP, motor2Pins[0], motor2Pins[2], motor2Pins[1], motor2Pins[3]);

	delay(1000);

	initializeStepper(&STEPPER1);
	initializeStepper(&STEPPER2); 
}


void Stepper::initializeStepper(AccelStepper * stepper) {
	(*stepper).setMaxSpeed(_stepperMaxSpeed);
	(*stepper).move(-1);  // I found this necessary
	(*stepper).setSpeed(_stepperSpeed);
}


void Stepper::executeMove() {
  _STEPS1 = STEPPER1.distanceToGo();
  _STEPS2 = STEPPER2.distanceToGo();

  STEPPER1.runSpeedToPosition();
  STEPPER2.runSpeedToPosition();

  // Serial.print("steps needed: ");
  // Serial.println(STEPS1);
}


void Stepper::moveStepper(AccelStepper *stepper, int target) {
  (*stepper).move(target);
  (*stepper).setSpeed(_stepperSpeed);
}


void Stepper::moveStepper1(int target) {
  if (_STEPS1 == 0) {
    moveStepper(&STEPPER1, target);
  }
}

void Stepper::moveStepper2(int target) {
  if (_STEPS2 == 0) {
    moveStepper(&STEPPER2, target);
  }
}

void Stepper::moveForward(int distance) {
  moveStepper1(-distance);
  moveStepper2(distance);
  executeMove();
}


void Stepper::moveBackward(int distance) {
  moveStepper1(distance);
  moveStepper2(-distance);
  executeMove();
}

void Stepper::turnLeft(int distance) {
  moveStepper1(distance);
  moveStepper2(distance);
  executeMove();
}

void Stepper::turnRight(int distance) {
  moveStepper1(-distance);
  moveStepper2(-distance);
  executeMove();
}


