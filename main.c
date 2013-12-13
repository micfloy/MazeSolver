#include <msp430.h> 
#include "ADCLibrary/sensors.h"
#include "motors.h"

int leftValues[5] = { 0 };
int centerValues[5] = { 0 };
int left;

/*
 * main.c
 *
 * Author:  C2C Michael Bentley
 *
 * Date Created:  12/11/13
 *
 * Description:  This code will the ECE382, two-wheeled robot to navigate a sufficiently wide maze by following the left wall.
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initPins();
	initTimer();
	initADCandPins();

	while (1) {


		left = getLeftSensor();		// Variable prevents calling the left sensor multiple times in one loop.

		if (getCenterSensor() > 0x322) {
			turnRight();
			_delay_cycles(150000);	// Much longer turns here prevent the robot from stuttering as it approaches a wall.
		} else if (left > 0x322) {
			turnRight();
			_delay_cycles(1500);	// Turning away from a side wall is generally a much smaller turn to keep the robot in the ideal distance window.
		} else if (left > 0x322 && left < 0x355) {		// If the robot is only a little too far away from the wall it will turn slightly into the wall.
			slightLeftTurn();
			_delay_cycles(500);
		} else if (left <= 0x333) {		// If the robot loses complete sight of the wall it starts a sweeping left turn.  This is for making left turns primarily.
			forwardLeftTurn();
			_delay_cycles(1000);
		} else {
			moveForward();	// If the robot is inside the optimal window from the wall, it will drive much faster in a straight line.
		}

	}

}

