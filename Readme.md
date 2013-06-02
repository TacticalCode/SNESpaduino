# SNESpaduino

**SNESpaduino** is a simple library to make an Arduino communicate with a Super Nintendo (**SNES**) Gamepad.
The core function is very simple, and easy to understand through the comments in the code.

*Blogpost explaining everything in detail to be written*

## Usage

* Download and copy the SNESpaduino Folder, containing both .cpp and .h files, to your Arduino libraries directory.
* Include the library header file into your project ( `#include <SNESpaduino.h>` )
* Create a new instance of the SNESpaduino class ( `SNESpaduino pad(PIN_LATCH, PIN_CLOCK, PIN_DATA);` )
* Call the `getButtons()` function, which will return the current state of all 12 buttons ( `uint16_t btns = pad.getButtons();` )

## Parse data

The returned data can easily be parsed using code that will be added shortly. There will also be examples.

## Interfacing the SNES Gamepad

There are 5 wires connecting to the Gamepad: *+5V, GND, Latch, Clock, Data*.
Connect **+5V** and **GND** to the Arduino's 5V/GND pins.
Latch, Clock and Data can be connected to any pin that can digitally read.

Detailed description to be added in the upcoming blogpost.

## License

**Creative Commons Attribution-ShareAlike Unported 3.0 ( CC-BY-SA 3.0 http://creativecommons.org/licenses/by-sa/3.0/legalcode )**
Feel free to contact me, if you have any questions or feedback!

Author: Damon Dransfeld
