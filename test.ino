#include "lib_stepper.h"

void setup() {
  //Serial.begin(9600);
  setupStepper();

}

void loop() {
  moveForward(1000);
  //executeMove();

}
