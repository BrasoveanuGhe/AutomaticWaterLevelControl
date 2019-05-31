/*
* ultrasonic_defines.h
*
* Created: 8/1/2018 11:04:58 AM
*  Author: Gheorghita.Brasovean
*/

#ifndef ULTRASONIC_DEFINES_H_
#define ULTRASONIC_DEFINES_H_


#include <avr/io.h>

typedef struct{
	
	volatile uint8_t *UltrasonicPort;
	uint8_t TRIG;
	uint8_t ECHO;
	uint8_t PULL;
	
   } UltrasonicPins;

UltrasonicPins ultrasonicInit;




/**
* \brief				Initiate ultrasonic Module port, TRIG pin and ECHO pin
*
* \param PORT			Port address
* \param TRIG_Pin		The pin on which the trigger signal is set
* \param ECHO_Pin		The pin on which the signal is received
*
* \return void
*/
void ultrasonicModule_init(volatile uint8_t *port, uint8_t trig_pin, uint8_t echo_pin);


/**
* \brief				Send 10us pulse on Sonar Trigger pin
*
* \param Port			Port address
* \param TRIG_Pin		Select the bit
*						1.   Clear trigger pin before sending a pulse
*						2.   Send high pulse to trigger pin for 10us
*						3.   Clear trigger pin to pull it trigger pin low
*
* \return void
*/
void bitTriggerSonar(volatile uint8_t *port, unsigned char TRIG_Pin );


//Gets value for distance and displays it on the series
void get_UltrasonicDist();


// The function calculates the time the signal received by echo was high
void risingEdge_duration();


#endif /* ULTRASONIC_DEFINES_H_ */