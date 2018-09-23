/*
 * Code for Sharp GP2Y0A60SZxF IR Sensor 
 * For use with DFA
 * $Version$ : 1
*/
#ifndef IR_H
#define IR_H

#include "arduino.h"

#define IR_PIN A1

//Gains
#define A 3269
#define B -0.02308
#define C 71.56
#define D -0.002927


void IRInit(){
	pinMode(IR_PIN, INPUT);
}


float readHeight(){
	//TODO: sensor does not read heights correctly below approximately 10 cm... 
	//	Need to deal with this
	float sensor_reading = analogRead(IR_PIN);

	//Mapping is an exponential function 
	return A*exp(B*sensor_height)+C*exp(D*sensor_height);
}

#endif