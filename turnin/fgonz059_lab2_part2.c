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
		
	unsigned char cntavail = 0x00;
	unsigned char tmpA = 0x00;		   // to 0s
	while (1) {
		tmpA = PINA;
		cntavail = (tmpA & 0x01) + (tmpA & 0x02) + (tmpA & 0x04) + (tmpA & 0x08);
		
		PORTC = cntavail; 
	}
	return 0;
}
