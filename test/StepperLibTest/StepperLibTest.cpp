#include <Arduino.h>
#include "StepperLib.h"

short motor1Pins[4] = { 4, 5, 6, 7 };
short motor2Pins[4] = { 8, 9, 10, 11 };


Stepper stepper = Stepper(motor1Pins, motor2Pins);

void setup() {
	Serial.println("### START TESTCASE ###");

	Serial.begin(115200);
	delay(1000);

}

void loop() {

	stepper.moveForward(1000);

	delay(1000);

}

