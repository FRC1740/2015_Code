#include "MecanumTankDrive.h"

MecanumTankDrive::MecanumTankDrive()
{
	Requires(drivetrain);  // obviously drive modes need exclusive drivetrain access
}

void MecanumTankDrive::Initialize()
{
//	l->Log("MecanumTankDrive::Initialize()", STATUS_MESSAGE);
}

void MecanumTankDrive::Execute()
{
	drivetrain->front_left_motor->Set(oi->tankDriveJoystickLeft->GetY() - oi->tankDriveJoystickLeft->GetX());
	drivetrain->rear_left_motor->Set(oi->tankDriveJoystickLeft->GetY() + oi->tankDriveJoystickLeft->GetX());
	drivetrain->front_right_motor->Set(oi->tankDriveJoystickRight->GetY() + oi->tankDriveJoystickRight->GetX());
	drivetrain->rear_right_motor->Set(oi->tankDriveJoystickRight->GetY() - oi->tankDriveJoystickRight->GetX());
}

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
