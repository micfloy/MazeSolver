#include <msp430.h> 
#include "ADCLibrary/sensors.h"
#include "motors.h"

int leftValues[5] = { 0 };
int centerValues[5] = { 0 };
int left;

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initPins();
	initTimer();
	initADCandPins();

	while (1) {

		// Works for 50% duty cycle.

//		if (getCenterSensor() > 0x326) {
//			turnRight();
//			_delay_cycles(30000);
//		} else if (getLeftSensor() > 0x3DD) {
//			turnRight();
//			_delay_cycles(1500);
//		} else if (getLeftSensor() < 0x333) {
//			TA0CCR1 = 30;
//			moveLeftForward();
//			moveRightForward();
//			_delay_cycles(5000);
//		} else {
//			moveForward();
//		}

		left = getLeftSensor();

		if (getCenterSensor() > 0x322) {
			turnRight();
			_delay_cycles(150000);
		} else if (left > 0x322) {
			turnRight();
			_delay_cycles(1500);
		} else if (left > 0x322 && left < 0x355) {
			slightLeftTurn();
			_delay_cycles(500);
		} else if (left <= 0x333) {
			forwardLeftTurn();
			_delay_cycles(1000);
		} else {
			moveForward();
		}

	}

}

