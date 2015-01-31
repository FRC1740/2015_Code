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
	// Driver Station option B: Stick 3 is 3-axis joystick
	joystick_3 = new Joystick(3);
	// Driver Station option C: Stick 4 is Xbox controller
	joystick_4 = new Joystick(4);

    // Create some buttons

	/*
	 *
	 *
	 * 	3-Axis Joystick Button Map
	 *  Uncomment the appropriate lines for the buttons you would like to map
	 *
	 */


    // JoystickButton *j1 = new JoystickButton(joystick_3, 1);	// Trigger
    // JoystickButton *j2 = new JoystickButton(joystick_3, 2);	// Thumb (Natural Position)

	// The following buttons are mapped to the lifter Raise() and Lower() commands
    JoystickButton *j3 = new JoystickButton(joystick_3, 3);		// Thumb (below/left of d-pad)
    JoystickButton *j4 = new JoystickButton(joystick_3, 4);		// Thumb (below/right of d-pad)

    // JoystickButton *j5 = new JoystickButton(joystick_3, 5);		// Thumb (left of d-pad)
    // JoystickButton *j6 = new JoystickButton(joystick_3, 6);		// Thumb (right of d-pad)
    // JoystickButton *j7 = new JoystickButton(joystick_3, 7);		// Left side/10-O'Clock Outer

    // The 9 & 11 buttons are mapped to the pneumatic gripper Grab() & Release() commands
    JoystickButton *j9 = new JoystickButton(joystick_3, 9);		// Left side/10-O'Clock Inner
    JoystickButton *j8 = new JoystickButton(joystick_3, 8);		// Left side/9-O'Clock Outer
	// JoystickButton *j10 = new JoystickButton(joystick_3, 10);		// Left side/9-O'Clock Inner
    JoystickButton *j11 = new JoystickButton(joystick_3, 11);	// Left side/8-O'Clock Outer
	// JoystickButton *j12 = new JoystickButton(joystick_3, 12);		// Left side/8-O'Clock Inner



    /*
     *
     * XBOX Controller Button Map
     * Uncomment the appropriate lines for the buttons you would like to map
     *
     */

    // JoystickButton *j1 = new JoystickButton(joystick_4, 1);	// A
    // JoystickButton *j2 = new JoystickButton(joystick_4, 2);	// B
    // JoystickButton *j3 = new JoystickButton(joystick_4, 3);	// X
    // JoystickButton *j4 = new JoystickButton(joystick_4, 4);	// Y

    // The 9 & 11 buttons are mapped to the pneumatic gripper Grab() & Release() commands
    JoystickButton *j5 = new JoystickButton(joystick_4, 5);		// Left Bumper
    JoystickButton *j6 = new JoystickButton(joystick_4, 6);		// Right Bumper

    // JoystickButton *j7 = new JoystickButton(joystick_4, 7);		// Left side/10-O'Clock Outer

    // JoystickButton *j9 = new JoystickButton(joystick_4, 9);		// Left side/10-O'Clock Inner
    // JoystickButton *j8 = new JoystickButton(joystick_4, 8);		// Left side/9-O'Clock Outer
	// JoystickButton *j10 = new JoystickButton(joystick_4, 10);		// Left side/9-O'Clock Inner
    // JoystickButton *j11 = new JoystickButton(joystick_4, 11);	// Left side/8-O'Clock Outer
	// JoystickButton *j12 = new JoystickButton(joystick_4, 12);		// Left side/8-O'Clock Inner


    // Connect the buttons to commands

    // Grabber
    j8->WhileHeld(new PrintRange());
    j9->WhenPressed(new Grab());
    j11->WhenPressed(new Release());

    // Lifter
    j3->WhileHeld(new Raise());
    j4->WhileHeld(new Lower());

}
