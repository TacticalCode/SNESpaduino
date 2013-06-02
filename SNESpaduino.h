/*******************************
 *
 *	File: SNESpaduino.h
 *	Description: Header file for the SNESpaduino library
 *	Author: Damon Dransfeld
 *	Web: http://tacticalcode.de
 *	License: CC-BY-SA 3.0 ( http://creativecommons.org/licenses/by-sa/3.0/legalcode )
 *
 ******************************/
 
#ifndef snesduino_h
#define snesduino_h

#include "Arduino.h"

class SNESpaduino
{
	public:
		SNESpaduino(int latch, int clock, int data);
		uint16_t getButtons(void);
	private:
		uint16_t state;
		int i, PIN_LATCH, PIN_CLOCK, PIN_DATA;
}

#endif