#include <Arduino.h>
#include "DistanceSensorLib.h"

/**
 * @file DistanceSensorLib.cpp
 * @author Benjamin Boortz <benjamin.boortz@secure.mailbox.org>
 * @version 1.0
 */



DistanceSensor::DistanceSensor() {
	// initialize variables
	_trigPin= DEFAULT_TRIG_PIN;
	_echoPin= DEFAULT_ECHO_PIN;

	pinMode(_trigPin, OUTPUT);
	pinMode(_echoPin, INPUT);
}

DistanceSensor::DistanceSensor(int trigPin, int echoPin) {
	// initialize variables
	_trigPin= trigPin;
	_echoPin= echoPin;

	pinMode(_trigPin, OUTPUT);
	pinMode(_echoPin, INPUT);
}


long DistanceSensor::getDistance() const {
	long duration;
	long distance;

	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2); 
	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10); 
	digitalWrite(_trigPin, LOW);

	duration = pulseIn(_echoPin, HIGH);
	distance = (duration/2) / 29.1;

	return distance;
}
