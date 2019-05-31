/*
* avr_timers.h
*
* Created: 10/11/2018 7:44:41 PM
*  Author: braso
*/


#ifndef AVR_TIMERS_H_
#define AVR_TIMERS_H_

#include <avr/interrupt.h>
#include "stdutils.h"


//! Timer1 Counter Waveform Generator modes
enum tc1_wg_mode_t {
	//! TC in normal Mode
	TC1_WG_NORMAL = 0x00, // TC in normal Mode
	//! TC in Phase Correct PWM Mode 1	(8 - bit)
	TC1_WG_PC1_PWD = 0x01,
	//! TC in Phase Correct PWM Mode 2	(9 - bit)
	TC1_WG_PC2_PWD = 0x02,
	//! TC in Phase Correct PWM Mode 3	(10 - bit)
	TC1_WG_PC3_PWD = 0x03,
	//! TC in Clear Timer on Compare Match (CTC) Mode match OCRnA
	TC1_WG_CTC_OCR1A = 0x04,
	//! TC in Fast PWM Mode 1	(8 - bit)
	TC1_WG_FS1_PWM = 0x05,
	//! TC in Fast PWM Mode 2	(9 - bit)
	TC1_WG_FS2_PWM = 0x06,
	//! TC in Fast PWM Mode 3	(10 - bit)
	TC1_WG_FS3_PWM = 0x07,
	//! TC in Phase and Frequency Correct PWM (ICRn)
	TC1_WG_PFC_PWM_I = 0x08,
	//! TC in Phase and Frequency Correct PWM (OCRnA)
	TC1_WG_PFC_PWM_O = 0x09,
	//! TC in Phase Correct PWM Mode 4	(ICRn)
	TC1_WG_PC4_PWD = 0x0A,
	//! TC in Phase Correct PWM Mode 5	(OCRnA)
	TC1_WG_PC5_PWD = 0x0B,
	//! TC in Clear Timer on Compare Match (CTC) Mode match ICRn
	TC1_WG_CTC_ICR1 = 0x0C,
	//! TC in Fast PWM Mode 4	(ICRn)
	TC1_WG_FS4_PWM_ICRn = 0x0E,
	//! TC in Fast PWM Mode	5	(OCRnA)
	TC1_WG_FS5_PWM_OCRn = 0x0F,
};


//! Timer3 Counter Waveform Generator modes
enum tc3_wg_mode_t {
	//! TC in normal Mode
	TC3_WG_NORMAL = 0x00, // TC in normal Mode
	//! TC in Phase Correct PWM Mode 1	(8 - bit)
	TC3_WG_PC1_PWD = 0x01,
	//! TC in Phase Correct PWM Mode 2	(9 - bit)
	TC3_WG_PC2_PWD = 0x02,
	//! TC in Phase Correct PWM Mode 3	(10 - bit)
	TC3_WG_PC3_PWD = 0x03,
	//! TC in Clear Timer on Compare Match (CTC) Mode match OCRnA
	TC3_WG_CTC_OCR1A = 0x04,
	//! TC in Fast PWM Mode 1	(8 - bit)
	TC3_WG_FS1_PWM = 0x05,
	//! TC in Fast PWM Mode 2	(9 - bit)
	TC3_WG_FS2_PWM = 0x06,
	//! TC in Fast PWM Mode 3	(10 - bit)
	TC3_WG_FS3_PWM = 0x07,
	//! TC in Phase and Frequency Correct PWM (ICRn)
	TC3_WG_PFC_PWM_I = 0x08,
	//! TC in Phase and Frequency Correct PWM (OCRnA)
	TC3_WG_PFC_PWM_O = 0x09,
	//! TC in Phase Correct PWM Mode 4	(ICRn)
	TC3_WG_PC4_PWD = 0x0A,
	//! TC in Phase Correct PWM Mode 5	(OCRnA)
	TC3_WG_PC5_PWD = 0x0B,
	//! TC in Clear Timer on Compare Match (CTC) Mode match ICRn
	TC3_WG_CTC_ICR1 = 0x0C,
	//! TC in Fast PWM Mode 4	(ICRn)
	TC3_WG_FS4_PWM_ICRn = 0x0E,
	//! TC in Fast PWM Mode	5	(OCRnA)
	TC3_WG_FS5_PWM_OCRn = 0x0F,
};


//! Timer0 Counter Waveform Generator modes
enum tc0_wg_mode_t {
	//! TC in normal Mode
	TC0_WG_NORMAL = 0x00, // TC in normal Mode
	//! TC in Phase Correct PWM Mode
	TC0_WG_PC_PWM = 0x08,
	//! TC in Clear Timer on Compare Match (CTC) Mode match OCR0
	TC0_WG_CTC = 0x40,
	//! TC in Fast PWM Mode
	TC0_WG_FS_PWM = 0x48,
};


//! Timer2 Counter Waveform Generator modes
enum tc2_wg_mode_t {
	//! TC in normal Mode
	TC2_WG_NORMAL = 0x00, // TC in normal Mode
	//! TC in Phase Correct PWM Mode
	TC2_WG_PC_PWM = 0x08,
	//! TC in Clear Timer on Compare Match (CTC) Mode match OCR0
	TC2_WG_CTC = 0x40,
	//! TC in Fast PWM Mode
	TC2_WG_FS_PWM = 0x48,
};


// Timer1 Counter Clock selection
enum tc1_clksel_t {
	
	// No clock source (Timer/Counter stopped)
	TC1_CLKSEL_NOCLK = 0x00,
	// clkI/O/1(No prescaling)
	TC1_CLKSEL_PS_1 = 0x01,
	// clkI/O/8 (From prescaler)
	TC1_CLKSEL_PS_8 = 0x02,
	// clkI/O/64 (From prescaler)
	TC1_CLKSEL_PS_64 = 0x03,
	// clkI/O/256 (From prescaler)
	TC1_CLKSEL_PS_256 = 0x04,
	// clkI/O/1024 (From prescaler)
	TC1_CLKSEL_PS_1024 = 0x05,
	// External clock source on Tn pin. Clock on falling edge.
	TC1_CLKSEL_EXT_FALLING = 0x06,
	// External clock source on Tn pin. Clock on rising edge.
	TC1_CLKSEL_EXT_RISING = 0x07
};


// Timer3 Counter Clock selection
enum tc3_clksel_t {
	
	// No clock source (Timer/Counter stopped)
	TC3_CLKSEL_NOCLK = 0x00,
	// clkI/O/1(No prescaling)
	TC3_CLKSEL_PS_1 = 0x01,
	// clkI/O/8 (From prescaler)
	TC3_CLKSEL_PS_8 = 0x02,
	// clkI/O/64 (From prescaler)
	TC3_CLKSEL_PS_64 = 0x03,
	// clkI/O/256 (From prescaler)
	TC3_CLKSEL_PS_256 = 0x04,
	// clkI/O/1024 (From prescaler)
	TC3_CLKSEL_PS_1024 = 0x05,
	// External clock source on Tn pin. Clock on falling edge.
	TC3_CLKSEL_EXT_FALLING = 0x06,
	// External clock source on Tn pin. Clock on rising edge.
	TC3_CLKSEL_EXT_RISING = 0x07
};


// Timer0 Counter Clock selection
enum tc0_clksel_t {
	
	// No clock source (Timer/Counter stopped)
	TC0_CLKSEL_NOCLK = 0x00,
	// clkI/O/(No prescaling)
	TC0_CLKSEL_PS_1 = 0x01,
	// clkI/O/8 (From prescaler)
	TC0_CLKSEL_PS_8 = 0x02,
	// clkI/O/32 (From prescaler)
	TC0_CLKSEL_PS_32 = 0x03,
	// clkI/O/64 (From prescaler)
	TC0_CLKSEL_PS_64 = 0x04,
	// clkI/O/128 (From prescaler)
	TC0_CLKSEL_PS_128 = 0x05,
	// clkI/O/256 (From prescaler)
	TC0_CLKSEL_PS_256 = 0x06,
	// clkI/O/1024 (From prescaler)
	TC0_CLKSEL_PS_1024 = 0x07
};


// Timer2 Counter Clock selection
enum tc2_clksel_t {
	
	// No clock source (Timer/Counter stopped)
	TC2_CLKSEL_NOCLK = 0x00,
	// clkI/O/(No prescaling)
	TC2_CLKSEL_PS_1 = 0x01,
	// clkI/O/8 (From prescaler)
	TC2_CLKSEL_PS_8 = 0x02,
	// clkI/O/64 (From prescaler)
	TC2_CLKSEL_PS_64 = 0x03,
	// clkI/O/256 (From prescaler)
	TC2_CLKSEL_PS_256 = 0x04,
	// clkI/O/1024 (From prescaler)
	TC2_CLKSEL_PS_1024 = 0x05,
	// External clock source on T2 pin. Clock on falling edge.
	TC2_CLKSEL_EXT_FALLING = 0x06,
	// External clock source on T2 pin. Clock on rising edge. ??? Datasheet gresit ? (Risinf sau falling)
	TC2_CLKSEL_EXT_RISING = 0x07
};


// Timer1 Compare Output Mode
enum tc1_ocom_mode_t{
 
	/************************************************************************************************
							NORMAL PORT OPERATION FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Normal port operation, OCnA/OCnB/OCnC disconnected)*/
	/*Fast PWM Mode ->			(Normal port operation, OCnA/OCnB/OCnC disconnected)*/
	/*Phase Correct PWM ->		(Normal port operation, OCnA/OCnB/OCnC disconnected)*/
	TC1_OCOMA_NORMAL = 0x00,
	TC1_OCOMB_NORMAL = 0x00,
	TC1_OCOMC_NORMAL = 0x00,

	/************************************************************************************************
							TOGGLE ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Toggle OCnA/OCnB/OCnC on compare match)*/
	/*Fast PWM Mode ->			(WGMn3:0 = 15: Toggle OCnA on Compare Match, OCnB/OCnC disconnected (normal port operation))*/
	/*Phase Correct PWM ->		(WGMn3:0 = 9 or 11: Toggle OCnA on Compare Match, OCnB/ OCnC disconnected (normal port operation))*/
	TC1_OCOMA_TOGGLE = 0x40,
	TC1_OCOMB_TOGGLE = 0x10,
	TC1_OCOMC_TOGGLE = 0x04,

	/************************************************************************************************
							CLEAR ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Clear OCnA/OCnB/OCnC on compare match)*/
	/*Fast PWM Mode ->			(Clear OCnA/OCnB/OCnC on compare match, set OCnA/OCnB/OCnC at BOTTOM, (non-inverting mode))*/
	/* Phase Correct PWM ->		(Clear OCnA/OCnB/OCnC on compare match when up-counting
									Set OCnA/OCnB/OCnC on compare match when down-counting )*/
	TC1_OCOMA_CLEAR = 0x80,
	TC1_OCOMB_CLEAR = 0x20,
	TC1_OCOMC_CLEAR = 0x08,

	/************************************************************************************************
							SET ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Set OCnA/OCnB/OCnC on compare match (set output to high level))*/
	/*Fast PWM Mode ->			(Set OCnA/OCnB/OCnC on compare match, clear OCnA/OCnB/OCnC at BOTTOM, (inverting mode))*/
	/* Phase Correct PWM ->		(Set OCnA/OCnB/OCnC on compare match when up-counting
									Clear OCnA/OCnB/OCnC on compare match when down-counting ) */
	TC1_OCOMA_SET = 0xC0,
	TC1_OCOMB_SET = 0x30,
	TC1_OCOMC_SET = 0x0C,
};


// Timer3 Compare Output Mode
enum tc3_ocom_mode_t{
		
	/************************************************************************************************
							NORMAL PORT OPERATION FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Normal port operation, OCnA/OCnB/OCnC disconnected)*/
	/*Fast PWM Mode ->			(Normal port operation, OCnA/OCnB/OCnC disconnected)*/
	/*Phase Correct PWM ->		(Normal port operation, OCnA/OCnB/OCnC disconnected)*/
	TC3_OCOMA_NORMAL = 0x00,
	TC3_OCOMB_NORMAL = 0x00,
	TC3_OCOMC_NORMAL = 0x00,
	
	/************************************************************************************************
							TOGGLE ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Toggle OCnA/OCnB/OCnC on compare match)*/
	/*Fast PWM Mode ->			(WGMn3:0 = 15: Toggle OCnA on Compare Match, OCnB/OCnC disconnected (normal port operation))*/
	/*Phase Correct PWM ->		(WGMn3:0 = 9 or 11: Toggle OCnA on Compare Match, OCnB/ OCnC disconnected (normal port operation))*/	
	TC3_OCOMA_TOGGLE = 0x40,
	TC3_OCOMB_TOGGLE = 0x10,
	TC3_OCOMC_TOGGLE = 0x04,
		
	/************************************************************************************************
							CLEAR ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Clear OCnA/OCnB/OCnC on compare match)*/
	/*Fast PWM Mode ->			(Clear OCnA/OCnB/OCnC on compare match, set OCnA/OCnB/OCnC at BOTTOM, (non-inverting mode))*/
	/* Phase Correct PWM ->		(Clear OCnA/OCnB/OCnC on compare match when up-counting
									Set OCnA/OCnB/OCnC on compare match when down-counting )*/
	TC3_OCOMA_CLEAR = 0x80,		
	TC3_OCOMB_CLEAR = 0x20,		
	TC3_OCOMC_CLEAR = 0x08,		

	/************************************************************************************************
							SET ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM Mode ->			(Set OCnA/OCnB/OCnC on compare match (set output to high level))*/
	/*Fast PWM Mode ->			(Set OCnA/OCnB/OCnC on compare match, clear OCnA/OCnB/OCnC at BOTTOM, (inverting mode))*/
	/* Phase Correct PWM ->		(Set OCnA/OCnB/OCnC on compare match when up-counting
									Clear OCnA/OCnB/OCnC on compare match when down-counting ) */								
	TC3_OCOMA_SET = 0xC0,		
	TC3_OCOMB_SET = 0x30,		
	TC3_OCOMC_SET = 0x0C,		
								
};


// Timer0 Compare Output Mode
enum tc0_ocom_mode_t{

	/************************************************************************************************
							NORMAL PORT OPERATION FOR ALL CHANNEL
	************************************************************************************************/ 
	/* Non-PWM MODE ->			(Normal port operation, OC0 disconnected)*/
	/* Fast PWM Mode ->			(Normal port operation, OC0 disconnected)*/
	/* Phase Correct PWM ->		(Normal port operation, OC0 disconnected)*/
	TC0_OCOM0_NORMAL = 0x00,

	/************************************************************************************************
							TOGGLE ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/* Non-PWM MODE ->			(Toggle OC0 on Compare Match)*/
	/* Fast PWM Mode ->			(Reserved)*/
	/* Phase Correct PWM ->		(Reserved)*/
	TC0_OCOM0_TOGGLE = 0x10,

	/************************************************************************************************
							CLEAR ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/* Non-PWM MODE ->			(Clear OC0 on Compare Match)*/
	/* Fast PWM Mode ->			(Clear OC0 on Compare Match, set OC0 at BOTTOM, (non-inverting mode)) */
	/* Phase Correct PWM ->		(Clear OC0 on Compare Match when up-counting. Set OC0 on Compare Match when downcounting)*/
	TC0_OCOM0_CLEAR = 0x20,

	/************************************************************************************************
							SET ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM MODE ->			(Set OC0 on Compare Match)*/
	/*Fast PWM Mode ->			(Set OC0 on Compare Match, clear OC0 at BOTTOM, (inverting mode))*/
	/*Phase Correct PWM ->		(Set OC0 on Compare Match when up-counting. Clear OC0 on Compare Match when downcounting)*/
	TC0_OCOM0_SET = 0x30,

};


// Timer2 Compare Output Mode
enum tc2_ocom_mode_t{

	/************************************************************************************************
							NORMAL PORT OPERATION FOR ALL CHANNEL
	************************************************************************************************/ 
	/* Non-PWM MODE ->			(Normal port operation, OC2 disconnected)*/
	/* Fast PWM Mode ->			(Normal port operation, OC2 disconnected)*/
	/* Phase Correct PWM ->		(Normal port operation, OC2 disconnected)*/
	TC2_OCOM2_NORMAL = 0x00,
	
	/************************************************************************************************
							TOGGLE ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/* Non-PWM MODE ->			(Toggle OC2 on Compare Match)*/
	/* Fast PWM Mode ->			(Reserved)*/
	/* Phase Correct PWM ->		(Reserved)*/
	TC2_OCOM2_TOGGLE = 0x10,
	
	/************************************************************************************************
							CLEAR ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/* Non-PWM MODE ->			(Clear OC2 on Compare Match)*/
	/* Fast PWM Mode ->			(Clear OC2 on Compare Match, set OC2 at BOTTOM, (non-inverting mode)) */
	/* Phase Correct PWM ->		(Clear OC2 on Compare Match when up-counting. Set OC2 on Compare Match when downcounting)*/
	TC2_OCOM2_CLEAR = 0x20,
	
	/************************************************************************************************
							SET ON COMPARE MATCH FOR ALL CHANNEL
	************************************************************************************************/ 
	/*Non-PWM MODE ->			(Set OC2 on Compare Match)*/
	/*Fast PWM Mode ->			(Set OC2 on Compare Match, clear OC2 at BOTTOM, (inverting mode))*/
	/*Phase Correct PWM ->		(Set OC2 on Compare Match when up-counting. Clear OC2 on Compare Match when downcounting)*/
	TC2_OCOM2_SET = 0x30,
};


//Timer/Counter Interrupt Mask Register (Timer1)
enum tc1_interruptMask_R{

	// Timer/Counter1, Input Capture Interrupt Enable
	TC1_MASK_INPUT = 0x20,
	// Timer/Counter1, Output Compare A Match Interrupt Enable
	TC1_MASK_OUTPUT_A = 0x10,
	// Timer/Counter1, Output Compare B Match Interrupt Enable
	TC1_MASK_OUTPUT_B = 0x08,
	// Timer/Counter1, Overflow Interrupt Enable
	TC1_MASK_OVERFLOW = 0x04,
};


//Extended Timer/Counter Interrupt Mask Register (Timer3)
enum tc3_interruptMask_R{

	// Timer/Counter3, Input Capture Interrupt Enable
	TC3_MASK_INPUT = 0x20,
	// Timer/Counter3, Output Compare A Match Interrupt Enable
	TC3_MASK_OUTPUT_A = 0x10,
	// Timer/Counter3, Output Compare B Match Interrupt Enable
	TC3_MASK_OUTPUT_B = 0x08,
	// Timer/Counter3, Overflow Interrupt Enable
	TC3_MASK_OVERFLOW = 0x04,
	// Timer/Counter3, Output Compare C Match Interrupt Enable
	TC3_MASK_OUTPUT_C = 0x02,
	// Timer/Counter1, Output Compare C Match Interrupt Enable
	TC1_MASK_OUTPUT_C = 0x01,
};


//Timer/Counter Interrupt Mask Register	(Timer0)
enum tc0_interruptMask_R{

	// Timer/Counter0 Output Compare Match Interrupt Enable
	TC0_MASK_OUTPUT = 0x02,
	// Timer/Counter0 Overflow Interrupt Enable
	TC0_MASK_OVERFLOW = 0x01,
};


//Timer/Counter Interrupt Mask Register (Timer2)
enum tc2_interruptMask_R{
	
	// Timer/CounterTimer/Counter2 Output Compare Match Interrupt Enable
	TC2_MASK_OUTPUT = 0x80,
	// Timer/CounterTimer/Counter2 Overflow Interrupt Enable
	TC2_MASK_OVERFLOW = 0x40,
};


/**
* \brief			* Configures TC1 in the specified Waveform generator mode
*
* \param			 wg_mode_enum : waveform generator
*					 specific mode begins with: TC1_WG_
*/
void tc1_set_wgm(enum tc1_wg_mode_t wg_mode_enum);


/**
* \brief			* Configures TC3 in the specified Waveform generator mode
*
* \param			wg_mode_enum : waveform generator
*					specific mode begins with: TC3_WG_
*/
void tc3_set_wgm(enum tc3_wg_mode_t wg_mode_enum);


/**
* \brief			* Configures TC0 in the specified Waveform generator mode
*
* \param			wg_mode_enum : waveform generator
*					specific mode begins with: TC0_WG_
*/
void tc0_set_wgm(enum tc0_wg_mode_t wg_mode_enum);


/**
* \brief			* Configures TC2 in the specified Waveform generator mode
*
* \param			wg_mode_enum : waveform generator
*					specific mode begins with: TC2_WG_
*/
void tc2_set_wgm(enum tc2_wg_mode_t wg_mode_enum);


/**
* \brief			 * Write the TC1 clock source
*
* \param			tc_clksel_enum : clock source
*					specific mode begins with: TC1_CLKSEL_
*/
void tc1_write_clock_source(enum tc1_clksel_t tc_clksel_enum);


/**
* \brief			 * Write the TC3 clock source
*
* \param			tc_clksel_enum : clock source
*					specific mode begins with: TC3_CLKSEL_
*/
void tc3_write_clock_source(enum tc3_clksel_t tc_clksel_enum);


/**
* \brief			 * Write the TC0 clock source
*
* \param			tc_clksel_enum : clock source
*					specific mode begins with: TC0_CLKSEL_
*/
void tc0_write_clock_source(enum tc0_clksel_t tc_clksel_enum);


/**
* \brief			 * Write the TC2 clock source
*
* \param			tc_clksel_enum : clock source
*					specific mode begins with: TC2_CLKSEL_
*/
void tc2_write_clock_source(enum tc2_clksel_t tc_clksel_enum);


/**
* \brief						* Write the TC1 compare output mode
*
* \param tc_ocom_enum			- TC1_OCOMA_NORMAL || TOGGLE || CLEAR || SET
* 								- TC1_OCOMB_NORMAL || TOGGLE || CLEAR || SET
*								- TC1_OCOMC_NORMAL || TOGGLE || CLEAR || SET
*
*/
void tc1_write_ocom_mode(enum tc1_ocom_mode_t tc_ocom_enum);


/**
* \brief						* Write the TC3 compare output mode
*
* \param tc_ocom_enum			- TC3_OCOMA_NORMAL || TOGGLE || CLEAR || SET
* 								- TC3_OCOMB_NORMAL || TOGGLE || CLEAR || SET
*								- TC3_OCOMC_NORMAL || TOGGLE || CLEAR || SET
*
*/
void tc3_write_ocom_mode(enum tc3_ocom_mode_t tc_ocom_enum);


/**
* \brief						* Write the TC0 compare output mode
*
* \param tc_ocom_enum			- TC0_OCOM0_NORMAL || TOGGLE || CLEAR || SET
*
*/
void tc0_write_ocom_mode(enum tc0_ocom_mode_t tc_ocom_enum);


/**
* \brief						* Write the TC2 compare output mode
*
* \param tc_ocom_enum			- TC2_OCOM2_NORMAL || TOGGLE || CLEAR || SET
*
*/
void tc2_write_ocom_mode(enum tc2_ocom_mode_t tc_ocom_enum);


/**
 * \brief				* Configures the TC1 Interrupt Mask Register
 * 
 * \param				tc_interrupt_enum : type of interrupt
 *						specific mode begins with: TC1_MASK_
 *
 */
void tc1_set_interruptMask(enum tc1_interruptMask_R tc_interrupt_enum);


/**
 * \brief				* Configures the TC3 Interrupt Mask Register
 * 
 * \param				tc_interrupt_enum : type of interrupt
 *						specific mode begins with: TC3_MASK_
 *						IMPORTANT !! 
 *						This method also contains the mask to activate: Timer/Counter1, Output Compare C Match 
 *						That method is called: TC1_MASK_OUTPUT_C
 *
 */
void tc3_set_interruptMask(enum tc3_interruptMask_R tc_interrupt_enum);


/**
 * \brief				* Configures the TC0 Interrupt Mask Register
 * 
 * \param				tc_interrupt_enum : type of interrupt
 *						specific mode begins with: TC0_MASK_
 *
 */
void tc0_set_interruptMask(enum tc0_interruptMask_R tc_interrupt_enum);


/**
 * \brief				* Configures the TC2 Interrupt Mask Register
 * 
 * \param				tc_interrupt_enum : type of interrupt
 *						specific mode begins with: TC2_MASK_
 *
 */
void tc2_set_interruptMask(enum tc2_interruptMask_R tc_interrupt_enum);


/**
 * \brief				Resets the timer value
 * 
 * \param TIMER			Select the desired timer (timer 0/1/2/3)
 * 
 */
void tc_resetTimer(unsigned char timer);


/**
 * \brief				Stop the timer
 * 
 * \param timer			Select the desired timer (timer 0/1/2/3)
 *							
 * 
 */
void tc_stopTimer(volatile uint16_t timer);


// Initialize the counter value TCNT1
void tc1_set_current_cValue(unsigned short counterVal);


// Initialize the counter value TCNT3
void tc3_set_current_cValue(unsigned short counterVal);

				
// Initialize the counter value TCNT0
void tc0_set_current_cValue(unsigned char counterVal);


// Initialize the counter value TCNT2
void tc2_set_current_cValue(unsigned char counterVal);


/**
* \brief	Read the counter value TCNT1
*
*
* \return unsigned short  - TCNT1
*/
unsigned short tc1_get_current_cValue();


/**
* \brief	Read the counter value TCNT3
*
*
* \return unsigned short  - TCNT3
*/
unsigned short tc3_get_current_cValue();


/**
* \brief	Read the counter value TCNT0
*
*
* \return unsigned short  - TCNT0
*/
unsigned char tc0_get_current_cValue();


/**
* \brief	Read the counter value TCNT2
*
*
* \return unsigned short  - TCNT2
*/
unsigned char tc2_get_current_cValue();



#endif /* AVR_TIMERS_H_ */