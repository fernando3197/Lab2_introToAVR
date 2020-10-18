/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize
		
	unsigned char tmpC = 0x00;
	unsigned char tmpA = 0x00;		   // to 0s
	while (1) {
		tmpA = PINA & 0x8F;
		
		tmpC = tmpA && 0x01 ? (tmpC | 0x01) : (tmpC & 0x8E);
		tmpC = tmpA && 0x02 ? (tmpC | 0x02) : (tmpC & 0x8D);
		tmpC = tmpA && 0x04 ? (tmpC | 0x04) : (tmpC & 0x8B);
		tmpC = tmpA && 0x08 ? (tmpC | 0x08) : (tmpC & 0x87);
		
		PORTC = (tmpC == (tmpC & 0x0F)) ? PINC | 0x80 : PINC & 0x0F; 
	}
	return 0;
}
