/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 2 Exercise # 3
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
	unsigned char cntavail = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpA = 0x00;		   // to 0s
	while (1) {
		cntavail = 0x00;
		tmpA = (~PINA) & 0x0F;
		if (tmpA & 0x01) { cntavail = cntavail + 1; }
		if (tmpA & 0x02) { cntavail = cntavail + 1; }
		if (tmpA & 0x04) { cntavail = cntavail + 1; }
		if (tmpA & 0x08) { cntavail = cntavail + 1; }
		
		tmpC = cntavail;
		if (tmpA & 0x0F){ tmpC = tmpC + 0x80; }	
		
		PORTC = tmpC;
	}
	return 0;
}
