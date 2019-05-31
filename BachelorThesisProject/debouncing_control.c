/*
 * debouncing.c
 *
 * Created: 5/29/2019 6:12:34 PM
 *  Author: braso
 */ 


#include "ultrasonic_module_defines.h"
#include "debouncing_control.h"
#include "avr_extInterrupt.h"
#include "servo_defines.h"
#include "lcd_defines.h"
#include "timers.h"



bool buttonPressed = false;
bool checkButton1 = false;
bool checkButton2 = false;
bool checkButton3 = false;
bool buttonStart = false;
bool buttonStop = true;


void checkWaterLvl()
{
	float i;
	i = distance;
	float j = i;
	
	lcd_goToLine(4,1);
	lcd_displayChar("Bazin 50% : ");
	lcd_goToLine(4,12);
	dtostrf(j, 4, 2, string);	
	lcd_displayChar(string);
}


void servoControlRotation()
{
	if(distance >= 8.8){
 		
 		set_ServoPosition(timer3,170);					/*90 degree -> the actuator is closed*/
 		PORTB = (1 << PORTB4) | (0 << PORTB3);			/*the motor is on*/
 	}
 	
 	/*	the size of the water tank is -> 17.13 cm
 	
 		50% from 17.13 -> ( 50/100 ) * 17.13 = x 
 							0.5 * 17.13 = x
 							x = 8.56 (represents 50% of the water tank)
 	*/
 	if((distance <= 8.8) && (distance >= 8.6)){	
 		
 		set_ServoPosition(timer3,170);					/*90 degree -> the actuator is closed*/
 		PORTB = (0 << PORTB4) | (0 << PORTB3);			/*the motor is closed*/
 		
 		checkWaterLvl();			
 	}
 	
 	if(distance <= 8.6){
 		
 		set_ServoPosition(timer3,115);					/*45 degree -> the actuator is open*/
 		PORTB = (0 << PORTB4) | (0 << PORTB3);			/*the motor is closed*/
 	}		
}


void debauncingTimer()
{
	// Set CTC mode and stop the timer
	tc2_set_wgm(TC2_WG_CTC);
	tc_stopTimer(timer2);
	
	// Set the start value of the counter
	tc2_set_current_cValue(0);
	
	// After 0.1s generate the interrupt
	OCR2 = 216;			//216 - 0.03s  //72 - 0.01s
	
	// Output Compare Match Interrupt Enable
	tc2_set_interruptMask(TC2_MASK_OUTPUT);

}


void setButtonState()
{	
	// Make the all buttons as input
	DDRD = (0 << DDRD1) | (0 << DDRD2) | (0 << DDRD3);
	
	// Set pull-up resistors
	PORTD = (1 << PORTD1) | (1 << PORTD2) | (1 << PORTD3);
	
	// Generate interrupt at falling-edge
	EICRA = (1 << ISC31) | (0 << ISC30) | (1 << ISC21) | (0 << ISC20) | (1 << ISC11) | (0 << ISC10);
	
	// Activate external interrupt
	EIMSK |= (1 << INT3) | (1 << INT2) | (1 << INT1);
}


void buttonsSequence()
{
	if((buttonPressed) && (checkButton1) && ((PIND & (1 << PIND1)) == 0))  // START
	{
		lcd_clear();
		checkButton1 = false;
		buttonPressed = false;
		
		lcd_goToLine(2,1);
		lcd_displayChar("|");
		lcd_goToLine(1,1);
		lcd_displayChar("--------------------");
		lcd_goToLine(2,3);
		lcd_displayChar("DISTANCE:");
		lcd_goToLine(3,1);
		lcd_displayChar("--------------------");
		lcd_goToLine(2,20);
		lcd_displayChar("|");
			
		gpio_pinWrite(&PORTB,PORTB4,LOW);					/*the motor is closed*/
	
		buttonStart = true;
		buttonStop = false;
	}
	
	if((buttonPressed) && (checkButton2) && ((PIND & (1 << PIND2)) == 0))  // STOP
	{
		lcd_clear();
		checkButton2 = false;
		buttonPressed = false;
		
		lcd_goToLine(2,1);
		lcd_displayChar("|");
		lcd_goToLine(1,1);
		lcd_displayChar("--------------------");
		lcd_goToLine(2,9);
		lcd_displayChar("STOP");
		lcd_goToLine(3,1);
		lcd_displayChar("--------------------");
		lcd_goToLine(2,20);
		lcd_displayChar("|");
		
		set_ServoPosition(timer3,170);
		gpio_pinWrite(&PORTB,PORTB4,LOW);					/*the motor is closed*/
		
		buttonStop = true;
		buttonStart = false;
	}
	
	if((buttonPressed) && (checkButton3) && ((PIND & (1 << PIND3)) == 0)) // EVACUARE
	{
		lcd_clear();
		checkButton3 = false;
		buttonPressed = false;
		
		lcd_goToLine(2,1);
		lcd_displayChar("|");
		lcd_goToLine(1,1);
		lcd_displayChar("--------------------");
		lcd_goToLine(2,6);
		lcd_displayChar("EVACUARE");
		lcd_goToLine(3,1);
		lcd_displayChar("--------------------");
		lcd_goToLine(2,20);
		lcd_displayChar("|");
		
		set_ServoPosition(timer3,57);
		gpio_pinWrite(&PORTB,PORTB4,LOW);					/*the motor is closed*/
				
		buttonStop = true;
		buttonStart = false;
	}
}


ISR(TIMER2_COMP_vect)
{
	buttonPressed = true;
	TCCR2 = (1 << WGM21) | (0 << CS22) | (0 << CS21) | (0 << CS20);
}


ISR(INT1_vect)
{
	checkButton1 = true;
	TCNT2 = 0;
	TCCR2 |= (1 << CS22) | (0 << CS21) | (1 << CS20);
}


ISR(INT2_vect)
{
	checkButton2 = true;
	TCNT2 = 0;
	TCCR2 |= (1 << CS22) | (0 << CS21) | (1 << CS20);
}


ISR(INT3_vect)
{
	checkButton3 = true;
	TCNT2 = 0;
	TCCR2 |= (1 << CS22) | (0 << CS21) | (1 << CS20);
}