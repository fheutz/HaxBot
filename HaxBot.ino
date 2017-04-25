#include "lib_stepper.h"

void setup() {
  // setupStepperDefault();

  short motorPins[8] = { 3, 5, 6, 7, 8, 9, 10, 11 };  
  setupStepper(motorPins);

}

void loop() {
  //moveForward(1000);
  //moveBackward(1000);
  //turnLeft(1000);
  turnRight(1000);
}
