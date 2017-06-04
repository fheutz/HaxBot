#include <Arduino.h>
#include <AccelStepper.h>
#include <StepperLib.h>
#include <DistanceSensorLib.h>


#define DEBUG 1
#define FORWARD 0
#define LEFT 1
#define RIGHT 2
#define BACKWARD 4


DistanceSensor *ds;
Stepper *stepper;
uint16_t maxRange = 200;
uint16_t loopCount = 0;
uint16_t loopMaxCount = 10000;
uint8_t turn = 0;




void setup() {
	Serial.begin(115200);

	Serial.println("### START PROGRAM ###");

	stepper = new Stepper;
	ds = new DistanceSensor;

	delay(1000);

}


void loop() {
	if (loopCount % 100 == 0) {
		if (turn == LEFT) {
			stepper->turnLeft(1000);
		} else if (turn == RIGHT) {
			stepper->turnRight(1000);
		} else {
			stepper->moveForward(1000);
		}
	}


	if (loopCount >= loopMaxCount) {
		long distance = ds->getDistance();
		Serial.print(distance);
		Serial.println(" cm");
		if (distance == 0) {
		} else if (distance < 20) {
			turn = LEFT;
			Serial.println("# turn left");
		} else {
			turn = FORWARD;
			Serial.println("# move forward");
		}
		loopCount = 0;
	}

/*
	if (loopCount >= loopMaxCount) {
		Serial.print("# loop");
		Serial.print(" - ");
		Serial.print(loopCount);
		long distance = ds->getDistance();
		if (distance > maxRange) {
			Serial.println("not in range!");
		} else {
			Serial.print(distance);
			Serial.println(" cm");
		}
		loopCount = 0;
	}
	*/



	loopCount++;


}

