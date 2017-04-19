#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins
#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 1
#define motorPin3  5     // IN3 on the ULN2003 driver 1
#define motorPin4  6     // IN4 on the ULN2003 driver 1

// #define motorPin5  8     // IN1 on the ULN2003 driver 2
// #define motorPin6  9     // IN2 on the ULN2003 driver 2
// #define motorPin7  10    // IN3 on the ULN2003 driver 2
// #define motorPin8  11    // IN4 on the ULN2003 driver 2


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper STEPPER1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
//AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);


// variables
int stepperSpeed = 1000; //speed of the stepper (steps per second)
int stepperMaxSpeed = 2000; //speed of the stepper (steps per second)
int STEPS1 = 0; // keep track of the step count for motor 1


/*
 * methods
 */

void setupStepper() {
  delay(3000);
  
  STEPPER1.setMaxSpeed(stepperMaxSpeed);
  STEPPER1.move(1);  // I found this necessary
  STEPPER1.setSpeed(stepperSpeed);

//  stepper2.setMaxSpeed(2000.0);
//  stepper2.move(-1);  // I found this necessary
//  stepper2.setSpeed(stepperSpeed);
}


void isMoveDone() {

}





void executeMove() {
  STEPS1 = STEPPER1.distanceToGo();
  STEPPER1.runSpeedToPosition();

  // Serial.print("steps needed: ");
  // Serial.println(STEPS1);
}


void moveStepper(AccelStepper stepper, int target) {
  stepper.move(target);
  stepper.setSpeed(stepperSpeed);
}


void moveForward(int distance) {

  if (STEPS1 == 0) {
    int target = distance;

    AccelStepper stepper = STEPPER1;
    // Serial.print("moveForward: ");
    // Serial.println(target);  
    STEPPER1.move(target);
    STEPPER1.setSpeed(stepperSpeed);
    //moveStepper(STEPPER1, target);
  }

  executeMove();
}


