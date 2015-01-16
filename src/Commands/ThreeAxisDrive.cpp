#include "ThreeAxisDrive.h"

ThreeAxisDrive::ThreeAxisDrive()
{
	Requires(drivetrain);
}

void ThreeAxisDrive::Initialize()
{

}

void ThreeAxisDrive::Execute()
{

	drivetrain->front_left_motor->Set(oi->joystick_3->GetTwist() - oi->joystick_3->GetY() - oi->joystick_3->GetX());
	drivetrain->front_right_motor->Set(oi->joystick_3->GetTwist() + oi->joystick_3->GetY() + oi->joystick_3->GetX());
	drivetrain->rear_left_motor->Set(oi->joystick_3->GetTwist() - oi->joystick_3->GetY() + oi->joystick_3->GetX());
	drivetrain->rear_right_motor->Set(oi->joystick_3->GetTwist() + oi->joystick_3->GetY() - oi->joystick_3->GetX());
}

// Make this return true when this Command no longer needs to run execute()
bool ThreeAxisDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ThreeAxisDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ThreeAxisDrive::Interrupted()
{
	drivetrain->Stop();
}
