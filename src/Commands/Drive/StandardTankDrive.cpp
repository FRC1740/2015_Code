#include "StandardTankDrive.h"


StandardTankDrive::StandardTankDrive(DataLogger *logger)
{
	Requires(drivetrain);
	l=logger;
}

// Called just before this Command runs the first time
void StandardTankDrive::Initialize()
{
	l->Log("StandardTankDrive::Initialize()", STATUS_MESSAGE);
}
// Called repeatedly when this Command is scheduled to run
void StandardTankDrive::Execute()
{
	drivetrain->front_left_motor->Set(oi->tankDriveJoystickLeft->GetY());
	drivetrain->rear_left_motor->Set(oi->tankDriveJoystickLeft->GetY());
	drivetrain->front_right_motor->Set(oi->tankDriveJoystickRight->GetY());
	drivetrain->rear_right_motor->Set(oi->tankDriveJoystickRight->GetY());
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
