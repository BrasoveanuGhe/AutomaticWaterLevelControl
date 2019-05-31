/*
 * lcd_func.c
 *
 * Created: 10/20/2018 12:32:33 PM
 *  Author: braso
 */ 


#include "lcd_defines.h"


void liquidCrystalPortInit(volatile uint8_t *dataPort, volatile uint8_t *cmdPort, uint8_t rsPin, uint8_t rwPin, uint8_t enPin)
{
	
	lcd_portInit.dataPort = dataPort;
	lcd_portInit.commandPort = cmdPort;
	lcd_portInit.pin_RS = rsPin;
	lcd_portInit.pin_RW = rwPin;
	lcd_portInit.pin_EN = enPin;
	
	// DDRn - set as output all data pins (from 0 to 7)
	*(lcd_portInit.dataPort - 1) = 0xff;
	
	// DDRn - set pin direction (all as output pins RS, RW, EN)
	*(lcd_portInit.commandPort - 1) |= (1 << lcd_portInit.pin_EN);
	*(lcd_portInit.commandPort - 1) |= (1 << lcd_portInit.pin_RS);
	*(lcd_portInit.commandPort - 1) |= (1 << lcd_portInit.pin_RW);	
	
	lcd_cmdWrite(LCD_CLEAR);					// Clear LCD
	lcd_cmdWrite(LCD_INCREMENT_RIGHT);			// Set entry mode set
	lcd_cmdWrite(LCD_DISPLAY_ON_CURSOR_OFF);	// Set display on and don't show the cursor
	lcd_cmdWrite(LCD_EIGHT_BIT_MODE);			// Set the 8 bit mode
	lcd_cmdWrite(LCD_CURSOR_HOME_POSITION);		// Cursor at home position
}



/* LCD command function */
void lcd_cmdWrite(uint8_t v_lcdCmd)
{
	// Set PORTx with command value
	*(lcd_portInit.dataPort) = v_lcdCmd;
	// Set RS to 0 -> write a command
	*(lcd_portInit.commandPort) &= ~(1 << lcd_portInit.pin_RS);
	// Set RW to 0 -> write data (not to read)
	*(lcd_portInit.commandPort) &= ~(1 << lcd_portInit.pin_RW);
	// Set EN pin to HIGH state -> enable pulse 
	*(lcd_portInit.commandPort) |= (1 << lcd_portInit.pin_EN);
	_delay_ms(1);
	// Set EN pin to LOW state
	*(lcd_portInit.commandPort) &= ~(1 << lcd_portInit.pin_EN);
   _delay_ms(1);

}



/* LCD data write function */
void lcd_dataWrite(uint8_t v_lcdData)
{
	// Set PORTx with data value
	*(lcd_portInit.dataPort) = v_lcdData;
	// Set RS to 1 -> write a data byte
	*(lcd_portInit.commandPort) |= (1 << lcd_portInit.pin_RS);
	// Set RW to 0 -> write data (no to read)
	*(lcd_portInit.commandPort) &= ~(1 << lcd_portInit.pin_RW);
	// Set EN pin to HIGH state
	*(lcd_portInit.commandPort) |= (1 << lcd_portInit.pin_EN);
	_delay_ms(1);
	// Set EN pin to LOW state
	*(lcd_portInit.commandPort) &= ~(1 << lcd_portInit.pin_EN);
	_delay_ms(1);
	
}



/* Send string to LCD function */
void lcd_displayChar(char *str)
{
	while(*str > 0){
		
		lcd_dataWrite(*str);
		str++;
	}	
}



/* Cleaning function lcd */
void lcd_clear(volatile uint8_t *PORT)
{	
	// Clear LCD screen and set the cursor at home position
	lcd_cmdWrite(LCD_CLEAR);
}



/* Send string to LCD with x-y position */
void lcd_goToLine(unsigned char row, unsigned char position)
{
	unsigned char firstAdress[] = {0x80,0xC0,0x94,0xD4};
	lcd_cmdWrite(firstAdress[row-1]+ position-1);
	_delay_ms(10);
}



/* Function for real numbers */
void lcd_displayFloatNumber(double floatNum)
{
	/* Function converts the double value passed in val into an ASCII representation that will be stored under string */
	dtostrf(floatNum,1,2,displayFloatNum);
	
	lcd_displayChar(displayFloatNum);
}

