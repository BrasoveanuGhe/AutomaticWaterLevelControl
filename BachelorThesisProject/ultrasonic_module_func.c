/*
* ultrasonic_module_func.c
*
* Created: 8/1/2018 1:53:02 PM
*  Author: Gheorghita.Brasovean
*/



#include "ultrasonic_module_defines.h"
#include "ultrasonic_pins_defines.h"
#include "debouncing_control.h"
#include "avr_extInterrupt.h"
#include "lcd_defines.h"
#include "timers.h"


char string[20];
float distance;
volatile uint32_t count = 0;
volatile uint32_t TimerOverflow = 0;
bool checkSignalEdge = true;
bool detectFallingEdge = false;


inline void risingEdge_duration()
{
	// Represent the time when the echo signal was high
	count = ((TimerOverflow*TIMER_MAX)+tc1_get_current_cValue());	// Counter count
	distance = (count/(CONVERT_TO_CM*CYCLE_PER_US));		// Distance in cm
	
	// If the measured distance is less than 3, it will be 2
	/* MIN : 2 cm */
	if(distance < 3){
		distance = 2;
	}
	//If the measured distance is greater than 400, it will be 400
	/* MAX : 400 cm */
	else if(distance > 25){
		distance = 25;
	}
}


void get_UltrasonicDist()
{
	if(detectFallingEdge == true)
	{
		risingEdge_duration();	
		lcd_goToLine(2,12);
		dtostrf(distance, 6, 2, string);
		lcd_displayChar(string);	
		
		servoControlRotation();
		
		detectFallingEdge = false;
		checkSignalEdge = true;
	}
}


ISR(INT5_vect)
{
	// Rising Edge
	if (checkSignalEdge)									
	{
		//reset timer -> TCNT = 0
		tc1_set_current_cValue(0);							
		TimerOverflow = 0;
		// Reset EICRB register
		reset_extInterrupt_B();	
		// No prescaler					
		tc1_write_clock_source(TC1_CLKSEL_PS_1);
		/* Wait for falling edge */		
		set_extInterrupt(&EICRB,INT5,FALLING_EDGE_5);	
		checkSignalEdge = false;
	}
	// Falling edge
	else {													
		// Stop Timer
		tc_stopTimer(timer1);	
		// Reset EICRB register							
		reset_extInterrupt_B();								
		detectFallingEdge = true;
		/* Wait for rising edge */
		set_extInterrupt(&EICRB,INT5,RISING_EDGE_5);
		
	}
}


ISR(TIMER1_OVF_vect)
{
	//Counter that increments each time TCNT reaches the maximum value
	TimerOverflow ++;
}



