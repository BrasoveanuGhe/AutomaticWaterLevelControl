/*
 * servo_defines.h
 *
 * Created: 11/12/2018 8:51:52 PM
 *  Author: braso
 */ 


#ifndef SERVO_DEFINES_H_
#define SERVO_DEFINES_H_

#include <avr/interrupt.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "gpio.h"
#include "timers.h"

extern double dutyCycle;
extern double servoPosition;

typedef struct
{
	volatile uint8_t *servoPort;

}servo_portDir;



/***************************************************************************************************
 * description : This function sets the servo motor pwm.   
 
  * I/P Arguments:
					 PORT:		Represents the port direction for which the PWM is set.
					 pinNumber:	The variable used to set the desired pin.            

 * Return value    : none
 ***************************************************************************************************/
void pwm_InitServoMotor(volatile uint8_t *port, unsigned char pinNumber);




/***************************************************************************************************
 * description :  Set TOP count for timer (16-bit) in ICRn register,
				  so the timer will count from 0 to ICRn (TOP Value)
				  
 * I/P Arguments:
				  TIMER:	The variable used to specify the desired timer.
				  topValue:	The variable used to set the TOP count for timer.
		               
 * Return value    : none
***************************************************************************************************/
uint16_t set_topValuePWM(unsigned char timer, unsigned short topValue);




/***************************************************************************************************
 * description :   Load OCRn register values to get compare match at the desired duty cycle
				   
				  
 * I/P Arguments:
				  TIMER:		The variable used to specify the desired timer.
				  positionValue:	The variable used to obtain the position of servo motor in degrees 
		               
 * Return value    : none
***************************************************************************************************/
void set_ServoPosition(unsigned char timer, unsigned short positionValue);



#endif /* SERVO_DEFINES_H_ */
