/*
* ultrasonic_func.c
*
* Created: 8/1/2018 11:18:29 AM
*  Author: Gheorghita.Brasovean
*/

#include "ultrasonic_pins_defines.h"
#include "stdutils.h"

#include <util/delay.h>


// Initiate ultrasonic Module port, TRIG pin direction (O) and ECHO pin direction (I)
void ultrasonicModule_init(volatile uint8_t *port, uint8_t trig_pin, uint8_t echo_pin)
{
	ultrasonicInit.UltrasonicPort = port;
	ultrasonicInit.TRIG = trig_pin;
	ultrasonicInit.ECHO = echo_pin;
	
	*(ultrasonicInit.UltrasonicPort-1) |= (1 << ultrasonicInit.TRIG);	 //Output
	*(ultrasonicInit.UltrasonicPort-1) &= ~(1 << ultrasonicInit.ECHO);	 // Input
}

		
// Initiate ultrasonic Module to send 10us pulse on Sonar Trigger pin
inline void bitTriggerSonar(volatile uint8_t *port, uint8_t trig_pin )
{
	ultrasonicInit.UltrasonicPort = port;
	ultrasonicInit.TRIG = trig_pin;

	*(ultrasonicInit.UltrasonicPort) &= ~(1 << ultrasonicInit.TRIG);	// Clear pin before setting it high
	_delay_us(1);														// Clear to zero and give time for electronics to set
	*(ultrasonicInit.UltrasonicPort) |= (1 << ultrasonicInit.TRIG);		// Set pin high
	_delay_us(10);														// Send high pulse for minimum 10us
	*(ultrasonicInit.UltrasonicPort) &= ~(1 << ultrasonicInit.TRIG);	// Clear pin
	_delay_us(1);
}



