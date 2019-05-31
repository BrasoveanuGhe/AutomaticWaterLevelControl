/*
* avr_timers.c
*
* Created: 10/11/2018 7:44:28 PM
*  Author: braso
*/


#include "timers.h"


/*Configures TC1 in the specified Waveform generator mode*/
inline void tc1_set_wgm(enum tc1_wg_mode_t wg_mode_enum)
{
	if (wg_mode_enum <= 0x07){
		
		TCCR1A |= (TCCR1A & ~((1<<WGM11)|(1<<WGM10))) | (wg_mode_enum & 0x03); // Mask then set WGM11, WGM10
		TCCR1B |= (TCCR1B & ~((1<<WGM13)|(1<<WGM12))) | (((wg_mode_enum >> 2) & 0x03) << WGM12); // Mask then set WGM13, WGM12
	}
	else if (wg_mode_enum <= 0x0B){
		
		TCCR1A |= (TCCR1A & ~((1<<WGM11)|(1<<WGM10))) | (wg_mode_enum & 0x03); // Mask then set WGM11, WGM10
		TCCR1B |= (TCCR1B & ~((1<<WGM13)|(1<<WGM12))) | ((wg_mode_enum << 1) & 0x11); // Mask then set WGM13, WGM12
	}
	else{
		
		TCCR1A |= (TCCR1A & ~((1<<WGM11)|(1<<WGM10))) | (wg_mode_enum & 0x03); // Mask then set WGM11, WGM10
		TCCR1B |= (TCCR1B & ~((1<<WGM13)|(1<<WGM12))) | ((wg_mode_enum << 1) & 0x18); // Mask then set WGM13, WGM12
	}
}


/*Configures TC3 in the specified Waveform generator mode*/
inline void tc3_set_wgm(enum tc3_wg_mode_t wg_mode_enum)
{
	if (wg_mode_enum <= 0x07){
		
		TCCR3A |= (TCCR3A & ~((1<<WGM11)|(1<<WGM10))) | (wg_mode_enum & 0x03); // Mask then set WGM11, WGM10
		TCCR3B |= (TCCR3B & ~((1<<WGM33)|(1<<WGM32))) | (((wg_mode_enum >> 2) & 0x03) << WGM32); // Mask then set WGM13, WGM12
	}
	else if (wg_mode_enum <= 0x0B){
		
		TCCR3A |= (TCCR3A & ~((1<<WGM11)|(1<<WGM10))) | (wg_mode_enum & 0x03); // Mask then set WGM11, WGM10
		TCCR3B |= (TCCR3B & ~((1<<WGM33)|(1<<WGM32))) | ((wg_mode_enum << 1) & 0x11); // Mask then set WGM13, WGM12
	}
	else{
		
		TCCR3A |= (TCCR3A & ~((1<<WGM11)|(1<<WGM10))) | (wg_mode_enum & 0x03); // Mask then set WGM11, WGM10
		TCCR3B |= (TCCR3B & ~((1<<WGM33)|(1<<WGM32))) | ((wg_mode_enum << 1) & 0x18); // Mask then set WGM13, WGM12
	}
}


/*Configures TC0 in the specified Waveform generator mode*/
void tc0_set_wgm(enum tc0_wg_mode_t wg_mode_enum)
{
	TCCR0 |= (TCCR0 & ~((1<<WGM01)|(1<<WGM00))) | (wg_mode_enum & 0x48); // Mask then set WGM01, WGM00
}


/*Configures TC2 in the specified Waveform generator mode*/
void tc2_set_wgm(enum tc2_wg_mode_t wg_mode_enum)
{
	TCCR2 |= (TCCR2 & ~((1<<WGM20)|(1<<WGM21))) | (wg_mode_enum & 0x48); // Mask then set WGM01, WGM00
}


/*Write the TC1 clock source*/
void tc1_write_clock_source(enum tc1_clksel_t tc_clksel_enum)
{
	TCCR1B |= (TCCR1B & ~((1<<CS12)|(1<<CS11)|(1<<CS10))) | tc_clksel_enum;
}


/*Write the TC3 clock source*/
void tc3_write_clock_source(enum tc3_clksel_t tc_clksel_enum)
{
	TCCR3B |= (TCCR3B & ~((1<<CS32)|(1<<CS31)|(1<<CS30))) | tc_clksel_enum;
}


/*Write the TC0 clock source*/
void tc0_write_clock_source(enum tc0_clksel_t tc_clksel_enum)
{
	TCCR0 |= (TCCR0 & ~((1<<CS02)|(1<<CS01)|(1<<CS00))) | tc_clksel_enum;
}


/*Write the TC0 clock source*/
void tc2_write_clock_source(enum tc2_clksel_t tc_clksel_enum)
{
	TCCR2 |= (TCCR2 & ~((1<<CS22)|(1<<CS21)|(1<<CS20))) | tc_clksel_enum;
}


/*Write the TC3 compare output mode*/
void tc1_write_ocom_mode(enum tc1_ocom_mode_t tc_ocom_enum)
{
	TCCR1A |= (TCCR1A & ~((1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0)|(1<<COM1C1)|(1<<COM1C0))) | tc_ocom_enum;
};


/*Write the TC3 compare output mode*/
void tc3_write_ocom_mode(enum tc3_ocom_mode_t tc_ocom_enum)
{
	TCCR3A |= (TCCR3A & ~((1<<COM3A1)|(1<<COM3A0)|(1<<COM3B1)|(1<<COM3B0)|(1<<COM3C1)|(1<<COM3C0))) | tc_ocom_enum;
};


/*Write the TC0 compare output mode*/
void tc0_write_ocom_mode(enum tc0_ocom_mode_t tc_ocom_enum)
{
	TCCR0 |= (TCCR0 & ~((1<<COM01)|(1<<COM00))) | tc_ocom_enum;
};


/*Write the TC2 compare output mode*/
void tc2_write_ocom_mode(enum tc2_ocom_mode_t tc_ocom_enum)
{
	TCCR2 |= (TCCR2 & ~((1<<COM21)|(1<<COM20))) | tc_ocom_enum;
};


/*Configures the TC1 Interrupt Mask Register*/
void tc1_set_interruptMask(enum tc1_interruptMask_R tc_interrupt_enum)
{
	TIMSK |= (TIMSK & ~((1<<TICIE1)|(1<<OCIE1A)|(1<<OCIE1B)|(1<<TOIE1))) | tc_interrupt_enum;
};


/*Configures the TC3 & TC1 Interrupt Mask Register*/
void tc3_set_interruptMask(enum tc3_interruptMask_R tc_interrupt_enum)
{
	ETIMSK |= (ETIMSK & ~((1<<TICIE3)|(1<<OCIE3A)|(1<<OCIE3B)|(1<<TOIE3)|(1<<OCIE3C)|(1<<OCIE1C))) | tc_interrupt_enum;
};


/*Configures the TC0 Interrupt Mask Register*/
void tc0_set_interruptMask(enum tc0_interruptMask_R tc_interrupt_enum)
{
	TIMSK |= (TIMSK & ~((1<<OCIE0)|(1<<TOIE0))) | tc_interrupt_enum;
};


/*Configures the TC2 Interrupt Mask Register*/
void tc2_set_interruptMask(enum tc2_interruptMask_R tc_interrupt_enum)
{
	TIMSK |= (TIMSK & ~((1<<OCIE2)|(1<<TOIE2))) | tc_interrupt_enum;
};


/*Reset the desired timer*/
void tc_resetTimer(unsigned char timer)
{
	if(timer == Timer0){
		TCNT0 = 0;
	}
	else if(timer == Timer1){
		TCNT1 = 0;
	}
	else if(timer == timer2){
		TCNT2 = 0;
	}
	else{
		TCNT3 = 0;
	}
}


/*Stop the timer*/
void tc_stopTimer(volatile uint16_t timer)   //TESTEAZA FUNCTIA
{

	if(timer == timer0){
		TCCR0 |= (TCCR0 & ~((1<<CS02)|(1<<CS01)|(1<<CS00)));
	}
	else if(timer == timer1){
		TCCR1B |= (TCCR1B & ~((1<<CS12)|(1<<CS11)|(1<<CS10)));
	}
	else if(timer == timer2){
		TCCR2 |= (TCCR2 & ~((1<<CS22)|(1<<CS21)|(1<<CS20)));
	}
	else{
		TCCR3B |= (TCCR3B & ~((1<<CS32)|(1<<CS31)|(1<<CS30)));
	}
}


// Initialize the counter value TCNT1
inline void tc1_set_current_cValue(unsigned short counterVal)
{
	TCNT1 = counterVal;
}


// Initialize the counter value TCNT3
inline void tc3_set_current_cValue(unsigned short counterVal)
{
	TCNT3 = counterVal;
}


// Initialize the counter value TCNT0
inline void tc0_set_current_cValue(unsigned char counterVal)
{
	TCNT0 = counterVal;
}


// Initialize the counter value TCNT2
inline void tc2_set_current_cValue(unsigned char counterVal)
{
	TCNT2 = counterVal;
}


/* Read the counter value TCNT1
Represents the value at which TCNT1 remained */
inline unsigned short tc1_get_current_cValue()
{
	unsigned short counterVal = TCNT1;
	return counterVal;
}


/* Read the counter value TCNT3
Represents the value at which TCNT3 remained */
inline unsigned short tc3_get_current_cValue()
{
	unsigned short counterVal = TCNT3;
	return counterVal;
}


/* Read the counter value TCNT0
Represents the value at which TCNT0 remained */
inline unsigned char tc0_get_current_cValue()
{
	unsigned char counterVal = TCNT0;
	return counterVal;
}


/* Read the counter value TCNT2
Represents the value at which TCNT2 remained */
inline unsigned char tc2_get_current_cValue()
{
	unsigned char counterVal = TCNT2;
	return counterVal;
}