#include "OI.h"
#include "Commands/Grab.h"
#include "Commands/Release.h"
#include "Commands/Raise.h"
#include "Commands/Lower.h"
#include "Commands/PrintRange.h"
#include "Commands/LightLED.h"
#include "DataLogger.h"

OI::OI(DataLogger *logger)
{
	l=logger;

	// Driver Station option A: Sticks 1 & 2 used for Tank Drive
	tankDriveJoystickLeft = new Joystick(1);
	tankDriveJoystickRight = new Joystick(2);
	// Driver Station option B: Stick 3 is 3-axis joystick
	threeAxisJoystick = new Joystick(3);
	// Driver Station option C: Stick 4 is Xbox controller
	xboxController = new Joystick(4);
	// Joystick 5 is the NES controller
	NESController = new Joystick(5);
	// Joystick 0 is the launchpad
	launchPad = new Joystick(0);
    // Create some buttons
	/*
	 *
	 *
	 * 	3-Axis Joystick Button Map
	 *  Uncomment the appropriate lines for the buttons you would like to map
	 *
	 */


    // JoystickButton *j3_1 = new JoystickButton(joystick_3, 1);	// Trigger
    // JoystickButton *j3_2 = new JoystickButton(joystick_3, 2);	// Thumb (Natural Position)

	// The following buttons are mapped to the lifter Raise() and Lower() commands
    // JoystickButton *j3_3 = new JoystickButton(joystick_3, 3);		// Thumb (below/left of d_pad)
    // JoystickButton *j3_4 = new JoystickButton(joystick_3, 4);		// Thumb (below/right of d_pad)

    // JoystickButton *j3_5 = new JoystickButton(joystick_3, 5);		// Thumb (left of d_pad)
    // JoystickButton *j3_6 = new JoystickButton(joystick_3, 6);		// Thumb (right of d_pad)
    // JoystickButton *j3_7 = new JoystickButton(joystick_3, 7);		// Left side/10_O'Clock Outer

    // The 9 & 11 buttons are mapped to the pneumatic gripper Grab() & Release() commands
    // JoystickButton *j3_9 = new JoystickButton(joystick_3, 9);		// Left side/10_O'Clock Inner
    // JoystickButton *j3_8 = new JoystickButton(joystick_3, 8);		// Left side/9_O'Clock Outer
	// JoystickButton *j3_10 = new JoystickButton(joystick_3, 10);		// Left side/9_O'Clock Inner
    // JoystickButton *j3_11 = new JoystickButton(joystick_3, 11);	// Left side/8_O'Clock Outer
	// JoystickButton *j3_12 = new JoystickButton(joystick_3, 12);		// Left side/8_O'Clock Inner



    /*
     *
     * XBOX Controller Button Map
     * Uncomment the appropriate lines for the buttons you would like to map
     *
     */

    // JoystickButton *j4_1 = new JoystickButton(joystick_4, 1);	// A
    // JoystickButton *j4_2 = new JoystickButton(joystick_4, 2);	// B
    // JoystickButton *j4_3 = new JoystickButton(joystick_4, 3);	// X
    // JoystickButton *j4_4 = new JoystickButton(joystick_4, 4);	// Y

    // JoystickButton *j4_5 = new JoystickButton(joystick_4, 5);		// Left Bumper
    // JoystickButton *j4_6 = new JoystickButton(joystick_4, 6);		// Right Bumper

    // JoystickButton *j4_7 = new JoystickButton(joystick_4, 7);		// Left side/10_O'Clock Outer

    // JoystickButton *j4_9 = new JoystickButton(joystick_4, 9);		// Left side/10_O'Clock Inner
    // JoystickButton *j4_8 = new JoystickButton(joystick_4, 8);		// Left side/9_O'Clock Outer
	// JoystickButton *j4_10 = new JoystickButton(joystick_4, 10);		// Left side/9_O'Clock Inner
    // JoystickButton *j4_11 = new JoystickButton(joystick_4, 11);	// Left side/8_O'Clock Outer
	// JoystickButton *j4_12 = new JoystickButton(joystick_4, 12);		// Left side/8_O'Clock Inner


    /*
     *
     * NES Controller Button Map
     * Uncomment the appropriate lines for the buttons you would like to map
     *
     */
    JoystickButton *NES_2 = new JoystickButton(NESController, 2);   // The "A Button" for closing the forks
    JoystickButton *NES_3 = new JoystickButton(NESController, 3);   // The "B Button" for opening the forks
    JoystickButton *NES_9 = new JoystickButton(NESController, 9);   // The "Select Button" for lowering the forks
    JoystickButton *NES_10 = new JoystickButton(NESController, 10); // The "Start Button" for raising the forks

    JoystickButton *launchPad_1 = new JoystickButton(launchPad, 1); // button 1 on the launchpad
    // Connect the buttons to commands

    //light led with launchpad
    launchPad_1->WhileHeld(new LightLED());

    // Grabber
    // j3_8->WhileHeld(new PrintRange());
    NES_2->WhenPressed(new Grab(logger));
    NES_3->WhenPressed(new Release(logger));

    // Lifter
    NES_9->WhileHeld(new Raise());
    NES_10->WhileHeld(new Lower());

}
