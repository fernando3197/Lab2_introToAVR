/*	Author: fgonz059
 *  Partner(s) Name: 
 *	Lab Section: 22
 *	Assignment: Lab # 2  Exercise # 4
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0X00; PORTC = 0xFF; // Configure port A's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port B's 8 pins as outputs, initialize
		
	unsigned char tempWeight = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	unsigned char tempD = 0x00;
	
	while (1) {
		tempA = PINA;
		tempB = PINB;
		tempC = PINC;
		tempWeight = tempA + tempB + tempC;
			
		tempD = tempWeight > 140 ? tempD | 0x01 : tempD & 0xFE;
		tempD = (tempA - tempC) > 80 ? tempD | 0x02 : tempD & 0xFD;
		tempD = (tempD & 0x03) | (tempWeight & 0xFC);	
		PORTD = tempD;
	}
	return 0;
}
