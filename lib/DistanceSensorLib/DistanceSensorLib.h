#ifndef _DISTANCE_SENSOR_LIB_
#define _DISTANCE_SENSOR_LIB_


#include <Arduino.h>


#define DEFAULT_TRIG_PIN 13
#define DEFAULT_ECHO_PIN 12


class DistanceSensor {

	public:

		DistanceSensor();
		DistanceSensor(int, int);

		long getDistance() const;

	private:

		//	VARIABLES
		uint8_t _trigPin;
		uint8_t _echoPin;

		//	CONSTANTS
};

#endif
