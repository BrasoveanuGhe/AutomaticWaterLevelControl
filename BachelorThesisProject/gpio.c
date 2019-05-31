/*
 * avr_gpio.c
 *
 * Created: 10/20/2018 7:26:27 PM
 *  Author: braso
 */ 


#include "gpio.h"


void gpio_portDirection (volatile uint8_t *port, unsigned char state)
{
	gpio_portInit.portDirection = port;
	
	 if(state == OUTPUT)
		*(gpio_portInit.portDirection-1) = 0xff;
	 else
		*(gpio_portInit.portDirection-1) = 0x00;	 
}


void gpio_pinDirection(volatile uint8_t *port,unsigned char pinNumber, unsigned char v_pinDir)
{
	gpio_portInit.pinDirection = port;
	
	if(v_pinDir == OUTPUT)
		*(gpio_portInit.pinDirection-1) |= (1 << pinNumber);
	else
		*(gpio_portInit.pinDirection-1) &= ~(1 << pinNumber);
}



void gpio_pinWrite(volatile uint8_t *port,unsigned char pinNumber, unsigned char v_pinValue)
{
	gpio_portInit.pinState = port;
	
	if(v_pinValue == HIGH)
		*(gpio_portInit.pinState) |= (1 << pinNumber);
	else
		*(gpio_portInit.pinState) &= ~(1 << pinNumber);
}



uint8_t gpio_pinRead(volatile uint8_t *port, char pinNumber)
{
	gpio_portInit.pinRead = port;
	
	if((*(gpio_portInit.pinRead-2) & (1 << pinNumber)) == 0)
		return 0;
	else 
		return 1;	
}