/*
 * debouncing.h
 *
 * Created: 5/29/2019 6:12:15 PM
 *  Author: braso
 */ 


#ifndef DEBOUNCING_CONTROL_H_
#define DEBOUNCING_CONTROL_H_

#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>

/*******************************************************
				  DEBOUNCING BUTTONS
********************************************************/
extern bool buttonPressed;
extern bool checkButton1;
extern bool checkButton2;
extern bool checkButton3;

/*******************************************************
					BUTTON COMMANDS
********************************************************/
extern bool buttonStart;
extern bool buttonStop;


// Function used to activate debouncing timer
void debauncingTimer();

// Function that sets the status of the buttons
void setButtonState();

// Function for button control
void buttonsSequence();

// Function used to control the actuator
void servoControlRotation();

// Function that checks when the water level has reached the desired level
void checkWaterLvl();

#endif /* DEBOUNCING_H_ */