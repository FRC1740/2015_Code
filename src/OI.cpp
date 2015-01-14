#include "OI.h"
#include "Commands/Grab.h"
#include "Commands/Release.h"
#include "Commands/Raise.h"
#include "Commands/Lower.h"

OI::OI() {
	// Driver Station option A: Sticks 1 & 2 used for Tank Drive
	joystick_1 = new Joystick(1);
	joystick_2 = new Joystick(2);
	// Drvier Station option B: Stick 3 is 3-axis joystick
	joystick_3 = new Joystick(3);

    // Create some buttons
    JoystickButton* j9 = new JoystickButton(joystick_3, 9);
    JoystickButton* j11 = new JoystickButton(joystick_3, 11);
    JoystickButton *j3 = new JoystickButton(joystick_3, 3);
    JoystickButton *j4 = new JoystickButton(joystick_3, 4);


    // Connect the buttons to commands

    // Grabber
    j9->WhenPressed(new Grab());
    j11->WhenPressed(new Release());

    // Lifter
    j3->WhileHeld(new Raise());
    j4->WhileHeld(new Lower());

}
