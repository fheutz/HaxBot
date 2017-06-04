#include <Arduino.h>
#include "DistanceSensorLib.h"

DistanceSensor ds;
uint16_t maxRange = 200;

void setup() {
	Serial.begin(115200);
	Serial.println("### START TESTCASE ###");

	delay(1000);

}

void loop() {

	long distance = ds.getDistance();

	if (distance > maxRange) {
		Serial.println("not in range!");
	} else {
		Serial.print(distance);
		Serial.println(" cm");
	}

	delay(1000);

}

