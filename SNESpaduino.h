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

#define BTN_B 0x01       // 0b0000000000000001
#define BTN_Y 0x02       // 0b0000000000000010
#define BTN_SELECT 0x04  // 0b0000000000000100
#define BTN_START 0x08   // 0b0000000000001000
#define BTN_UP 0x10      // 0b0000000000010000
#define BTN_DOWN 0x20    // 0b0000000000100000
#define BTN_LEFT 0x40    // 0b0000000001000000
#define BTN_RIGHT 0x80   // 0b0000000010000000
#define BTN_A 0x100      // 0b0000000100000000
#define BTN_X 0x200      // 0b0000001000000000
#define BTN_L 0x400      // 0b0000010000000000
#define BTN_R 0x800      // 0b0000100000000000

#include "Arduino.h"

class SNESpaduino
{
	public:
		SNESpaduino(byte latch, byte clock, byte data);
		uint16_t getButtons(boolean return_inverted = true);
	private:
		uint16_t state;
		byte i, PIN_LATCH, PIN_CLOCK, PIN_DATA;
};

#endif
