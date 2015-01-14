#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 // drivetrain motors go here, currently set up to assume 4 motor
#define front_left_motor_port 0
#define front_right_motor_port 1
#define rear_left_motor_port 2
#define rear_right_motor_port 3

// Pneumatic port configuration
#define CYLINDER_PORT0 0 // Gripper solenoid wired to port 0 on pneumatic break-out card
#define CYLINDER_PORT1 1 // Release solenoid wired to port 1 on pneumatic break-out card

#define RANGEFINDER_CHANNEL 6

#endif
