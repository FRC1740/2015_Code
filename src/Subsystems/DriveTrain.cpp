#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/TeleopDrive.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") { // remember to update this to the correct type of motor controller
	front_right_motor = new Victor(front_right_motor_port);
	front_left_motor = new Victor(front_left_motor_port);
	rear_right_motor = new Victor(rear_right_motor_port);
	rear_left_motor = new Victor(rear_left_motor_port);
}
    
void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new TeleopDrive());
}

// NOTE: STANDARD: high grip wheels
void DriveTrain::StandardTankDrive(float input_left, float input_right){
	front_left_motor->Set(input_left);  // note in the tutorial video he uses SetSpeed(float) instead, not sure what the difference is
	rear_left_motor->Set(input_left);
	front_right_motor->Set(input_right);
	rear_right_motor->Set(input_right);
}
void DriveTrain::MecanumTankDrive(float input_left_x, float input_left_y, float input_right_x, float input_right_y){
	front_right_motor->Set(input_right_y + input_right_x);
	rear_right_motor->Set(input_right_y - input_right_x);
	front_left_motor->Set(-1 * (input_left_y - input_left_x));
	rear_left_motor->Set(-1 * (input_left_y + input_left_x));
}
void DriveTrain::ThreeAxisDrive(float input_y, float input_x, float input_twist){
	front_right_motor->Set(input_y + input_x + input_twist);
	rear_right_motor->Set(input_y - input_x + input_twist);
	front_left_motor->Set(-1 * (input_y - input_x - input_twist));
	rear_left_motor->Set(-1 * (input_y + input_x - input_twist));
}
void DriveTrain::Stop(){
	front_right_motor->Set(0);
	front_left_motor->Set(0);
	rear_right_motor->Set(0);
	rear_left_motor->Set(0);
}
		



