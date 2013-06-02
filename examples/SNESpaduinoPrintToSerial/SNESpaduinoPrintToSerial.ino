/*******************************
 *
 *	File: SNESpaduinoPrintToSerial.ino
 *	Description: Demo basic usage of the SNESpaduino library: How to read and parse values
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
	// INVERTED, easy parsing of SINGLE button presses at ONCE
	btns = pad.getButtons();

	/***************************
	* In this example, we use the INVERTED button states for easy checking
	* of SINGLE button presses. Join the button states and a button constant
	* with an AND junction; this statement is TRUE if the button belonging
	* to that constant was pressed:		btns & BTN_A
	***************************/

	// True if A was pressed
	if(btns & BTN_A)
		Serial.println("BTN_A");

	// True if DOWN was pressed
	if(btns & BTN_DOWN)
		Serial.println("BTN_DOWN");

	/***************************
	* You can also use this to check for MULTIPLE button presses.
	* But maybe, the NON-INVERTED states suit you better. See also:
	* examples/SNESpaduinoNonInverted
	* Anyway, here is how to check for multiple buttons being pressed:
	* (Just nest the IF statements)
	***************************/

	// True if X was pressed
	if(btns & BTN_X)
	{
		// True if Y was pressed
		if(btns & BTN_Y)
		{
			// X *AND* Y were pressed!
			Serial.println("BTN_X + BTN_Y");
		}
		else
		{
			// Y was NOT pressed, only X
			Serial.println("BTN_X");
		}
	}

	/***********************
	* Now, we can also cover many possible combinations:
	* Either	START
	* or		START + SELECT
	* or		START + L
	* or		START + Y
	* or		START + SELECT + L
	* or		START + SELECT + Y
	* or		START + L + Y
	* or		START + SELECT + L + Y
	* were pressed. Magic? Nope:
	***********************/

	// True if START was pressed
	if(btns & BTN_START)
	{
		Serial.print("BTN_START");

		//True, if SELECT was pressed
		if(btns & BTN_SELECT)
			Serial.print(" + BTN_SELECT");

		//True, if L was pressed
		if(btns & BTN_L)
			Serial.print(" + BTN_L");

		//True, if Y was pressed
		if(btns & BTN_Y)
			Serial.print(" + BTN_Y");

		//Just write a NEWLINE
		Serial.println("");
	}

	// Wait a bit, we don't want to flood the serial connection
	delay(250);
}
