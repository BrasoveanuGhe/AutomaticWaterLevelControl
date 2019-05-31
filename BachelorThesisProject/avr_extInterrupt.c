/*
 * avr_extInterrupt.c
 *
 * Created: 10/14/2018 12:24:27 PM
 *  Author: braso
 */ 


#include "avr_extInterrupt.h"


void set_extInterrupt(volatile uint8_t *interrupt_Reg, uint8_t interrupt_Pin, uint8_t interrupt_Control)
{
	interrupt_init.interruptRegister = interrupt_Reg;
	interrupt_init.interruptControl = interrupt_Control;
	
	switch(interrupt_Pin)
	{
		case INT0: 
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
				
		case INT1:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
		case INT2:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
		case INT3:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
		case INT4:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
		case INT5:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
		case INT6:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;
		case INT7:
				{
					*(interrupt_init.interruptRegister) |= (interrupt_init.interruptControl);
					
				}break;		
	}
}


void set_extInterrupt_Enable(volatile uint8_t *interrupt_Reg, uint8_t mask)
{
	interrupt_init.interruptRegister = interrupt_Reg;
	interrupt_init.MASK = mask;
	
	*(interrupt_init.interruptRegister) |= (1 << interrupt_init.MASK);
}


void set_extInterrupt_Disable(volatile uint8_t *interrupt_Reg, uint8_t mask)
{
	interrupt_init.interruptRegister = interrupt_Reg;
	interrupt_init.MASK = mask;
	
	*(interrupt_init.interruptRegister) &= ~(1 << interrupt_init.MASK);
}


void reset_extInterrupt_A()
{
	EICRA = 0x00;
}


void reset_extInterrupt_B()
{
	EICRB = 0x00;
}
