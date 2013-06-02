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

#define BTN_B 0x01
#define BTN_Y 0x02
#define BTN_SELECT 0x04
#define BTN_START 0x08
#define BTN_UP 0x10
#define BTN_DOWN 0x20
#define BTN_LEFT 0x40
#define BTN_RIGHT 0x80
#define BTN_A 0x100
#define BTN_X 0x200
#define BTN_L 0x400
#define BTN_R 0x800

#include "Arduino.h"

class SNESpaduino
{
	public:
		SNESpaduino(byte latch, byte clock, byte data);
		uint16_t getButtons(void);
	private:
		uint16_t state;
		byte i, PIN_LATCH, PIN_CLOCK, PIN_DATA;
};

#endif
