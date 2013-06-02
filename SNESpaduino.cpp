/*******************************
 *
 *	File: SNESpaduino.cpp
 *	Description: SNESpaduino library: Use an Arduino to read the button states of a SNES Gamepad
 *	Author: Damon Dransfeld
 *	Web: http://tacticalcode.de
 *	License: CC-BY-SA 3.0 ( http://creativecommons.org/licenses/by-sa/3.0/legalcode )
 *
 ******************************/

#include "Arduino.h"
#include "SNESpaduino.h"

// Constructor: Init pins
SNESpaduino::SNESpaduino(byte latch, byte clock, byte data)
{
	// Store the latch, clock and data pin for later use
	PIN_LATCH = latch;
	PIN_CLOCK = clock;
	PIN_DATA = data;

	// Set correct modes for the communication pins
	pinMode(PIN_LATCH, OUTPUT);
	pinMode(PIN_CLOCK, OUTPUT);
	pinMode(PIN_DATA, INPUT);

}

// Return the state of all buttons. 12 of the uint16_t's bits are used, the 4 MSBs must be ignored.
uint16_t SNESpaduino::getButtons(boolean return_inverted)
{
	// Init the button-state variable
	state = 0;

	// Latch the current buttons' state into the pad's register
	digitalWrite(PIN_LATCH, HIGH);
	digitalWrite(PIN_LATCH, LOW);

	// Loop to receive 12 bits from the pad
	for(i = 0; i < 12; i++)
	{
		// Read a button's state, shift it into the variable
		state |= digitalRead(PIN_DATA) << i;

		// Send a clock pulse to shift out the next bit
		digitalWrite(PIN_CLOCK, HIGH);
		digitalWrite(PIN_CLOCK, LOW);
	}

	// Return the bits
	if(return_inverted)
		return ~state;
	else
		return state;
}
