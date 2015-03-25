#include "OI.h"
#include "Commands/Gripper/Grab.h"
#include "Commands/Gripper/Release.h"
#include "Commands/Lifter/Raise.h"
#include "Commands/Lifter/Lower.h"
#include "Commands/Lifter/CalibrateLifter.h"
#include "Commands/Lifter/MoveToLevel.h"
//#include "Commands/Rangefinder/RangeLight.h"
#include "Commands/Launchpad/LightLED.h"

OI::OI()
{

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


    // JoystickButton *threeAxis_1 = new JoystickButton(threeAxisJoystick, 1);	// Trigger
    // JoystickButton *threeAxis_2 = new JoystickButton(threeAxisJoystick, 2);	// Thumb (Natural Position)

	// The following buttons are mapped to the lifter Raise() and Lower() commands
    // JoystickButton *threeAxis_3 = new JoystickButton(threeAxisJoystick, 3);		// Thumb (below/left of d_pad)
    // JoystickButton *threeAxis_4 = new JoystickButton(threeAxisJoystick, 4);		// Thumb (below/right of d_pad)

    // JoystickButton *threeAxis_5 = new JoystickButton(threeAxisJoystick, 5);		// Thumb (left of d_pad)
    // JoystickButton *threeAxis_6 = new JoystickButton(threeAxisJoystick, 6);		// Thumb (right of d_pad)

    // The 7, 9 & 11 buttons are mapped to the Lifter level (1, 2, 3) commands
    JoystickButton *threeAxis_7 = new JoystickButton(threeAxisJoystick, 7);		// Left side/10_O'Clock Outer
    // JoystickButton *threeAxis_8 = new JoystickButton(threeAxisJoystick, 8);		// Left side/9_O'Clock Outer
    JoystickButton *threeAxis_9 = new JoystickButton(threeAxisJoystick, 9);		// Left side/10_O'Clock Inner
	// JoystickButton *threeAxis_10 = new JoystickButton(threeAxisJoystick, 10);		// Left side/9_O'Clock Inner
    JoystickButton *threeAxis_11 = new JoystickButton(threeAxisJoystick, 11);	// Left side/8_O'Clock Outer
	// JoystickButton *threeAxis_12 = new JoystickButton(threeAxisJoystick, 12);		// Left side/8_O'Clock Inner

    threeAxis_7->WhenPressed(new CalibrateLifter());
    threeAxis_9->WhenPressed(new MoveToLevel(LEVEL_ONE));
    threeAxis_11->WhenPressed(new MoveToLevel(LEVEL_TWO));


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

    // Grabber
    // threeAxis_8->WhileHeld(new PrintRange());
    NES_2->WhenPressed(new Grab());
    NES_3->WhenPressed(new Release());

    // Lifter
    NES_9->WhileHeld(new Raise());
    NES_10->WhileHeld(new Lower());
// TODO Map button to auto stack
//    JoystickButton *launchPad_1 = new JoystickButton(launchPad, 1); // button 1 on the launchpad
    // Connect the buttons to commands

    //light led with launchpad
//    launchPad_1->WhileHeld(new LightLED());


}
