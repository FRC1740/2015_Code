#include "MecanumTankDrive.h"

MecanumTankDrive::MecanumTankDrive()
{
	Requires(drivetrain);
}

void MecanumTankDrive::Initialize()
{

}

void MecanumTankDrive::Execute()
{
	drivetrain->front_right_motor->Set(oi->joystick_2->GetY() + oi->joystick_2->GetX());
	drivetrain->rear_right_motor->Set(oi->joystick_2->GetY() - oi->joystick_2->GetX());
	drivetrain->front_left_motor->Set(oi->joystick_1->GetY() - oi->joystick_1->GetX());
	drivetrain->rear_left_motor->Set(oi->joystick_1->GetY() + oi->joystick_1->GetX());
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumTankDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumTankDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumTankDrive::Interrupted()
{
	drivetrain->Stop();
}
