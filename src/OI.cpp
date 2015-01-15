#include "OI.h"
#include "Commands/Grab.h"
#include "Commands/Release.h"
#include "Commands/Raise.h"
#include "Commands/Lower.h"
#include "Commands/PrintRange.h"

OI::OI() {
	// Driver Station option A: Sticks 1 & 2 used for Tank Drive
	joystick_1 = new Joystick(1);
	joystick_2 = new Joystick(2);
	// Drvier Station option B: Stick 3 is 3-axis joystick
	joystick_3 = new Joystick(3);
	// Driver Station option C: Stick 4 is Xbox controller
	joystick_4 = new Joystick(4);

    // Create some buttons

	/*
	 *
	 *
	 * 	3-Axis Joystick Controls
	 *  Uncomment the appropriate lines for the inputs you would like to map
	 *
	 */


    // JoystickButton *j1 = new JoystickButton(joystick_3, 1);	// Trigger
    // JoystickButton *j2 = new JoystickButton(joystick_3, 2);	// Thumb (Natural Position)
    JoystickButton *j3 = new JoystickButton(joystick_3, 3);		// Thumb (below/left of d-pad)
    JoystickButton *j4 = new JoystickButton(joystick_3, 4);		// Thumb (below/right of d-pad)
    // JoystickButton *j5 = new JoystickButton(joystick_3, 5);		// Thumb (left of d-pad)
    // JoystickButton *j6 = new JoystickButton(joystick_3, 6);		// Thumb (right of d-pad)
    // JoystickButton *j7 = new JoystickButton(joystick_3, 7);		// Left side/10-O'Clock Outer
	JoystickButton *j9 = new JoystickButton(joystick_3, 9);		// Left side/10-O'Clock Inner
    JoystickButton *j8 = new JoystickButton(joystick_3, 8);		// Left side/9-O'Clock Outer
	// JoystickButton *j10 = new JoystickButton(joystick_3, 10);		// Left side/9-O'Clock Inner
    JoystickButton *j11 = new JoystickButton(joystick_3, 11);	// Left side/8-O'Clock Outer
	// JoystickButton *j12 = new JoystickButton(joystick_3, 12);		// Left side/8-O'Clock Inner


    // Connect the buttons to commands

    // Grabber
    j8->WhileHeld(new PrintRange());
    j9->WhenPressed(new Grab());
    j11->WhenPressed(new Release());

    // Lifter
    j3->WhileHeld(new Raise());
    j4->WhileHeld(new Lower());

}
