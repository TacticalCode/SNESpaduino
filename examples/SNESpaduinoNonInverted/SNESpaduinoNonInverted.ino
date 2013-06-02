/*******************************
 *
 *	File: SNESpaduinoNonInverted.ino
 *	Description: Demo parsing the NON-INVERTED output of the pad
 *	Author: Damon Dransfeld
 *	Web: http://tacticalcode.de
 *	License: CC-BY-SA 3.0 ( http://creativecommons.org/licenses/by-sa/3.0/legalcode )
 *
 ******************************/

// First, include the library
#include <SNESpaduino.h>

// Create a SNESpaduino instance, change the parameters (pin values) to your needs!
SNESpaduino pad(20, 21, 19);

// A variable to store the button-state value
uint16_t btns;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	// Get the state of all buttons
	// NOT INVERTED, easy to parse MULTIPLE button presses at ONCE
	btns = pad.getButtons(false);

	/***************************
	* Now, checking if MULTIPLE buttons were pressed at once is easy.
	* First, join all button constants you want to check against w/ logic OR junction
	* You want to test is A & B were pressed:	BTN_A | BTN_B
	* Next, AND-ing this with the NON-INVERTED button states will give you FALSE,
	*	if ALL those buttons were pressed:		btns & (BTN_A | BTN_B)
	* Finally, invert this statement to become true, if ALL those buttons were pressed
	*											!(btns & (BTN_A | BTN_B))
	* This might seem a bit more complicated than the INVERTED output, but helps
	* especially when checking for MANY simultaneous button presses.
	* Got it? See the examples below!
	***************************/

	// True if A *AND* B were pressed
	if(!(btns & (BTN_A | BTN_B)))
		Serial.println("BTN_A + BTN_B");

	// True if X *AND* Y were pressed
	if(!(btns & (BTN_X | BTN_Y)))
		Serial.println("BTN_X + BTN_Y");

	// True, if X *AND* A *AND* UP were pressed
	if(!(btns & (BTN_X | BTN_A | BTN_UP)))
		Serial.println("BTN_X + BTN_A + BTN_UP");

	// True if START *AND* SELECT were pressed
	if(!(btns & (BTN_START | BTN_SELECT)))
	{
		// True, if L *AND* R were pressed
		if(!(btns & (BTN_L | BTN_R)))
		{
			// Now, START & SELECT *AND* L & R were pressed!
			Serial.println("BTN_START + BTN_SELECT + BTN_L + BTN_R");
		}
		else
		{
			// START & SELECT were pressed, L&R not
			Serial.println("BTN_START + BTN_SELECT");
		}
	}

	// Don't spam over serial
	delay(250);
}