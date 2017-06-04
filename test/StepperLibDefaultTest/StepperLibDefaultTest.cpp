#include <Arduino.h>
#include <AccelStepper.h>
#include <StepperLib.h>

Stepper *stepper;

void setup() {
	Serial.begin(115200);
	Serial.println("### START TESTCASE ###");

	stepper = new Stepper;
	delay(1000);
}

void loop() {

	stepper->moveForward(10000);

}

