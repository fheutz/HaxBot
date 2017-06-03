#include <Arduino.h>
#include <Wire.h>
#include "DistanceSensorLib.h"

DistanceSensor ds;

void setup() {

	Serial.begin(115200);
	delay(1000);

}

void loop() {

	Serial.println("Hello world");
	ds.firstFooMethod();
	delay(1000);
	ds.secondFooMethod();
	delay(1000);

}

