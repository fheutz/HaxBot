#include <Arduino.h>
#include "StepperLib.h"

short motor1Pins[4] = { 4, 5, 6, 7 };
short motor2Pins[4] = { 8, 9, 10, 11 };

#define STEPS 4076


uint16_t i = 0;
uint16_t iMax = 4000;


Stepper *stepper;

void setup() {
	Serial.begin(115200);
	Serial.println("### START TESTCASE ###");

	stepper = new Stepper(motor1Pins, motor2Pins);


	delay(1000);

}

void loop() {
	if (i == 0) {
		delay(100);
		stepper->moveForward(STEPS);
		i++;
	}
	uint16_t distance = stepper->getDistanceToGo();
	if (distance == 0) {
		i = 0;
	} else {
		stepper->moveForward(distance);
	}
}

