/*
* License_project.c
*
* Created: 10/11/2018 6:22:27 PM
* Author : braso
*/

#include <avr/io.h>
#include <stdlib.h>
#include <stdbool.h>

#include "timers.h"
//Timer driver (Timer0, Timer1, Timer3)

#include "ultrasonic_pins_defines.h"
//Ultrasonic initialization (ports, pins)

#include "avr_extInterrupt.h"
//External Interrupt Control Register driver

#include "ultrasonic_module_defines.h"
//Application related defines and variables

#include "gpio.h"
//GPIO driver (Direction, Write, Read)

#include "lcd_defines.h"
//LCD initialization

#include "debouncing_control.h"
// Initialization buttons and control the servo motor

#include "servo_defines.h"
// Servo motor
	

int main(void)
{
	// Sets the initial position of the servomotor
	set_ServoPosition(timer3,170);
	
	liquidCrystalPortInit(&PORTA,&PORTC,PORTC0,PORTC1,PORTC2);	 	
	lcd_clear();
	lcd_goToLine(1,1);
	lcd_displayChar("--------------------");
	lcd_goToLine(2,3);
	lcd_displayChar("Brasoveanu Ghe.");
	lcd_goToLine(3,2);
	lcd_displayChar("Reglarea nivelului");
	lcd_goToLine(4,1);
	lcd_displayChar("--------------------");
	
	// Buttons init & debouncing & servo control
	debauncingTimer();
	setButtonState();
	
	// Pwm function for servo
	pwm_InitServoMotor(&PORTE,PORTE3);
	
	// Ports initialization (ultrasonic sensor)
	ultrasonicModule_init(&PORTE,PORTE6,PORTE5);

	// External interrupt, rising edge
	set_extInterrupt(&EICRB,INT5,RISING_EDGE_5);
	
	// Enable the Interrupt Mask Register
	set_extInterrupt_Enable(&EIMSK,INT5);
	
	// Configures the TC1 Interrupt Mask Register
	// Overflow Interrupt Enable
	tc1_set_interruptMask(TC1_MASK_OVERFLOW);
	sei();
	
	//-----------------------------------------------


	do
	{		
		buttonsSequence();
		
		if ((!buttonStop) && (buttonStart))
		{
					// Initiate ultrasonic Module to send 10us pulse on Sonar Trigger pin
			bitTriggerSonar(&PORTE,PORTE6);
			
			// Displays the distance measured by the sensor
			get_UltrasonicDist();
			
		}
		

	} while (1);
	
}
