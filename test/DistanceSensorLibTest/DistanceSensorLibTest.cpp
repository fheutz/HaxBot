#include <Arduino.h>
#include "DistanceSensorLib.h"


#define TRIG_PIN 13
#define ECHO_PIN 12


DistanceSensor ds = DistanceSensor(TRIG_PIN, ECHO_PIN);
uint16_t maxRange = 200;

void setup() {
	Serial.println("### START TESTCASE ###");

	Serial.begin(115200);
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

