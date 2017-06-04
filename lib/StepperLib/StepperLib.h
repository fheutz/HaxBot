#ifndef _DISTANCE_SENSOR_LIB_
#define _DISTANCE_SENSOR_LIB_


#include <Arduino.h>
#include <AccelStepper.h>


#define HALFSTEP 8

// motor pins for left motor
#define defaultMotorPin1  4     // IN1 on the ULN2003 driver 1
#define defaultMotorPin2  5     // IN2 on the ULN2003 driver 1
#define defaultMotorPin3  6     // IN3 on the ULN2003 driver 1
#define defaultMotorPin4  7     // IN4 on the ULN2003 driver 1

// motor pins for right motor
#define defaultMotorPin5  8     // IN1 on the ULN2003 driver 2
#define defaultMotorPin6  9     // IN2 on the ULN2003 driver 2
#define defaultMotorPin7  10    // IN3 on the ULN2003 driver 2
#define defaultMotorPin8  11    // IN4 on the ULN2003 driver 2


class Stepper {

	public:

		Stepper();
		Stepper(short motor1Pins[], short motor2Pins[]);

		void executeMove();
		void moveStepper(AccelStepper *stepper, int target);
		void moveStepper1(int target);
		void moveStepper2(int target);
		void moveForward(int distance);
		void moveBackward(int distance);
		void turnLeft(int distance);
		void turnRight(int distance);

	private:

		void initializeStepper(AccelStepper * stepper);

		//	VARIABLES
		// must be initialized with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
		AccelStepper STEPPER1;
		AccelStepper STEPPER2;
		
		int16_t _STEPS1 = 0;
		int16_t _STEPS2 = 0;

		//	CONSTANTS
		int16_t _stepperSpeed = 1000;
		int16_t _stepperMaxSpeed = 2000;
};

#endif
