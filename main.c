#include <msp430.h> 
#include "ADCLibrary/sensors.h"
#include "motors.h"
#include "moving_average.h"

int leftValues[5] = { 0 };
int centerValues[5] = { 0 };

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initPins();
	initTimer();
	initADCandPins();

	while (1) {

//		addSample(getCenterSensor(), leftValues, 5);
		if (getCenterSensor() > 0x346) {
			stop();
			turnRight();
			_delay_cycles(10000);
			stop();
		} else if (getLeftSensor() > 0x3DD) {
			turnRight();
			_delay_cycles(3000);
		} else if (getLeftSensor() < 0x1CC) {
			TA0CCR1 = 30;
			moveLeftForward();
			moveRightForward();
			_delay_cycles(10000);
		} else {
			moveForward();
		}

//		addSample(getCenterSensor(), centerValues, 5);

//		if (getLeftSensor() > 0x386) {
//			turnRight(100);
//		} else {
//			forwardLeft();
//		}
//
//		if (getCenterSensor() > 0x2DD) {
//			turnRight(500);
//		}
	}

}

