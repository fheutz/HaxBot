#include <AccelStepper.h>
#define HALFSTEP 8


// motor pins for left motor
#define defaultMotorPin1  4     // IN1 on the ULN2003 driver 1
#define defaultMotorPin2  5     // IN2 on the ULN2003 driver 1
#define defaultMotorPin3  6     // IN3 on the ULN2003 driver 1
#define defaultMotorPin4  7     // IN4 on the ULN2003 driver 1

// motor pins for right motor
#define defaultMotorPin5  8     // IN1 on the ULN2003 driver 2
#define defaultMotorPin6  9     // IN2 on the ULN2003 driver 2
#define defaultMotorPin7  10    // IN3 on the ULN2003 driver 2
#define defaultMotorPin8  11    // IN4 on the ULN2003 driver 2


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper STEPPER1;
AccelStepper STEPPER2;


// variables
int stepperSpeed = 1000; //speed of the stepper (steps per second)
int stepperMaxSpeed = 2000; //speed of the stepper (steps per second)
int STEPS1 = 0; // keep track of the step count for motor 1
int STEPS2 = 0; // keep track of the step count for motor 2


/*
 * method definitins
 */
void initializeStepper(AccelStepper * stepper);
void setupStepper(int motorPins[]);
void setupStepperDefault();
void executeMove();
void moveStepper(AccelStepper *stepper, int target);
void moveStepper1(int target);
void moveStepper2(int target);
void moveForward(int distance);
void moveBackward(int distance);
void turnLeft(int distance);
void turnRight(int distance);



/*
 * constructor(s)
 */

void setupStepper(short motor1Pins[], short motor2Pins[]) {
  STEPPER1 = AccelStepper(HALFSTEP, motor1Pins[0], motor1Pins[2], motor1Pins[1], motor1Pins[3]);
  STEPPER2 = AccelStepper(HALFSTEP, motor2Pins[0], motor2Pins[2], motor2Pins[1], motor2Pins[3]);

  delay(1000);

  initializeStepper(&STEPPER1);
  initializeStepper(&STEPPER2);  
}

void setupStepperDefault() {
  STEPPER1 = AccelStepper(HALFSTEP, defaultMotorPin1, defaultMotorPin3, defaultMotorPin2, defaultMotorPin4);
  STEPPER2 = AccelStepper(HALFSTEP, defaultMotorPin5, defaultMotorPin7, defaultMotorPin6, defaultMotorPin8);

  delay(1000);
  
  initializeStepper(&STEPPER1);
  initializeStepper(&STEPPER2);  
}


/*
 * methods
 */

void initializeStepper(AccelStepper * stepper) {
  (*stepper).setMaxSpeed(stepperMaxSpeed);
  (*stepper).move(-1);  // I found this necessary
  (*stepper).setSpeed(stepperSpeed);
}






void executeMove() {
  STEPS1 = STEPPER1.distanceToGo();
  STEPS2 = STEPPER2.distanceToGo();
  
  STEPPER1.runSpeedToPosition();
  STEPPER2.runSpeedToPosition();

  // Serial.print("steps needed: ");
  // Serial.println(STEPS1);
}


void moveStepper(AccelStepper *stepper, int target) {
  (*stepper).move(target);
  (*stepper).setSpeed(stepperSpeed);
}


void moveStepper1(int target) {
  if (STEPS1 == 0) {
    moveStepper(&STEPPER1, target);
  }
}

void moveStepper2(int target) {
  if (STEPS2 == 0) {
    moveStepper(&STEPPER2, target);
  }
}

void moveForward(int distance) {
  moveStepper1(-distance);
  moveStepper2(distance);
  executeMove();
}


void moveBackward(int distance) {
  moveStepper1(distance);
  moveStepper2(-distance);
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
