#include "lib_stepper.h"

void setup() {
  // setupStepperDefault();

  short motor1Pins[4] = { 4, 5, 6, 7 };  
  short motor2Pins[4] = { 8, 9, 10, 11 };  
  setupStepper(motor1Pins, motor2Pins);

}

void loop() {
  moveForward(1000);
  //moveBackward(1000);
  //turnLeft(1000);
  //turnRight(1000);
}
