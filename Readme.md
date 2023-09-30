# SNESpaduino

**SNESpaduino** is a simple library to make an Arduino communicate with a Super Nintendo ( **SNES** ) Gamepad.
The core function is very simple, and easy to understand through the comments in the code.

For details on the SNES communication specification see:
https://www.fpgalover.com/ip-cores/snes-controller-core

## Usage

* Download and copy the SNESpaduino Folder, containing both .cpp and .h files, to your Arduino libraries directory.
* Include the library header file into your project ( `#include <SNESpaduino.h>` )
* Create a new instance of the SNESpaduino class ( `SNESpaduino pad(PIN_LATCH, PIN_CLOCK, PIN_DATA);` )
* Call the `getButtons()` function, which will return the current state of all 12 buttons ( `uint16_t btns = pad.getButtons();` )

## Parse data

The easiest way to process the incoming data is AND'ing it with the bitmasks defined as constants in `SNESpaduino.h`.

Look into the `examples` directory for some code examples. Also, read the blogpost linked above for more information.

## Interfacing the SNES Gamepad

There are 5 wires connecting to the Gamepad: *+5V, GND, Latch, Clock, Data*.
Connect **+5V** and **GND** to the Arduino's 5V/GND pins.
Latch, Clock and Data can be connected to any pin that can digitally read.

Again, read the blogpost for more details :)

## License

**Creative Commons Attribution-ShareAlike Unported 3.0 ( CC-BY-SA 3.0 )**

http://creativecommons.org/licenses/by-sa/3.0/legalcode

Feel free to contact me, if you have any questions or feedback!

Author: Damon Dransfeld
