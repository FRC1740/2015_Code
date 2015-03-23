#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 // drivetrain motors go here, currently set up to assume 4 motor
#define front_left_motor_port 	0
#define front_right_motor_port 	1
#define rear_left_motor_port 	2
#define rear_right_motor_port 	3

#define ANGLE_CORRECTION 5; // offsets straight by x degrees counter clockwise
// TODO VECTORIZE JOYSTICK INPUTS

// #define LIFTER_MOTOR_PORT		4 // Use if LifterMotor is controlled by a Victor
#define LIFTER_MOTOR_CAN_CHANNEL 0  //
#define LIFTER_ENCODER_PORT_0	5
#define LIFTER_ENCODER_PORT_1 	4

#define UPPER_LIMIT_PORT		0
#define LOWER_LIMIT_PORT		1

#define LEFT 1
#define RIGHT -1

#define FWD  1 // these are directions relative to the robot
#define REV -1

// Pneumatic port configuration
#define CYLINDER_PORT0 0 // Gripper solenoid wired to port 0 on pneumatic break-out card
#define CYLINDER_PORT1 1 // Release solenoid wired to port 1 on pneumatic break-out card

#define RANGEFINDER_CHANNEL 0

// Forklift Levels
#define LEVEL_ONE 0 // // We reset encoder to 0 at bottom limit switch
#define LEVEL_TWO 375 // SWAG
#define LEVEL_THREE 750 // SWAG

#endif
