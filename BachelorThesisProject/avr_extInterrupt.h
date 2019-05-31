/*
 * avr_extInterrupt.h
 *
 * Created: 10/14/2018 12:24:50 PM
 *  Author: braso
 */ 


#ifndef AVR_EXTINTERRUPT_H_
#define AVR_EXTINTERRUPT_H_

#include <avr/io.h>
#include <stdlib.h>
#include "stdutils.h"


typedef struct{
	
	volatile uint8_t *interruptRegister;
	uint8_t interruptControl;
	uint8_t MASK;
	
} ExternalBits;

ExternalBits interrupt_init;


/**	
 * \brief							configures the external interrupt control register
 * 
 * \param interrupt_Reg				register A (EICRA) or register B (EICRB)
 * \param interrupt_Pin				select the pin on which the interruption occurs
 *									bits 7:0 – INTn: [n = 7:0]
 *
 * \param interrupt_Control			bits 7:0 – INTn: [n = 7:0]
 *									LOW_LVL_n -> The low level of INTn generates an interrupt request
 * 									RESERVED_n -> Reserved.
 *									FALLING_EDGE_n -> The falling edge of INTn generates asynchronously an interrupt request.
 *									RISING_EDGE_n -> The rising edge of INTn generates asynchronously an interrupt request.
 *									
 * \return void
 */

void set_extInterrupt(volatile uint8_t *interrupt_Reg, uint8_t interrupt_Pin, uint8_t interrupt_Control);


/**
 * \brief						external interrupt request n Enable [n = 7:0]
 * 
 * \param interrupt_Reg			port address
 * \param mask					Bits 7:0 – INTn: External Interrupt Request n Enable [n = 7:0]
 * 
 * \return void
 */
void set_extInterrupt_Enable(volatile uint8_t *interrupt_Reg, uint8_t mask);


/**
 * \brief						external interrupt request n Disable [n = 7:0]
 * 
 * \param interrupt_Reg			port address
 * \param mask					Bits 7:0 – INTn: External Interrupt Request n Disable [n = 7:0]
 * 
 * \return void
 */
void set_extInterrupt_Disable(volatile uint8_t *interrupt_Reg, uint8_t mask);


/**
 * \brief	Reset register EICRA 
 * 
 * 
 * \return void
 */
void reset_extInterrupt_A();


/**
 * \brief	Reset register EICRB 
 * 
 * 
 * \return void
 */
void reset_extInterrupt_B();


#endif /* AVR_EXTINTERRUPT_H_ */