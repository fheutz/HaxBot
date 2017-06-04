#include <Arduino.h>
#include "StepperLib.h"

Stepper stepper;

void setup() {
	Serial.println("### START TESTCASE ###");

	Serial.begin(115200);
	delay(1000);

}

void loop() {

	stepper.moveForward(1000);

	delay(1000);

}

