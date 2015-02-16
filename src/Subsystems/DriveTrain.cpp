#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") { // remember to update this to the correct type of motor controller
	front_left_motor = new Victor(front_left_motor_port);
	front_right_motor = new Victor(front_right_motor_port);
	rear_left_motor = new Victor(rear_left_motor_port);
	rear_right_motor = new Victor(rear_right_motor_port);
}
// NOTE I removed a function called InitDefaultCommand since this subsystems default command is controled by the sendable chooser
void DriveTrain::Go(float front_left_speed, float front_right_speed, float rear_left_speed, float rear_right_speed){
	front_left_motor->Set(-1 * front_left_speed); // should the -1 be taken care of here?, reverses the motors since they are on the opposite side of the robot
	front_right_motor->Set(front_right_speed);  // ktk - one big drive command because you can use pointers to directly control the motors from other objects eg. drivetrain->frontrightmotor->Set(1);
	rear_left_motor->Set(-1 * rear_left_speed);
	rear_right_motor->Set(rear_right_speed);
}

void DriveTrain::Stop(){ // give stopping the motors its own function for clarity
	front_left_motor->Set(0);
	front_right_motor->Set(0);
	rear_left_motor->Set(0);
	rear_right_motor->Set(0);
}
