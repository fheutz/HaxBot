#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins
#define motorPin1  4     // IN1 on the ULN2003 driver 1
#define motorPin2  5     // IN2 on the ULN2003 driver 1
#define motorPin3  6     // IN3 on the ULN2003 driver 1
#define motorPin4  7     // IN4 on the ULN2003 driver 1

#define motorPin5  8     // IN1 on the ULN2003 driver 2
#define motorPin6  9     // IN2 on the ULN2003 driver 2
#define motorPin7  10    // IN3 on the ULN2003 driver 2
#define motorPin8  11    // IN4 on the ULN2003 driver 2


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper STEPPER1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper STEPPER2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);


// variables
int stepperSpeed = 1000; //speed of the stepper (steps per second)
int stepperMaxSpeed = 2000; //speed of the stepper (steps per second)
int STEPS1 = 0; // keep track of the step count for motor 1
int STEPS2 = 0; // keep track of the step count for motor 2


/*
 * methods
 */

void setupStepper() {
  delay(3000);
  
  STEPPER1.setMaxSpeed(stepperMaxSpeed);
  STEPPER1.move(1);  // I found this necessary
  STEPPER1.setSpeed(stepperSpeed);

  STEPPER2.setMaxSpeed(stepperMaxSpeed);
  STEPPER2.move(-1);  // I found this necessary
  STEPPER2.setSpeed(stepperSpeed);
}


void isMoveDone() {

}





void executeMove() {
  STEPS1 = STEPPER1.distanceToGo();
  STEPS2 = STEPPER1.distanceToGo();
  
  STEPPER1.runSpeedToPosition();
  STEPPER2.runSpeedToPosition();

  // Serial.print("steps needed: ");
  // Serial.println(STEPS1);
}


void moveStepper1(int distance) {
  if (STEPS1 == 0) {
    int target = distance;
    STEPPER1.move(target);
    STEPPER1.setSpeed(stepperSpeed);
  }
}

void moveStepper2(int distance) {
  if (STEPS2 == 0) {
    int target = distance;
    STEPPER2.move(target);
    STEPPER2.setSpeed(stepperSpeed);
  }
}

void moveForward(int distance) {
  moveStepper1(distance);
  moveStepper2(-distance);
  executeMove();
}


void moveBackward(int distance) {
  moveStepper1(-distance);
  moveStepper2(distance);
  executeMove();
}

void turnLeft(int distance) {
  moveStepper1(distance);
  moveStepper2(distance);
  executeMove();
}

void turnRight(int distance) {
  moveStepper1(-distance);
  moveStepper2(-distance);
  executeMove();
}
