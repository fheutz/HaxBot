#include <Arduino.h>
#include <AccelStepper.h>
#include <StepperLib.h>
#include <DistanceSensorLib.h>


// #define DEBUG 1
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

	// move robot
	if (loopCount % 100 == 0) {
		if (turn == LEFT) {
			stepper->turnLeft(1000);
		} else if (turn == RIGHT) {
			stepper->turnRight(1000);
		} else {
			stepper->moveForward(1000);
		}
	}


	// detect obstacles
	if (loopCount >= loopMaxCount) {
		long distance = ds->getDistance();
#ifdef DEBUG
		Serial.print(distance);
		Serial.println(" cm");
#endif
		if (distance == 0) {
		} else if (distance < 20) {
			turn = LEFT;
#ifdef DEBUG
			Serial.println("# turn left");
#endif
		} else {
			turn = FORWARD;
#ifdef DEBUG
			Serial.println("# move forward");
#endif
		}
		loopCount = 0;
	}


	loopCount++;


}

