#ifndef OI_H
#define OI_H

#include "WPILib.h"

// currently set up for 2 joystick tank, add more features later!


class OI {
private:

public:
	OI();
	Joystick *joystick_1;
	Joystick *joystick_2;
	Joystick *joystick_3;

};

#endif
