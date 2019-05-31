/*
 * stdutils.h
 *
 * Created: 4/19/2019 9:46:20 PM
 *  Author: braso
 */ 


#ifndef STDUTILS_H_
#define STDUTILS_H_

#ifndef F_CPU
#define F_CPU  7372800UL
#endif

/***************************************************************************************************
				Macros for Bit Manipulation
 ****************************************************************************************************/
#define  util_GetBitMask(bit)          (1<<(bit))
#define  util_BitSet(x,bit)            ((x) |=  util_GetBitMask(bit))
#define  util_BitClear(x,bit)          ((x) &= ~util_GetBitMask(bit))
#define  util_BitToggle(x,bit)         ((x) ^=  util_GetBitMask(bit))
#define  util_UpdateBit(x,bit,val)     ((val)? util_BitSet(x,bit): util_BitClear(x,bit))
/**************************************************************************************************/


/***************************************************************************************************
				Port Direction configurations
 ***************************************************************************************************/
#define C_PinOutput_U8     0x01u
#define C_PinInput_U8      0x00u
#define C_PortOutput_U8    0xFFu
#define C_PortInput_U8     0x00u

#define INPUT              C_PinInput_U8
#define OUTPUT             C_PinOutput_U8
#define LOW                0x00u
#define HIGH               0x01u
/**************************************************************************************************/


/***************************************************************************************************
				Macros to set the timer
 ***************************************************************************************************/
#define Timer0 TCNT0
#define Timer1 TCNT1
#define Timer2 TCNT2
#define Timer3 TCNT3

#define timer0		0
#define timer1		1
#define timer2		2
#define timer3		3
/**************************************************************************************************/

/***************************************************************************************************
				Macros of commonly used LCD Commands	
 ***************************************************************************************************/
#define LCD_CLEAR				0x01

#define LCD_RETURN_HOME				0x02

#define LCD_INCREMENT_RIGHT			0x06
#define LCD_DECREMENT_LEFT			0x04

#define LCD_DISPLAY_ON_CURSOR_OFF		0x0C
#define LCD_DISPLAY_ON_CURSOR_ON		0x0E
#define LCD_DISPLAY_ON_CURSOR_BLINK		0x0F

#define LCD_FOUR_BIT_MODE			0x28
#define LCD_EIGHT_BIT_MODE			0x38

#define LCD_CURSOR_HOME_POSITION		0x80
/**************************************************************************************************/


/***************************************************************************************************
				Macros to set the interrupt sense control 
 ***************************************************************************************************/
#define LOW_LVL_0		0x00u
#define RESERVED_0		0x01u
#define FALLING_EDGE_0		0x02u
#define RISING_EDGE_0		0x03u

#define LOW_LVL_1		0x00u
#define RESERVED_1		0x04u
#define FALLING_EDGE_1		0x08u
#define RISING_EDGE_1		0x0Cu

#define LOW_LVL_2		0x00u
#define RESERVED_2		0x10u
#define FALLING_EDGE_2		0x20u
#define RISING_EDGE_2		0x30u

#define LOW_LVL_3		0x00u
#define RESERVED_3		0x40u
#define FALLING_EDGE_3		0x80u
#define RISING_EDGE_3		0xC0u

#define LOW_LVL_4		0x00u
#define RESERVED_4		0x01u
#define FALLING_EDGE_4		0x02u
#define RISING_EDGE_4		0x03u

#define LOW_LVL_5		0x00u
#define RESERVED_5		0x04u
#define FALLING_EDGE_5		0x08u
#define RISING_EDGE_5		0x0Cu

#define LOW_LVL_6		0x00u
#define RESERVED_6		0x10u
#define FALLING_EDGE_6		0x20u
#define RISING_EDGE_6		0x30u

#define LOW_LVL_7		0x00u
#define RESERVED_7		0x40u
#define FALLING_EDGE_7		0x80u
#define RISING_EDGE_7		0xC0u
/**************************************************************************************************/


#endif /* STDUTILS_H_ */
