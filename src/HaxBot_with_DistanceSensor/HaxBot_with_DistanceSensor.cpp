#include <Arduino.h>
#include <AccelStepper.h>
#include <StepperLib.h>
#include <DistanceSensorLib.h>


// #define DEBUG 1
#define STEPS 4076 / 4

#define FORWARD 0
#define LEFT 1
#define RIGHT 2
#define BACKWARD 4


DistanceSensor *ds;
Stepper *stepper;
uint16_t loopCount = 0;
uint16_t loopMaxCount = 10000;
uint16_t stepOfMove = 0;
uint8_t turn = FORWARD;




void setup() {
	Serial.begin(115200);
	Serial.println("### START PROGRAM ###");

	stepper = new Stepper;
	ds = new DistanceSensor;

	// Timer0 is already used for millis() - we'll just interrupt somewhere
	// in the middle and call the "Compare A" function below
//	OCR0A = 0xAF;
//	TIMSK0 |= _BV(OCIE0A);

	delay(1000);

}

// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
//SIGNAL(TIMER0_COMPA_vect) {
//	Serial.println("timer");
//} 



void turnLeft(int distance) {
	if (stepOfMove == 0) {
		stepper->turnLeft(distance);
		stepOfMove = 1;
	} else {
		uint16_t distance = stepper->getDistanceToGo();
		if (distance == 0) {
			stepOfMove = 0;
		} else {
			stepper->executeMove();
		}
	}
}

void turnRight(int distance) {
	if (stepOfMove == 0) {
		stepper->turnRight(distance);
		stepOfMove = 1;
	} else {
		uint16_t distance = stepper->getDistanceToGo();
		if (distance == 0) {
			stepOfMove = 0;
		} else {
			stepper->executeMove();
		}
	}

}

void moveForward(int distance) {
	if (stepOfMove == 0) {
		stepper->moveForward(distance);
		stepOfMove = 1;
	} else {
		uint16_t distance = stepper->getDistanceToGo();
		if (distance == 0) {
			stepOfMove = 0;
		} else {
			stepper->executeMove();
		}
	}
}

void moveBackward(int distance) {
	if (stepOfMove == 0) {
		stepper->moveBackward(distance);
		stepOfMove = 1;
	} else {
		uint16_t distance = stepper->getDistanceToGo();
		if (distance == 0) {
			stepOfMove = 0;
		} else {
			stepper->executeMove();
		}
	}
}


void loop() {


	// detect obstacles
	if (loopCount % 10001 == 0) {
		long distance = ds->getDistance();
	}

	// detect obstacles
	if (loopCount % 10001 == 0) {
		long distance = ds->getDistance();
		Serial.println(distance);
		if (distance == 0) {
		} else if (distance < 20) {
			if (turn == FORWARD) {
				turn = LEFT;
				stepOfMove = 0;
			} else {
				turn = FORWARD;
			}
		} else {
			turn = FORWARD;
		}
		loopCount = 0;
	}


	// move robot
	if (loopCount % 100 == 0) {
		if (turn == LEFT) {
			turnLeft(STEPS);
		} else if (turn == RIGHT) {
			turnRight(STEPS);
		} else if (turn == FORWARD) {
			moveForward(STEPS);
		} else if (turn == BACKWARD) {
			moveBackward(STEPS);
		}
	}


	loopCount++;


}

