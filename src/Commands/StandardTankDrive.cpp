#include "StandardTankDrive.h"


StandardTankDrive::StandardTankDrive()
{
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void StandardTankDrive::Initialize()
{

}
// Called repeatedly when this Command is scheduled to run
void StandardTankDrive::Execute()
{
	drivetrain->front_left_motor->Set(oi->joystick_1->GetY());
	drivetrain->rear_left_motor->Set(oi->joystick_1->GetY());
	drivetrain->front_right_motor->Set(oi->joystick_2->GetY());
	drivetrain->rear_right_motor->Set(oi->joystick_2->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool StandardTankDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StandardTankDrive::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StandardTankDrive::Interrupted()
{
	drivetrain->Stop();
}
