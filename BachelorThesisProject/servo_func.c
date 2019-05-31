/*
* servo_func.c
*
* Created: 11/12/2018 8:51:34 PM
*  Author: braso
*/

#include "servo_defines.h"

#include "timers.h"

double dutyCycle = 0;
double servoPosition = 0;


/* Set TOP count for timer (16-bit) */
uint16_t set_topValuePWM(unsigned char timer, unsigned short topValue)
{	
	if (timer == timer1){
		
		ICR1 = topValue;
		
		return ICR1;
	}
	else if (timer == timer3){
		
		ICR3 = topValue;
		
		return ICR3;
	}
	else{
		return 0;
	}
}



/**************************************************************************************** 
*	To calculate the duty cycle specific to the desired angle, use the formula:

	** DC = TW / T * 100%    where:		DC = duty cycle
										TW = pulse width
										T  = period
										
		
*	Duty cycle you can calculate by putting the calculated value in OCRn registers
	Formula:
	
	** OCRn = ICR / (100/DC)  where:	ICR = the top value that was set in 
													  the set_topValuePWM function
										DC = the value obtained above for the duty cycle		
		
******************************************************************************************/
void set_ServoPosition(unsigned char timer, unsigned short positionValue)
{
	
	if (timer == timer1){

		/* To compare other output modes, change the value in OCRn (A,B,C) */
		OCR1A = positionValue;
	}
	else if(timer == timer3){
		/* To compare other output modes, change the value in OCRn (A,B,C) */
 		
 		OCR3A = positionValue;
	}

}



/* Set fast PWM mode with non-inverted output (Timer3) */
void pwm_InitServoMotor(volatile uint8_t *port, unsigned char pinNumber)
{
	servo_portDir portInit;
	
	portInit.servoPort = port;	
	
	*(portInit.servoPort-1) |= (1 << pinNumber);
	
	// Compare Output Mode for Channel A -> pin PE3
	if(pinNumber == PORTE3)							
	{
		tc3_set_wgm(TC3_WG_FS4_PWM_ICRn);			// Fast-PWM mode
		tc3_write_ocom_mode(TC3_OCOMA_CLEAR);		// Non-Inverting PWM output
		tc3_write_clock_source(TC3_CLKSEL_PS_64);	// 64-prescaler
		tc3_set_current_cValue(0);					// set TCNT3 value
		
		set_topValuePWM(timer3,2303);				// PWM-50hz
	}
	
	// Compare Output Mode for Channel A -> pin PB5
	else if (pinNumber == PORTB5)
	{
		tc1_set_wgm(TC3_WG_FS4_PWM_ICRn);			// Fast-PWM mode
		tc1_write_ocom_mode(TC1_OCOMA_CLEAR);		// Non-Inverting PWM output
		tc1_write_clock_source(TC1_CLKSEL_PS_64);	// 64 - prescaler
		tc1_set_current_cValue(0);					// set TCNT1 value
		
		set_topValuePWM(timer1,2303);				// PWM-50hz
		
	}	
}