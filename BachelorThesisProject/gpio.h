/*
 * avr_gpio.h
 *
 * Created: 10/20/2018 7:26:39 PM
 *  Author: braso
 */ 


#ifndef AVR_GPIO_H_
#define AVR_GPIO_H_

#include <avr/io.h>
#include "stdutils.h"

typedef struct
{
	volatile uint8_t *portDirection;
	volatile uint8_t *pinDirection;
	volatile uint8_t *pinState; 
	volatile uint8_t *pinRead;	
	
}  gpio_commandInit;

gpio_commandInit gpio_portInit;


/***************************************************************************************************
 * description : This function sets the specified direction as INPUT/OUTPUT for PORT.  
 
 * I/P Arguments: 
				PORT:	The port you want to use.
                state:	Direction to be configured:  INPUT/OUTPUT.
                             
 * Return value    : none
 ***************************************************************************************************/
void gpio_portDirection (volatile uint8_t *port, unsigned char state);



/***************************************************************************************************
 * description : This function sets the specified direction as INPUT/OUTPUT.  
 
 * I/P Arguments: 
				PORT:		The port you want to use.
                pinNumber:	Pin number which needs to be updated.
                            Refer the gpio.h for pin numbering.
                v_pinDir:	Direction to be configured:  INPUT/OUTPUT.
                              

 * Return value    : none
 ***************************************************************************************************/
void gpio_pinDirection(volatile uint8_t *port,unsigned char pinNumber, unsigned char v_pinDir);



/***************************************************************************************************
 * description : This function updates the specified value on the selected pin.
 
 * I/P Arguments:
				PORT:		The port you want to use.
                pinNumber:	Pin number which needs to be updated.
                            Refer the gpio.h for pin numbering.
                v_pinValue: Value to be updated(LOW/HIGH) on the selected pin.
                              

 * Return value    : none
***************************************************************************************************/
void gpio_pinWrite(volatile uint8_t *port,unsigned char pinNumber, unsigned char v_pinValue);



/***************************************************************************************************
 * description : This function returns the status of the selected pin.
 
 * I/P Arguments:
				PORT:	   The port you want to use 
                pinNumber: Pin number which needs to be read.
                           Refer the gpio.h for pin numbering.

 * Return value    : 
                 uint8_t:    Status of the specified pin.
 ***************************************************************************************************/
uint8_t gpio_pinRead(volatile uint8_t *port, char pinNumber);



#endif /* AVR_GPIO_H_ */