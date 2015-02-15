#ifndef OI_H
#define OI_H

#include "WPILib.h"

// currently set up for 2 joystick tank, add more features later!


class OI
{
private:

public:
	OI();
	Joystick *tankDriveJoystickLeft;
	Joystick *tankDriveJoystickRight;
	Joystick *threeAxisJoystick;
	Joystick *xboxController;
	Joystick *NESController;
	Joystick *launchPad;
};

#endif
